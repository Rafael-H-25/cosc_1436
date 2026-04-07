/*
*   Lab 2
*   Rafael Hernandez
*   COSC 1436
*   Spring 2026
*/

#include <iostream>
#include <iomanip>



/// @brief Displays program information
void displayProgramHeader()
{
    std::cout << "FallingDistance" << std::endl;
    std::cout << "Programmer: Rafael Hernandez" << std::endl;
    std::cout << "Course: COSC 1436" << std::endl;
    std::cout << "Semester: Spring 2026" << std::endl;
}

/// @brief Asks for a falling time number from 1 to 60.
void getFallingTime()
{
    int time;
    std::cout << "Please enter falling time in seconds (1-60): ";
    std::cin >> time;

    while (time < 1 || time > 60)
    {
        std::cout << "Problem: Invalid value. Please enter a value between 1 and 60: ";
        std::cin >> time;
    }
    return time;
}


void main()
{
    displayProgramHeader();

    int seconds = getFallingTime();


}
