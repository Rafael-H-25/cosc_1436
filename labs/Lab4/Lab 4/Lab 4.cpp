/*
*   Lab 4
*   Rafael Hernandez
*   COSC 1436
*   Spring 2026
*/ 
 
#include <iostream>
#include <iomanip>

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
/// @param currentCount The current number of elements already in the array (defaults to 0).
/// @return The actual number of valid entries stored.
int getNumbers(int list[], int size, int currentCount = 0)
{
    int count = currentCount;
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
        std::cout << std::setw(5) << list[i];

        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
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
            largest = list[i];
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
    std::cout << "L) Largest Value" << std::endl;
    std::cout << "S) Sum Calculated" << std::endl;
    std::cout << "M) Mean Calculated" << std::endl;
    std::cout << "T) Tiniest Value" << std::endl;
    std::cout << "I) Insert New Values" << std::endl;
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
            } else if (choice == 'L')
            {
                std::cout << "\nThe largest value is: " << getLargestValue(myNumbers, actualSize) << std::endl;
            } else if (choice == 'S')
            {
                std::cout << "\nThe sum of all values is: " << getSum(myNumbers, actualSize) << std::endl;
            } else if (choice == 'M')
            {
                std::cout << "\nThe mean of all values is: " << std::fixed << std::setprecision(4) << getMean(myNumbers, actualSize) << std::endl;
            } else if (choice == 'T')
            {
                std::cout << "\nThe tiniest value is: " << getSmallestValue(myNumbers, actualSize) << std::endl;
            }
            else if (choice == 'I')
            {
                actualSize = getNumbers(myNumbers, MAX_SIZE, actualSize);
            }  
            else if (choice != 'Q')
            {
                std::cout << "\nInvalid choice. Select From Above Again." << std::endl;
            }
        }
    } else
    {
        std::cout << "No data entered." << std::endl;
    }
    std::cout << "\nEnd of Program" << std::endl;
    return 0;

}
