
/*
Below is a main function that uses a **Ship** data structure.
Also in this task you should first define a *Ship* structure, but in addition
you'll need to implement two functions. You can copy the data structure
(and change, if needed) from the previous task. The functions to be implemented
are:

* **clear_cargo** that empties the cargo of the given ship, i.e., sets all
items in *cargo* array to NULL.

* **add_cargo** that adds one item as ship cargo. The item should be added as
first free item in the *cargo* table, i.e., to the first slot with NULL
pointer.

By investigating the *main* function you should deduce what arguments are
needed for the functions, and for example, if you will need pointers or not.
To earn points, the program should compile, and it should print the expected
output, as in the previous task.
*/

#include <stdio.h>
#include <string.h>

// Define the missing structure here
struct Ship{
    char *name;
    float weight;
    char *cargo[10];
};

// Define function clear_cargo here
void clear_cargo(struct Ship *ship){
  int i = 0;
  int size = sizeof(ship -> cargo)/sizeof(char*);
  while (i < size){
    ship -> cargo[i] = NULL;
    i++;
  }
}
// Define function add_cargo here
void add_cargo(struct Ship *ship, char* name){
  int i = 0;
  int size = sizeof(ship -> cargo)/sizeof(char*);
  while (i < size){
      if (ship -> cargo[i] == NULL) {
        break;
      }
    i++;
  }
  ship -> cargo[i] = name;
}

int main(void)
{
    struct Ship vessel_1 = { "Tanker", 100000, { NULL } };

    clear_cargo(&vessel_1);
    add_cargo(&vessel_1, "Gasoline");
    add_cargo(&vessel_1, "Oil");
    add_cargo(&vessel_1, "Diesel");
    
    struct Ship vessel_2;
    vessel_2.name = "Fun boat";
    vessel_2.weight = 1.25;
    clear_cargo(&vessel_2);
    add_cargo(&vessel_2, "Food basket");
    add_cargo(&vessel_2, "Sunscreen");
    add_cargo(&vessel_2, "Very good lemonade");
    add_cargo(&vessel_2, "Frankfurters");

    struct Ship ships[2];
    ships[0] = vessel_1;
    ships[1] = vessel_2;

    for (int i = 0; i < 2; i++) {
	    printf("Name: %s  / Weight %.2f tonnes\n", ships[i].name, ships[i].weight);
	    printf("Cargo:\n");
	    for (int j = 0; ships[i].cargo[j] != NULL; j++) {
	        printf("* %s\n", ships[i].cargo[j]);
	    }
	    printf("----------\n");
    }

    return 0;
}
