#include "source.h"
#include <ctype.h>  // for toupper

char *my_toupper(char *dest, const char *src){
	int countD = 0;
	int countS = 0;
	char* origin = dest;
	while(src[countS] != '\0'){
    if (isalpha(src[countS])){
      dest[countD] = toupper(src[countS]);
    } else if (src[countS] == '?'){
      dest[countD] = '!';
	} else if (src[countS] == '.'){
		dest[countD] = '!';
	  for (int i = 0; i <= 1; i++){
		countD++;
		dest[countD] = '!';
	  }
	} else {
      dest[countD] = src[countS];
	}
	  countS++;
	  countD++;
	} 
	dest[countD] = '\0';
    return origin;
}
