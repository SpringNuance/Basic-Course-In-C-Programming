#include <stdio.h>
#include <stdarg.h>

int myprint(const char *str, ...) {
  va_list args;
  int count = 0;
  va_start (args, str);
  while (*str != '\0') {
    if (*str == '&') {
      printf("%d", va_arg(args, int));
      count++;
    } else {
      printf("%c", *str);
    }
    str++;
  }
  va_end(args);
  return count;
}
