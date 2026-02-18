/*
* Chapter 3          <---- (Your header here)
* COSC 1436
* Spring 2026
*/
#include <iostream>
#include <string>
#include <iomanip>

void main()
{
    // Math Functions: Useful for math codes. You must include "cmath" all functions for this which comes from this.
    // Language provides some of the common types of math fuctions.
    //  Function | What it does
    // --------------------------
    // pow(x,  y) | raises x to y power        x^y double
    // The second power integer must be an int (a whole number)
    // sqrt(x) | Square root of x (double)  
    // abs(x) | (determines the variable) int is an int, double-double 
    // ceil(x)  | Returns the smallest possible int that is >= x ceil(x) => int     ex: 9.1 => the smallest int value is 10. [ x ] (y is above the x)
    // floor(x) | Returns the largest possible int that is <= x (both similar)  floor(x) => int     ex: 9.1 => the largest int value is 9 [ x ] (y is below the x)
    // exp(x)   | Takes the exponent of x 
    // log(x)   | Takes the log of x (resiprical of each other) Working against a named value
    // trunc(x) | Truncates a floating point value to an int.       Is equivalent to casting a double into an int type cast.
    // round(x) | Converts a floating point value into an int (both). They do it two different ways. Work how cout works. It does midpoint rounding.

    double mathValue;
    // First function
    std::cout << "Enter value: ";
    std::cin >> mathValue;

    std::cout << std::setw(20) << "Function " << "Result" << std::endl;
    std::cout << std::setw(20) << "pow (square)" << pow(mathValue, 2) << std::endl;
    std::cout << std::setw(20) << "pow (third)" << pow(mathValue, 3) << std::endl;

    // Second Function
    std::cout << std::setw(20) << "sqrt" << sqrt(mathValue) << std::endl;

    // Third Function
    std::cout << std::setw(20) << "abs" << abs(mathValue) << std::endl;

    // Forth Function
    std::cout << std::setw(20) << "ceil" << ceil(mathValue) << std::endl;
    std::cout << std::setw(20) << "floor" << floor(mathValue) << std::endl;

    // Fifth Function
    std::cout << std::setw(20) << "exp" << exp(mathValue) << std::endl;
    std::cout << std::setw(20) << "log" << log(mathValue) << std::endl;

    // Sixth Function
    std::cout << std::setw(20) << "trunc" << trunc(mathValue) << std::endl;
    std::cout << std::setw(20) << "round" << round(mathValue) << std::endl;


    // Prompt for accruded points and total points and determine the average. Percentages are value over maximum value. ex 400/3 or 400/ 2, how much the students maximum points earned.
    int actualPoints, totalPoints;

    std::cout << "enter the actual points earned: ";
    std::cin >> actualPoints;

    std::cout << "Enter the total points available: ";
    std::cin >> totalPoints;

     // Unless the student gets a perfect score, its zero regardless. You can't change the behavior with type coersion.
     // It will not help us here. There are 3 ways possible.
    // inte / int =>
    // Need to convert one or other to double
    // Options-
    //  1 - Change the type of either variable, but we can't really (usually the wrong answer)
    // why: The expectation must be whole numbers for variables when declared to clarify the type you intend to store, not to change the type of the variables to use situations like this.
    //  2 - Type Casting, when you explicitly change the type of an expression. This is one of the scenarios where, change the type. When you put it in explicitaly. Doesn't change the ocde beyond that.
    //          A :: C++ cast ::= static_cast<T>(E)
    //          B :: C cast ::= (T) E
    // This cast you wrap this type with the parinthesis followed with the type and then the expression

    double average = (actualPoints / totalPoints) * 100;  // Wrong      
    average = (static_cast<double>(actualPoints) / totalPoints) * 100;  //Option 2. A: Does change the code or runtime code, just changes the types to figure out the expression.
    // This a way to write out the type cases.
    average = (actualPoints / (double)totalPoints) * 100; // Option 2.B     It can be hard to idenitfy what expression your using. If you use type casting with parinthesis.
    average = ((double)(actualPoints) / totalPoints) * 100; // Option 2. B
    // C style cast is wild west, you are responsible with it in run time and it is not reccomended to use c-style cast. Static casts are always safe casts.
    // Ex: string type casting with a double, good with C, not great with C++
    // Static cast will never conver, little more control.
    // Use static cast, stands out, always safe, and concured.


    std::cout << "Average grade = "
        << std::fixed << std::setprecision(2)
        << average << std::endl;


    // Formatted output: when you use for more control for "cout" (flexibility for common senarios)
    // x    y   + - * / % <= modulus
    // -------------------
    // 3    4   7 -1 12 0 3
    
    double firstValue, secondValue;
    std::cout << "Enter x and y: ";
    std::cin >> firstValue >> secondValue;

    std::cout << std::left << std::fixed;
    std::cout << std::setprecision(3);

    std::cout << std::setw(8) << "x" 
        << std::setw(8) << "y"
        << std::setw(10) << "+"
        << std::setw(8) << "-"
        << std::setw(12) << "*" 
        << std::setw(10) << "/"
        << std::setw(8) << "%"
        << std::endl;
    std::cout << std::setfill('-') << std::setw(36) << "" << std::setfill(' ') << std::endl;
    // The "-" as is since isn't great to have at all. we prefer to do: setw(#) to replace this. However this doesn't give a good solution.
    // Integers (int) are simple, doubles aren't, so change int to double though we can't use "%"
    // And if we do decimals with our x and y, we run our effort. It gets worse with exponents.
    // If doing an exponent and a decimal, you have not much control, which is where we add our next manipulator.

    std::cout << std::setw(8) << firstValue
        << std::setw(8) << secondValue
        << std::setw(10) << (firstValue + secondValue)
        << std::setw(8) << (firstValue - secondValue)
        << std::setw(12) << (firstValue * secondValue)
        << std::setw(8) << (firstValue / secondValue)
        //<< std::setw(4) << (firstValue % secondValue)
        << std::endl;                       // Should be all combined, not good.    Add spaces for the values x and y +-*/% to fit what the data would look like if its 3 values
                                            // We need lines and spaces for the expressions
                                            // After adding spaces its stil not correct to us, we are making assumptions of values. We need to look at the actual run time value. (Later in the semester for the outmated output
    // C++ has some output options but are not perfect. Insert/type "#include <iomanip>"

    //
    // Manipulators (common used): Most used frequently is "setw(#)" sets the value of a variable, it is a minimum #. it will just ensure they are that long. pad your value to the given number character.
    // Helps et your collumns to the correct length. The manipulator appears before the expression.
    // They are not percistant, if you need patting, you must set a setw for every value.
    // Used to get rid of the unneeded ""_""
    // Persisted: No
    
    // Manipulator: Left, it is left justified (std::cout << std::left;
    // Persisted: Yes
    // Right is justified, 
    // Persisted: Yes
    
    // Setfill(char): What: puting char. Once set it is persistent until you change it. You can change it with a set fill at the end of whatever you use. ex: the "-"
    // std::setfill('character')
    // Persisted: yes

    // Fixed:  focuses fixed point notation, decimals. Once fixed with it, your stuck with the rest of the program. If its a float, then its defined to its persision
    // Persistent: Yes,
    
    // Set Percision: sets the percision for numbers. If you don't want your values go over your percision use that. Total number of digits left and right. That's the precision.
    // Its potentially able to make exponential notations still.
    // if added fixed: it now does precision = digits after decision when fixed
    // Persistent: Yes

    // To use double use fixed and set precision
    // If your using fixed with set precision you won't know since the left side of the decimal will not matter.
    // When wrighting the labs need to be 2, you are expected to see 2 digits of precision. Make sure you don't set values before doing fixed.

    // These you can make table structures and data values. Now Lab 2,3,4,and 5
    



    // Input
    //std::cin >> requires an expression by an l value (l value: left side of an assignment, must be a variable) A complicated statment, you can give it any expressions and try to get it to that type, and not perfect to the imagination, is dumb.
    // Ex: length should be an int (Types don't exist in run times) an int is layed out from memory. It has no idea of what type it would be. the input would treat it as an int
    // Try put in "Bob" or "Elliot" it loses it. Try "20abc" lost it again. Try 43.39, now it doesn't either.
    // It can't tell its compatible to the varibale you enter, that is how "cin" works. Not really supported for a user input.

    // For labs and future, it says "You don't need to worry for int value inputs".
    // Cin doesn't work as you wouldn't expect.
    // Behind cin: your input when typing, will be inputed into an input buffer, and what it does it extracts data from the input buffer.

    // It hadle: if you ask for an int, and you have nothing in the input buffer, it does nothing (blocks it). As soon as you input something, it goes to the next input buffer.
    // cin only care about white spaces. you can input a space and add a value in it, and when you hit enter all that value will be inputed into the buffer but it will stop to any white space. So it goes until a space ( ), and then goes to the next buffer: 100 () 20
    // cin: all it cares is the input buffer, all its looking for is white space.

    //std::string name;
    //std::cout << "Enter your name: ";
    
    //std::cin >> name;
    //std::getline(std::cin, name);

    //std::cout << "Hello " << name << std::endl;     // In the input, it sees billy and puts into the variable, the second the space is a seperator, and skips it. So it gives bob as an int, that mangeled everything.
    // spaces are seperators for cin, you better make sure there is no space or white space.

    // If you use string values, instead of string values, use getline(); a reuseable block of code, it just works, purpose to read in a string from "cin". functions does not have access to your code. ex tell it from cin and give it a name of a string
    // You specifiy the arguements from the function name "getline(arguements)"
    // if you have multiple data points put in a comma ,. That tells which input to read it. 
    // This is how you will read strings in C++. After that everything will work like normal.
    // Getline is mentioned in <string> you must need to input #include <string>

    // Getline and cin does not work together. Getline is lookcing for new lines, cin leaves white space for values.
    // Getline works until a new line and will try to remove it. They both are colliding in the middle when reading it. Cin will follow getline.
    // If we flip the order is where it goes wrong.

    std::cout << "Enter the length: ";

    // std::cin >> E (Expression)
    //  Get input from user
    int length;
    std::cin >> length;

    std::cout << "Enter the width: ";

    int width;
    std::cin >> width;

    int area = length * width;
    std::cout << "Area of rectangle = " << area << std::endl;

    // Prompt for name
    std::string name;
    std::cout << "Enter your name: ";

    // Hack to work around getline and cin issues when getline follows cin (This is how to fix that)
    std::cin.ignore(INT32_MAX, '\n');       // Tells cin to ignore the 2 billion characters, this should clear out the input buffer. Not very reliable but its there to wipe it out.

    //cin with strings will cause issues if string has spaces
    //std::cin >> name;
    std::getline(std::cin, name);

    std::cout << "Hello " << name << std::endl;


    std::cout << "Enter the base and height: ";

    int base, height;
    std::cin >> base >> height;

    area = base * height / 2;      
    std::cout << "Area of triangle = " << area << std::endl;

    // Read in a string: look at top
    
    // Operation Precedence order: An expression: literals, variables, expresion acp expression, and presedence ()
    // What happens when you combine 2 operators: ex 4 + 5 * 3 = 19 (That is operator precedents)
    // Multiplication, division, and % are at the top of the chart. + and - is at the bottom.
    // Where things get harder: unary operators are higher. ex: 5 -- 3 = 8 -> 5 - (-3) = 8
    // If operators are at the same precedents level, it goes left to right. ex: (b * h) / 2.
    // To be very clear on the change of precedence order, we use the (). the highest precedence level. ex: (4 + 5) * 9 = 27
    // Every operator has an associativity: left or right, it does "what is the order of evaluation", order of evaluation is not very important for () but will radically changes them soon.
    // Most operators are left associated. We evaluate the left first, then the right, then evaluate from there.
    // Assignment is the only one (currently) that is right associated, the variable evaluates the expression first then the value side. (Right then left next)

    // Ex: x = y = 10; this is why assignment is right. If right wasn't right associated for assigment then it would not work, x=y forever.
    // The other operator that is right associated is + and - (unary)
    
    // The combination operators: ex: some variable = some variable by some number (+ 10)
    // We can use the combination operator by using as v+= 10; its to simply reduce the amount of work.
    
    // Combination operators
    //  Op= where op is + - * / %
    // First operand must be a variable
    base = base + 10;
    base += 10; // Only works when the operan is that same variable or the order.
    // ex: v = x- 5, if we try to combine that, your taking v -=5
    // You are not required to use this but will see it often

    // Type coercion: compiler implicitly coerces/converts one type to another to make it identical. (ex: line 111)
    // Applies when using 2 different types in a binary expression
    
    area = (1 / 2) * base * height;     // (int / int) * int * int <-- this expression is an int, so if its 1/2 then this will be a zero. 

    // what we really want is: but violates the language
    area = 0.5 * base * height;     // double * int * int ==> double
    
    // Type coersion: this is how we use this. the int coerces as a double instead, which causes this expression as a double.(always coverges to a higher version) 
    // Doesn't change the value or anything, but the type of the expression while evaluating. It changes the view of that expression it is. variable is not changed
    // Types more natural code that it saves us more effort for formulas and more, and is done by the compiler.
    
    // Type hierarchy:
    // Largest to smallest: Double, float, unsigned long, long, unsigned int, int, short/char and everybody else. (8, 4, 4, 4) 
    
    // Double, 8 bytes, does decimal numbers, more preffered to choose as standard, double precision of float by 7-12 decimal digits, from +-10^308
    // Double, 4 bytes, does integers (whole numbers) and will remove any decimals and truncate it to the interger value (12.20 => 12)
    // Float, 4 bytes, does store decimals from e +-10^38, and is percise @ 6-7 digits.
    // Int (integer), 4 bytes, same as long from +-2 billion range limit.
    
    
    // An unsigned long is larger than a normal long
    // Anything smaller than an int, then the type will be coerced to an int. char + int ==> int or short + int ==> int
    // Quiz: Float + long + int ==> float (Operance order does not matter since everything is all a float)
    // And also it doesn't matter about the result of it.
    float someValue = 0.5 * 10; // still is a float
    // Given two different types, the compiler identifies the type and coerces that type to the higher type. float + long ==> float

    // To work on a narea of a triangle is by making on of the expression as a double. 1.0 is a double.

    // Overflow and underflow: when dealing with small types
    short minValue = -32768;
    short maxValue = 32767;
    //it occurs
    maxValue += 1; //32768, we can't store this into a short (too big)
    //in this case it wraps around, the overflow results into a wrap around into -32768, from a positive to a negative (big circle)
    // Underflow is the opposite:
    minValue -= 1; // -32769 - wraps around to the largest positive number of the type.
    // Not much you can do about it and is hard to notice, this is why we use int as it is less likely to overflow or underflow.  If it happens to an int, then we go to the next highest type. 
    // Ended- 2/10. You can now do the lab with this information.
}

