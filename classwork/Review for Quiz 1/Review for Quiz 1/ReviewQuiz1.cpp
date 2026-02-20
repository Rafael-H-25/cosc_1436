/*
*
*
*/
#include <iostream>

void main()
{
    // 20-25 questions
    // muliple choice (all), questions are randomly ordered.
    // Black sheet, wort needed but its there, no studio etc.
    // No trick question, but could have two answers but must pick best answer from both answers.

// Parts of C++
    // Tokens vs Keywords
    // Tokens, examples, and use cases:
    // The smallest individual units of a program that the compiler can recognize and process. 
    // Serves as the fundemental building blocks of the language's syntax. 
    // Types of Tokens:
    // There is 6 main categories that are classified in C++ for Tokens:
    // Keywords, identifiers, constants (or literals), strings, operators, and puctuators/special symbols.
    // Ex: "int/if/while", "variables like firstName", "10, 3.9, A", ""Hello"", "+, ==, <=", and ";, {}"
    
    // Keywords, examples, use cases:
    // Are reserved words that have a predefined meaning for the compiler. Can't be uses as identifiers (variable or function names).
    // Categories commonly used: 
    // Fundemental data types: int, double, bool, void
    // Control flow: if/else, for/while, switch/case
    // Object-Oriented Programming: used to define and manage classes and objects.

    // Single and multi line comments:
    // Single Comments: used to add brief notes or temporarily disable specific lines of code.
        // Symbol is "//"
        // Scope: anything following is ignored by the compiler.
        // Termination: ends at the end of the line.
    // Multi-line comments: used for longer longer descriptions or to disable entire sections of code.
        // Symbol is "/*, */" (start, end)
        // Scope: Everything between them is ignored by compiler, including dozens of lines.
        // Can be used in the middle of a line of code. ex: int x = 5 /* initial value */ + 10

    // Literals including strings and integers:
    // Literals and types of literals: are fixed values written directly in the source code, and can't be changed.
        // Integer literals: whole numbers and can be written in different number systems (bases)
            // Decimal: standard way (47, -7) 
            // Hexadecimal: starts with 0x or 0X and uses 0-9 and A-F (0x2A "42 in decimal")
            // Binary: starts with 0b or 0B (not important)
        // Floating-Point Literals: represents numbers with fractional parts (decimals)
            // Standard Notation: uses decimal point (3.14, -0.9)
            // Scientific Notation: uses e or E to represent x 10^n, (2.5e3)
            // Suffixes: float, double.
        // String: represent a sequence of characters:
            // Standard: Enclosed in double quotes "Hello world"
            // Escape Sequences: used to include special characters within a string (\n, \t, \")
        // Character Literals: represents a single character
            // Standard: in single quotes 'A', '7', '$'
        // Boolean: True or False.

    // Case sensitivity rules: 
    // Case sensitivity: It is absolute, compiler treats uppercase and lowercase letters as an entirely different characters
    // Applies to: keywords, variables, functions, and every other identifier.
        // Variables and Identifiers: different casing creates entirely seperate memory locations. (value=10, Value= 20)
        // Keywords: must be lowercase, and if you capitalize them, the compiler won't recongnize them and will likely throw an error (if, while (Yes), If, While (No).
        // Function names: The name used in the function definition must match the call exactly "calculateData".
        // Headers: #include <iostream>, not #INCLUDE <IOSTREAM>. Use lowercase for standard headers.

    // #include:
    // A preprocessor directive used to insert the contents of another file into your currect source file. (preforms a "copy and paste" operation before the actual compiltation begins.
        // Put them first before building the code. And doesn't end in a semicolon.
        // Examples: #include <(iostream, string, iomanip, thread, future, memory, cmath, set, and more)


// Variables:
    // Essentially a named location in the computer's memory. (A labeled box where you can store, retrieve, and modify data during the execution of your program)
    // Purpose: Data storage, labeling ( taxRate = 0.09, float total = price + (price * taxRate), Data manipulation, memory management, and reusability. 
    
    // Declaring single variables: Specify the type, followed by a unique name, type (int, double, short) variable_Name.
    // Declaring multiple variables: declaring several variables of the same type in a single line to keep the code concise. type var1, var2 ect.

    // Initializer expressions: the process of assigning an intial value to a variable at the moment it is created.
    // Initializer expression is the actual value or logic provided to set that starting state. int x "= 10, (10), {10}, {}"
    // Complex Initializer expressions: doesn't have to be a simple #, it can be a calculation, fuction call, or another variable.
    // int double = 10 * 2, int width = 5  int area = width * 10, double root = sqrt(25.0).

    //Identifier rules: If broken, code won't compile
    // Allowed characters: (a-z, A-Z), (0-9) underscores"_" permitted. Not 1score, Yes score1.
    // Not correct: No key words (int, double, etc), No special characters: @#$%^, Case sensitivity: myVar, MYVar.
    // Underscore (if used): Avoid double "_", avoid using _Var, use var_id as shown.
    // Make it descriptive to explain the data.

    // Scope: a region of a program where a variable is "visible" anc can be accessed. Once a variable goes "out of scope" it's destroyed, and memory is reclaimed.
    // Local Scope: {}, varaibles declared inisde a function or a pair of this "{}" and are local to that block.
    // Life time, created when block starts and ends/is destroyed from }. Visible during the {}.
    // Global Scope, declared outside all funcitions, check the start of this solution.
    // Class and namespace Scope: declared within a class (members or fields), and variable or functions declared inside a namespace block.
    // Ex: namespace Game { int score = 0; }

    
    
    
    
    
    // The quiz questions are not focused at syntax, which code block does this and reading code, and academics side.

    // Literals: 10 or a name. Read only, anywhere the value is baked into the source code.
    // Variables: has a name.
    // both expressions, and two data points (value and type) lacking a name.

    // Header file, Cmath. 
    // Getline, and why use: read it in a string, cin when put into 2 values, it always stop at a space. 10_20, Bob_Miller \n.
    // Type casting: difference. One is C based, other is C++. (type cast and expression), static cast is longer and is guaranteed to fail, C style will alolow anything to anything (more free but your responsible to that).
    // Variable: needs to be declared and assigned to a value, or just inititialed a value to 0 to not worry about that variable.
    // Formatting command: setw(#), setfill('') and uses ay character as, fixed forces fixed point notation, setprecision, sets the precision of a decimal point #, if not fixed left and right side, if fixed then after the decimal.
    // Not percistent is setw.
    // Left, right, which side the patting goes to. Right is default.
    // 
    // Assuming the # is the largest #, short ex: and add a 1, it goes over and goes negative.
    // OverflowAssuming the # is the largest #, short ex: and add a 1, it goes over and becomes the largest negative #.
    // Underflow: is the smallest possible and subtract 1 from it and wraps around and becomes the largest #.

// Celling and floor in math fuctions:
// ceil(x) [x]=: the smallest int >= x
// floor(x) [x]=: gives the largest int <= x


}