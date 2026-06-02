/*
  Summer of 2026
  COSC1420 Lab01: Determine whether an integer is odd or even.
  Programmer: Rafael Hernandez
  Date: 6/2/2026
  Program Description: Determine if a number is odd or even.
  Pesudocode:
    1. Ask the user for an integer
    2. Checks whether its an integer
    3. Accept input
    4. Test if input has a remainder
    5. If no remainder, let the user know the input is even
    6. If the remainder, let the user know the input is odd
    7. End program
*/

#include <stdio.h>

int main()
{
    int userInput = 0; // Variable declaration.
    
    printf("Please enter an integer: "); // Prompts user for an integer

    if (scanf("%d", &userInput) != 1) // Checks if input is valid. And then accepts integer value.
    {
        printf("Error: Invalid input. Please insert a number only.\n");
        return 1;
    }

    if (userInput % 2 == 0) // Determines whether the integer is even.
    {
        printf("The input number %d is even.\n", userInput); 
    }
    else 
    {
        printf("The input number %d is odd.\n", userInput); // Determines whether the integer is odd.
    }
    return 0;
}