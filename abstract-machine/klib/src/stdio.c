#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

inline int count_digits(int num_1) {
  int cnt_1 = 0;
  while (num_1 > 0) {
    num_1 /= 10;
    cnt_1++;
  }
  return cnt_1;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int i = 0, cnt = 0;
  while (*(fmt + i) != '\0') {
    if (*(fmt + i) != '%') {
      *(out + cnt) = *(fmt + i);
      cnt++;
      i++;
    } else {
      switch (*(fmt + i + 1)) {
        case 's':
          char* chs = va_arg(ap, char*);
          while (*chs != '\0') *(out + cnt++) = *(chs++); 
          break;
        case 'd':
          int num = va_arg(ap, int);
          if (!num) *(out + cnt++) = '0'; 
          else {
            bool of = false; 
            if (num < 0) {
              *(out + cnt++) = '-';
              of = num == -2147483648;
              num = num == -2147483648 ? -(num + 1) : -num;
            }
            int num_digit = count_digits(num);
            char num_chs[num_digit + 1];
            num_chs[num_digit] = '\0';
            int i = 1;
            while (num > 0) {
              num_chs[num_digit - i] = (i == 1 && of) ? '8' : num % 10 + '0';
              num /= 10;
              i++;
            }
            i = 0;
            while (*(num_chs + i) != '\0') *(out + cnt++) = *(num_chs + i++);
          }
          break;
      }
      i += 2;
    }
  }
  *(out + cnt) = '\0';
  return cnt;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
