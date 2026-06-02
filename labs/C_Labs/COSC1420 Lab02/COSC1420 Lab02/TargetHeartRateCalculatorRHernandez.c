/*
  Summer of 2026
  Program Name: COSC1420 Lab02 - Target Heart-Rate Calculator
  Program Description: Calculates the maximum and the target heart rate range using user age.
  Programmer: Rafael Hernandez
  Date: 6/2/2026
 Pseudocode: 
    1. Declare and initialize an integer to hold age
    2. Ask user to enter age.
    3. Accept input for users age.
    4. Declare an integer for max heart rate and initialize.
    5. Output to screen users Maximum heart rate.
    6. Output users target heart rate and range of the users target heart rate.
    7. End program
  */

#include <stdio.h>

int main()
{
    // Declares and initialize an integer to hold age. 
    int userAge = 0;
    int maxHeartRate = 0;
    int minTargetRate = 0;
    int maxTargetRate = 0;

    // Asks user to enter their age.
    printf("Please enter your age in years: ");

    // Checks if user inputed a integer.
    if (scanf("%d", &userAge) != 1 || userAge <= 0)
    {
        printf("Error: Invalid age entered. Please enter a numberical value.\n");
        return 1;
    }

    // Declares an integer for max heart rate and initializes it. (220 minus users age)
    maxHeartRate = 220 - userAge;
    minTargetRate = maxHeartRate * 0.50;    // Calculates the heart rate range. (50% to 85% of max heart rate)
    maxTargetRate = maxHeartRate * 0.85;

    // Shows your maximum heart rate on screen.
    printf("\nYour maximum heart rate is: %d bpm\n", maxHeartRate);

    // Outputs the user's terget heart rate and range of the users target heart rate.
    printf("Your Target Heart-Rate range (50%% - 85%%) is: %d bpm to %d bpm\n", minTargetRate, maxTargetRate);

    return 0;
}