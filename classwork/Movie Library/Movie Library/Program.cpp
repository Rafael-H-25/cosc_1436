/*
* Movie Library
* COSC 1436
* Sprng 2026
*/
#include <iostream>
#include <iomanip>
#include <string>


//Movie definition
const int MaximumGenres = 5;
struct Movie
{
    int id;



    //Fields
    std::string title;  // Required, not empty

    std::string genres[MaximumGenres]; // comma seperated list
    int genreCount = 0;

    int runLength = 0;      // >=0
    int releaseYear = 0;    // 1900 to 2100

    double userRating = 0;  //1 to 5

    bool isClassic = false;

    std::string description; //Optional (summary)
};

enum MENU_COMMAND   //C style enum, not very good for us. The problem comes in when you have another enum. So we can use the abreviations for them (MC). They are very restricitve.
{
    // Defines the value that represent the subset of integers 
    //Emum values: rather than reading a character calling it a choice, now were going to declare a variable command as input.
    MC_ADD = 1,        // const int ADD = 0, named integer constants used for integers
    MC_EDIT = 2,       // = 1 etc. generally not useful, you sometimes care for the numerical value
    MC_DELETE = 3,     // do not represent one of them as 0. Consider it as undefined.
    MC_VIEW = 4,
    MC_QUIT = 5
};

enum ENHANCED_MENU_COMMAND  // Enum values are considered the whole scope, they are rewritten as named constants globally. They must be globally unique can't be the same anywhere.
{
    EMC_INSERT,
    EMC_DELETE

};

enum class MenuCommand // You will still need to the same thing as before.
{
    Add = 1,
    Edit = 2,
    Delete = 3,
    View = 4,
    Quit = 5
};

enum class EnhancedMenuCommand
{
    Insert,     // Its scope is from the blocks {}
    Delete
};

enum class ConsoleColor
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,

    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97,
};

//Prototypes / foward reference
// Function declaration without the definition
void DisplayError(std::string);
void DisplayWarning(std::string);
void ResetColors();
void SetForegroundColor(ConsoleColor);

//int g_standardConsoleLineLength = 80;
//int g_maximumLineLength = g_standardConsoleLineLength;  //This code may not work. The order can be any one because the order is undefined.
const int g_maximumLineLength = 80; // Only allowed case for a constant.

/// @brief Displays a horizontal line.
/// @param width Width of the line
void DisplayLine( int width ) /* The function name determines the function action*/ /* The int width is a parameter list, parameter seperated by commas, local variable declaration*/
{
    int maximumLineLength = -1; // Make sure a variable isn't the same as a global variable.
    
    {
        double width = 24;
        int someValue = width * g_maximumLineLength;
    }

    if (width < 0)
        width = 0;
    else if (width > g_maximumLineLength)
        width = g_maximumLineLength;
    //int width = 10;
    
    // Logical operation any # of code you want.
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
};

//Function to reset color
/// @brief Resets the output colors to their default values.
void ResetColors()
{
    std::cout << "\033[0m";
};

/// @brief Clears the input buffer of extra characters
void ClearInputBuffer()
{
    std::cin.ignore(INT32_MAX, '\n');    // Has 2 arguements. 
};

// Function to set text color to red
/// @brief Sets the output color for displaying errors.
/// @param color Color to use for the foreground
void SetForegroundColor( ConsoleColor color )
{
    char buffer[10] = {0};
    _itoa_s((int)color, buffer, 10, 10);

    std::string value = "\033[";
    value += buffer;
    value += "m";
    std::cout << value;
};
// Above are simple functions.

/// @brief Displays a message
/// @param color Color to show the message in.
/// @param message Message to display
/// @param includeNewLine Add a new color?
void DisplayMessage(ConsoleColor color, std::string message, bool includeNewLine)
{
    SetForegroundColor(color);
   
    std::cout << message;;
    if (includeNewLine)
        std::cout << std::endl;
    
    ResetColors();
}


/// @brief Displays an error message.
/// @param message Message to display.
void DisplayError(std::string message)
{
    SetForegroundColor(ConsoleColor::BrightRed);
    std::cout << "ERROR: " << message << std::endl;
    ResetColors();
}

/// @brief Displays a warning message.
/// @param message Message to display.
void DisplayWarning(std::string message)
{
    SetForegroundColor(ConsoleColor::Yellow);
    std::cout << "WARN: " << message << std::endl;
    ResetColors();
}
// Main is a special function
// it is the entry fuction o your program
// it's declaration can vary slightly
// You can't call main directly
// Functions are compiled at isolation but it works like a variable with an expression because of C.

/// @brief Confirms information from the user
/// @param message Message to display 
/// @return true if yes or false if no
bool Confirm(std::string message)
{
    // Confirm
    message += " (Y/N) ";
    DisplayMessage(ConsoleColor::Cyan, message, false);
    bool confirm = false;
    do
    {
        char choice;
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
            return true;
       /* {
            confirm = true;
            break;
        } */
        else if (choice == 'N' || choice == 'n')
            return false; //correct version
        /*{
            confirm = false;
            break;
        }*/
    } while (true);

    //return false; // if a return is inside another return, its nt needed unless you use a break.
}

int ReadInt(std::string message, int minValue, int maxValue)
{
    std::cout << message;

    int input;
    
    do
    {
        std::cin >> input;

        if (input >= minValue && input <= maxValue)
            return input;
            // Fix later
        DisplayError("Value is not in expected range");
    } while (true);
}

int ReadInt(std::string message, int minValue)
{
    return ReadInt(message, minValue, INT32_MAX);
}

/// @brief Reads a string from the user
/// @param message Message to display
/// @param required true to indicate a required value
/// @return Input from user
std::string ReadString(std::string message, bool required)
{
    std::cout << message;

    std::string input; 
    do
    {
        std::getline(std::cin, input);

        //Validate
        if (input != "" || !required)
            return input;

        DisplayError("Value is required");
    } while (true);
}

/// @brief Reads an optional string
/// @param message Message to display
/// @return Input from user
std::string ReadString(std::string message)
{
    return ReadString(message, false);
}

/// @brief Find a movie given its ID
/// @param movies 
/// @param size 
/// @param id 
/// @return 
int FindMovieById(Movie movies[], int size, int id)
{
    for (int index = 0; index < size; ++index)
        if (movies[index].id == id)
            return index;
    return -1;
}

Movie AddMovie()
{
    ClearInputBuffer();

    Movie movie;
    // Prompt for movie details
    
    movie.title = ReadString("Enter title (required): ", true);
    movie.description = ReadString("Enter description: ");

    for (int count = 0; count < MaximumGenres; ++count)
    {
        std::string genre = ReadString("Enter genre: ", false);
        if (genre == "")
            break;

        movie.genres[count] = genre;
        ++movie.genreCount;
    }

    movie.runLength = ReadInt("Enter run length (in minutes): ", 0);
    movie.releaseYear = ReadInt("Enter release year (1900-2100): ", 1900, 2100);

    movie.isClassic = Confirm("Is classic?");
    return movie;
}

// Arrays as parameters are always open arrays (Any size/undefined size) Any function you write musts support an open array.
// arrays size always follows array parameters
int AddMovie( Movie movies [], int size )
{//you cannot determine the data at runtime in an array.
    // Get the movie details
    Movie movie = AddMovie();

    //find an empty spot in the array
    static int id = 1;
    
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "") // Find 1st element that isn't assigned
        {
            movie.id = id++;

            movies[index] = movie;
            return index;
        }
    }
    return -1;
}

void DeleteMovie(Movie& movie)
{
    // No movie = no work
    if (movie.title == "")
        return;
    
    if (Confirm("Are you sure you want to delete '" + movie.title + "'"))
        movie.title = "";
}

// Arrays are pass by value
// Array behaves like pass by reference (parameter and arguement point to the same arrat in memory)
// Since the parameter is a pass by value, you cannot change what the arguement refers to (the array)
// Arrays cannot be the return type of a function, if you do, the function will fail the call.
void DeleteMovies(Movie movies[], int size)
{
    //Determine movie to delete
    int id = ReadInt("Enter ID of the movie to delete: ", 1);

    // Find the movie.
    int index = FindMovieById(movies, size, id);
    if (index < 0 || index >= size)
    {
        DisplayWarning("Movie not found");
            return;
    };
    //Delete it
    DeleteMovie(movies[index]);
}

void ViewMovie(Movie const& movie)
{
    if (movie.title == "")
        return;
    

    //Display movie details
    std::cout << "[" << movie.id << "] ";
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Length (in minutes) " << movie.runLength << std::endl;
    //std::cout << "Genre(s): " << movie.genres << std::endl;
    std::cout << "Genres: ";
    for (int index = 0; index < movie.genreCount; ++index)
    {
            if (index > 0)
                std::cout << ", ";
            std::cout << movie.genres[index];

    }
    std::cout << std::endl;

    std::cout << "User Rating: " << movie.userRating << std::endl;
    std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    
    std::cout << movie.description << std::endl;
}

void ViewMovies(Movie movies[], int size)
{
    //For range statement doesn't work with array parameters

    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title != "")
            ViewMovie(movies[index]);
    }
}

void ArrayDemo()
{
    const int MaximumValues = 10;
    int values[MaximumValues];

    // Syntax for array elements: array name [ expression ]
    // Index is specified inside the brackets
    // Must be an integer type.
    // index ::= E (integral)
    // Index is always zero-based.
    // Indez starts at 0 not one, so the first element in the array is at index 0.
    // ex:      Index 0 = Element 1
    //          Indez 1 = Element 2
    //          Index N = Element N+1
    // Given an array of size M
    //      There are M elements (1-M)
    //      Index is 0 to M - 1
    int thirdElement = values[2];
    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    // Iterate the elements in an array. Want to access all the elements of the array.
    // Secrets: there is no way at runtime to correctly determine the number of elements in an array.
    for (int index = 0; index < MaximumValues; ++index)
    //int index = 0;
    //for (int& value: values)
    {
        values[index] = index * 10;
        //value = index * 10;
    }

    // for-range statement: made for arrays     ::= for (type identifier : array)
    // Only works if the array is declared within the same function.
    //for (int index = 0; index < 10; ++index)
    for (int value: values)
    {
        std::cout << value << " ";
    }
}

void ArrayInitDemo()
{
    // Zero array initialization- inititallizer all elements in the array: works in the primitive except the string. 
    //int daysInMonth[12] = {0};

    // Full array initialization sets all 
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };

    // Init each element to specific value
    /*daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7] = daysInMonth[9] = daysInMonth[11] = 31;
    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;
    daysInMonth[1] = 28;*/
         
    // Implicit array string - when using an array initializater, size of array is optional. Only useful in something like "month names", "sides in a shape", ect.
    // Use cases: 
    // 1. Size of array will never change for your life.
    // 2. String
    // Disadvantage: the size if it.
    // Know the size of it. months in a year.
    std::string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    //monthNames[0] = "Jan";
    //monthNames[1] = "Feb";
    //monthNames[2] = "Mar";
    //monthNames[3] = "Apr";
    //monthNames[4] = "May";
    //monthNames[5] = "Jun";
    //monthNames[6] = "Jul";
    //monthNames[7] = "Aug";
    //monthNames[8] = "Sep";
    //monthNames[9] = "Oct";
    //monthNames[10] = "Nov";
    //monthNames[11] = "Dec";

    for (int index = 0; index < 12; ++index)
        std::cout << monthNames[index] << " has " << daysInMonth[index] << " days" << std::endl;

    // Partial array initialization - only some elment values are set, the rest are zero initialized. 
    char name[100] = {'8', 'o', 'b'}; //"Tom"
    char companyName[] = "My Company";

    double rates[5] = {1.2, 3.4, 5.6, 7.8, 9.0};


    int numbers[10];

    // Off by one errors: 
    // Starting at 1 and therefore skipping first element
    // Indexing to size which is one after the last element
    // General purpose: for loop

    for (int index = 0; index < 10; ++index)
        numbers[index] = index + 1;

    for (int index = 0; index < 10; ++index)
        std::cout << numbers[index] << " ";
    std::cout << std::endl;

}

void CopyArray(int target[], int targetSize, int source[], int sourceSize)
{
    int size = (sourceSize <= targetSize) ? sourceSize : targetSize;

    for (int index = 0; index < size; ++index)
        target[index] = source[index];
}

bool CompareArray(int left[], int leftSize, int right[], int rightSize)
{
    if (leftSize != rightSize)
        return false;
    for (int index = 0; index < leftSize; ++index)
        if (left[index] != right[index])
            return false;
    return true;
}

void DisplayArray(int values[], int size, int elementsPerLine, std::string delimiter)
{
    for (int index = 0; index < size; ++index)
    {
        /*std::cout << values[index] << " ";*/
        // Divides index by elements, when evenly divisible then print newline.
        if (index % elementsPerLine == 0 && index != 0)
            std::cout << std::endl;

        std::cout << values[index] << delimiter;
    }
    std::cout << std::endl;
}

void ArrayUsageDemo()
{
    // Things toy can't do with array variables.
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {2, 4, 6, 8, 9, 10, 12, 14, 16, 20};

    // Can't Copy them
    // array2 = array1
    CopyArray(array2, 10, array1, 5);

    // Can't Compare them
    // bool areEqual == array1 == array2
    bool areEqual = CompareArray(array1, 10, array2, 10);

    //Can't Display them
    //std::cout << array1 << std::endl;
    DisplayArray(array1, 10, 5, " ");

    //Pre/Postfix increment
    int values[3] = {1, 2, 3};
    int sum = 0;
    
    int index = 0;
    while (index < 3)
    {
        //Most common index 'Prefix' ++x, values[1], values[2]
        //sum += values[++index]; 
        //sum += values[index++]; //values[0], values[1] ,values[2]


        //Prefix to the element
        //sum += ++values[index];
        //index++;

        // equivalent to previous lines
        sum += ++values[index++];
    }

}

void DisplayTable(int table[][12], int size)
{
    for (int row = 0; row < size; ++row)
        DisplayArray(table[row], 12, 12, " ");  // Prints out an array of tabels.
        //for (int col = 0; col < 12; ++col)
          //  std::cout << table[row][col] << " ";
    
    std::cout << std::endl;
}

void MultiDimentionalArrayDemo()
{
    // 10 x 12 table of values
    const int MaxRows = 100;
    const int MaxCols = 100;
    int multiplication[MaxRows][MaxCols] = {
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
        { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24},
        { 3, 6, 9, 12 },
        { 4, 8, 12, 16 }
    };
        // Table with 10 rows and 12 columns
    
    // 2 ways to store tables in memory:
    // Row major - (C++) problem : how to store a stucutre 3D+ into simple values:
    // We store by row. We store the entire rows value then the next one. ex: A1-B1-C1-D1, then. Stored consecutive in memory.
    // The perfect way to all the values in the row then the next one until done. Reading the array stored in memory. (row stored first, for row; for col)
    // 
    // Column major
    // Store the whole column: A1-4, then B1-4.
    // Reads 1 element at a time. Need to do rows of 1st column before moving to the next column.
        for (int row = 0; row < MaxRows; ++row)
            for (int col = 0; col < MaxCols; ++col)
                multiplication[row][col] = (row + 1) * (col + 1);

 /*   DisplayTable(multiplication, MaxRows);*/
}

void main()
{ 

    //Movie movie;
    //ArrayDemo();
    //ArrayIntDemo();
    //ArrayUsageDemo();

    // Array: multiple values stored as 1 into a single variable.
    // arr_decl::= 'Type' 'identifier name' [expression] alocates space for 5 movies.
    // By declaring 5 movies, we can store up to 5 movies, and each movie is independent to the other.
    // Array stores elements which you can equate to values.
    // restrictions: You can't declarate different types.
    // array names are always plural.
    // All elements have the same type
    // Don't use it to store unrelated values just to save variables.
    // The value inside the [] is the size, number of elements, in the array
    // 1. The size of the array must be a compile time constant. You can't change it at runtime.
    // 2. Greater than 0. All arrays must store 1 element. 
    // 3. Must be an integer (whole number) ex: 0.75 of a movie, how?
    // Important point: Array is not part of the type. Changes how types work.
    // Its tied to the variable, not the type.
    // Other names for arrays: in C++ arrays are primitive, built in the language. There are other types, but none will not be used.
    // Collection, vector set, list, array. Don't use any of them except array.
    // size of bytes (array) is the size of the element by the size of the '[x]'.
    // All arrays store their elements contiguosly in memory.
    // Local variables are stored on stack so be careful of stack space.
    const int MaximumMovies = 100;
    Movie movies[MaximumMovies];

    bool quit = false;
    while (!quit)
    {
        std::cout << "Main Menu" << std::endl;
        DisplayLine(10);
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "V)iew Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;
        std::cout << "?";

        MenuCommand input = (MenuCommand)0;
        char choice;

        while (input == (MenuCommand)0)
        {
            std::cin >> choice;
            switch (choice)
            {
                case 'A':
                case 'a': input = MenuCommand::Add; break;

                case 'E':
                case 'e': input = MenuCommand::Edit; break;

                case 'V':
                case 'v': input = MenuCommand::View; break;

                case 'D':
                case 'd': input = MenuCommand::Delete; break;

                case 'Q':
                case 'q': input = MenuCommand::Quit; break;

                default:
                { 
                    /*SetForegroundColor(ConsoleColor::BrightRed);
                    std::cout << "ERROR: Invalid option" << std::endl;
                    ResetColors();*/
                    DisplayError("Invalid option");
                    break; 
                }
            }
        }
      
        switch (input)
        {
            case MenuCommand::Add:
            {
                int index = AddMovie(movies, MaximumMovies);

                if (index < 0)
                    DisplayError("No more space is avaliable");

                break; 
            }
            case MenuCommand::Edit: DisplayWarning("Edit not implemented");
            case MenuCommand::Delete: DeleteMovies(movies, MaximumMovies); break;
            case MenuCommand::View: ViewMovies(movies, MaximumMovies); break;
            
            case MenuCommand::Quit: quit = true; break;
            
            default: DisplayError("ERROR: Invalid option"); break;
        }
    }
}