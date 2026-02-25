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

    int runLength;      // >=0
    int releaseYear;    // 1900 to 2100

    double userRating;  //1 to 5

    bool isClassic;

    std::string description; //Optional (summary)
};

void main()
{
    //Basics: define a movie. Name/Title (string), genres (string+), length (timr), actors (string+), directors (string+), release date (date), mpaaratings (string), userrating (double, int) etc. #1. 
    // We ignore Actors and directos, the ratings, time and date we can't use, so adjust definition. Length is minutes (int), dates => release year (int), Isclassic (bool)

    // Display menu (simple)
    std::cout << "Main Menu" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "A)dd Movie" << std::endl;
    std::cout << "E)dit Movie" << std::endl;
    std::cout << "D)elete Movie" << std::endl;
    std::cout << "V)iew Movie" << std::endl;
    std::cout << "?";

    char choice;
    std::cin >> choice;

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

    switch (choice)
    {
        // TODO: Move addmovie logic here
        case 'A':
        //{
        //    //choice = 'a'
        //    //std::cout << "Hello";
        //    std::cout << "Add not implemented" << std::endl;
        //    break;
        //}
        case 'a': std::cout << "Add not implemented" << std::endl; break;     // Easy to read, and maintainability. The restrictions:

        case 'E': /*std::cout << "Eddit not implemented" << std::endl; break;  */    // How to prevent fall through including the default. You need to use {} also, but it sometimes can be avoided like this.
        case 'e': std::cout << "Eddit not implemented" << std::endl; break;     // if needed another statement plus the break then use the block {}
        
        case 'D': /*std::cout << "Delete not implemented" << std::endl; break;*/
        case 'd': std::cout << "Delete not implemented" << std::endl; break;
        
        case 'V': /*std::cout << "View not implemented" << std::endl; break;*/
        case 'v': std::cout << "View not implemented" << std::endl; break;

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

    // Add movie logic
    Movie movie;
    // Reset input buffer
    std::cin.ignore(INT32_MAX, '\n');

    //: Prompt for movie details
    std::cout << "Enter title (required): ";
    std::getline(std::cin, movie.title);

    //: Validate title
    if (movie.title == "")
        std::cout << "ERROR: Title is required" << std::endl;

    std::cout << "Enter description: ";
    std::getline(std::cin, movie.description);

    std::cout << "Enter genres: ";
    std::getline(std::cin, movie.genres);

    std::cout << "Enter run length (in minutes): ";
    std::cin >> movie.runLength;

    //Runlength >= 0
    if (movie.runLength < 0)
    {
        std::cout << "ERROR: Run length must be at least 0" << std::endl;
        movie.runLength = 0;
    }

    std::cout << "Enter release year (1900-2100): ";
    std::cin >> movie.releaseYear;

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

    if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "ERROR: Release Year must be between 1900 and 2100" << std::endl;                  // prec, /, (), unary, !, arith, relational, logical { && ||}
        movie.releaseYear = 1900;
    }

    std::cout << "Enter the user rating (1.0-5.0): ";
    std::cin >> movie.userRating;

    char isClassic;
    std::cout << "Is classic (Y/N)?: ";
    std::cin >> isClassic;

    //If statement
    //  if_stat ::= if (Eb) S
    //              [ else S];
    // Else always goes with immediately preceding if
    // 
    //Translate to boolean if input is Y then true
    //movie.isClassic = isClassic == 'Y' || isClassic == 'y'; // <= removes the need of an "if"
    if (isClassic == 'Y' || isClassic == 'y')               // <= This removes excess code from 'y'.
        movie.isClassic = true;
    else if (isClassic == 'N' || isClassic == 'n')
        movie.isClassic = false;
    else
    {
        std::cout << "ERROR: Must be Y or N" << std::endl;  // != Y, y, N, n        // We are goig to expand by using a different statement. (if_state ::= if (Eb), St, [else S(f);]
        movie.isClassic = false;
    }
        //if (isClassic == 'y')                                                         
    //    movie.isClassic = true;                   

    //Validate classic
    /*if (isClassic != 'Y')
        if (isClassic != 'y')
            if (isClassic != 'N')
                if (isClassic != 'n')*/
    //if (isClassic != 'Y' && isClassic != 'y' && isClassic != 'N' && isClassic != 'n') //Simplified the code, but must need a boolean expression.
                    //std::cout << "ERROR: Must be Y or N" << std::endl;  // != Y, y, N, n
    
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