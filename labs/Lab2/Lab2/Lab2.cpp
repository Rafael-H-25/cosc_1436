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


/// @brief  Clears the input buffer of extra characters
void ClearInputBuffer()
{
    std::cin.ignore(INT32_MAX, '\n');
};


void main()
{
    int tableWidth = 60;
    double monthlyPayment;
    Loan loan;
    do
    {
        std::cout << "Enter a loan amount: ";
        std::cin >> loan.initialAmount;

        if (loan.initialAmount < 1 || loan.initialAmount > 1000)
        {
            std::cout << "Error: Initial loan amount must be $1-1000 range." << std::endl;
            std::cin.clear();
            ClearInputBuffer();
        }

    } while (loan.initialAmount < 1 || loan.initialAmount > 1000);
    
    do
    {
        std::cout << "Enter your interest rate (%): ";
        std::cin >> loan.interestRate;

        if (loan.interestRate < 1.0 || loan.interestRate > 100.0)
        {
            std::cout << "Issue: Interest rate number value must be from 1-100% range." << std::endl;
            std::cin.clear();
            ClearInputBuffer();
        }

    } while (loan.interestRate < 1.0 || loan.interestRate > 100);

    do
    {
        std::cout << "Enter how much you want to pay each month: ";
        if (!(std::cin >> monthlyPayment) || monthlyPayment < 0 || monthlyPayment > loan.initialAmount)
        {
            std::cout << "Payment value must be higher than zero but lower than " << loan.initialAmount << "." << std::endl;
            std::cin.clear();
            ClearInputBuffer();
        }
        else
        {
            break;
        }
    } while (true);

    
    std::cout << std::left << std::setw(10) << "Month"
        << std::setw(15) << "Balance"
        << std::setw(15) << "Interest"
        << std::setw(15) << "New Balance" << std::endl;
    DisplayLine(tableWidth);
    
    std::cout << std::fixed << std::setprecision(2);

    double currentBalance = loan.initialAmount;
    double monthRate = (loan.interestRate / 100.0) / 12.0;

    for (int month = 1; month <= 12; month++)
    {
        double monthInterest = 0;
        if (month > 1)
        {
            monthInterest = currentBalance * monthRate;
        }
        double newLoanBalance = currentBalance + monthInterest;

        std::cout << std::left << std::setw(10) << month
            << "$ " << std::setw(14) << currentBalance
            << "$ " << std::setw(14) << monthInterest
            << "$ " << std::setw(14) << newLoanBalance << std::endl;
        currentBalance = newLoanBalance;
    }
}