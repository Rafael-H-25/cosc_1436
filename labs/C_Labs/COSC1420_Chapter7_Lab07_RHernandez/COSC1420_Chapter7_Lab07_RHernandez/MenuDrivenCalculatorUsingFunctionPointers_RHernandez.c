/*

Course Name: Summer of 2026, COSC 1420, Chapter 7, Lab 7
Program Name: Menu Driven Calculator Using Function Pointers
Program Description: This code is a polymorphic, menu-driven calculator which maps console inputs (A, S, M, D)
to an integer index, which triggers mathematical actions via an array of function pointers. This code implements
checks against division-by-zero.

Programmer: Rafael Hernandez
Date: 6 / 19 / 2026

Pseudocode:
1. Declare and prototype 4 math processing functions:
    - void addValues(double, double);
    - void subtractValues(double, double);
    - void multiplyValues(double, double);
    -void divideValues(double, double);

2. Define the main function logic:
    a. Create character variable named 'userAction' to intercept menu choices.
    b. Create integer variable named 'calcIndex' to track the mapped operation.
    c. Create the double variables named 'operand1' and 'operand2' for calculation inputs.
    d. Initialize an array of 4 function pointers 'executeMath' containing the memory addresses of 
    {addValues, subtractValues, multiplyValues, divideValues}.
    e. Display menu options and collect 'userAction' via scanf.
    f. Execute a 'while' loop as long as toupper(userAction) is not equal to 'E':
        i. Validate if input is a recognized a recognized option ('A', 'S', 'M' 'D'):
            - If invalid input: print an error message.
            - If valid:
                * Map the letter choice to a numeric index (A->0, S->1, M->2, D->3).
                * Prompt for and read 'operand1' and 'operand2'.
                * Fire the targeted calculation function out of the function point array:
                    (*executeMath[calcIndex])(operand1, operand2);
        ii. Prompt the user for the next menu action to update the loop condition.
    g. Once the loop terminates on 'E', display the text 'Program ended.'

3. Define individual function block behaviors:
    - addValues: Computes sum and print formatted output.
    - subtractValues: Computes the difference and print formatted output.
    - multiplyValues: Computes product and print formatted output.
    - divideValues: Check if denominator is 0.0. If true, then print safety alert.
                    else, compute quotient and print formatted output.

*/

#include <stdio.h>
#include <ctype.h>

// Foward function declarations (prototype) matching assigment requirements.
void addValues(double a, double b);
void subtractValues(double a, double b);
void multiplyValues(double a, double b);
void divideValues(double a, double b);

int main(void)
{
    // Variable Declarations
    char userAction;
    int calcIndex = -1;
    double operand1 = 0.0;
    double operand2 = 0.0;

    // Array of 4 function pointers mapping directly to our calculation modules.
    void (*executeMath[4])(double, double) = { addValues, subtractValues, multiplyValues, divideValues };

    // Prime the loop: step-by-step console prompt.
    printf("Enter A to add, S to subtract, M to multiply, D to divide, and E to end: ");
    // Space preceding %c clears out trailing newlines (\n) from standard input.
    scanf(" %c", &userAction);

    //Sentinel controlled loop evaluating uppercase normalized user choice.
    while (toupper((unsigned char)userAction) != 'E')
    {
        char upperChoice = toupper((unsigned char)userAction);

        // Input validation and explicit indexing logic.
        if (upperChoice == 'A' || upperChoice == 'S' || upperChoice == 'M' || upperChoice == 'D')
        {
            // Map character selections to explicit numeric array offsets.
            if (upperChoice == 'A')
            {
                calcIndex = 0;
                printf("Enter the first number to add: ");
                scanf("%lf", &operand1);
                printf("Enter the second number to add: ");
                scanf("%lf", &operand2);
            }
            else if (upperChoice == 'S')
            {
                calcIndex = 1;
                printf("Enter the first number for subtraction: ");
                scanf("%lf", &operand1);
                printf("Enter the second number for subtraction: ");
                scanf("%lf", &operand2);
            }
            else if (upperChoice == 'M')
            {
                calcIndex = 2;
                printf("Enter the first number for multiplication: ");
                scanf("%lf", &operand1);
                printf("Enter the second number for multiplication: ");
                scanf("%lf", &operand2);
            }
            else if (upperChoice == 'D')
            {
                calcIndex = 3;
                printf("Enter the first number for division: ");
                scanf("%lf", &operand1);
                printf("Enter the second number for division: ");
                scanf("%lf", &operand2);
            }

            // Execute the polymorphic calculator module via the function pointer array.
            (*executeMath[calcIndex])(operand1, operand2);
        }
        else
        {
            // Handles unexpected input actions.
            printf("Value not valid. Please re-enter a choice.\n");
        }
    
    // Prompts the user for subsequent worker parameters to continue or to exit loop.
        printf("Enter A to add, S to subtract, M to multiply, D to divide, or E to end: ");
        scanf(" %c", &userAction);
    }
    
    printf("Program ended.\n");
    return 0;
}

// Core Calculation Modules (Function definitions)

void addValues(double a, double b)
{
    printf("%.2f + %.2f is %.2f\n", a, b, a + b);
}

void subtractValues(double a, double b)
{
    printf("%.2f - %.2f is %.2f\n", a, b, a - b);
}

void multiplyValues(double a, double b)
{
    printf("%.2f * %.2f is %.2f\n", a, b, a * b);
}
 
void divideValues(double a, double b)
{
    // Explicit runtime safety constraints to trap division-by-zero crashes.
    if (b == 0.0)
    {
        printf("Error: Division by zero is undefined.\n");
    }
    else
    {
        printf("%.2f / %.2f is %.2f\n", a, b, a / b);
    }
}
