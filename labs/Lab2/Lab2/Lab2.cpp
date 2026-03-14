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
    int interestRate = 0; 


};

/// @brief  Clears the input buffer of extra characters
void ClearInputBuffer()
{
    std::cin.ignore(INT32_MAX, '\n');
};


void main()
{
    Loan loan;
    do
    {
        std::cout << "Enter initial loan amount: ";
        std::cin >> loan.initialAmount;
    } 
    
    while (loan.initialAmount < 1 || loan.initialAmount > 1000);
    {
        std::cin >> loan.initialAmount;

        if (loan.initialAmount < 1 || loan.initialAmount > 1000)
        {
            std::cout << "Error: Initial loan amount must be $1-1000 range.";
            ClearInputBuffer();
        }   
    };
    
    
    
}