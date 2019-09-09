#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person{
    char name[26];
    int age;
};

int main(void){
    // Declare a new struct
    struct person user;

    // Get and set data
    printf("Enter your age: \n");
    scanf("%d", &user.age);
    printf("Enter your name: \n");
    scanf("%s", user.name);

    // Print
    printf("Your name is %s and you are %d years old. \n", user.name, user.age);

    // End
    return 1;
}