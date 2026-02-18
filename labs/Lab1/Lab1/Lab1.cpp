/*  
* Lab 1
* Rafael Hernandez               // Part 1
* COSC 1436
* Spring 2026
*/

#include <iostream>
#include <string>
#include <iomanip>

void main()
{       // Working on name
    std::string firstName, lastName;
    std::cout << "Enter your name: ";
    std::cin >> firstName, lastName;

    // Working Correctly, Don't edit unless needed.
    double labOneGrade, labTwoGrade, labThreeGrade, labFourGrade;       // Part 2
    std::cout << "Enter your lab 1 grade: ";
    std::cin >> labOneGrade;
    std::cout << "Enter your lab 2 grade: ";
    std::cin >> labTwoGrade;
    std::cout << "Enter your lab 3 grade: ";
    std::cin >> labThreeGrade;
    std::cout << "Enter your lab 4 grade: ";
    std::cin >> labFourGrade;

    double examGradeOne, examGradeTwo, examGradeThree;
    std::cout << "Enter your exam 1 grade: ";
    std::cin >> examGradeOne;
    std::cout << "Enter your exam 2 grade: ";
    std::cin >> examGradeTwo;
    std::cout << "Enter your exam 3 grade: ";
    std::cin >> examGradeThree;

    // Part 3 works correctly
    double averageLab;
    averageLab = (double)(labOneGrade + labTwoGrade + labThreeGrade + labFourGrade) / 4; 

    std::cout << "Average lab grade = "
        << std::fixed << std::setprecision(2)       // Decimals work, set average as double to fix it
        << averageLab << std::endl;

    // Part 4, Done correctly
    double averageExam;
    averageExam = (double)(examGradeOne + examGradeTwo + examGradeThree) / 3;
    std::cout << "Average exam Grade = "
        << std::fixed << std::setprecision(2)
        << averageExam << std::endl;

    // Part 2
std:getline(std::cin, firstName, lastName);
    std::cout << "Hello " << firstName, lastName << std::endl; // Work in progress
}

