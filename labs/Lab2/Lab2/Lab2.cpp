/*
*   Lab 2
*   Rafael Hernandez
*   COSC 1436
*   Spring 2026
*/

#include <iostream>
#include <string>
#include <iomanip>

struct Loan
{
    std::string loan;

    int initialAmount = 0; 
    float interestRate = 0; 
    int monthNumber = 0;
};

/// @brief  Displays a horizontal line.
/// @param width Width of a line
void DisplayLine(int width)
{
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
}

/// @brief  Clears the input buffer of extra characters and sentences
void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT32_MAX, '\n');
};

void main()
{
    int tableWidth = 70;
    double monthlyPayment;
    Loan loan;
    do
    {   // Prompts the user for a numerical loan number
        std::cout << "Enter a loan amount (No commas): ";
        std::cin >> loan.initialAmount;

        if (loan.initialAmount < 1 || loan.initialAmount > 1000)
        {
            std::cout << "Issue: The nitial loan amount must a numerical value from 1 to 1000 range." << std::endl;
            ClearInputBuffer();
        }

    } while (loan.initialAmount < 1 || loan.initialAmount > 1000);
    
    do
    {   // Prompts the user for a numerical interest number.
        std::cout << "Enter your interest rate (no commas or %): ";
        std::cin >> loan.interestRate;

        if (loan.interestRate < 1.0 || loan.interestRate > 100.0)
        {
            std::cout << "Issue: The Interest rate amount must be a numerical value from 1 to 100 range." << std::endl;
            ClearInputBuffer();
        }

    } while (loan.interestRate < 1.0 || loan.interestRate > 100);

    do
    {   // Prompts the user for a numerical number for payment.
        std::cout << "Enter how much you want to pay each month (no commas): ";
        if (!(std::cin >> monthlyPayment) || monthlyPayment < 0 || monthlyPayment > loan.initialAmount)
        {
            std::cout << "Issue: Payment value must be a numerical value that's higher than 0 but lower than the loan amount." << std::endl;
            ClearInputBuffer();
        }
        else
        {
            break;
        }
    } while (true);

    std::cout << std::left << std::setw(10) << "Month"
        << std::setw(15) << "Balance"
        << std::setw(15) << "Payment"
        << std::setw(15) << "Interest"
        << std::setw(15) << "New Balance" << std::endl;
    DisplayLine(tableWidth);
    std::cout << std::fixed << std::setprecision(2);

    double totalPayments = 0;
    double totalInterest = 0;
    double currentBalance = loan.initialAmount;
    double monthRate = (loan.interestRate / 100.0);

    for (int month = 1; month <= 12; month++)
    {
        double paymentMade = 0;
        double monthInterest = 0;
        // Provides the logic for every month after the 1st month.
        if (month > 1)
        {
            // Prohibits payment exceeding remaining balance.
            if (monthlyPayment > currentBalance)
            {
                paymentMade = currentBalance;
            }
            else
            {
                paymentMade = monthlyPayment;
            }
            // Removes amount from balance after payment before interest.
            currentBalance -= paymentMade;
            // No interest added if there's no balance.
            if (currentBalance > 0)
            {
                monthInterest = currentBalance * monthRate;
            }
        }
        // Adds all payments and interests amounts
        totalPayments += paymentMade;
        totalInterest += monthInterest;
        double newLoanBalance = currentBalance + monthInterest;

        std::cout << std::left << std::setw(10) << month
            << "$ " << std::setw(14) << currentBalance
            << "$ " << std::setw(14) << paymentMade
            << "$ " << std::setw(14) << monthInterest
            << "$ " << std::setw(14) << newLoanBalance << std::endl;
        currentBalance = newLoanBalance;
    }
    // Shows your payments and interest totals
    DisplayLine(tableWidth);
    std::cout << std::left << std::setw(26) << "Total:"
        << "$ " << std::setw(14) << totalPayments
        << "$ " << std::setw(10) << totalInterest << std::endl;

}