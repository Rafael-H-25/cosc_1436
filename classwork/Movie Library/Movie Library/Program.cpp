/*
* Movie Library
* COSC 1436
* Sprng 2026
*/
#include <iostream>
#include <iomanip>
#include <string>


//Movie definition
struct Movie
{
    //Fields
    std::string title;  // Required, not empty

    std::string genres; // comma seperated list

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


Movie AddMovie()
{
    ClearInputBuffer();

    Movie movie;
    // Prompt for movie details
    
    movie.title = ReadString("Enter title (required): ", true);
    movie.description = ReadString("Enter description: ");

    for (int count = 0; count < 5; ++count)
    {
        std::string genre = ReadString("Enter genre: ", false);
        if (genre != "")
            break;
        movie.genres += ", " + genre;
    }

    movie.runLength = ReadInt("Enter run length (in minutes): ", 0);
    movie.releaseYear = ReadInt("Enter release year (1900-2100): ", 1900, 2100);

    movie.isClassic = Confirm("Is classic?");
    return movie;
}

void DeleteMovie(Movie& movie)
{
    // No movie = no work
    if (movie.title == "")
        return;
    
    if (Confirm("Are you sure you want to delete '" + movie.title + "'"))
        movie.title = "";
}

void ViewMovie(Movie const& movie)
{
    if (movie.title == "")
    {
        DisplayWarning("No movies in library");
        return;
    }

    //Display movie details
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Length (in minutes) " << movie.runLength << std::endl;
    std::cout << "Genre(s): " << movie.genres << std::endl;
    std::cout << "User Rating: " << movie.userRating << std::endl;
    std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    
    std::cout << movie.description << std::endl;
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
void main()
{ 
    //ArrayDemo();

    //Movie movie;

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
                // Get the movie details
                // Find the first element not being used in the array
                // Store new movie there, if any.
                Movie movie = AddMovie();

                int index;
                for (index = 0; index < MaximumMovies; ++index)
                {
                    if (movies[index].title == "") // Find 1st element that isn't assigned
                    {
                        movies[index] = movie;
                        break;
                    }
                }

                if (index == MaximumMovies)
                    DisplayError("No more space is avaliable");

                break; 
            }
            case MenuCommand::Edit: DisplayWarning("Edit not implemented");
            case MenuCommand::Delete: DeleteMovie(movies[0]); break;
            case MenuCommand::View:
            {
                for (Movie movie: movies)
                {
                    if (movie.title != "")
                        ViewMovie(movie);
                }
                break;
            }
            case MenuCommand::Quit: quit = true; break;
            
            default: DisplayError("ERROR: Invalid option"); break;
        }
    }
}