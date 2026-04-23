// Quiz 4 Review
//
//Arrays:   (Think of an array like a row of lockers in a hallway)
//                  A data structure used to store multiple values of the same type in a single, contiguous block of memory.
//          Think of it as a labeled egg carton: one container with several numbered slots
//
//            Definition: A collection of variables (elements) of the same data type.
//            Purpose: To organize related data so it can be easily managed, sorted, and searched using a single identifier.   
//          (Like all 'int' or all 'double')
// 
//            Element vs index and how they are counted: 
//                  Element: The actual data value stored in a slot (e.g., the number)
//              (The actual data inside the locker: ex: 42)
// 
//                 Index: The "address" or position of the element.
//              (The locker number. Also, C++ starts couting at 0, so if you have 5 items, their indicates are 0,1,2,3,4.)
//                  Counting: Arrays are zero-indexed. The first element is at index 0, the second at index 1, and so on.
//
//            Layout in memory:     Is stored in memory, labeled at a top down, consecutive in memory. Multi -row major order: all row data stored together.
//                          (Arrays are 'contiguous', meaning they sti right next to each ohter in your computer's RAM. Making them very fast to access.)
// 
//              Contiguous: Elements are stored side-by-side in memory.
//              Direct Access: Because they are adjacent, the computer can calculate 
//                  the exact memory address of any element using the formula
//              Base Address + (Index * Size of Type)
//
//Defining arrays:      To create an array, you must specify the type, name, and size.
//          (Tell what's inside it and how big it is.)
//
//            Defining an array: 'int highScores[5];'   (Creates an array of 5 integers.)
// 
//            Requirements on array sizes:      Fixed Size: In most low-level languages (C/C++), the size must be known at compile time.                                          
//                                              Positive Integer: The size must be a constant positive integer.
//                                          (inside the '[]' and be a constant ingeter ( 3, 2, or 'const int' ) and is greater than 0.)
//            Initializing arrays:
//
//                Initializer syntax: Set values at the moment you create the array using the '{}' (ex: int numbers[3] = {10, 20, 30})      
//                          for ( int arr[], int size )
//
//                Implicit sizing:      If you initialize the array immediately, you can leave '[]' empty. C++ will count the items for you)
//                              Ex: double prices[] = {1.99, 2.50} (C++ will automatically make the size 2.)
//
//                Using loop: Declare an empty array and use a 'for' loop to assign values to each index manually.
//                  (To fill an array after it's been defined, you typically use a 'for' loop to step trhough each index.
//                  Ex:     for (int i = 0; i < 5; i++) { myArray[i] = 0;  <----(sets every element to zero)    }
// 
//Using Arrays
//
//            Get / setting elements:       Get: To get (read) a value: 'std::cout << myArray[2];' (Prints the value at index 2.)
//                                          Set: To set (write) a value: myArray[0] = 50; (Assigns 50 to the first spot.)
//                  Get: int x = myArray[0];           
//                  Set: myArray[0] = 10;
//
//            Iterating elements using a for loop:  The most common way to work with arrays. You use the loop counter (i) as the index.
//          Ex: for (int i = 0; i< 5; i++) { std::cout << myArray[1] << " ";   <-----(Prints every element in the array.)     }
//
//            Bounds checking
//
//                Purpose: To prevent your program from trying to acess an index that doesn't exist ( Ex: trying to access an index '10' in an array of size '5'. )
//              (To prevent "Buffer Overflows" (accessing memory outside the array).)
//
//                Implementation: Most low-level languages (C/C++) do not check bounds automatically. 
//                          You must write code (like an 'if' statement) to ensure your index is between '0' and 'size - 1'.
//                          If you go out of bounds, your program might crash or corrupt data.
//
//            Pre / postfix increment / decrement impact on array access(inside and outside array brackets): 
//              
//                  Inside brackets: 'myArray[i++]' uses the current value of 'i' first, then moves to the next index.
//                  'myArray[++1}' moves to the next index first, then accesses it.
// 
//                  Outside brackets: 'myArray[i]++' takes the value INSIDE the array and adds 1 to it.
//            
//            Copying arrays: You CANNOT just say 'arrayA = arrayB'. To copy an array, you must use a loop to compare each element. 
//                  If even one element is different, the arrays are not equal.
//            
//            Comparing arrays: Just like copying, you can't use 'arrayA == arrayB'. You must use a loop to compare each element. 
//                  If even one element is different. If even one element is different, the arrrays are not equal.
//
//
//Functions
//
//            Passing arrays as functions: You only use the array's name as the argument. ex: myFunction(myArray);
//              Usually, arrays are passed by reference (or pointer). 
//            Pass by reference behavior: C++: arrays are automatically passed by reference.
//          (Meaning the function recieves the memory address of the first element
//              CRUCIAL: Because it is passed by reference, any changes the function makes to the array 'will affecct the original array' in you main program.
//          
//            Function parameter syntax: To tell the function to expect an array, use empty square brackets '[]'.
//              Ex: void printArray(int arr[])
//
//            Passing size: Because an array "decays" to a pointer when passed, the fuction loses track of how many elements are in it. 
//          'Best practice' is to always pass the size as a seperate argument.      Ex: void process(int arr[], int size)
// 
//    
//Multi - dimensional Arrays(Tables):   an "array of arrays". The mmost common: 2D array, which acts like a grid or table with rows and columns.
//              
//
//            Syntax and purpose
//                  Purpose: To store data in grid format (like a speadsheet or game board).
//                  Syntax: dataType name[Rows][Cols];
//                  Example: int table[3][4];       (Creates 3 rows and 4 columns, totaling 12 elements.)
//
//            Passing tables to functions: 
//                  Column Rule: When passing a 2D array, the column size must be specified in the function parameter so the compiler can calculate memory offsets.
//                  Syntax: void myFunction(int arr[][4], int rows).
//                          The function recieves a pointer to the first row, making it "Pass by Reference" behavior by default.
// 
//            Enumerating tables: To "enumerate" (visit every spot) in a table, you use nested loops.
//                  The outer loop usually handles the rows, and the inner loop handles the columns.
//              ( for (int r = 0; r< 3; r++)
//              {
//                      for(int c= 0; c< 4; c++)
//                      {
//                          std::cout << grid[r][c];     <---- (Accesses each "cell" one by one.)
//                      }
//              }   )
// 
//            Row vs column major order:        Row:    Memory stores the entire first row, then the entire second row.
//                                          ( The computer sotres the entire 1st row, then the entire 2nd row, etc. )
// 
//                                              Column:     Memory stores the first column, then the second.
//                                          ( The computer stores the fist column, then the second column. )
//
//            Jagged vs rectangular arrays:   
//                                          Jagged:    An "array of arrays" where each row can have a different length.
//                                          ( An array where rows can have different lengths. In C++, you usually achieve this using an "array of pointers,"
//                                              but for your current level, just know it means the "rows" aren't all the same size.)
// 
//                                          Rectangular:    Every row has the same number of columns (a perfect box).
//                                          ( Every row has the exact same number of columns (like a perfect box). (This is standard in C++.)
//

