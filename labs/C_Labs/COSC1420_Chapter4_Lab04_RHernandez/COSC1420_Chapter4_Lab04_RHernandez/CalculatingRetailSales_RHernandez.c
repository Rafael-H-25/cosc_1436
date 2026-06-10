/*
Program Name: Retail Sales Calculator
Program Description: This code calculates the total retail value of a series of porducts sold.
The program loops to accept product numbers and quantities, evaluates retail pricings using a 
switch selection structure, and to track a runnning total until a sentinel value (-1) is read.

Programmer: Rafael Hernandez
Date: 6/10/2026

Pseudocode:
* START
* INITIALIZE the integer variables for the product number and quatity sold.
* INITIALIZE the double variable for total retail value to 0.0.
* PROMPT the user for initial product number using puts.
* READ the product number.
* WHILE the product number is not equal to -1:
    * PROMPT the user to enter quantity of products using puts.
    * READ the quantity sold.
    * SWITCH based on the product number:
        * CASE 1: Add (quantity * 2.98) to total retial value using +=.
        * CASE 2: Add (quantity * 4.50) to total retial value using +=.
        * CASE 3: Add (quantity * 9.98) to total retial value using +=.
        * CASE 4: Add (quantity * 4.49) to total retial value using +=.
        * CASE 5: Add (quantity * 6.87) to total retial value using +=.
        * DEFAULT: Display an invalid product number warning message.
    * END SWITCH
    * PROMPT the user for next product number or -1 to end using puts.
    * READ the product number.
* END WHILE 
* DISPLAY the total retail value formatted to 2 decimal places.
* END
*/

#include <stdio.h>

int main(void)
{
    int productNumber = 0;
    int quantitySold = 0;
    double totalRetailValue = 0.0;

    /* ----- Priming the Loop ----- */
    puts("Enter Product Number:");  // Prints the initial prompt for the product number to the console screen.
    puts("Enter -1 for the product number to end input:");  // Prints the instructions for terminating the data entry.
    scanf_s("%d", &productNumber);      // Reads the initial product integer input from the user's keyboard.

    while (productNumber != -1)     // Executes the pretest loop continuosly until the user sets product code to -1.
    {
        puts("Enter the quantity of product:");     // Prints the prompt by asking the user to provide total item counts.
        scanf_s("%d", &quantitySold); // Captures the product quantity amount from keyboard input.
    
        switch (productNumber)      // The selection structure to process pricing behavior based on product code.
        {
        case 1: totalRetailValue += quantitySold * 2.98;    // Check if user selected item ID 1.
            break; 
        case 2: totalRetailValue += quantitySold * 4.50;    // Check if user selected item ID 2.
            break;
        case 3: totalRetailValue += quantitySold * 9.98;    // Check if user selected item ID 3.
            break;
        case 4: totalRetailValue += quantitySold * 4.49;    // Check if user selected item ID 4.
            break;
        case 5: totalRetailValue += quantitySold * 6.87;    // Check if user selected item ID 5.
            break;
        default:    // Catch-all safety measure block to execute if input falls outside range of 1-5 or -1.
            printf("Invalid product code: %d\n", productNumber);    // Prints exact code that caused fault.
            printf("Invalid quantity: %d\n", quantitySold);     // Prints the accompanying error quality.
            break;
        } // End of switch multi-selection block.

        /* ----- Update Step ----- */
        puts("\nEnter another product number or -1 to end input:");
        scanf_s("%d", &productNumber);
    } // End of while loop.

    /* ----- Terminate Phase ----- */
    printf("The total retail value was: $%.2f\n", totalRetailValue);

    return 0;
}