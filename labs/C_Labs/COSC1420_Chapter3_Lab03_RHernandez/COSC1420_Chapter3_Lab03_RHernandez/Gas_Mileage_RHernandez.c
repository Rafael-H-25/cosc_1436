/*
Program Name: Gas Mileage and Fuel Efficiency Calculator

Program Description: Program tracks the fuel usage and miles driven across multiple automobile tanksfuls.
This code calculates the individual miles-per-gallon, or short for MPG, for each tankful and computes the overall combined aveage.

Programer: Rafael Hernandez
Date: 6/10/2026

Pseudocode:
    * START code
    * INITIALIZE float variables for the current/total miles and the current/total gallons.
    * PRINT prompt to enter the gallons used for the first tank to prime the loop.
    * READ the current gallons used.
    * WHILE the current gallons used is not equal to -1.0:
        * ADD the current gallons used to the total gallons. 
        * PRINT prompt to enter the miles driven.
        * READ the current miles driven.
        * ADD the current miles driven to total miles.
        * CALCULATE current tank miles per gallon.
        * PRINT the current tank miles per gallon.
        * PRINT the prompt to the enter gallons used for the next tank.
        * READ the current gallons used.
    * ENDWHILE
    * IF the total gallons used is greather than 0.0, 
        THEN: 
        * CALCULATE the overall average miles per gallon.
        * PRINT the overall average miles per gallons.
    * ENDIF 
    * END
*/

#include <stdio.h>

int main(void)
{
    // Initialize the float variables to number 0.0 to prevent garbage memory data.
    float currentMilesDriven = 0.0f;
    float currentGallonsUsed = 0.0f;
    float totalMilesDriven = 0.0f;
    float totalGallonsUsed = 0.0f;

    /* ----- Priming The Loop ----- */
    // Get the initial gallons value before checking the 'while' condition.
    printf("%s", "Enter the gallons used (-1 to end): ");
    scanf_s("%f", &currentGallonsUsed);

    // Loop continues running until the user enters the sentinel value (-1.0).
    while (currentGallonsUsed != -1.0f)
    {
        // Accumulate the current gallons into the running total.
        totalGallonsUsed = totalGallonsUsed + currentGallonsUsed;

        // Prompt user and accept the input for miles driven.
        printf("%s", "Enter the miles driven: ");
        scanf_s("%f", &currentMilesDriven);

        // Accumulate the current miles into the running total.
        totalMilesDriven = totalMilesDriven + currentMilesDriven;

        // Calculate the fuel economy for the individual tank.
        float currentTankMpg = currentMilesDriven / currentGallonsUsed;
        
        // Using the %.2f forces the output to show exactly 2 decimal places.
        printf("The miles/gallons for this tank was %.2f miles per gallon.\n\n", currentTankMpg);

        printf("%s", "Enter the gallons used (-1 to end): ");
        scanf_s("%f", &currentGallonsUsed);

    } // End of while loop.
    
        /* ----- The Update Step ----- */
        // Checking if any data was processed to prevent a division-by-zero math crash.
        if (totalGallonsUsed > 0.0f)
        {
            float overallAverageMpg = totalMilesDriven / totalGallonsUsed;
            printf("\nThe overall average miles/gallon was %.2f miles per gallon.\n", overallAverageMpg);
        }

    return 0;

}
