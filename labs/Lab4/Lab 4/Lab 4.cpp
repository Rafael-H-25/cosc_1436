// Lab 4
//
//
//Use use C++ arrays, Only use C arrays shown in class
// User input: expecting user input validation
// 
// Break up code in functions
// Functions must be documented
// Avoid prototypes or foward references.
// Order your  functions to not need them.
// Don't assume the size of the array.
// Stored is where you are declaring it.
// Don't use global variables.
// 
// We use a header function.
// 
// Story 2:
// number are greater than 0
// create an array that can store up to 100 numbers
// and provide the user to prompt a number.
// The user can leave if put 0.
// 0 is not a part of the array values stored.
// If user inputs -1 or lower error.
// If limit of 100, they get out of it.
// Know the number of values entered. Return that to the function.
// Make sure the main prgram is gonna need the array and delclare it inside of main for an array.
// 
// 
// Story 3:
// After the user data collected.
// "quit" is there
// We can use 123 or letters.
// Put it in a function to call the function when the user asks for it.
// 
// Story 4:
// add an option of the largest value in the array, add logic, and call the function for the largest value for the array into the array.
//  You need to calculate to the array values not upfront.
//  Display the values to the user and to chose the next option.
//  
//  Story 5:  smallest value. dont use 0. the smallest should be 1.
//
// Story 6:
// Sum up all values in array. 
// if did 123456. We do 6 of them.
// 
// Story 7: Calculating the mean or average of the values.
// Sum array values and divide the 
// Number divided by the number they asked, they said 4, we divide by four.
// 4 decimal places.
// 
// Story 8: Show the values, just the values enter, if done more than 10, we only show 10 values per line.
// Story 9: Hardest potentially
// Add support to new values to the array without overighting it.
// All rules must be positive 1-100, 0 is out , -# means error.
// Add a new menu item.
// Once enter the new value, it will corectly done.
// 
//

/*
*   Lab 3
*   Rafael Hernandez
*   COSC 1436
*   Spring 2026
*/

#include <iostream>
#include <iomanip>
#include <string>

const int MAX_SIZE = 100;

/// @brief Displays a dashed line.
/// @param width The width of the line.
void DisplayLine(int width)
{
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
};

/// @brief  Clears the input buffer of extra characters and sentences.
void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT32_MAX, '\n');
};

/// @brief Displays program information.
void displayProgramHeader()
{
    DisplayLine(50);
    std::cout << "      Array Calculations        " << std::endl;
    DisplayLine(50);
    std::cout << "Programmer: Rafael Hernandez" << std::endl;
    std::cout << "Course: COSC 1436" << std::endl;
    std::cout << "Semester: Spring 2026" << std::endl;
    DisplayLine(50);
    std::cout << std::endl;
};

/// @brief Prompts for the user numbers and store them in the array.
/// @param list The array to store values.
/// @param size The maximum capacity of array.
/// @return The actual number of valid entries stored.
int getNumbers(int list[], int size)
{
    int count = 0;
    int input = -1;
    while (count < size && input != 0)
    {
        std::cout << "Enter an integral number (0 to quit): ";

        if (!(std::cin >> input))   // Enters words as input
        {
            std::cout << "Invalid input given, enter an integer." << std::endl;
            ClearInputBuffer();
            continue;
        }
        if (input == 0)     // Quits prompting numbers
        {
            break;
        } else if (input < 0)   // If lower than 0
        {
            std::cout << "Error: The number must be positive." << std::endl;
        } else
        {
            list[count] = input;
            count++;
        }
    }
    return count;
};

/// @brief Displays all valid numbers stored in the array.
/// @param list The array of numbers.
/// @param count The actual number of valid elements stored.
void displayArray(int list[], int count)
{
    std::cout << "     List of Current Numbers     " << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "Entry [" << i + 1 << "]: " << list[i] << std::endl;
    }
    DisplayLine(30);
}

/// @brief Finds the largest value in the array.
/// @param list The array of integers.
/// @param count The number of elements actually stored.
/// @return The largest integer found.
int getLargestValue(int list[], int count)
{
    int largest = list[0];

    for (int i = 1; i < count; i++)
    {
        if (list[i] > largest)
        {
            largest = list[1];
        }
    }
    return largest;
};

/// @brief Finds the smallest value in the array.
/// @param list The array of integers.
/// @param count The number of elements actually stored.
/// @return The smallest interger found.
int getSmallestValue(int list[], int count)
{
    int smallest = list[0];
    for (int i = 1; i < count; i++)
    {
        if (list[i] < smallest)
        {
            smallest = list[i];
        }
    }
    return smallest;
};

/// @brief Calculates the total sum of all the values in the array.
/// @param list The array of integers.
/// @param count The array of integers.
/// @return The total sum.
int getSum(int list[], int count)
{
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total += list[i];
    }
    return total;
};

/// @brief Calculates the mean (average).
/// @param list The array of integers.
/// @param count The array of integers.
/// @return Returns average as a double for precision.
double getMean(int list[], int count)
{
    if (count == 0) return 0.0;
    return static_cast<double>(getSum(list, count)) / count;
}

/// @brief Displays menu and returns validation selection given.
/// @return Returns the uppercase character of the selection.
char getMenuChoice()
{
    char selection;
    std::cout << "\n     MAIN MENU      " << std::endl;
    std::cout << "A) Display All Numbers" << std::endl;
    std::cout << "B) Find Largest Value" << std::endl;
    std::cout << "C) Find Smallest Value" << std::endl;
    std::cout << "D) Calculate Sum" << std::endl;
    std::cout << "E) Calculate Mean" << std::endl;
    std::cout << "Q) Quit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> selection;
    return toupper(selection);  // Does q or Q automatically.
};

int main()
{
    int myNumbers[MAX_SIZE];
    int actualSize = 0;
    char choice = ' ';

    displayProgramHeader();
    actualSize = getNumbers(myNumbers, MAX_SIZE);

    if (actualSize > 0)
    {
        while (choice != 'Q')
        {
            choice = getMenuChoice();

            if (choice == 'A')
            {
                displayArray(myNumbers, actualSize);
            } else if (choice == 'B')
            {
                std::cout << "\nThe largest value is: " << getLargestValue(myNumbers, actualSize) << std::endl;
            } else if (choice == 'C')
            {
                std::cout << "\nThe smallest value is: " << getSmallestValue(myNumbers, actualSize) << std::endl;
            } else if (choice == 'D')
            {
                std::cout << "\nThe sum of all values is: " << getSum(myNumbers, actualSize) << std::endl;
            } else if (choice == 'E')
            {
                std::cout << "\nThe mean of all values is: " << std::fixed << std::setprecision(4) << getMean(myNumbers, actualSize) << std::endl;
            }
            else if (choice != 'Q')
            {
                std::cout << "\nInvalid choice. Select A, B, C, or Q." << std::endl;
            }
        }
    } else
    {
        std::cout << "No data entered." << std::endl;
    }
    std::cout << "\nEnd of Program" << std::endl;
    return 0;

}
