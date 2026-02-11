/*
* Chapter 3          <---- (Your header here)
* COSC 1436
* Spring 2026
*/
#include <iostream>
#include <string>

void main()
{
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

    // Type coercion: compiler implicitly coerces one type to another (ex: line 111)
    // Applies when using 2 different types in a binary expression
    
    area = (1 / 2) * base * height;     // (int / int) * int * int <-- this expression is an int, so if its 1/2 then this will be a zero. 

    // what we really want is: but violates the language
    area = 0.5 * base * height;     // double * int * int ==> double
    
    // Type coersion: this is how we use this. the int coerces as a double instead, which causes this expression as a double.(always coverges to a higher version) 
    // Doesn't change the value or anything, but the type of the expression while evaluating. It changes the view of that expression it is. variable is not changed
    // Types more natural code that it saves us more effort for formulas and more, and is done by the compiler.
    
    // Type hierarchy:
    // Largest to smallest: Double, float, unsigned long, long, unsigned int, int, short/char and everybody else. (8, 4, 4, 4) 
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

