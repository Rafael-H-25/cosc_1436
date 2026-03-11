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

 /* Enumeration: a subrange of int:
    *
    *
    */
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
// C++ style enum, cout doesn't suppport it so use a cast

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

    //Function: a reusable block of code that does 1 logical thing.
    // Must sit outside of main.
    // An error message, may require 1-2 lines of code that may require its own function
    // Example: getline (a fuction/module: reads a string from an input.)
    // std::cin: (module) not technically a function but the input string option is.
    // std::cout: the functionality of it converting text in a input.
    // pow() exp(), many are out there. (modulus)
    // Very critical to identify when to find a function and build one.
    // Have several benefits:
    /*  1. Maintanability: when programs are getting more complicated, the harder it is to maintain, by using fuctions it reduces it.
    *   2. Smaller: reduces how much code is needed to operate. ex: case function from add movie function.
    *   3. encapsulation: its a black box, you should not care. The program does their job and you trust on that. If it doesn't work is because its not in your work. ex: cout and cin.
    *   4. Changes: isolate changes from how fuctions are implemented from us. ex: pow may mean something else from an x time before vs a y time after, the code doesn't care at all from that.
    *   5. Isolated: The code in a function is isolated from any other code. No visibility in them and will have no chance to mess other functions in them.
    *   One benifit it doesn't provide: Speed: Slows down your code down, however with modern processors you won't really tell. Keep that in mind.
    */

// Function to display a horizontal line ex:
/* Starts with function definition::= void id(), statement in void
* {
* statement
* } and a ";"
* func_defn ::= T id () { S* }
* casing for fuctions: camel or Pascal , write them as Capital letter or Pascal casing and must be consistent if use functions. ex: Pascal for all functions must be consistent.
*/
// Function definition here below. a function represents: "does something", name the function a verb/action and use standard identifiers also.
// How to document a document below, a high requirement when intering the "(" must be correct based on the function's intension.
// Briefs is the single sentence description of code. Major requirement to describe a function in one simple sentence. 


/// @brief Displays a horizontal line.
void DisplayLine() /* The function name determines the function action*/
{
    // Logical operation any # of code you want.
    std::cout << "-----------------" << std::endl;
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
void SetErrorColor()
{
    std::cout << "\033[91m";
};
// Above are simple functions.

// Main is a special function
// it is the entry fuction o your program
// it's declaration can vary slightly
// You can't call main directly
// Functions are compiled at isolation but it works like a variable with an expression because of C.

void main()
{
    /* Demo  (Heavily used, you must know this)            SYNTAX
    * 4 operators:           x += 1, x -= 1     x'        Expression
    * Prefix increment:      ++x X + 1          x+1         x' (current new value) always get the new value
    * Postfix intrement:     x++                x+1         temp = x (value before its modifed) alwayas get the prevalue
    * Prefix decremint:      --x x - 1          x-1         x'
    * Postfix decrement:     x--                x-1         
    */ 

    //Side effect: is the consequences of evaluating an expression. 
   // int someValue = 20;
   // //++someValue;    // prefix increments someValue by 1 and stores it back into someValue (someValue += 1)
   // std::cout << ++someValue << " " << someValue << std::endl; // 21 21

   //// someValue++;    // postfix inc.
   ////std::cout << someValue << std::endl;
   // std::cout << someValue++ << " " << someValue << std::endl; // 21 22

   // //--someValue;    // prefix dec
   // //std::cout << someValue << std::endl;
   // std::cout << --someValue << " " << someValue << std::endl; // 21 21

   // //someValue--;    // postfix dec
   // //std::cout << someValue << std::endl;
   // std::cout << someValue-- << " " << someValue << std::endl; // 21 20

   // someValue = 20;
   // std::cout << someValue++ << " " << ++someValue << " " << someValue << std::endl;

   // someValue = 20; // short circuit value
   // if (++someValue > 30 || someValue-- < 10)   // We won't see the right if the left would be true because left side was true and short circuited it to be true and "skip it"
   //     std::cout << "Is true: ";
   // std::cout << someValue << std::endl;


    //Basics: define a movie. Name/Title (string), genres (string+), length (timr), actors (string+), directors (string+), release date (date), mpaaratings (string), userrating (double, int) etc. #1. 
    // We ignore Actors and directos, the ratings, time and date we can't use, so adjust definition. Length is minutes (int), dates => release year (int), Isclassic (bool)
 
    //// The while loop (easiest)
    //
    //// Demo nested loops
    //int someValue = 10;
    //for (int x = 0; x < 50; ++x) // always start at 0. How we do it. this loop will do 50 iterations.
    //{
    //    for (int y = 0; y < 20; ++y) // 20 * 50 = 1000, will be every long. Blows up when uing nested loops like this, and will slow the program down.
    //    {
    //        std::cout << x + y << std::endl;

    //        if (y != 0 && y % 10 == 0)
    //            break;
    //    }

    //    if (x != 0 && x % 10 == 0)
    //    {
    //        std::cout << "Quit? ";
    //        int choice;
    //        std::cin >> choice;
    //        if (choice != 0)
    //            break;
    //    }
    //
    //}
    
    /*              prehost     S
    * while         pre         0+      if neither
    * for           pre         0+      fixed iterations
    * do while      post        1+      at least once       "Quiz which should you use for post test". Quiz over this. 
    */
   
    Movie movie;
    
    bool quit = false;
    while (!quit)
    {
    // Display menu (simple)
        std::cout << "Main Menu" << std::endl;
        //std::cout << "------------" << std::endl;
        DisplayLine(  // We declared a function, and made a code smaller
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "V)iew Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;
        std::cout << "?";

        //Handle user input
        //MENU_COMMAND input = (MENU_COMMAND)0; // Only do this if you have to program against, but we won't do this in class, static cast works, any interger value can be assigned an enum.
        MenuCommand input = (MenuCommand)0;
        char choice;    // Enum allows to make named to prefined values, but gives a false sense of security.


        // while loop,   syntax: while (Expression boolean, then executes statement) a pretest, testing the condition before doing the work. executes 0 or more times.
        // Used alot
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
                    SetErrorColor();
                    std::cout << "ERROR: Invalid option" << std::endl;
                    ResetColors();
                    break; 
                }
            }
        }


        // Handle menu choice
        //if (choice == 'A' || choice == 'a')
        //    // TODO: Move addmovie logic here
        //    std::cout << "Add not implemented" << std::endl;
        //else if (choice == 'E' || choice == 'e')
        //    std::cout << "Edit not implemented" << std::endl;           //else if from a, e. d. v, will not show. 
        //else if (choice == 'D' || choice == 'd')
        //    std::cout << "Delete not implemented" << std::endl;         
        //else if (choice == 'V' || choice == 'v')
        //    std::cout << "View not implemented" << std::endl;
        //else 
            /*if (choice != 'A' && choice != 'a'
            && choice != 'E' && choice != 'e'           <= This makes no sense as all are either true or false, everything else won't show. So we remove it.
            && choice != 'D' && choice != 'd'
            && choice != 'V' && choice != 'v')*/
            //std::cout << "ERROR: Invalid option" << std::endl;       
        // switch_statement ::= switch (E) { case_statement* } ;
        // The restrictions: the replacement for (E must equal to Value)
        // Limitations: 1, swtich expression must be an integral or char. Cant use floating point values or string.
        // 2: All case labels must be compile time constants integers (Value doesn't change, and compiler knows it) integer literals, named constants that are literals. No floats or string or any other.
        // 3: case labels must be unique. Within a switch statement must only appear once. Can't have duplicates and won't know where to jump to. No way to work around it.
        // To prevent fallthrough frim one case to the next, end your case statements will break.
        // The only reason why we can have a fall through, a case can be optional.

        //MENU_COMMAND input; // It comes to play is when we star using it with characters or full range on values.
        //input = ADD;
        //std::cin >> (int)input; // (C) Cin doesn't know what that means, can't work with it sadly. But we can put an int. Cout should work just fine, cin cant understand user input for this.
        //std::cout << (int)input; // (C++) cout doesnt know
       
        switch (input)
        {
            
            //// TODO: Move add movie logic here
            //case 'A':
            ////{
            ////    //choice = 'a'
            ////    //std::cout << "Hello";
            ////    std::cout << "Add not implemented" << std::endl;
            ////    break;
            ////}
            case MenuCommand::Add:
            {
                // Add movie logic          // block declarations: c style type: , the alternantive approach is the inline delaration: //code int x = E; //code double y = E (declare it when needed and is most prefered)   
               
                // Reset input buffer
                //std::cin.ignore(INT32_MAX, '\n');
                ClearInputBuffer();

                //: Prompt for movie details
                std::cout << "Enter title (required): ";

                while (movie.title == "")
                {
                    std::getline(std::cin, movie.title);

                //: Validate title
                    if (movie.title == "")
                        std::cout << "ERROR: Title is required" << std::endl;
                }

                std::cout << "Enter description: ";
                std::getline(std::cin, movie.description);

                std::cout << "Enter genre: ";
                
                // Cases for when expressions can be excluded.
                // for (;;) {/* infinite loop*/ }
                // for (; choice < 10; ++choice) {}
                // May have mmultiple of each expression
                // for (int x = 0, int y = 10; x < 20, y > 0; ++x, --y) {} (only possible used when two values are getting close to each other)
                // Goes bad in the middle expression (x < 20, y > 0), the x < 20 is removed entirely, the y > 0 is the test condition. If you want to use both then use && for ",".

                //int genreCount = 0;
                //while (genreCount < 5)
                // Break and continue: Useable inside of a loop. Purpose
                // Break: getting out of the case. Used when want out of the loop (stops the loop) use when needed or not precive any further. Begining of a loop or end. Use 2 or only 1.
                // Continue statement: purpose to exit the current iteration of that loop. (it is skipped to the next part.)
                
//                int count = 0;
                for (int count = 0; count < 5; ++count) // Commonly used case.
                {
                    std::string genre;
                    std::getline(std::cin, genre);

                    //if (genre == "")
                    //    continue;   // still going to execute but won't enter anything with empty space. still adds up to the "5"
                    //movie.genres += ", " + genre;

                    if (genre != "")
                    {
                        movie.genres += ", " + genre;
                       //++genreCount;
                    } else
                        //genreCount = 5;
                        //count = 5;
                        break;
                }
               

                std::cout << "Enter run length (in minutes): ";
                // do-while: do statement while (Eb),
                //      post-test S executes at least once
              /* movie.runLength = -1;
                while (movie.runLength < 0)*/ // must ensure this scenario or any scenario must guarantee that it is false or will be false or it will be an infinite loop.
                do
                {
                    std::cin >> movie.runLength;


                    //Runlength >= 0
                    if (movie.runLength < 0)
                    {
                        std::cout << "ERROR: Run length must be at least 0" << std::endl;
                        //movie.runLength = 0;
                    }
                } while (movie.runLength < 0);

                std::cout << "Enter release year (1900-2100): ";
                /*std::cin >> movie.releaseYear;*/

                //ReleaseYear >= 1900 and <= 2100
                /*if (movie.releaseYear < 1900)
                {
                    std::cout << "ERROR: Release Year must be al least 1900" << std::endl;
                    movie.releaseYear = 1900;
                }
                if (movie.releaseYear > 2100)
                {
                    std::cout << "ERROR: Release Year must be no more than 2100" << std::endl;
                    movie.releaseYear = 1900;
                }*/
                // if (A && B || C && D)        They do not share precedence
                // if ((A && B) || (C && D))    Use this for clarity and proper intention
                // if (A || B && C || D)
                // if ((A || B) && (C || D)     Use this for clarity and proper intention
                // When doing this, logical operators does short circuit evaluation. (A && B = A, B?) it skips out the evaluation to the right (How logical operations work) ( if A is F, then it all is false, B won't be checked, see table), vise versa for "||"
                while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
                {
                    std::cin >> movie.releaseYear;

                    if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
                    {
                        std::cout << "ERROR: Release Year must be between 1900 and 2100" << std::endl;                  // prec, /, (), unary, !, arith, relational, logical { && ||}
            //            movie.releaseYear = 1900;
                    }

                }

                std::cout << "Enter the user rating (1.0-5.0): ";
                std::cin >> movie.userRating;


                char isClassic;
                std::cout << "Is classic (Y/N)?: ";
                /*std::cin >> isClassic;*/

                //If statement
                //  if_stat ::= if (Eb) S
                //              [ else S];
                // Else always goes with immediately preceding if
                // 
                //Translate to boolean if input is Y then true
                //movie.isClassic = isClassic == 'Y' || isClassic == 'y'; // <= removes the need of an "if"

                //bool done = false; // declare it before a loop
                //while (!done)
                do
                {
                    std::cin >> isClassic;

                    if (isClassic == 'Y' || isClassic == 'y')               // <= This removes excess code from 'y'.
                    {
                        movie.isClassic = true;
                        //done = true;
                        break;
                    } else if (isClassic == 'N' || isClassic == 'n')
                    {
                        movie.isClassic = false;
                        //done = true;
                        break;
                    } else
                        std::cout << "ERROR: Must be Y or N" << std::endl;  // != Y, y, N, n        // We are goig to expand by using a different statement. (if_state ::= if (Eb), St, [else S(f);]

                } while (true);

                break;
            }
            //case 'E': /*std::cout << "Eddit not implemented" << std::endl; break;  */    // How to prevent fall through including the default. You need to use {} also, but it sometimes can be avoided like this.
            case MenuCommand::Edit: std::cout << "Edit not implemented" << std::endl; break;     // if needed another statement plus the break then use the block {}

            //case 'D': /*std::cout << "Delete not implemented" << std::endl; break;*/
            case MenuCommand::Delete: //std::cout << "Delete not implemented" << std::endl; break;
            {
                if (movie.title == "")
                    break;

                // Confirm
                std::cout << "Are you sure you want to detele '" << movie.title << "' (Y/N)? ";

                bool confirm = false;
                do
                {
                    char choice;
                    std::cin >> choice;
                    if (choice == 'Y' || choice == 'y')
                    {
                        confirm = true;
                        break;
                    } else if (choice == 'N' || choice == 'n')
                    {
                        confirm = false;
                        break;
                    }
                } while (true);

             // Delete
                if (confirm)
                movie.title = "";
                break;
            }


            //case 'V': /*std::cout << "View not implemented" << std::endl; break;*/
            case MenuCommand::View:
            {
                if (movie.title == "")
                {
                    std::cout << "No movies in library" << std::endl;
                    break;
                }

            //Display movie details
                std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
                std::cout << "Length (in minutes) " << movie.runLength << std::endl;
                std::cout << "Genre(s): " << movie.genres << std::endl;
                std::cout << "User Rating: " << movie.userRating << std::endl;

                // Conditional Operator
                // if (Eb), E = Vt, else E = Vf, Eb ? Vt : Vf
                // Replaces if-else when calculating a value, must understand what it is for future exams.
                // 
                //std::string classicIndicator = "No";
                //if (movie.isClassic)
                //    classicIndicator = "Yes";
                //std::string classicIndicator = movie.isClassic ? "Yes": "No";       // We're writing how we like it, compiler figures it out on its own. 
                                                                                //  Easy way to remove/not need if statements, for determining one or two possible values only.
                //std::cout << "Classic? " << classicIndicator << std::endl;  

                // First issue: Both Vf and Vt must be the same type, the type of conditional is the type of value is returning.
                // Here this is string. The compiler must determine which type is it at the same time at runtime. Type coersion won't work, so you could use typecast if necessary/possible.
                // 2nd: The compiler can't tell the expression if its a different expression, it won't bother guessing, and won't pick, to fix this then make it around a parenthesis.
                // Ex:
                std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;

                // if (movie.isClassic)
                 //   std::cout << "Classic? " << "Yes" << std::endl;         // doable but not maintainable.
                //else
                  //  std::cout << "Classic? " << "No" << std::endl;          // if (Eb), E = Vt, else E = Vf, Eb ? Vt : Vf (conditional operator) Anytime we need an expression for 2 other values we can use that.

                std::cout << movie.description << std::endl;
            }
            break;
            case MenuCommand::Quit: quit = true; break;
            //Everything else, that execute if that value from the switch expression from everything else.
            default: std::cout << "ERROR: Invalid option" << std::endl; break;

            //    if (choice == 'A' || choice == 'a')
            //    // TODO: Move addmovie logic here
            //    std::cout << "Add not implemented" << std::endl;
            //else if (choice == 'E' || choice == 'e')
            //    std::cout << "Edit not implemented" << std::endl;           //else if from a, e. d. v, will not show. 
            //else if (choice == 'D' || choice == 'd')
            //    std::cout << "Delete not implemented" << std::endl;
            //else if (choice == 'V' || choice == 'v')
            //    std::cout << "View not implemented" << std::endl;
            /*else
                std::cout << "ERROR: Invalid option" << std::endl;*/
        }
        // Were designed if if else is true only.For this, it will take an t time for your input be chosen ex: e
        // The more you do if,else, the slower will run.
        // Use switch, switch(E) { case Label1 : Statement;, case Label2 : Statement;, ... } It evaluates the expression then umps to the case statement which matches to the case value.
        // It only needs to evaluate the assignment and then jumps to that exact case that value matches too only once. Once found it executes that statement.
        // Logical operators
        //  log_expr ::= Eb log_op Eb
        //              | ! Eb
        //  log_op   ::= && ||              && (and), || (or), ! (not)      Evealuates the left side then right, and then joins them together. If condition is true and is also in the other, then both true.
        //  T       T
        // cond1 && cond2                   Truth table:        A       B       &&      ||      !A
        // cond || cond2                                        F       F       (F)     (F)     (T)
        // !cond1                                               F       T       (F)     (T)
                                            //                  T       F       (F)     (T)     (F)
                                            //                  T       T       (T)     (T)
            //if (isClassic == 'y')                                                         
        //    movie.isClassic = true;                   
        //Validate classic
        /*if (isClassic != 'Y')
            if (isClassic != 'y')
                if (isClassic != 'N')
                    if (isClassic != 'n')*/
        //if (isClassic != 'Y' && isClassic != 'y' && isClassic != 'N' && isClassic != 'n') //Simplified the code, but must need a boolean expression.
                        //std::cout << "ERROR: Must be Y or N" << std::endl;  // != Y, y, N, n
        // If statement: consists if(Eb) Statement; if that boolean expression is true, if false then we do nothing. And ONLY one statement. S = one statement
        // To do more than one statement: Use block statement {}. blockstmt ::= { S*} Perfectly legal for an if stament to be an if statement (nested "ifs")
        // Downside: the more it indence, the harder it is to read. And impacts performance.
        // Relational demo
        //// Relational operators (only six of them)
        //// They are binary operators: rel::op= Two boolean expressions and the return type is always a boolean, greater than, less than, greater than equal to, less than equal to, = =, !=
        //// rel_expr ::= Eb rel_op Eb => bool
        //// rel_op ::= > >= < <= == !=
        //// Operator precedence: Below arithmetic but above equality: ex: y = 4 + 5 > 9 - 3 (All are left associated)
        //// How bool works: Yes no scenario, or false and true for possible valuables, the language type can coeerse any type.
        //// If you not use a bool value
        //// Do not relly on the conversion to the bool type because it is not consistent to all values, never use a bool type as an integer.
        //// Both require the same type ut return a bullian, we use to use comparisons
        //bool isGreater = 4 > 5; // False
        //isGreater = 10 >= 3;    // True
        //int x = 10, y = 20;
        //bool areEqual = x == y; //Equality, False because they are not equal to 20
        //bool areNotEqual = x != y; //Inequal: The ! means not equal.
        //// Common C code for boolean since it didn't support it
        //// Ex: Of an incorrect way:
        //int isCorrect = 0; //False
        //isCorrect = 10;     // True
        //// Be very careful using int as a bool code.
        ////areEqual = x == y;            // false, because this is equality.   Every time you use this, assignment works, so its hard for the compiler to notice. Not gonna work really well. 
        ////areEqual = x = y;             // True, because this is assignment
        //// When comparing to constants put the constant first.
        //// One way to partically work around this: To work
        ////areEqual = x == 10;               // Compare a variable to the value 10, both are valid.
        ////areEqual = 10 == x;               // If you use an assigment, you will get a compile error, but we usually use two variables.
        //// Be very careful with equality with floating type (includes inequality) try not to use them
        //float f1 = 1 / 3;
        //float f2 = 100 / (100 / 30 * 100);          //Mathmatically these two expressions are the same value. (Mathematically equal), but the computer may not see it that.
        //// When using floating #s, you risk an infidentially small precision. Its possible that division on the rounding kicks in in #2, and now the numbers are not equal. They can be indecimally off, making them inequal
        //// Not recommended in some cases, won't notice until runtime.
        //areEqual = f1 == f2; //Mathematically equal
        //areEqual = f1 >= f2; // "Correct way"
        //// Is ok when using floating point with integers
        //f1 = 100.0;
        //areEqual = f1 == 100;       // True
        //// Other type, strings: works with relational
        //// Imagine we have 2 strings
        //// strings:
        //// Case sensitive: Case matters when using strings, so capital B x= b as a character
        //std::string firstName = "Bob";
        //std::string lastName = "bob";
        //bool isSingularName = firstName == lastName;
        //// We use them but not expecting them as intended to.
        ////Numeric comparison: They take the numeric value and compare it. Ex: Bob and bob, Capital B is 66, 80, 46, bob is 46, 80, 46
        //// #2: Its locale insensitive: English is different from other languages. (not really designed for sorting, won't work like how you expect)
        //// If you plan to do one, you can use string compare i
        //int result = _strcmpi("Bob", "bob");    //(A C verion)
        //// The issue is the return value, comparison is not a bool operation, it returns 3 possible values, string compare the left and the right and comes up with 3 values.
        //// Less than 0, equal to 0, or greater than 0, Ex: a > b, give value greater than 0, a = b, gives a 0, a < b, gives less than 0
        //
        ////isSingularName = _strcmpi("Bob", "bob") == 0; //Not equal != 0, issue is this is a C function.
        //
        //// Can't use C++ strings with C compare. lastName, or firstName
        //// Use .c_str() to convert C++ string to C
        //isSingularName = _strcmpi(firstName.c_str(), lastName.c_str()) == 0; // Not equal != 0, the correct way to do this.
    }
}