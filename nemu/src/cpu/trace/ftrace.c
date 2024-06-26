#include <common.h>
#include <elf.h>
#include <utils.h>

#define MAX_FUNC_NUM 20
#define MAX_TMP_STR 100
#define MAX_BUF_SIZE 240
#define MAX_RECUR_DEPTH 50
#define INST_BYTE MUXDEF(CONFIG_ISA64, 8, 4)
#define EXTRACT_ST_TYPE(x) MUXDEF(CONFIG_ISA64, ELF64_ST_TYPE, ELF32_ST_TYPE)((x))
#define UNKNOWN_FUNC_NAME "?????"
#define UNKNOWN_FUNC_ADDR 0xFFFFFFFF

typedef MUXDEF(CONFIG_ISA64, Elf64_Ehdr, Elf32_Ehdr) Elf_header;
typedef MUXDEF(CONFIG_ISA64, Elf64_Shdr, Elf32_Shdr) Elf_section_header;
typedef MUXDEF(CONFIG_ISA64, Elf64_Off,  Elf32_Off)  Elf_off;
typedef MUXDEF(CONFIG_ISA64, Elf64_Sym,  Elf32_Sym)  Elf_sym;
typedef MUXDEF(CONFIG_ISA64, uint64_t,   uint32_t)   Elf_entsize;
typedef MUXDEF(CONFIG_ISA64, Elf64_Addr, Elf32_Addr) Elf_addr;

typedef struct {
    char func_name[20];
    vaddr_t func_addr;
} Func;
typedef Func Func_list[MAX_FUNC_NUM];

Func_list func_list;
int func_idx = 0;
int recur_depth = 0;
int recur_times = 0;
vaddr_t snpcs[MAX_RECUR_DEPTH];

int cmp_st_name(const void* sym1_, const void* sym2_) {
    Elf_sym *sym1 = (Elf_sym *) sym1_, *sym2 = (Elf_sym *) sym2_;
    return (int) sym1->st_name - (int) sym2->st_name;
}

int cmp_sh_name(const void* sh1_, const void* sh2_) {
    Elf_section_header *sh1 = (Elf_section_header *) sh1_, *sh2 = (Elf_section_header *) sh2_;
    return (int) sh1->sh_name - (int) sh2->sh_name;
}

int cmp_func(const void *fn1_, const void* fn2_) {
    Func *fn1 = (Func *) fn1_, *fn2 = (Func *) fn2_;
    return (int) fn1->func_addr - (int) fn2->func_addr; 
}


void init_elf(const char *elf_file_path) {
    FILE* elf_file = NULL;
    Elf_header* elf_header = malloc(sizeof(Elf_header));
    Elf_section_header* shstrtab_section_header = malloc(sizeof(Elf_section_header));
    Elf_section_header* strtab_section_header = malloc(sizeof(Elf_section_header));
    Elf_section_header* symtab_section_header = malloc(sizeof(Elf_section_header));
    
    if (elf_file_path != NULL) {
        FILE *cur_file = fopen(elf_file_path, "r");
        Assert(cur_file, "(Fail read elf file) Cannot open elf file '%s'", elf_file_path);
        elf_file = cur_file;
    }
    int num_read = fread(elf_header, sizeof(Elf_header), 1, elf_file);
    Elf_section_header* section_headers_start = malloc(elf_header->e_shnum * sizeof(Elf_section_header));
    fseek(elf_file, elf_header->e_shoff, SEEK_SET);
    num_read = fread(section_headers_start, sizeof(Elf_section_header), elf_header->e_shnum, elf_file);
    shstrtab_section_header = section_headers_start + elf_header->e_shstrndx;
    fseek(elf_file, shstrtab_section_header->sh_offset, SEEK_SET);
    Elf_sym* shstrtab = malloc(shstrtab_section_header->sh_size);
    num_read = fread(shstrtab, shstrtab_section_header->sh_size, 1, elf_file);
    qsort(section_headers_start, (size_t) elf_header->e_shnum, sizeof(Elf_section_header), cmp_sh_name);
    char* shstrptr = (char *) shstrtab;
    bool found_sym = false, found_str = false;
    int idx = 0;
    for (int i = 0; i < elf_header->e_shnum; i++) {
        Elf_section_header* cur_section_header = section_headers_start + i;
        if (!found_sym && cur_section_header->sh_type == SHT_SYMTAB) {
            symtab_section_header = cur_section_header;
            found_sym = true;
        }
        if (!found_str && cur_section_header->sh_type == SHT_STRTAB) {
            shstrptr++;
            int sh_name_idx = cur_section_header->sh_name;
            while (idx++ < sh_name_idx) shstrptr = strchr(shstrptr, '\0');
            if (!strcmp(shstrptr + 1, ".strtab")) {
                strtab_section_header = cur_section_header;
                found_str = true;
            }
        }

    }
    Elf_sym* strtab = malloc(strtab_section_header->sh_size);
    Elf_sym* symtab = malloc(symtab_section_header->sh_size);
    fseek(elf_file, symtab_section_header->sh_offset, SEEK_SET);
    num_read = fread(symtab, symtab_section_header->sh_size, 1, elf_file);
    fseek(elf_file, strtab_section_header->sh_offset, SEEK_SET);
    num_read = fread(strtab, strtab_section_header->sh_size, 1, elf_file);
    Assert(num_read == 1, "All fseek() and fread() calls are successful.");
    word_t num_ent = symtab_section_header->sh_size / symtab_section_header->sh_entsize;
    qsort(symtab, num_ent, symtab_section_header->sh_entsize, cmp_st_name);
    char* strptr = (char *) strtab;
    idx = 0;
    for (int i = 0; i < num_ent; i++) {
        Elf_sym* cur_ent = symtab + i;
        if (EXTRACT_ST_TYPE(cur_ent->st_info) == STT_FUNC) {
            func_list[func_idx].func_addr = cur_ent->st_value;
            strcpy(func_list[func_idx].func_name, strptr + cur_ent->st_name);
            Log("(Parsing function) Function -- function name : %s | function address " FMT_WORD, func_list[func_idx].func_name, func_list[func_idx].func_addr);
            func_idx++;
        }
    }
    qsort(func_list, func_idx, sizeof(Func), cmp_func);
}


void print_func_trace(vaddr_t cur_pc, vaddr_t jfn_pc, word_t cur_inst) {
    bool jtype = cur_inst == 0x00008067;
    Func* cur_func = jtype ? NULL : bsearch(&(Func){UNKNOWN_FUNC_NAME, jfn_pc}, func_list, func_idx, sizeof(Func), cmp_func);
    if (!cur_func && !jtype) return;
    int num_space = recur_depth - (int) jtype;      
    char n_spaces[num_space + 1];
    N_SPACES_STR(n_spaces, num_space);
    char buf[MAX_BUF_SIZE];
    char *buf_p = buf;
    buf_p += snprintf(buf_p, 20, "0x" FMT_WORD ": ", cur_pc);
    buf_p += snprintf(buf_p, num_space + 1, "%s", n_spaces);
    buf_p += snprintf(buf_p, 10, "%s", jtype ? "ret" : "call");
    if (jtype) buf_p += snprintf(buf_p,  buf + MAX_BUF_SIZE - buf_p, "[address: " FMT_WORD "]", jfn_pc);
    else buf_p += snprintf(buf_p, buf + MAX_BUF_SIZE - buf_p, "[%s@0x" FMT_WORD "]", cur_func == NULL ? UNKNOWN_FUNC_NAME : cur_func->func_name, cur_func == NULL ? UNKNOWN_FUNC_ADDR : cur_func->func_addr);
    Log("(Ftrace result) depth : %d | times : %d | output : %s", num_space, recur_times, buf);
    //#ifdef CONFIG_FTRACE_COND
    //if (FTRACE_COND) log_write("%s\n", buf);
    //#endif
    if (!jtype) snpcs[recur_depth++] = cur_pc + INST_BYTE;
    else {
        while (snpcs[recur_depth - 1] != jfn_pc) recur_depth--;
        recur_depth--;
    }
    recur_times += (int) (!jtype);
}