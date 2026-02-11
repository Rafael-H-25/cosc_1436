/*
* Chpater 2
* COSC 1436 Spring 2026
*/
#include <iostream>
#include <string>
// #include is the first processor plant
// how it works, when it runs it strips out the line of the file which is "iostream"

// Custom types
struct Point
{
    // Declare the variables that make up the type
    int x;
    int y;
};
// This is how to declare a type
// Point type has 2 data points, they are no longer seperate, we can treat them as singular value.
// 

//Entry point of your progress
void main()
{
        //What main does

        //Display output
        // Literals are constant
        // String literals are enclised in double quotes and represent text, new lines are not supported in string literals
        // Semicolns are statement terminators; a period at the end of a sentence


    std::cout << "Hello World"; // <- Known as a string literals "Hello World" Also it is a statement -> Does something, which an output for the user.
        // An expression is a calculation ex 4 + 5, when its run, its evaluated into a number of some sort (calculates a value) , its not a statements
        // And statements don't have values to different things. 
        // S = Statement (does something)
        // E = Expression (value)
        // T = type
        // id = identifier
        // You can change additional expressions as long as you chain out multiple expressions cout << E << E2 << E3
    std::cout << "Hello World" << std::endl;
    
    std::cout << "Hello" << "World" << std::endl;
    std::cout << "Hello" << " " << "World" << std::endl;

    // Escape sequence - only usable inside string literals
    //   Start with a slash followed by a special character "\c "
    //   \n - new line
    //   \" - double quote
    //   \\ - slash
    std::cout << "Hello World\n";
    std::cout << "Hello\tWorld\n";
    std::cout << "Hello \"Bob\", How are you" << std::endl;
    std::cout << "C:\\Windows\\Stystem32" << std::endl;

    // 4 + 5 = 9 integer literals - 4, 5 , 8 (whole numbers)
    std::cout << 4 << " + " << 5 << " = " << 4 + 5 << std::endl;

    // Floating point literal - fracional numbers (3.32)
    std::cout << 4.5 << " * " << 6.7 << " = " << 4.5 * 6.7 << std::endl;

    // Variables - Named memory location where data is stored. (Also an expression) Used for reading and writing and dataS
    //Prompt user for their name
    std::cout << "Enter your name: ";
    
    std::string name;
    std::cin >> name;   //TODO: Talk about this in chapter 3
    
    //Print out user's name
    std::cout << "Hello " << name << std::endl;

    // varaiable_decl ::= T id;
    //variable identifiers: (var id) are always nouns and are they descriptive to store them.
    // variables represent data, values are allways nouns, are descriptives and have no abreviations or acronyms. We use good descriptive names.
    // Descriptive names to identify the variable, between 5-12 characters
    // Important Rule for Identifier:DO NOT USE A SINGLULAR character for a variable. includes double letters. H = Hotel, Heat. (Don't do).
    // ex: First Name or Paygrade- good.
    // ex: first Nm- no abreviations or acronyms
    // Rules of an Identifier: All identifiers are  with letters "or" an underscore. id ::= (letter | _)
    //Continued: * (zero or more) + = one or more (letter | digits | _)* or +
    
    // Compound words: Names by itself is not desriptive, ex John
    // ex: firstname, lastname
    // Issue: it puts too much stress firstname, the more you do, the more tired your head is.
    
    // Compound words are made to break down words. the prefered approach is to use word boundaies. ex firstName, FirstName
    // ok: firstname, lastname
    // better: firstName, FirstName
    // worse: first_name, last_name, rest_of_name
    // We will use casing: for variable identifiers, we wil use camel casing. Means capatilize on word boundaries expect the first word.
    // ex: payGrade, restOfName. This is how C++ Programmers write code and is universaly used.
    // If you type a lower case letter, the edditor will help you to find the variable you want. And if you do then hit tab on the one you need.

    // Exceptions of the identifier words: You cant use it as a keyword. Most keywords are verbs.

    // Type side: (T) - it determines 2 things about a variable, what kind of data you can store and the size of the data.
    // Type is very important to variables.
    // The compiler can tell a variable based on a type.
    
    // Variables must be declared before they can be used.
    // The variable comes to existance when it exists at the point of declaration.
    

    int age;
    // This variable stores an interval value for age.
    double payRate;
    // This declares that it stores a fractional number.
    // A rule for variable declarations: id cannot already exist. You can't declare age ever again twice. You can't change it to any type. Its a compiler error.
    
    //Compiler error - can't redeclare a variable

    // Student name
    std::string firstName;
    std::string lastName;

    //Perimeter of a rectangle
    //int length;
    //int width;

    int length, width, perimeter; // You are declaring this to the compiler, you are making this easier.
 /*   int perimeter;*/
    // You can also do all of them too. This includes the firstName and lastName.

    // Write to a variable using the assignment operator
    length = 10;
    width = 20;
    // Once this value executes, the value will be 10.

    std::cout << length;

    // The remaining types:
    // The type to delclare our variable
    // There are primitive type. primitive : understood by the language

    // The types, their size/bytes, and range.
    // byte = the smallest atomic value a computer can type. A single byte can store 256 values.
    // type, "short" is the smallest type, 2 bytes, range is + or - 32k can store numbers from -32768 to 32767. the negative is larger than the positive by one.
    // An "int" is 4 bytes from + - 2 billion
    // "Long" is 4 bytes from + - 2 billion
    // These are the signed types (being positive or negative)
    
    // unsigned types are always positive from 0 to the byte range.
    // unsigned short 2, 0 - 64 k
    // unsigned int 4, 0 - 4 billion
    // unsigned long 4, 0 - 4 billion
    // We won't use them for class. We will ignore them.

    // use "int" since its simple to use and won't confuse you easily. If you need to store a whole number use "int".

    // Literals: is an expression, every expression must have a type. The compiler knows every type of expression. For expression we care for the type. We must know what type an expression it is.
    // ex of literals, 95 or 4, it is automatically typed as "int" if its a stored whole number.
    // 5L is about "long". If you have a integer with a letter its a "long".

    // Floating Points: Fractionals (we care about float and double) 4 bytes, 8 bytes.
    // If you need to store fractional values ex: 3.32, use float and double.
    // They can be very complicated ex: 3.14159. They have a rounding factor for all floating point value.

    // the range such as e+-38,
    // for a floating digit it's precision is 5 to 7 then errors past there.
    // Floats are sueful for small numbers

    // Double has a range of e+-^308, but its precision is 12-15. (floating value numbers)
    // We care more about the precision. Stick to double.
    // Floating point literals. If you see one, the compiler sees it as a double.

    // bool: Takes a byte, range is false or true. Yes, no value, thats whats its used for. Has the student 
    // Don't use "int"

    // Char (Care): Represents a single character: takes up only one byte, the range is -128 to 127. ex: a or +
    // It's an integer type, we don't see it as it, but if you need single character value use "Char"

    // Dates are not primitives in this.

    // Type
    //  primitives : understood by language
    // Type     Size (Bytes)    Range
    // -------------------------------
    // Signed Intergrals
    // --
    // short    2       +-32k (-32768 to 32767)
    // int      2       +-2 billion (default for whole numbers and literals)
    // long     4       +-2 billion
    
    // Unsigned Integrals (reference purposes only)
    // --
    // unsigned short      2           0 to 64k
    // unsigned int        4           0 to 4 billion
    // unsigned long       4           0 to 4 billion
    
    // Floating point
    // --
    // float    4       e+-38,  5-7 digits after the decimal precision (maximum)      (+- 38 = 10^38 exponent)
    // double   8       e+-308, 12-15 digits after the decimal precision (default for fractional values)
    
    // Other
    // --
    // bool     1       false, true
    // char     1       -128 to 127, single character    (default for char literal) (char is said as care)

    int hoursWorked; // hours worked in past week
    hoursWorked = 25;

    //Store class average on a quiz
    double classAverage; // or classQuizAverage
    classAverage = 78.9;

    //Store letter grade for a student
    char letterGrade;
    letterGrade = 'A';

    //Store first time in college
    bool firstTimeInCollege;
    firstTimeInCollege = true;

    // Assignment
    //      l-value = r-value
    length = 50;
    width = length;
    // asn_stnt::= E = E;       E = string literals and/or variables
    // L-value expressions is allowed on the left side, it must be an L-value, the right side must r-value. (l=left, r=right)
    // r-value: any expression that can be read.
    // L-value: something I can write

    // Assignment ::= E = E
    //      l-value = r-value; only variables are l-values

    //Types do not exist at run times, at run time it is a series of bytes, the run time interperts the bytes based o your variable.

    // ex: int level; (level = 65) the system sees 65, if you write 50, then the system sees 50.000 (extra zeros)
    // Every time you declare a variable 

    // Zero-init variables before use
    // Can't read vaiable before definitely assigned
    // Definitely assigned
    //   Assignment
    //   std::cin
    int someVariable;
    someVariable = 0;
    //int someVariable; someVariable = 0;

    // Read an int from user
    //std::cin >> someVariable;
    
    int anotherValue = 10, anotherValueAgain = 20;
    
    // If you don't assign a value, then the compiler will make a error. The language will never allow you.
    std::cout << someVariable;

    // Don't modify your program when debugging

    //Breakpoint: it tells the debuger to pause and to see what is going on.
    // Click on the line select the line and F9
    // To remove it click on the same line F9 it

    // Select on step into (F11) and Step Over (F10)
    // Red shows that those values changed
    // If your variables are not right, then your program is wrong. -End of class 2/3

    // id ::= (letter|_) {letter|digit|_}*
    // var_decl ::=    T   id [= E]{, id[= E]};
    // asn_stnt ::=  E(underscore T) = E(underscore T)
   
    // The 5 Arithmetic operators

    // +,-,*,/ (add, subtract, multiply, divide)   4 + 5 = 9, 10 - 3 = 7, (binary operators)
    // binary operator: has 2 operants
    // binary_op = E op E
    // arith_op = + - * / %
    // Language requires the exact same type. the type of that equation will be T
    // ex: if the lant operant has an int on the left, the right must be an int.

    // modulus   
    int quotient = 10 / 3;  // interger division problem: int/int => int
    // int / int => int (10 / 3 = 3, the 0.3333 is removed.)


    // modulus is the remainer when you divide 2 ints (its the only type) only applies to the ints
    int remainder = 10 % 3; // 1

    // 2 uninary operator: only has a single operan: unary: = + or -
    int negativeRemainder = -remainder;
    quotient = +quotient;

    double actualQuotient = 10.0 / 3.0;     // double / double -> double, now we will get the 3.33 value

    // Length, Width, Perimeter

    //Calculate perimeter of rectangle
    std::cout << "Enter length? ";
    std::cin >> length;

    std::cout << "Enter width? ";
    std::cin >> width;

    // P = 2L +2W
    perimeter = length + length + width + width;
    std::cout << "Perimeter = " << perimeter << std::endl;

    // Scope: of a variable is effectively its lifetime, its "how long can I use it?", how long is it good for. Are avaliable from declaration until the block that containst it ends.
    // starts at "{" on its block, any variable defined until it ends until it gets to "}" ends on block that declared it
    int aLocalVariable = 0; // Declaring a variable here
    aLocalVariable = 10;

    // Start a new block by using "{ and }"
    // each block is distict for every outher block
    {
        double blockVariableA = 0;
   
        // Inside of this block you have all access in this block, you can nest to each block, and you can nest to that block's block
        // Can access var declared in block + any parent blocks
        blockVariableA = 10;
        aLocalVariable = 20; //We can use this in this block, but not VariableA

        double length;
        length = 80;
    }

    std::cout << length << std::endl;
    //blockVariableA is no longer accessible
    //If you need a variable, keep he scope minimal as possible.
    //How to manage it, declare it inside the scope of that block shown in line 294 to line 301
    //Used for more complex code. A child block can redeclare a parent block

    // Dont recommend doing this as it is very confusing right now.
    // Redeclaring a avariable in a block is strongly not recommended.
    // Point of declaratio to the point of the block it ended in. { to } - On the quiz

    //- C++ strings: std::string <-- not a keyword,
    //- It is atype to use but its not a primitive of a language type like others.
    //- This is only avaliable in C++ (usable in C++) Don't use this in other languages. Really easy to use, acts like a primitive type
    //- Use = for assignment
    //- Use + for concatenating 2 string values
    std::string someStringValue;
    someStringValue = "Bob";
    someStringValue = someStringValue + " How are you?"; // We will be using them often. If you use C++, you must always include (#include <string>)

    // Assignment- it is also an expression as well
    // We can write "x = 5"     5 is an int, and x mush be an int, so the expression is an int.
    // We can say it as "x = y = 5;"
    // The value of your expression is whatever the value of the expression. we can chain primary use cases.

    // Value is value of variable after assignment. Everything except the last value is a variable.
    // Can chain assignment together
    length = width = perimeter = 0;
    
    // Named Constants:
    // Literals- Constants. I can only read them, has a value and is fixed at a compilled time, its signed type "int", if its float type it's "double", single "char", value is whatever the variable is
    // It is unmaitainable
    
    // Variables- Value and a type, and a variable. Easy to maintain but the program will use them also.
    // literal: 25 (fixed at compiled times)
    // Variable :
    // const_decl ::= const T id = E; 
    // Casing: Pascal or all uppercase for const. Pascal = all words are capitilized
    // Must be a compile time constant - must be calculatable at compile time
    // - Literals
    // - Simple math expressions with constant expressions
    //      4+5, MaximumStudents, MaximumStudents - +10
    const int MAX_SIZE = 25;
    const int MaximumStudents = 50; // You can change the value if needed at any time

    //Change value at runtime
    //MaximumStudents = 40; //Dont use variables for constant values

                          
    int largestNumberOfStudents = 25; //Using the literal
    //largestNumberOfStudents = maximumStudents; // Using the Variable
    largestNumberOfStudents = MaximumStudents; // Using the Constant
    
    // Named constants: they sit in the middle of literals and variables, gets some of both, good and bad.      (const)
    // They are fixed at compiled time, they have a value and a type, and a name
    // Any attempts to write to it will fail. The compiler will fail the call.
    // Purpose: we wil soon use named constants
    // A constant in C++ means the value as its fixed at the point of compulation. the literal value remains, the constant goes away

    // Create abd get input for a point
    // Declare a variable
    Point left; //Now we can propt the user for the X value

    std::cout << "Enter the X value: ";
    std::cin >> left.x; 
    // You need to specify which field value, the dot is the operator, consists of whatever the type is, followed by the expression followed by the type.

    std::cout << "Enter the Y value: ";
    std::cin >> left.y;

    std::cout << "(" << left.x << ", " << left.y << ")" << std::endl;

    // Left literals: Value and type,
    // Right Variables: Name, value, and type, rewrite
    // Middle Named Costants: name, value, and type. Read only (things that won't change because of maintainability) const Type and id=E keyword constant
    // Compilte time constant: literals, simple, named constants. One is value, and one can represent a constant.

    // 
}