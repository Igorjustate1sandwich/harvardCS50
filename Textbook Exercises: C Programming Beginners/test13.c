/*
    Ch25. Arrays and Pointers
    - array names are known as pointer constants.
    - fgets() is better than scanf and gets().
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // Example Section 1
    int nums[5] = {5, 10, 15, 20, 25};

    /* Normally you can print the first num in array like this */
    printf("First value: %d \n", nums[0]);

    /* With pointers you can also do this */
    printf("First value: %d \n", *nums);

    /*..And this */
    printf("First value: %d \n", *(nums + 0));
    printf("Second value: %d \n", *(nums + 1));
    printf("Third value: %d \n", *(nums + 2));



    // Example Section 2: Characters & Pointers
    char name[50] = "Tyrion Lannister";        // name points to J
    char * pName = "Tyrion Lannister";         // pName points to J

    /* Normally if you wanted to change name you'd need to use strcpy */
    strcpy(name, "Jon Snow");   // make sure array has enough mem

    /* With pointers, there's no need for strcpy */
    pName = "Jon Snow";         // again, be mindful of memory allocation
    printf("Name: %s \n", pName);


    // Example Section 3: Characters, Pointers and SAFE Memory Allocation
    /*  * Normally to get user input you'd use scanf or gets().
        * This is bad because it doesn't control for the user entering more
          information than an array can handle.
        * SOLUTION: start using fgets.                   */
    char country[50];               // Holds string worth 49 characters
    char * pCountry = country;      // Pointer to country. 

    /* Use fgets() to control user input and prevent them from stupidity */
    printf("What country are you from? \n");
    fgets(pCountry, 49, stdin);     // User CANNOT type more than 49 chars
    printf("You're from %s \n", pCountry);


    // Example Section 4: Arrays of Pointers
    int * pAges[5];             // 5 pointers to integers
    float * pWeights[5];        // 5 pointers to floats

    /* You can point to various strings within a single array! */
    char * pNames[5] = {"Jon", "Tyrion", "Jorah", "Sansa", "Arya"};

    for (int i = 0; i < 5; i++)
    {
        printf("Name: %s \n", pNames[i]);
    }
}