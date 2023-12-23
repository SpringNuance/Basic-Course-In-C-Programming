#include <string.h>

void addname(char *buffer, const char *addme, unsigned int maxsize)
{
  strncat(buffer, addme, maxsize - strlen(buffer) - 1);
  strncat(buffer, ",", maxsize - strlen(buffer) - 1);
}
