/* 
* File header
* Name
* Lab #
* COSC 1436 Spring 2026
*/
#include <iostream>

// token - word in a program ,void, main
// keyword - a word that has special meaning to the language example void (all lower case)
// identifier - word that has special meaning to you (Starts with an Upper case)
// puncitators - () {} + -
// comments - Annotations about the code, compiler ignores them
// pre-processor directives - Removed before compilation, always start with a #

// how to write comments in C++
// Two approaches to coments
// Single line -> // ... (end of line)
// Coments can be put anywhere, even in the end of a line
// Multi line -> /* ... */

/* This is a multi line comment
* Continuing the comments
* Yet more comments
*/

// Some rules
// - Case sensitive
// - Keywords are lower cases
// - Whitespace doesn't matter except between 2 tokens. Don't put too much white space
// Code is alot like writing example book or essay
// - Code runs top down
// - Source lines not equal to executable code in all cases
//Anotation is very important

void main()
{
    //Indent once each time you enter a block
    // All of code in  that block indent the same
    
    // TODO: Remember to change this, comments can be used to remind things
   std::cout << "Hello World";  //A single line comment

   // 4 + 5 prefer this over 4+5 because its easy to read

   //Block 1 - logical operation
   // 
   //Block 2 - next logical operation
}