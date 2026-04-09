// Functions chapter 6:

//  1. Function Fundamentals & Syntax
//  Purpose & Benefits: Functions allow for modularity, breaking complex programs into smaller, manageable units. They promote reusability (write once, use many times) and improve readability by giving names to specific tasks.
//  (Think of a function like a recipe. Instead of writing out "how to make a cake" every time you want one, you just call the "MakeCake" function.)
// 
//  Declaration vs. Definition:
//      (In C++, the compiler is picky. It needs to know a function exists before you use it.)
//      Declaration (Prototype): Informs the compiler about the function's name, return type, and parameter types before it is used. It does not contain the body.
//      (Like a "heads up" to the compiler. It has the return type, name, and parameters, ending with a semicolon.)
// 
//          int add(int a, int b);
// 
//      Definition: Provides the actual implementation or "body" of the function (the code within {}).
//      (The actual code inside the curly braces.)
//          int add(int a, int b) { return a + b; }
// 
//  Returning a Value: The return type specifies what kind of data the function sends back to the caller (e.g., int, double).
//          A void return type indicates no value is returned. [1, 2, 3, 4, 5] 
//
//  2. Parameters & Arguments
//  Definitions:
//      Parameters (Formal): Placeholders defined in the function header (e.g., void func(int x)).
//          (These are the holes in the mailbox (defined in the function header).) 
//          (They are placeholders like int x.)
// 
//      Arguments (Actual): The actual values passed to the function during a call (e.g., func(10)).
//          (These are the letters you actually drop into the holes when you call the function.
//              Like add(5, 10). Here, 5 and 10 are arguments.)
// 
//  Parameter Kinds (Input, Output, I/O):   (This is how data moves in and out of your function)
//      Input (Pass-by-Value): The function receives a copy of the argument. 
//          Changes inside the function do not affect the original variable.     
//      (void func(int x). The function gets a copy.
//      If the function changes x, the original variable outside stays the same.
// 
//      Output/Input-Output (Pass-by-Reference): Uses the ampersand (&) syntax (e.g., int &ref).
//              The function works directly on the original variable's memory address, allowing it to modify the external value. [3, 4, 6, 7, 8] 
//          void func(int &x). Notice the &. This gives the function the "address" of the original variable.
//          If you change x inside, it changes the original outside too.         
//      
//      Output: In C++, we usually use references or pointers to "output" multiple values since a function can only return one thing.
// 
//  3. The Call Stack
//      How it Works: C++ uses a LIFO (Last-In, First-Out) structure to manage function execution. 
//          When a function is called, a stack frame is "pushed" onto the stack.
//  Think of a stack of plates. When main() calls func1(), a plate for func1 is put on top.
//          When func1 calls func2, another plate goes on top.
// 
//      Storage: A stack frame typically stores:
//          Function parameters and local variables.
//          The return address (where the program should resume after the function finishes).
// 
//      Stack Overflow: Occurs when too many function calls are made without returning (most common in unrestrained recursion)
//              exhausting the stack's allocated memory. [3, 9, 10] 
//  If you keep adding plates (too many function calls) without ever taking them off,
//      the stack runs out of room and the program crashes.
// 
// 
//  4. Forward Declarations:    (C++ reads your file from top to bottom.)
//      Purpose: To satisfy the Declaration before Usage rule. C++ compiles from top to bottom;
//          if a function is defined after main(), it must be declared before main() so the compiler recognizes the call.
//  If main() tries to call calculate() but calculate() is written at the bottom of the file, the compiler will error out.     
// 
//      Syntax: A prototype consisting of the return type, function name, and parameter types, ending with a semicolon 
//              (e.g., int add(int, int);). [3, 10] 
//      Put a Forward Declaration (the prototype) at the very top. This satisfies the "Declaration before usage" rule.
// 
//  5. Scope & Visibility:      Scope determines where a variable is "alive."
//      Local Scope: Parameters and variables declared inside a function are local to that function. 
//              They are created when the function starts and destroyed when it finishes.
//      Variables created inside a function {} only exist there. Once the function hits the }, those variables are deleted.     
// 
//      Global Scope: Variables declared outside all functions are accessible throughout the entire file.
//      Variables created outside of all functions (at the very top). They are "immortal" and can be seen by every function.      
// 
//      Overriding (Shadowing): If a local variable has the same name as a global one, the local variable "shadows" or overrides the global one within that function's scope. [3, 6, 9, 11] 
//
//  6. Advanced Execution   
//      Recursive Functions: A function that calls itself to solve a problem. (A recursive function is a function that calls itself.)
//          Why: Useful for tasks with a naturally repeating structure (e.g., factorials, tree traversal).
//      It’s great for math (factorials) or searching through folders inside folders.
//         
//          Issues: Without a base case (an exit condition), recursion will continue infinitely, leading to a stack overflow.
//      You must have a Base Case (an "exit strategy"). If you don't tell the function when to stop calling itself, you get a Stack Overflow.
// 
//      Function Overloading: Creating multiple functions with the same name but different signatures.
//      You can have two functions with the exact same name, as long as their Signatures are different.
// 
//      Function Signature: Determined by the function name and its parameter list (the types and order of parameters). 
//          Changing only the return type is not enough to overload a function.
//      This consists of the function name + the types of parameters.
// Function overload ex:
//  int Display (int)
//  double Display (double)
// double result = Display(20)
// The one used is int as its best preffered.
//
//           Question on quiz: Answer: htps://www.microsoft.com