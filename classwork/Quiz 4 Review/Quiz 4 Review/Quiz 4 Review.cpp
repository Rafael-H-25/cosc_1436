// Quiz 4 Review.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Arrays:   a data structure used to store multiple values of the same type in a single, contiguous block of memory.
//          Think of it as a labeled egg carton: one container with several numbered slots
//
//            Purpose and definition: Definition: A collection of variables (elements) of the same data type.
//                                   Purpose: To organize related data so it can be easily managed, sorted, 
//                                          and searched using a single identifier.   
//
//            Element vs index and how they are counted: 
//                  Element: The actual data value stored in a slot (e.g., the number
//                  Index: The "address" or position of the element.
//                  Counting: Arrays are zero-indexed. The first element is at index 0, the second at index 1, and so on.
//
//            Layout in memory:     Is stored in memory, labeled at a top down, consecutive in memory. Multi -row major order: all row data stored together.
//              Contiguous: Elements are stored side-by-side in memory.
//              Direct Access: Because they are adjacent, the computer can calculate 
//                  the exact memory address of any element using the formula
//              Base Address + (Index * Size of Type)
//
//Defining arrays: 
//
//            Defining an array: To create an array, you must specify the type, name, and size.
// 
//            Requirements on array sizes:      Fixed Size: In most low-level languages (C/C++), the size must be known at compile time.
//                                              Positive Integer: The size must be a constant positive integer.
//
//            Initializing arrays:
//
//                Using loop: Declare an empty array and use a 'for' loop to assign values to each index manually.
//
//                Initializer syntax:       for ( int arr[], int size ) ex: int scores[3] = {90, 85, 80};
//
//                Implicit sizing:      If you provide values, you can omit the size: int scores[] = {90, 85, 80};
//                                  (The compiler counts 3 elements).
//
//Using Arrays
//
//            Get / setting elements Get: int x = myArray[0];           Set: myArray[0] = 10;
//
//            Iterating elements using a for loop:
//
//            Bounds checking
//
//                Purpose: To prevent "Buffer Overflows" (accessing memory outside the array).
//
//                Implementation: Most low-level languages (C/C++) do not check bounds automatically. 
//                          You must manually ensure your index is betweem 0 and size - 1.
//
//            Pre / postfix increment / decrement impact on array access(inside and outside array brackets): 
//
//            Copying arrays
//
//            Comparing arrays
//
//
//Functions
//
//            Passing arrays as functions: Usually, arrays are passed by reference (or pointer). 
//                      The function gets the address of the first element.
//
//            Impact on arrays when modifying elements in functions:  Because the function has the address, 
//                                         any changes made inside the function permanently affect the original array.
//
//
//    
//Multi - dimensional Arrays(Tables)
//
//            Syntax and purpose
//
//            Passing tables to functions
//
//            Enumerating tables
//
//            Row vs column major order:        Row:    Memory stores the entire first row, then the entire second row.
//                                              Column:     Memory stores the first column, then the second.
//
//            Jagged vs rectangular arrays:   Jagged:    An "array of arrays" where each row can have a different length.
//                                          Rectangular:    Every row has the same number of columns (a perfect box).
//
//

