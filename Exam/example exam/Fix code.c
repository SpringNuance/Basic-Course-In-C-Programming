#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *mystrchr(char *str, char c)
{
    while (*str) {
        if (*str == c) {
            return str; 
        } 
        str++;
    }
    if (c == '\0') return str;
    return NULL;
}

int *createArray(unsigned int size)
{
    int *array = malloc((sizeof(int) * size));
    for (unsigned int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

struct products {
    char *title;
    double price;
};

/*
struct nation* addNation (const char *nationName, int gold, int silver, int bronze, struct nation *database) {
	int i = 0;
    for ( ; database[i].name != NULL; i++); 
    database = realloc(database, sizeof(struct nation) * (i + 2)); 
    database[i].name = malloc((strlen(nationName) + 1));
    strcpy(database[i].name, nationName);
	database[i].gold = gold; 
	database[i].silver = silver;
	database[i].bronze = bronze;
    database[++i].name = NULL;
    return database;
}
*/

struct products *add_product(struct products *array, unsigned int length,
                             const char *newtitle, double newprice){

    array = realloc(array, sizeof(struct products) * (length + 1)); 
    array[length].title = malloc((strlen(newtitle) + 1)); 
    strcpy(array[length].title, newtitle); 
	array[length].price = newprice;
    return array;
}

// implement your main function here
int main(){
    char * one = mystrchr("hello", 'e');
    char * two = mystrchr("hello", '\0');
    char * three = mystrchr("hello", 'n');
    printf("%s %s %s\n", one, two, three);
    int * array = createArray(10);
    for (unsigned int i = 0; i < 10; i++) {
        printf("%u ", array[i]);
    }
    printf("\n");
    
    struct products * shop = malloc(sizeof(struct products));
    shop = add_product(shop, 0, "cookies", 1);
    shop = add_product(shop, 1, "candies", 2);
    shop = add_product(shop, 2, "cakes", 3);
    for (unsigned int j = 0; j < 3; j++) {
        printf("%s\n", shop[j].title);
        printf("%f\n", shop[j].price);
    }

    for (unsigned int k = 0; k < 3; k++) {
        free(shop[k].title);
    }

    free(shop);
    free(array);
}


/*
// Printing the table
    for (int i = 0; i < sizeDatabase; i++){
	  printf("%s %d %d %d\n", database[i].name, database[i].gold, database[i].silver, database[i].bronze);
    };
*/
/*
struct nation* addNation (const char *nationName, int gold, int silver, int bronze, struct nation *database) {
	int i = 0;
    for ( ; database[i].name != NULL; i++); // Find the index i of the last element of the database
    database = realloc(database, sizeof(struct nation) * (i + 2)); // Memory reallocation for database
    database[i].name = malloc((strlen(nationName) + 1)); // Allocate dynamic memory for new nation name
    strcpy(database[i].name, nationName); // Copy the name into the memory
    // Default number of gold, silver and bronze medals when a nation is added
	database[i].gold = gold; 
	database[i].silver = silver;
	database[i].bronze = bronze;
	// New last element's name shall be NULL again 
    database[++i].name = NULL;
    return database;
}
*/

/*
case 'A': ; // A nation: adding a country into the database
		    int res1 = sscanf(input, "%c %s %s", &command, nationName, check);
			// Only "A string" is accepted. Any unnecessary endings will produce an error
		    if (res1 != 2) {
               printf("A should be followed by exactly 1 argument.\n"); 
		    } else { // Input accepted, main function carried out
                int result1 = checkNation(nationName, database); // Check whether this country is already in the database
                // If yes, prints error
                if (result1 != -1) printf("Nation \"%s\" is already in the database.\n", nationName); else {
                   database = addNation(nationName, 0, 0, 0, database); // If no, add nation to the database
                   printf("SUCCESS\n"); 
                }
			   
		    } 
            break;
*/

/*

        case 'L': ; // L : Output medal table
			int res3 = sscanf(input, "%c %s", &command, check);
			// Only "L" is accepted. Any unnecessary endings will produce an error
		    if (res3 != 1) {
               printf("L should not be followed by any argument.\n"); 
		    } else { // Input accepted, main function carried out
               outputMedalTable(database);
               printf("SUCCESS\n");
		    } 
            break;
*/