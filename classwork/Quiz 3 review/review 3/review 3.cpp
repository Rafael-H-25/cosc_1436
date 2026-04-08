
// Functions chapter 6:

//Purpose and benefits of a function
// 
// 
//Syntax for function declaration and definition
//
// 
//Parameters
//
// 
//      Purpose of parameters
// In function: with in that {} it refers double x = 10 and not int x.
// 
// We can redeclare its presence.    
//      Declaring and using parameters
//  
//      Parameters vs arguments
//  arguement is part of the expression value
//      Calling a function with arguments
//
//      Parameter kinds(input, output, input / output)
// 
// input/output : caller provides the value, the function returns something. The caller sees any changes.
// Delcare the pass by reference. Pass it (a variable ex)
// 
// Output: The caller passes nothing, the function returns something, and allows the function sends data to the caller.
//  (return type, one value.)
//          Syntax in C++
//
//          What you can do with each kind
//
//          Passing arguments to each kind
//
//      Returning a value from a function
//
//Callstack
// Lowest main, func, bar (local variables).
// 
//      How it works and what is stored on it
//
//      What happens when too many function calls occur
//  stackoverlow: it can be very small, or a recurisive function
//  memory gets corrupted, then the callstack will then fall along with it.
// 
//Forward declarations / function prototypes
//  
//      Purpose
//
//      Syntax of a function declaration
//
//      Declaration before usage rule
//
//Scope
//
//      Scope of parameters and local variables
//      
//      Global variable scope
//  
//      Overriding variables in outer scopes
//
//Recursive functions
//
//      Why
//  To solve recursive problems, walking a tree, to get to somewhere I need to.
//      Issues with unrestrained recursive calls
//
//Function overloading
// name to get the overloads and the order.
// never pay attention to the return type in overloading. example below.
//      Purpose
//
//      Function signatures
// 
// Prototyping:
// The function name, the overloads, the return type.
// Must declare the function before it to work.
// 1st) bar 
// 
// Question on quiz: Answer: htps://www.microsoft.com

// Function overload ex:
//  int Display (int)
//  double Display (double)
// double result = Display(20)
// The one used is int as its best preffered.
