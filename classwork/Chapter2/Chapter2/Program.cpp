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

        // String literals are enclised in double quotes and represent text, new lines are not supported in string literals
        // Semicolns are statement terminators; a period at the end of a sentence

    std::cout << "Hello World"; // <- Known as a string literals "Hello World" Also it is a statement -> Does something, which an output for the user.
        // An expression is a calculation ex 4 + 5, when its run, its evaluated into a number of some sort (calculates a value) , its not a statements
        // And statements don't have values to different things.
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
}