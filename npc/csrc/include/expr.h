#ifndef __EXPR_H__
#define __EXPR_H__

#include <deque>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include "common.h"


enum class TokenType {
	NUMBER, REGNAME, OPERATOR, PAREN, 
};

std::string token_type_str(TokenType token_type) {
	switch (token_type) {
		case TokenType::NUMBER: return "NUMBER";
		case TokenType::REGNAME: return "REGNAME";
		case TokenType::OPERATOR: return "OPERATOR";
		case TokenType::PAREN: return "PAREN";
	}
	return "";
}


using TokenValue = std::variant<double, std::string>;

struct Token {
	TokenType token_type;
	TokenValue token_value;

	Token(TokenType type, TokenValue value) : token_type(type), token_value(value) {}

	friend std::ostream& operator<<(std::ostream& os, const Token& token);
};


std::ostream& operator<<(std::ostream& os, const Token& token) {
	os << "Token(token type: " << token_type_str(token.token_type) << ", token value: " << (std::holds_alternative<std::string>(token.token_value) ? std::get<std::string>(token.token_value) : std::to_string(std::get<double>(token.token_value))) << ")";
	return os;
}


std::vector<Token> lexer(const std::string& expr_raw) {
	std::string expr;
	std::copy_if(expr_raw.begin(), expr_raw.end(), std::back_inserter(expr), [](char ch) {return !std::isspace(ch);});
	std::vector<Token> tokens;
	for (int i = 0; i < expr.size();) {
		char ch = expr[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') tokens.emplace_back(TokenType::OPERATOR, std::string(1, ch)), i++;
		else if (ch == '(' || ch == ')') tokens.emplace_back(TokenType::PAREN, std::string(1, ch)), i++;
		else if (ch >= '0' && ch <= '9') {
			int j = i;
			while (j < expr.size() && (expr[j] >= '0' && expr[j] <= '9' || expr[j] == '.')) j++;
			std::string num_str = expr.substr(i, j - i);
			tokens.emplace_back(TokenType::NUMBER, std::stod(num_str));
			i = j;
		} else {
			int j = i + 1;
			while (j - i <= 4 && expr[j] != '+' && expr[j] != '-' && expr[j] != '*' && expr[j] != '/' && expr[j] != '(' && expr[j] != ')') j++;
			std::string reg_name = expr.substr(i, j - i);
			if (valid_register_name(reg_name)) tokens.emplace_back(TokenType::REGNAME, reg_name);
			else throw std::runtime_error("[expr.h : lexer] Invalid register name " + reg_name);
			i = j;
		}	
	}
	return tokens;
}


std::unordered_map<std::string, int> precedence = {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};

void evaluate(std::deque<double>& num_stack, std::deque<std::string>& op_stack) {
	double num1 = num_stack.back(); num_stack.pop_back();
	double num2 = num_stack.back(); num_stack.pop_back();
	std::string op = op_stack.back(); op_stack.pop_back();
	if (op == "+") num_stack.push_back(num2 + num1);
	else if (op == "-") num_stack.push_back(num2 - num1);
	else if (op == "*") num_stack.push_back(num2 * num1);
	else if (op == "/")num_stack.push_back(num2 / num1);
}

double parse(const std::vector<Token>& tokens, const std::unique_ptr<VTop>& vtop) {
	std::deque<double> num_stack;
	std::deque<std::string> op_stack; 
	std::cout << "Number of tokens: " << tokens.size() << std::endl;
	for (int i = 0; i < tokens.size(); i++) {
		std::cout << "Iterations " << i << ": " << tokens[i] << std::endl;
		auto cur_token = tokens[i];
		if (cur_token.token_type == TokenType::PAREN && std::get<std::string>(cur_token.token_value) == "(") op_stack.push_back("(");
		else if (cur_token.token_type == TokenType::PAREN && std::get<std::string>(cur_token.token_value) == ")") {
			while (!op_stack.empty()) {
				if (op_stack.back() != "(") evaluate(num_stack, op_stack);
				else {op_stack.pop_back(); break;}
			}
		} else if (cur_token.token_type == TokenType::NUMBER || cur_token.token_type == TokenType::REGNAME) {
			double cur_num = std::holds_alternative<std::string>(cur_token.token_value) ? get_register(vtop, std::get<std::string>(cur_token.token_value)) : std::get<double>(cur_token.token_value);
			num_stack.push_back(cur_num);
		} else {
			if (i > 0 && tokens[i - 1].token_type == TokenType::PAREN && std::get<std::string>(tokens[i - 1].token_value) == "(") num_stack.push_back(0);
			std::string cur_op = std::get<std::string>(cur_token.token_value);
			while (!op_stack.empty() && op_stack.back() != "(") {
				if (precedence[op_stack.back()] >= precedence[cur_op]) {
					evaluate(num_stack, op_stack);
				} else break;
			}
			op_stack.push_back(cur_op);
		}
	}
	std::cout << "Remaining num_stack size " << num_stack.size() << " op_stack size " << op_stack.size() << std::endl;
	while (!op_stack.empty()) evaluate(num_stack, op_stack);
	return num_stack.back();
}

int expression(const std::string& expr, const std::unique_ptr<VTop>& vtop) {
	std::vector<Token> tokens;
	try {
		tokens = lexer(expr);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 0;
	}
	double val;
	try {
		val = parse(tokens, vtop);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 0;
	}
	printf("The expression %s has value %f\n", expr.c_str(), val);
	return 0;
}	

#endif