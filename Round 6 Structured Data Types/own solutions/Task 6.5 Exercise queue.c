#include "queue.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int enqueue(struct studentqueue *q, const char *name)
{
  struct studentqueue *student = malloc(sizeof(struct studentqueue));
  if (student == NULL){
      return 0;
  } else {
    student -> name = malloc(strlen(name) + 1);
    strcpy(student -> name, name);
    student -> next = NULL;
    struct studentqueue *current = q;
    for (int i = 0; current->next != NULL; i++){
      current = current -> next;
    }
    current -> next = student;
    return 1;
  }
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
  if (q -> next == NULL){
      return 0;
  } else {
      struct studentqueue* firstItem = q -> next;
      q -> next = q -> next -> next; 
      strncpy(buffer, firstItem -> name, size);
      buffer[size] = '\0';
      free(firstItem -> name);
      free(firstItem);
      return 1;
  }
}