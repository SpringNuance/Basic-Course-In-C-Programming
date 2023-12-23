#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;  // name of student
    char ID[7];  // student ID (nul terminated)
    // you may add fields to this structure if needed
} Student;

typedef struct {
    Student * students;
} Course;

// implement your functions and main function here

void add_student(Course *c, const char *name, const char *ID){
    int i = 0;
    for ( ; c->students[i].name != NULL; i++); // Find the index i of the last element of the database
    c->students = realloc(c->students, sizeof(Student) * (i + 2)); // Memory reallocation for database
    c->students[i].name = malloc((strlen(name) + 1)); // Allocate dynamic memory for new nation name
    strcpy(c->students[i].name, name); // Copy the name into the memory
    strcpy(c->students[i].ID, ID); // Copy the name into the memory
    c->students[++i].name = NULL;
}

void remove_student(Course *c, const char *ID){
    int check = -1;
    int i = 0;
    while (c->students[i].name != NULL){
        if (strcmp(c ->students[i].ID, ID) == 0) {
            check = i;
            break;
        }
        i++;
    }

    if (check != -1){
        free(c->students[check].name);
        while (c->students[check+1].name != NULL){
            c->students[check].name = c->students[check+1].name;
            c->students[check].ID[0] = c->students[check+1].ID[0];
            check++;
        }
        c->students[check].name = c->students[check+1].name;
        c->students[check].ID[0] = c->students[check+1].ID[0];
        
    }

}

int main(void){
    Course * algebra = malloc(sizeof(Course));
    algebra -> students = malloc(sizeof(Student));
    algebra -> students[0].name = NULL;
    Course * calculus = malloc(sizeof(Course));
    calculus -> students = malloc(sizeof(Student));
    calculus -> students[0].name = NULL;
    Course * statistics = malloc(sizeof(Course));
    statistics -> students = malloc(sizeof(Student));
    statistics -> students[0].name = NULL;
    add_student(algebra, "A", "123");
    add_student(algebra, "B", "234");
    add_student(algebra, "C", "345");
    add_student(calculus, "D", "456");
    add_student(calculus, "E", "567");
    add_student(calculus, "F", "678");
    add_student(statistics, "G", "789");
    add_student(statistics, "H", "890");
    add_student(statistics, "I", "012");
    for (unsigned int i = 0; i < 3; i++) {
        printf("%s %s\n", algebra->students[i].name, algebra->students[i].ID);
    }
    for (unsigned int i = 0; i < 3; i++) {
        printf("%s %s\n", calculus->students[i].name, calculus->students[i].ID);
    }
    for (unsigned int i = 0; i < 3; i++) {
        printf("%s %s\n", statistics->students[i].name, statistics->students[i].ID);
    }
    
    remove_student(algebra, "123");
    remove_student(calculus, "456");
    remove_student(statistics, "789");
    
    for (unsigned int i = 0; i < 2; i++) {
        printf("%s %s\n", algebra->students[i].name, algebra->students[i].ID);
    }
    for (unsigned int i = 0; i < 2; i++) {
        printf("%s %s\n", calculus->students[i].name, calculus->students[i].ID);
    }
    for (unsigned int i = 0; i < 2; i++) {
        printf("%s %s\n", statistics->students[i].name, statistics->students[i].ID);
    }
   
    add_student(algebra, "J", "286");
    add_student(calculus, "K", "048");
    add_student(statistics, "L", "348");
       for (unsigned int i = 0; i < 3; i++) {
        printf("%s %s\n", algebra->students[i].name, algebra->students[i].ID);
    }
    for (unsigned int i = 0; i < 3; i++) {
        printf("%s %s\n", calculus->students[i].name, calculus->students[i].ID);
    }
    for (unsigned int i = 0; i < 3; i++) {
        printf("%s %s\n", statistics->students[i].name, statistics->students[i].ID);
    }

    for (unsigned int k = 0; k < 3; k++) {
        free(algebra -> students[k].name);
        free(calculus -> students[k].name);
        free(statistics -> students[k].name);
    }
    free(algebra->students);
    free(calculus->students);
    free(statistics->students);
    free(algebra);
    free(calculus);
    free(statistics);
    return 0;
}

