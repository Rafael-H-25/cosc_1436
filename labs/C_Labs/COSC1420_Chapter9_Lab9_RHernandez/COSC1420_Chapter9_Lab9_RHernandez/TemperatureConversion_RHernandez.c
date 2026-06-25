/*

Course Name: Summer of 2026, COSC 1420, Chapter 9, Lab 9
Program Name: Temperature Conversion
Program Description: This program works on converting temperature values between three scales: Celsius, Fahrenheit, and Kelvin.
    This program reads user selections for source and target scales, applies the correct algebraic floating-point formulas, handles console input
    buffers safely, and formats output values to exactly two decimal places.

Programmer: Rafael Hernandez
Date: 6 / 25 / 2026

Formulas Used:
    Celsius to Kelvin: K = C + 273.15
    Kelvin to Celcius: C = K - 273.15
    Fahrenheit to Celsius: C = (F - 32) * (5.0 / 9.0)
    Celsius to Fahrenheit: F = (C * (9.0 / 5.0)) + 32
    Fahrenheit to Kelvin: K = (F - 32) * (5.0 / 9.0) + 273.15
    Kelvin to Fahrenheit: F = (K - 273.15) * (9.0 / 5.0) + 32

Pseudocode:

Input:
    1. Displays the main menu detailing C, F, K, or E (Exit).
    2. Reads a character from standard input into 'fromScale'.
    3. If 'fromScale' is equal to 'E', it terminates the loop execution sequence.
    4. Prompts and reads a double precision value into 'inputTemp'.
    5. Prompts and reads a character mapping target scale into 'toScale'.

Process:
    1. Clears the standard input buffer trailing newlines using a buffer variable.
    2. Normalize all scale choice input characters to uppercase using 'touppper()'.
    3. Passes 'fromScale' into a primary switch-case conditional construct.
    4. Case 'C' (Celsius):
        - If 'toScale' is 'F', calculate: inputTemp * (9.0 / 5.0) + 32.0
        - If 'toScale' is 'K', calculate: inputTemp + 273.15
        - Default: Displays the conversion configuration error notification.
    5. Case 'F' (Fahrenheit):
        - If 'toScale' is 'C', calculate: (inputTemp - 32.0) * (5.0 / 9.0)
        - If 'toScale' is 'K', calculate: (inputTemp - 32.0) * (5.0 / 9.0) + 273.15
        - Default: Displays the conversion configuration error notification.
    6. Case 'K' (Kelvin):
        - If 'toScale' is 'K', calculate: (inputTemp - 273.15) * (9.0 / 5.0) + 32.0
        - If 'toScale' is 'C', calculate: inputTemp - 273.15
        - Default: Displays the conversion configuration error notification.
    7. Default: Handles the unrecognizable primary options cleanly.

Output:
    1. Prints the formatted notification string matching sample verification records.
    2. Displays the original and target values ultilizing a fixed "%.2f" precision width.

*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
// Variable Declarations
    // Source scale tracking selection (and loop sentinel).
    char fromScale = ' ';   
    // Target destination conversion scale tracker.
    char toScale = ' ';
    // Processing the character to clean trailing return keys.
    char bufferFlush = ' ';

    // Tracks the user specified initial temperature value.
    double inputTemp = 0.0;
    // Stores the evaluated calculation metric output.
    double resultTemp = 0.0;

 // Control loop & Menu execution
    while (1)
    {
        // Displays the Main Interface text.
        printf("Temperature Conversion Program\n\n");
        printf("Enter C to convert from Celsius.\n");
        printf("Enter F to convert from Fahrenheit.\n");
        printf("Enter K to convert from Kelvin.\n");
        printf("Enter E to end the program.\n");

        // Captures the initial option selection.
        scanf(" %c", &fromScale);
        fromScale = (char)toupper((unsigned char)fromScale);
        // Sentinel condition: Cleanly break away when 'E' is entered.
        if (fromScale == 'E')
        {
            break;
        }
        
        // Prompt user for baseline tracking data value.
        printf("\nPlease enter the temperature to convert:\n");
        scanf("%lf", &inputTemp);
        // Cleans out newline artifacts remaining in input buffer streams.
        scanf("%c", &bufferFlush);

        // Prompts user to choose target scale depending on their initial configuration.
        if (fromScale == 'C')
        {
            printf("Enter F to convert Celsius to Fahrenheit or enter K to convert to Kelvin:\n");
        }
        else if (fromScale == 'F')
        {
            printf("Enter C to convert Fahrenheit to Celsius or enter K to convert Fahrenheit to Kelvin:\n");
        }
        else if (fromScale == 'K')
        {
            printf("Enter C to convert Kelvin to Fahrenheit or enter F to convert to Kelvin to Fahrenheit:\n");
        }

        // Captures the target selection path.
        scanf(" %c", &toScale);
        toScale = (char)toupper((unsigned char)toScale);
        printf("\n");

        // Switch Processing Core
        switch (fromScale)
        {
            // Source Scale is Celsius
            case 'C':
                if (toScale == 'F')
                {
                    resultTemp = (inputTemp * (9.0 / 5.0)) + 32.0;
                    printf("Converted %.2f degrees Celsius to %.2f degrees Fahrenheit.\n\n", inputTemp, resultTemp);
                }
                else if (toScale == 'K')
                {
                    resultTemp = inputTemp + 273.15;
                    printf("Converted %.2f degrees Celsius to %.2f degrees Kelvin.\n\n", inputTemp, resultTemp);
                }
                else
                {
                    printf("Invalid destination scale fallback configuration targeted.\n\n");
                }
                break;

            // Source Scale is Fahrenheit
            case 'F':
                if (toScale == 'C')
                {
                    resultTemp = (inputTemp - 32.0) * (5.0 / 9.0);
                    printf("Converted %.2f degrees Fahrenheit to %.2f degrees Celsius.\n\n", inputTemp, resultTemp);
                }
                else if (toScale == 'K')
                {
                    resultTemp = ((inputTemp - 32.0) * (5.0 / 9.0)) + 273.15;
                    printf("Converted %.2f degrees Fahrenheit to %.2f degrees Kelvin.\n\n", inputTemp, resultTemp);
                }
                else
                {
                    printf("Invalid destination scale fallback configuration targeted.\n\n");
                }
                break;
        
            // Source Scale is Kelvin
            case 'K':
                if (toScale == 'C')
                {
                    resultTemp = inputTemp - 273.15;
                    printf("Converted %.2f degrees Kelvin to %.2f degrees Celsius.\n\n", inputTemp, resultTemp);
                }
                else if (toScale == 'F')
                {
                    resultTemp = ((inputTemp - 273.15) * (9.0 / 5.0)) + 32.0;
                    printf("Converted %.2f degrees Kelvin to %.2f degrees Fahrenheit.\n\n", inputTemp, resultTemp);
                }
                else
                {
                    printf("Invalid destination scale fallback configuration targeted.\n\n");
                }
                break;

            // Default fallback catch configuration handler.
            default:
                printf("Invalid configuration parameters specified inside source selector fields.\n\n");
                break;
        }

        // Completes the flush pass on dangling residual user keystroke buffers.
        scanf("%c", &bufferFlush);
    }
    return 0;
}