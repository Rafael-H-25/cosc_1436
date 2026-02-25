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

    //Types
    // -Primitive types, size and range
    // The most basic data ypes provided by the language.
    // Integer types(whole numbers): char: 1 byte, -128 to 127, or 0 to 255, short: 2 bytes, -32768 to 32767.
    // int: 4 bytes, 2 billion (+-), long: 4-8 bytes, same as int or larger, long long:8 bytes +-9x10^18
    // Floating points: float: 4 bytes- 5-7 decimals precision, double: 8 bytes, 7-12 decimals (the default)
    // Boolean type: bool: 1 byte, true or false.
    // Character types: Char: represents a single character "a"
    // Void type: represetns absence of type, used for functions that don't return a value.

    // Operators: symbols that tell the compiler to preform specific mathematical or logical manipulations.
    // Assignment: used to store a value in a variable, left must be variable, and right side is the value or expression being stored.
    // +=, x= x+5, -= x=x-2, *= x=x*3, ect.
    // Arithmetic Operators: +,-,*,/,% (if using division, on int it discards the remainder, 2.5 => 2, must use float or double.
    // % only works on integers.

    // Constant: a data item whose value can't be modified once has been set. (read only)
    //Purpose: prevents accidental changes to crit data, taxRate, allows the compiler to preform optimizations
    // Tells it as a value that is fixed.
    // Syntax: to create a constant, you must use const. before or after the data type (const ind/double)
    // Must be initiallied at the moment of declaration.
    // Literals, fixed value writtten directly into the code, cant be changed or named. 35, "hello"
    // Constant, a named memory location with a fixed value, const int limit = 10;, can't be changed.
    // A named memory location with a chagable value, int score =0;

    // Output: is handled via streams, std::cout, part of <iostream>
    // Displaying output: sends data to the screen, using <<, and you can chain multiple items together in a single statement.
    // New line: moves cursor to the next line: \n or std::endl; (a manipulator that inserts a new line and flushes the output buffer.
    // Formatted Output: controls how #s and text look,
    // Header file: must include the <iomanip>
    // Manipulators: setw(n) sets the width of the next output field to n spaces., set precision(n) sets the number of sig figs or decimal places.
    // Fixed: forces set precision to count digits after the decimal point. cout << fixed << set precision(2);
    // left/right: aligns text within the width set by setw.
    // setfill(char) fills empty setw spaces with a specific character ex: -------------

    // Input: handled by the std::cin object which represents the standard input stream.
    // Getting input: to read data from user into a variable, use the extraction op (>>).
    // Issues with Reading Multiple Values: has 2 major gotchas: the whitespace problem and mixed types and leftover newline.
    // Trying to read a full name into a string variable, last name stays behing the input buffer and waits for the next input command.
    // When entering a number and enter, cin reads the number but leave the \n sitting in the buffer.Ex: cin >> getline(), \n will see that leftover \n.
    // Reading Strings Using getline(), to read an entire line of text (including spaces) use getline()
    // EX: getline(cin, variable_name).
    
    // Type Casting: the process of converting a value from one data type to another.
    // Type coercion: the auto conversion by the compiler iwthout the programmer's intervention
    //      Purpose: to allow operations between diferent types, results in a single, predictable data type.
    //  does promotion rule: int is moved to highest data type from the two types: int + double = double.
    // Type hierarchy: highest: double (or long double), long long, long/unsingned long, int/ unsigned int, short, char, bool.
    // Types of conversion scenarios: 
    // Promotion: moving from a lower rank to higher rank. no risk of lost data. into to double ex: int x =10, double y = x;
    // Demotion: higher to lower, with risk of data loss. double pi = 3.14, int x = pi;.
    // Explicit Type Casting (done mannual): forcing a conversion that the compiler won't do automatically.
    // C-style: (int)myDouble, C++: static_cast<int>(myDouble)  <= safer to use.
    // C-style: from C language. powerful but uses brute force (target_type)expression. ex: double pi = 3.1243, int truncatedPi = (int)pi
    // Short and easy to use but high risk.
    // Static_cast: C++ version to a safer visible way to handle conversions and is check by the compiler at compiler time.
    // static_cast<target_type>(expression): int total =100, int count = 8, double average = static_cast<double>(total) / count.
    // Static better/safer.

    // Operators:
    // Operator Precedence: rank, similar to pemdas, Postfix/scope (::, ++, --, (), []), Unary (!,+,-,++,--), Multiplicative (*,/,%)
    // Additive (+-), Relational (<, >, <=, >=), Equality (==, !=), and assignment (=, +=, -=, etc).
    // Associativity (tie breaker):if two operators have the same precedence, the associativity tells the compiler which way to read.
    // Ex: L-to-R, most opertators (+,-,*,/). R-to-L, assingment and unary operators: x=y=10 => x= (y=10) 
    // Overflow: when trying to store a value outside a data type's capacity, greater than max value, goes to lowest number.
    // Underflow: is opposite.

    // Math functions: advanced mathematical ops. beyond basic arithmetic (square roots, rounding, or absolute)
    // Header File: must include <cmath>
    // Common Math Functioms: most frequently used functions for manipulating #s. All typically take a double or float as an argument and return a double or float.
    // abs(x) Absolute Value.
    // round(x) standard rounding: round to nearest integer. If its 2.5 or 0.5, then rounds to the 2 or 0.
    // ceil(x) ceiling rounds up to the next whole integer, from 3.1 to 3.9 regardless.
    // floor(x): rounds down to previous whole integer. opposite of ceil.
    // Other Essential Functions: 
    // pow(base, exp) raises to an exponent (pow(2,3)=8.0, 
    // sqrt(x) calc the square root, qrt(25) => 5.0
    // max(a,b) returns the larger of two values, max(10,20) => 20
    // min(a,b) opposite of max(a,b)
 }