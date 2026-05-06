/*
*   Lab 5
*   Rafael Hernandez
*   COSC 1436
*   Spring 2026
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

/// @brief Represents a single stop on a trip with integer coordianates.
struct Stop
{
    int x;
    int y;
};

/// @brief Displays a dashed line.
/// @param width The width of the line.
void displayLine(int width)
{
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
};

/// @brief  Clears the input buffer of extra characters and sentences.
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT32_MAX, '\n');
};

/// @brief Prompts for speed and validates between 1 and 60 MPH.
/// @return Returns the speed number.
int getSpeed()
{
    int speed;
    while (true) 
    {
        std::cout << "Enter you travel speed (1 - 60 MPH): ";
        if (std::cin >> speed && speed >= 1 && speed <= 60)
        {
            clearInputBuffer();
            return speed;
        }
        std::cout << "Error: Speed must be an interger between 1 and 60." << std::endl;
        clearInputBuffer();
    }

}

/// @brief Validates that an integer input is within the required range.
/// @param prompt The message to show the user.
/// @return A validated integer between -100 and 100.
int getValidatedCoordinate(std::string prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value && value >= -100 && value <= 100) {
            clearInputBuffer();
            return value;
        }
        std::cout << "Error: Please enter an integer between -100 and 100." << std::endl;
        std::cin.clear();
        clearInputBuffer();
    }
}

/// @brief Calculates the distance between 2 points using the distance formula.
/// @param x1 First point in the x-axis.
/// @param y1 First point in the y-axis.
/// @param x2 Second point in the x-axis.
/// @param y2 Second point in the y-axis.
/// @return Returns the distance to the user.
double calculateDistance(int x1, int y1, int x2, int y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

/// @brief Shifts pointers to fill gaps after a deletion.
/// @param stops The array of Stop pointers.
/// @param size The maximum size of the array.
/// @param startIndex The index where the deletion occurred.
void compactArray(Stop* stops[], int size, int startIndex)
{
    int newIndex = startIndex;
    for (int index = startIndex + 1; index < size; ++index)
    {
        stops[newIndex] = stops[index];
        ++newIndex;
        if (!stops[index]) return;
    }
}

/// @brief Finds a stop pointer based on a 1-based stop number.
/// @param stops The array of Stop pointers.
/// @param size The maximum size of the array.
/// @param stopNumber The number for the Stop.
/// @return returns a nullptr.
Stop* getStopByNumber(Stop* stops[], int size, int stopNumber)
{
    int index = stopNumber - 1;
    if (index >= 0 && index < size && stops[index] != nullptr)
    {
        return stops[index];
    }
    return nullptr;
}

/// @brief Removes a specific stop pointer from the array and cleans up memory
/// @param stops The array of Stop pointers.
/// @param size The maximum size of the array.
/// @param stopToRemove Removes a stop pointer
void removeStop(Stop* stops[], int size, Stop* stopToRemove) 
{
    for (int index = 0; index < size; ++index) 
    {
        if (stops[index] == stopToRemove) 
        {
            delete stops[index];
            stops[index] = nullptr;
            compactArray(stops, size, index);
            return;
        }
    }
}

/// @brief Removes all stops from memory and resets the array.
/// @param stops The array of Stop pointers.
/// @param size The maximum size of the array.
void clearTrip(Stop* stops[], int size) 
{
    for (int index = 0; index < size; index++) 
    {
        if (stops[index] != nullptr) 
        {
            delete stops[index];
            stops[index] = nullptr;
        }
    }
}

/// @brief Adds a stop to the first avaliable null pointer in the array.
/// @param trip The array of Stop pointers.
/// @param maxStops The size of the array.
/// @param newStop The pointer to the new stop and add.
/// @return True if added successfully, false if the trip is full.
bool addStopToTrip(Stop* trip[], const int maxStops, Stop* newStop)
{
    for (int index = 0; index < maxStops; index++)
    {
        if (trip[index] == nullptr)
        {
            trip[index] = newStop;
            return true;
        }
    }
    return false;
}

/// @brief Orchestrates the removal of a stop by the user's request.
/// @param stops The array of Stop pointers.
/// @param size The maximum size of the array.
void handleRemoveOption(Stop* stops[], int size)
{
    int stopNum;
    std::cout << "\nEnter the Stop number to remove (1 or higher): ";
    if (!(std::cin >> stopNum))
    {
        std::cout << "Error: Invalid input." << std::endl;
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    Stop* targetStop = getStopByNumber(stops, size, stopNum);

    if (targetStop != nullptr)
    {
        removeStop(stops, size, targetStop);
        std::cout << "Success: Stop number " << stopNum << " is now removed." << std::endl;
    }
    else
    {
        std::cout << "Error: Stop number " << stopNum << " doesn't exist." << std::endl;
    }
}

/// @brief Clears the trip by choice by user.
/// @param stops The array of Stop pointers.
/// @param size The maximum size of the array.
void handleClearOption(Stop* stops[], int size) 
{
    char confirm;
    std::cout << "\nWarning: Are you sure you want to clear the trip? (Y/N): ";
    std::cin >> confirm;
    clearInputBuffer();

    if (toupper(confirm) == 'Y') {
        clearTrip(stops, size);
        std::cout << "\nSuccess: Trip cleared." << std::endl;
    } else {
        std::cout << "\nCancelled: The trip clearing was canceled." << std::endl;
    }
}

/// @brief Displays the trip stops in a formatted table.
/// @param trip The array of Stop pointers.
/// @param maxStops The size of the array.
/// @param speed Returns the speed in miles per hour.
void handleViewTrip(Stop* trip[], const int maxStops, int speed)
{
    if (trip[0] == nullptr)
    {
        std::cout << "\nTrip currently has no stops." << std::endl;
        return;
    }

    double totalDistance = 0;
    double totalTime = 0;

    int prevX = 0, prevY = 0;

    std::cout << "\n                Current Trip Details" << std::endl;
    displayLine(65);
    std::cout << std::left << std::setw(8) << "Stop #"
        << std::right << std::setw(10) << "X"
        << std::right << std::setw(10) << "Y"
        << std::right << std::setw(20) << "Dist (miles)"
        << std::right << std::setw(15) << "Time (mins)" << std::endl;
        displayLine(65);

        for (int index = 0; index < maxStops; index++)
        {
            if (trip[index] != nullptr)
            {
                double distance = calculateDistance(prevX, prevY, trip[index]->x, trip[index]->y);
                double time = (distance / static_cast<double>(speed)) * 60.0;
                
                totalDistance += distance;
                totalTime += time;
                std::cout << std::left << std::setw(8) << (index + 1)
                    << std::right << std::setw(10) << trip[index]->x
                    << std::right << std::setw(10) << trip[index]->y
                    << std::right << std::fixed << std::setprecision(2) << std::setw(15) << distance
                    << std::right << std::setw(15) << std::ceil(time) << std::endl;

                prevX = trip[index]->x;
                prevY = trip[index]->y;
        
            }
        }
        displayLine(65);
        std::cout << "Total Distance: " << std::fixed << std::setprecision(2) << totalDistance << " miles" << std::endl;
        std::cout << "Total Travel Time: " << std::ceil(totalTime) << " minutes" << std::endl;
    
    std::cout << std::endl;
}

/// @brief Handles the menu logic for adding a stop.
/// @param trip The array of Stop pointers.
/// @param maxStops The size of the array.
void handleAddStop(Stop* trip[], const int maxStops)
{
    Stop* newStop = new Stop;
    std::cout << "\n      Add New Stop        " << std::endl;
    newStop->x = getValidatedCoordinate("Enter X coordinate (-100 to 100): ");
    newStop->y= getValidatedCoordinate("Enter Y coordinate (-100 to 100): ");
    if (addStopToTrip(trip, maxStops, newStop))
    {
        std::cout << "Stop added to trip." << std::endl;
    }
    else
    {
        std::cout << "Error: Trip is full, cleaning up memory space." << std::endl;
        delete newStop;
    }

}

/// @brief Displays program information.
void displayProgramHeader()
{
    displayLine(35);
    std::cout << "      Trip Management System        " << std::endl;
    displayLine(35);
    std::cout << "Programmer: Rafael Hernandez" << std::endl;
    std::cout << "Course: COSC 1436" << std::endl;
    std::cout << "Semester: Spring 2026" << std::endl;
    displayLine(35);
    std::cout << std::endl;
};

/// @brief Prompts user for a choice.
/// @return Gives user the choice selected.
char getMenuChoice()
{
    char choice;
    bool isValid = false;

    while (!isValid)
    {
        std::cout << "\n     Main Menu        " << std::endl;
        std::cout << "A) Add Stop" << std::endl;
        std::cout << "V) View Trip" << std::endl;
        std::cout << "R) Remove Stop" << std::endl;
        std::cout << "C) Clear" << std::endl;
        std::cout << "Q) Quit Program" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        clearInputBuffer();

        choice = (char)toupper(choice);
        
        if (choice == 'A' || choice == 'V' || choice == 'R' || choice == 'C' || choice == 'Q')
            return choice;
            std::cout << "Error: " << choice << " is not valid." << std::endl;
    }
}

/// @brief Prompts user to ask if they want to quit.
/// @return Returns true if user enters 'Y' or 'y'.
bool confirmExit()
{
    char confirmation;
    std::cout << "Are you sure you want to quit? (Y/N): ";
    std::cin >> confirmation;
    clearInputBuffer();
    return (toupper(confirmation) == 'Y');
}

/// @brief Acts as the program controller
/// @param trip The array of Stop pointers.
/// @param maxStops The size of the array.
void manageMenu(Stop* trip[], const int maxStops, int speed)
{
    bool keepRunning = true;
    while (keepRunning)
    {
        char choice = getMenuChoice();
        switch (choice) 
        {
            case 'A': handleAddStop(trip, maxStops);
                break;
            case 'V': handleViewTrip(trip, maxStops, speed);
                break;
            case 'R': handleRemoveOption(trip, maxStops);
                break;
            case 'C': handleClearOption(trip, maxStops);
                break;
            case 'Q':
                if (confirmExit())
                {
                    std::cout << "\nExiting program." << std::endl;
                    keepRunning = false;
                }
            break;
        }
    }
}

int main()
{   
    displayProgramHeader();
    const int Max_Stops = 100;
    int speed = getSpeed();
    Stop* trip[Max_Stops] = {nullptr};
    manageMenu(trip, Max_Stops, speed);

    for (int index = 0; index < Max_Stops; index++)
    {
        delete trip[index];
    }
    return 0;
}