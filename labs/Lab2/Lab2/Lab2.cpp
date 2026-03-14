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


void main()
{
    Loan loan;


    std::cout << "Enter initial loan amount: ";

    while (loan.initialAmount < 1 || loan.initialAmount > 10000)
    
}