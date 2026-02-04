/*
* Chpater 2
* COSC 1436 Spring 2026
*/
#include <iostream>

// #include is the first processor plant
// how it works, when it runs it strips out the line of the file which is "iostream"

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
    int length;
    int width;
    int perimeter;

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
    
    //unsigned types are always positive from 0 to the byte range.
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
    // They can be very complicated ex: 3.15





}