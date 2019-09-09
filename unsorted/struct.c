#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person{
    char *surname;
    char *occupation;
    int age;
};

int main(void){
    // Declare a new struct
    struct person sahil;

    // Set some data
    sahil.surname = malloc(sizeof(char)); 
        strcpy(sahil.surname, "Tandon");
    sahil.occupation = malloc(sizeof(char));
        strcpy(sahil.occupation, "Student");
    sahil.age = 21;

    // Print
    printf("Hello Mr %s. You are a %i year old and you are a %s. \n,", sahil.surname, sahil.age, sahil.occupation);

    // Free & End
    free (sahil.surname);
    free (sahil.occupation);
    return 1;
}