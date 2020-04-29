#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_correct_float(string prompt);
int totalcoins;
int quarters;
int dimes;
int nickles;
int pennies;
int q_remain;
int d_remain;
int n_remain;

// Check to see if user input is correct
float get_correct_float(string prompt)
{
    float x;
    do
    {
        x = get_float("%s", prompt);
    }
    while (x < 0);
    return x;
}

int main(void)
{
    float change_owed = get_correct_float("Enter how much change is owed in dollars: ");
    int cents = round(change_owed *100);
    quarters = (cents / 25);  
    q_remain = (cents % 25);   
    dimes = (q_remain / 10);     
    d_remain = (q_remain % 10);      
    nickles = (d_remain /5);        
    n_remain = (d_remain % 5);
    pennies = (n_remain /1);       
    totalcoins = (quarters + dimes + nickles + pennies);
 
    printf("Amount of coins you will recieve: %i \n", totalcoins);
}

