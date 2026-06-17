/*
Program Name: COSC4120 Lab05: Parking Fee ledger Calculator
Program Description: This program tracks daily stays and calculates precise 
parking metrics for four seperate clients using a custom function.
Programmer: Rafael Hernandez
Date: 6/17/2026

Pseudocode:
 - Establish a custon function prototype for calculations.
 - Display an interface title for parking reciept.
 - Declare the needed variables.
 - Initialize an iterative loop configuration to run exactly four times.
    - Request and read the amount of time parked from the keyboard.
    - Accept the input from the user for the hours entered.
    - Prints the table column headers (Unit, Hours, and Csot)
    - Calculate the current car's charge and update the total.
    - Add the current charge to the total charge accumulator variable.
    - Display the data for the current car.
 - End for loop
 - Display row data for totals
 - Show the final costs of bill.
 */

#include <stdio.h>
#include <math.h>

// Custom Function Prototype
double determineParkingFee(double parkedTime);

int main(void)
{
    // Local variable declarations with updated names.
    double grandTotalHours = 0.0;
    double grandTotalFees = 0.0;
    double vehicleHours;
    double vehicleFee;

    // Displays table column headers before processing data.
    printf("======================================\n");
    printf("          Parking Fee Receipt         \n");
    printf("======================================\n\n");

    // Loop structure designed to cycle exactly 4 times.
    for (int vehicleId = 1; vehicleId <= 4; vehicleId++)
    {
        // Prompts user and accept input for the hours entered.
        printf("Enter the hours parked for vehicle #%d: ", vehicleId);
        scanf("%lf", &vehicleHours);

        // Adds hours entered to the total hours accumulator variable.
        grandTotalHours += vehicleHours;

        printf("\n%-10s %10s %10s\n", "Unit", "Hours", "Cost");
        printf("--------------------------------------\n");

        // Calculates the current car's charge by calling the custom function.
        vehicleFee = determineParkingFee(vehicleHours);
        
        // Adds the current charge to the total charge accumulator variable.
        grandTotalFees += vehicleFee;

        // Displays the data for the current car (car number, current hours, current charges).
        printf("Car %-6d %10.1f %10.2f\n\n", vehicleId, vehicleHours, vehicleFee);
    } // End of loop.

    // Displays the row data for totals.
    printf("======================================\n");
    printf("%-10s %10s %10s\n", "", "Hours", "Cost");
    printf("%-10s %10.1f %10.2f\n", "TOTALS", grandTotalHours, grandTotalFees);
    printf("======================================\n");

    return 0;
} // End of main

/// @brief Assesses financial tiers based on total time parameters provided.
/// @param parkedTime User inputs the duration units
/// @return Returns the dollar balance.
double determineParkingFee(double parkedTime)
{
    double finalBill = 0.0;

    // Checks if the hours parked are less than or equal to 2 hours ($5.00 flat fee).
    if (parkedTime <= 2.0)
    {
        finalBill = 5.00;
    }
    // Checks if the hours parked is less than 48 hours.
    else if (parkedTime < 48.0)
    {
        // Base cost + incremental fees calculated from ceiling values.
        finalBill = 5.00 + (ceil(parkedTime - 2.0) * 1.50);
    }
    // Checks if the hours parked is over 48 hours or over. (Maximum cap restriction)
    else
    {
        finalBill = 75.00;
    }
    return finalBill;
}