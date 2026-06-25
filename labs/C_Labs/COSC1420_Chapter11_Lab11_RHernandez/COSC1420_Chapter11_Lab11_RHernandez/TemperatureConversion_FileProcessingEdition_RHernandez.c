/*

Course Name: Summer of 2026, COSC 1420, Chapter 11, Lab 11
Program Name: Temperature Conversion (File Processing Edition)
Program Description: This program project updates the Chapter 9 Lab 9 code of temperature conversion application to utilize
sequential-access text-file storage. The user inputs are evaluated via a while-sentinel loop and nested switch statements. The
valid logs are instantly routed into an external data file using the 'WriteToFile' system wrapper. When upon entering the 
terminalsentinel 'E', the file is closed, re-opened in read-mode, and its complete records are structurally formatted and streamed
back onto the terminal interface.

Programmer: Rafael Hernandez
Date: 6 / 25 / 2026

Pseudocode:

Input:
    1. Initializes the file pointer mapping to "Temperature_Conversion.dat" in write ("w") mode.
    2. Checks if the pointer resolves to NULL; if so, terminate with an operational error.
    3. Enters a loop: displays the interactive menu mapping C, F, K, or E (Exit).
    4. Fetches character selection tracking 'fromScale'. If 'E', termintates the loop execution.
    5. Prompts and intercepts double precision numeric values into 'inputTemp'.
    6. Requests target tracking destination scale character choice into 'toScale'.

Process:
    1. Clears trailing line breaks from standard input via buffer flush scans.
    2. Pass uppercase normalized 'fromScale' into a multi-branch switch statement.
    3. Evaluates the mathematical conversion routines across target scales:
        - C to F: (inputTemp * 1.8) + 32.0  | C to K: inputTemp + 273.15
        - F to C: (inputTemp - 32.0) / 1.8  | F to K: ((inputTemp - 32.0) / 1.8) + 273.15
        - K to C: inputTemp - 273.15        | K to F: ((inputTemp - 273.15) * 1.8) + 32.0
    4. Prints the matching conversation log string to the console display.
    5. Invokes the 'WriteToFile' function to print line records into the text file pointer.

Output:
    1. Closes the active file writing channel pointer cleanly.
    2. Re-opens the "Temperature_Conversion.dat" utilizing the read ("r") file access modifier.
    3. Outpouts the tabular column headers matching the sample data specifications.
    4. Reads the file text records line-by-line within a structured loop until EOF is encountered.
    5. Prints file contentss precisely onto the console screen layout.
    6. Close reading streams cleanly before returing zero.

*/

#include <stdio.h>
#include <ctype.h>

// The function prototype declaration.
void WriteToFile(FILE* filePtr, double originalVal, char originalUnit, double convertedVal, char convertedUnit);

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

    // Master file handling stream reference pointer.
    FILE* ofPtr = NULL;

    // Initialize File Stream
    if ((ofPtr = fopen("Temperature_Conversion.dat", "w")) == NULL)
    {
        puts("Unable to open one of the files.");
        return 1; // Terminate with error code if file block fails.
    }

    // Control loop & Data capture
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

        // Conversion Processing & Writing
        int validConversion = 0; // Flag to guarantee we only log valid operational paths.

        // Switch Processing Core
        switch (fromScale)
        {
            // Source Scale is Celsius
        case 'C':
            if (toScale == 'F')
            {
                resultTemp = (inputTemp * (9.0 / 5.0)) + 32.0;
                printf("Converted %.2f degrees Celsius to %.2f degrees Fahrenheit.\n\n", inputTemp, resultTemp);
                validConversion = 1;
            }
            else if (toScale == 'K')
            {
                resultTemp = inputTemp + 273.15;
                printf("Converted %.2f degrees Celsius to %.2f degrees Kelvin.\n\n", inputTemp, resultTemp);
                validConversion = 1;
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
                validConversion = 1;
            }
            else if (toScale == 'K')
            {
                resultTemp = ((inputTemp - 32.0) * (5.0 / 9.0)) + 273.15;
                printf("Converted %.2f degrees Fahrenheit to %.2f degrees Kelvin.\n\n", inputTemp, resultTemp);
                validConversion = 1;
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
                validConversion = 1;
            }
            else if (toScale == 'F')
            {
                resultTemp = ((inputTemp - 273.15) * (9.0 / 5.0)) + 32.0;
                printf("Converted %.2f degrees Kelvin to %.2f degrees Fahrenheit.\n\n", inputTemp, resultTemp);
                validConversion = 1;
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

        // Write directly to file system if formula successfully evaluated.
        if (validConversion)
        {
            printf("Writing Data to File. \n\n");
            WriteToFile(ofPtr, inputTemp, fromScale, resultTemp, toScale);
        }
        else
        {
            printf("\n");
        }

        // Completes the flush pass on dangling residual user keystroke buffers.
        scanf("%c", &bufferFlush);
    }

    // Close output stream writing sequence.
    fclose(ofPtr);

    // Re-open File & Stream Display

    printf("\Displaying Contents of File:\n\n");
    printf("%-19s%-24s\n\n", "From Temperature", "Converted Temperature");

    // Opens file pointer targeting read mode.
    if ((ofPtr = fopen("Temperature_Conversion.dat", "r")) == NULL)
    {
        puts("Unable to open the file for read verification operations.");
        return 1;
    }

    // Temporary string layout vector tracking buffered document streaming blocks.
    char fileLineBuffer[120];

    // Reads lines sequentially untilencountering the end of file bounds.
    while (fgets(fileLineBuffer, sizeof(fileLineBuffer), ofPtr) != NULL)
    {
        printf("%s", fileLineBuffer);
    }
    
    // Final clean termination closeout call.
    fclose(ofPtr);

    return 0;
}

// Mandatory Technology Function (the WriteToFile)
void WriteToFile(FILE* filePtr, double originalVal, char originalUnit, double convertedVal, char convertedUnit)
{
    // Protects file operations from executing if the stream address is invalid.
    if (filePtr == NULL)
    {
        return;
    }

    // Format matches required file tracking data specs: "10.00C            =           50.00F".
    // Pads the spacings symmetrically utilizing specific positional print widths.
    fprintf(filePtr, "      %6.2f%c             =               %6.2f%c\n\n", originalVal, originalUnit, convertedVal, convertedUnit);
} 