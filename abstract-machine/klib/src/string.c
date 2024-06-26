#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  for (const char *p = s; *p != '\0'; p++) len++;
  return len;
}

char *strcpy(char *dst, const char *src) {
  int i;
  for (i = 0; *(src + i) != '\0'; i++) *(dst + i) = *(src + i);
  *(dst + i) = *(src + i);
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  for (size_t i = 0; i < n; i++) *(dst + i) = *(src + i);
  *(dst + n) = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *p = dst;
  while (*p != '\0') p++;
  int i;
  for (i = 0; *(src + i) != '\0'; i++) *(p++) = *(src + i);
  *p = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  int i;
  for (i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++) {
    uint8_t ch1 = *(s1 + i), ch2 = *(s2 + i);
    if (ch1 != ch2) return (unsigned char) ch1 - (unsigned char) ch2;
  }
  return (unsigned char) *(s1 + i) - (unsigned char) *(s2 + i);
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int i;
  for (i = 0; i < n && *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++) {
    uint8_t ch1 = *(s1 + i), ch2 = *(s2 + i);
    if (ch1 != ch2) return (unsigned char) ch1 - (unsigned char) ch2;
  }
  return i == n ? 0 : (unsigned char) *(s1 + i) - (unsigned char) *(s2 + i);
}

void *memset(void *s, int c, size_t n) {
  unsigned char *cs = (unsigned char *) s;
  for (size_t i = 0; i < n; i++) *(cs + i) = (unsigned char) c;
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  char *dst = (char *) out, *src = (char *) in;
  for (size_t i = 0; i < n; i++) *(dst + i) = *(src + i);
  return dst;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  char *c1 = (char *) s1, *c2 = (char *) s2;
  for (size_t i = 0; i < n; i++) {
    char ch1 = *(c1 + i), ch2 = *(c2 + i);
    if (ch1 != ch2) return (unsigned char) ch1 - (unsigned char) ch2;
  }
  return 0;
}

#endif
