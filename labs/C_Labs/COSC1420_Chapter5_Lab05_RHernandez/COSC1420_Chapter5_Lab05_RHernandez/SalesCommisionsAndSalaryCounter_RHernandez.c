/*

Course Name: Summer of 2026, COSC 1420, Chapter 6, Lab6
Program Name: Sales Con=mimissions & Salary Counter
Program Description: This code calculates the weekly earnings for salesmen using specific base
salary styles and a 10% commisions. This code tracks the salary ranges using a one-dimensinal array of counters.

Programmer: Rafael Hernandez
Date: 6/19/2026

Pseudocode:
1. Initialize constants
2. Declare a 1D integer array of size 11 and zero-initialize it.
3. Declare double variables for 'grossSales', 'weeklySalary', and 'commission'.
4. Prompt the user to enter a gross sales value for an employee (-1 to terminate).
5. Read the gross sales from the keyboard.
6. Enter in a loop that runs while gross sales doesn't equal to -1.0:
    a: Compute commission = gross sales * COMMISSION _RATE.
    b:  If gross sales < 100.00,
            weeklySalary = INTERN_SALARY + commission.
        Else:
            weeklySalary = BASE_SALARY + commision.
    c: Print out the calculated weekly salary formatted to two decimal places.
    d: Cast the weeklySalary to an integer to truncate it.
    e: Compute array index = truncatedSalary / 100.
    f: If array is greather than or equal to 10:
        Cap index at 10 (representing the salaries >= 100)
    g: Increment the counter at salaryBuckets[index] by 1.
    h: Prompt user for next salesperson's gross sales.
    i: Read the next gross sales value.
7. After the loop exits, print out the formatted distribution table showing 
the counts for each pf the 11 salary catagories matching the requested layout.

*/

#include <stdio.h> 

int main(void)
{
    // Constant indentifiers for business rules and array constraints.
    const double BASE_PAY = 100.00;
    const double INTERN_PAY = 50.00;
    const double COMMISSION_PCT = 0.10;
    const double SENTINEL = -1.0;

    // One-dimensional array to track counts for 11 distinct salary ranges (0 to 10).
    int distribution[11] = { 0 };

    // Variables for input processing and calculations.
    double salesInput = 0.0;
    double currentSalary = 0.0;
    double calculatedComm = 0.0;
    int indexTracker = 0;

    // 3 - Step Input Process : 1. Prompt       2. Variable         3. Scanf
    printf("Enter employee gross sales (-1 to end): ");
    scanf("%lf", &salesInput);

    // Loop executing until sentinel termination value (-1) is encountered.
    while (salesInput != SENTINEL)
    {
        // 1. Calculates the 10% gross sales commission.
        calculatedComm = salesInput * COMMISSION_PCT;

        // 2. Determines the appropriate starting base pay depending on intern status.
        if (salesInput < 100.00)
        {
            currentSalary = INTERN_PAY + calculatedComm;
        }
        else
        {
            currentSalary = BASE_PAY + calculatedComm;
        }

        // Prints the calculated individual performance metrics.
        printf("Employee Salary is %.2f\n", currentSalary);

        // 3. Determines the array index by truncating and dividing by 100.
        indexTracker = (int)currentSalary / 100;

        // 4. Constrain index to bucket 10 for salaries >= $1,000.
        if (indexTracker >= 10)
        {
            indexTracker = 10;
        }

        // 5. Safety increment specific tracked group counter.
        distribution[indexTracker]++;

        // Fetches the next worker's data point.
        printf("Enter employee gross sales (-1 to end): ");
        scanf("%lf", &salesInput);
    }
    
    // Displays the output breakdown table that represents the population metrics.
    printf("\nEmployees in the range:\n");
    printf("$000-$99: %d\n", distribution[0]);
    printf("$100-$199: %d\n", distribution[1]);
    printf("$200-$299: %d\n", distribution[2]);
    printf("$300-$399: %d\n", distribution[3]);
    printf("$400-$499: %d\n", distribution[4]);
    printf("$500-$599: %d\n", distribution[5]);
    printf("$600-$699: %d\n", distribution[6]);
    printf("$700-$799: %d\n", distribution[7]);
    printf("$800-$899: %d\n", distribution[8]);
    printf("$900-$999: %d\n", distribution[9]);
    printf("Over $1,000: %d\n", distribution[10]);

    return 0;

}