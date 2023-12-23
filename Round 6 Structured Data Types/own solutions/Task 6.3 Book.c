#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

int init_book(struct book *p_book, const char *p_id, const char *p_title, 
              const char * p_author, struct date release){
	    
	if (strlen(p_id) <= 9){
		p_book -> title = calloc(strlen(p_title) + 1, sizeof(char*));
		strcpy(p_book-> title, p_title);
		p_book -> author = calloc(strlen(p_author) + 1, sizeof(char*));
		strcpy(p_book-> author, p_author);
		p_book -> release_date = release;
		strcpy(p_book-> id, p_id);
		return 1;
	} else {
		return 0;
	}

}

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book){
    
    // Increase size of the array by one, and reserve space for final NULL member
    struct book *newarray = realloc(collection, sizeof(struct book) * (size + 2));
	if (newarray == NULL) {
        return NULL; // allocating memory did not work
    }
	if (init_book(&newarray[size], new_book.id, new_book.title, new_book.author, new_book.release_date) == 1){
		return newarray;
	} else {
	  free(newarray);
      return NULL;
	}


}