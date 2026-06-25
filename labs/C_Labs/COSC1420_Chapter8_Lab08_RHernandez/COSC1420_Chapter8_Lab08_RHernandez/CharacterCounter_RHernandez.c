/*

Course Name: Summer of 2026, COSC 1420, Chapter 8, Lab 8
Program Name: Character Counter Code
Program Description: This code is a string-manipulation type code that is capable to enable us to count
the number of characters (both letters and numbers) in strings of data.
This program will read the written text and prints a table indicating the number of occurrences of numbers (0-9)
in the text. This code will count both lower and uppercase letters entered. Example: Apple.

Programmer: Rafael Hernandez
Date: 6 / 24 / 2026

Pseudocode:
Input:
    1. Define a 2D array 'lineNumber' that is initialized with {"first", "second", "third"}.
    2. Define a 2D char array 'text' with dimensions [3][80] to hold the text lines.
    3. Loop 3 times (from 0 to 2) using size_t i;
        - Print the prompt using lineNumber[i].
        - Read the string input using fgets and store it in texts[i].

Process:
    1. Initialize a 1D int array called 'letterCounts' of size 26 to 0.
    2. Initialize a 1D int array called 'digitCounts' of size 10 to 0.
    3. Initialize total counters called 'upperCount' and 'lowerCount' to zero.
    4. Loop through each row of 'text' (0 to 2):
        - Loop through each character of the current row until reaching the null terminator '\0':
            - If character is alphabetic (isalpha):
                - If character is uppercase (isupper):
                    - Increment 'upperCount'.
                - If character is lowercase (islower):
                    - Increment 'lowerCount'.
                - Convert character to lowercase using tolower.
                - Subtract ASCII 'a' from the character to get the index (0-25).
                - Increment 'letterCounts' at that index.
            - Else if character is a digit (isdigit):
                - Subtract ASCII '0' from the character to get the index (0-9).
                - Increment 'digitCounts' at that index.

Output:
    1. Display the introductory/explanatory text header matching sample output.
    2. Print "Total letter counts:" header.
    3. Loop from 0 to 25:
        - Print the matching character ('a' + index) and its count from 'letterCounts'.
    4. Print the 'upperCount' total.
    5. Print the 'lowerCount' total.
    6. Print the 'Total number count:" header.
    7. Loop from 0 to 9:
        - Print the matching digit character and its count from 'digitCounts'.

 */


#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Array Declarations and Initializations

    // 2D Array to store the string labels for prompting the user.
    char lineNumber[3][8] = { "first", "second", "third" };
    // 2D Array to store 3 lines of user text, max 80 characters each.
    char text[3][80];
    // 1D Array tracking the lowercase/combined letter frequencies (a-z).
    int letterCounts[26] = { 0 };
    // 1D Array tracking the numeric digit frequencies (0-9).
    int digitCounts[10] = { 0 };
    // Interger counters for uppercase and lowercase character analytics.
    int upperCount = 0;
    int lowerCount = 0;

    // Program introduction text matching the data run.
    printf("For this progream, please enter three lines of characters and a number.\n");
    printf("The program will count the number of each letter in the alphabet and the count of each number from 0 to 9: \n\n");

    // Loops exactly 3 times using size_t to read and store text blocks safely.
    for (size_t i = 0; i <= 2; ++i)
    {
        printf("%s%s%s", "Enter ", lineNumber[i], " line of text: ");
        fgets(&text[i][0], 80, stdin);
    }

    // Data Processing Loop.

    // Outer loop parses through each of the 3 captured lines.
    for (size_t i = 0; i <= 2; ++i)
    {
        // Inner loop reads every individual element until the end of string token.
        for (size_t j = 0; text[i][j] != '\0'; ++j)
        {
            char current = text[i][j];
            // Evaluates if the character is part of the alphabet.
            if (isalpha((unsigned char)current))
            {
                if (isupper((unsigned char)current))
                {

                    upperCount++;
                }
                else if (islower((unsigned char)current))
                {
                    lowerCount++;
                }
                // Standardize case to lowercase for the 0-25 offset mapping.
                char lowerChar = tolower((unsigned char)current);
                int letterIndex = lowerChar - 'a';
                letterCounts[letterIndex]++;
            }

            // Evaluates if the character is a numeric digit.
            else if (isdigit((unsigned char)current))
            {
                int digitIndex = current - '0';
                digitCounts[digitIndex]++;
            }
            
        }
    }

    // Output Results Generation.

    // Output table detailing the continuous frequency distribution of letters (a-z).
    printf("\nTotal letter counts:\n");
    for (int i = 0; i < 26; ++i)
    {
        printf(" % c: % d\n", 'a' + i, letterCounts[i]);
    }

    // Outputs total structural metrics of cases.
    printf("\nTotal uppercase letters count: %d\n", upperCount);
    printf("\nTotal lowercase letters count: %d\n", lowerCount);

    // Outputs the table detailing of the continuous frequency distribution.
    printf("\nTotal number count:\n");
    for (int i = 0; i < 10; ++i)
    {
        printf("%d: %d\n", i, digitCounts[i]);
    }
    return 0;
}