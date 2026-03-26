/*
*
* 
* 
*/

#include <iostream>

void main()
{
    /*  Chapter 4 summary:
    *   Comparison: the process of eevaluating the relationship between 2 values to determine if they are equal, unequal
    *       or greater/less than.
    *       The compiler evaluates the expression and returns a boolean value: true(1) or false(2)
    *       Types are: int or char (for comparing raw numerical values directly) and strings.
    *   The relational operators: 
    *   == (equal to), != (Not equal to), > (Greater than), < (Less than), >= (greater than equal to), and <= (less than equal to).
    *   The behaviors: assignment is =, equality is ==.
    *   It is case sensitive: Character and string comparisons differ as the uppercase and lower have different values: A = 65, a = 97.
    * 
    *   If statements: the basic way to make decisions and use the compariosn resluts to decide which code to run.  
    *   Purpose: To execute a block of code only if a specific condition is true. if false then it skips that block.
    *       If else statements: Provides the alternative or fork in the road code. One can be true and the other can be false based on the comparison.
    *       Any one of those blocks will always run.
    *   Behaviors: The zero rule: any non zero is treated as true while a 0 is false.
    *   Single lines of code in a if command don't need a {}, but it is highly encouraged.
    *   If-else-if statemtets: to check multiple conditions in order. Once the program finds a true condition, it runs that block and skips the rest of the chain.
    *   ex: if (10) { is greater than 12 go to red}, else if (10) {is less than 9 go to white} else {go to blue}
    *   Behavior: the order matters, the computer runs from top to bottom, if the first condition is true, then it ignores the second condition even if its also true.
    *   The catch-all: the final else is considered optional and acts as a safety net if none of the conditions match.
    *   Scoping rules in a "if" statement: variable "lives" and can be used when inside the {}, ex: 10 exists at the {}.
    *       Avariable must be declared in the if block and is not declared after the }, and is invisible outside of it so you can't access a variable oustide the if block.
    *       Parent access: an If block can see a nd change variable declared before it {}. ex: ego = 10, if ego > 5 {int ago = 3, ego = ego + ago} (ago is not usable outside of } afterwards.)
    * 
    *   Logical operators: allows you to combine multiple comparison expressions into a single true/false decision. They are the "connectives" of programming logic
    *   The three logical operators:    &&: (AND) only true if both sides are true.     ! (NOT) reverses the values ( false becomes true etc.)
    *   Truth table: shows the result changes based on the inputs (A and B)
    *   | A | B | (A && B)-- AND  (A || B)-- Or  | !A  |-- NOT 
          F   F      (F)            (F)            (T) 
          F   T      (F)            (T)
          T   T      (F)            (T)            (F)
          T   F      (T)            (T)
    *   Short-circuit evaluation: a shortcut to save time and prevent errors: the compiler stops evaluating as soon as the final result is certain.
    *       For && (and)- if the first part is false then the whole thing must be false. skips checking the 2nd part.
    *       For || (or)- if the first part is true, then the whole thing must be true. skips checking the 2nd part.
    *   Behavior and Common pitfalls: ! is first, then &&, then ||. Use () to make logic clear.
    *   ex: don't do ( 5 < x < 10), you must seperate them " if ( x > 5 && x < 10)
    * 
    *   Conditonal operators: the short hand way to write a simple if-else statement in a single line.
    *   Purpose: to return a value based upon on a condition.   
    *   While a regular 'if-else' is a statement, does something, the ternary/conditional operator is an expression, results in something.
    *   Syntax: follows the pattern:   condition ? vlaue_if_true : value_if_false;
    *   condition: a boolean expression (x > 10), '?'-is the question true, 'value_if_true'- result if condition is true, '::' otherwise, 'value_if_false'- result of condition is false. 
    *   Behaviors: expression based: it returns avalue, you can see it inside other expressions or assignments. Type Matching: both result values must be the same type, seperatoed by the ':'.
    *   Readibility: Use it for simple one-line logic.
    * 
    *   Switch statement: a control flow tool used to select one of many code blocks to be exceuted based on the vlaue of a single expresssion.
    *   Purpose: to test a variable against a list of possible "cases".
    *   Syntax: swtch(expression) { case value1: 'code to run' break; case value2: 'code to run' break; default: code if no cases match}.
    *   The limits on switch expression: in the () must be an int type (int, char, short, long), or an enum. Can't use float or double or strings.
    *   Limits on case expressions: The value following the case keyword must be a constant expression known at compile-time.
    *   ex: lteral constants case 5:, case 'A', named constants: const int Max = 10; case MAX:
    *   What is invalid is variables or ranges (case x: or case > 10:)
    *   Default statement: a keyword that acts as a "catch all". Executes if non of the case values match the switch expression. Highly recommended for handling unexpected input or errors.
    *   
    *   Break and Fall-through Behavior: 
    *   Break: this exists the switch block immediately. 
    *       Without it, the program continues executing the code in the next case even if the case doesn't match the expression.
    *   Fall Through: this "leaking into the next case. Usually an error, it can be used intntionally to let multiple cases execute the same block of code.
    */


    /*  Chapter 5:
    *   Pre/postfix increment/decrement operators:
    *   Provides the shorthand way to add or subtract 1 from a variable.
    *   Syntax and Behavior: Prefix (++x, --x): the value is changed first, and then the expression is evaluated using the new value.
    *   (Change now, use later)
    *   Postfix (x++, x--) the expresion is evaluated using the original value, and the variable is changed.
    *   (Use now, change later)
    *   ex: x=5                 result of expression    Value of x After
    *   ++x Prefix:     y = ++x;     -> 6                        6
    *   x++ Postfix     y = x++:     -> 5                        6
    *   --x Prefix      y = --x:     -> 4                        4
    *   x-- Postfix     y = x--;     -> 5                        4
    * 
    *   Side effects: a change to the state of the program that happens as a result of evaluating an expression.
    *   1. Delayed update: in postfix, the side effect is guaranteed to happen. 
    *   But doesn't take affect until after the current vlaue has been sent to the rest of the statement
    *   2. Undefined behavior: Never use the same variable more than once in a single statement if on of them involves a side effect. 
    * 
    *   While statement: The most basic looping structure, designed to repeat a block of code as long as a specified condition remains true. 
    *   Purpose: To handle indefinite iteration whenre you don't necessarily know exactly how many times the loop will run before it starts.
    *   Syntax: while (condition) { code to repeat, update statement (i++) }
    *   Pre-test: means the condition is evaluated before the code block executes.
    *       If condition is flase the 1st time it's checked, the code inside the loop will never run.
    *       Differs from a do-while loop, which will always run at least once.
    *   Scoping within the loop: variables inside the while block are local to that block.
    *       They are created and destroyed with every single iteration of the loop.
    *       Variables used in the condition must be declared outside the loop to persist across iterations.
    *   When to use a 'while' loop: Choose it over a for loop
    *  1. Unknown iterations. You don't know the exact number of repeats.
    *  2. Event based: the loop should stop based on a specific event or condition change rather than a simple count.
    *  3. Sentinel Values: You are looking for a specific "stop" value (ex: quit to exit)
    * 
    *   For statement: A compact, organized way to handle definite iteration, where you typically know how many times you want to run a block of code before the loop even starts.
    *   Purpose: To bundle the three essential parts of a loop- initialization, testing, and updating- into a single line for better readability.
    *   Syntax: for ( initializer; test; update) { code to repeat }
    *   The 3 Expressions: 
    *   1. Initializer: Runs once at the very beginning. Usuall used to declare and set a counter variable ( i = 0 )
    *   2. Test: A boolean expression checked before every iteration. If 'true', the loop runs; if false, the loop ends.
    *   3. Update: Runs at the end of every iteration (after the code block). Usually increments or decrements the counter (ex: i++)
    *   Pre-Test Behavior: its a loop. The 'text' expression is evaluated before the code block ever runs. If the condition is false initially, the loop body is skipped entirely.\
    *   Inline Initializer and Scoping: You can declare the variable directly in the initializer: for (int i = 0: ... )
    *   Impact: the variable 'i' is local to the loop, once loop finishes, 'i' is destroyed and can't be accessed outside the {}. Prevents variable pollution.
    *   When to use a 'for' loop:
    *   1. Counting: You need to run a block a specific number of times (ex: "1-100")
    *   2. Data Structures: You are stepping through an array or a collection where you know the size.
    *   3. Predictable Patterns: the loop follows a clear "start, end, and step" logic.
    * 
    *   Break and Continue Statements: jump statements used to override the normal flow  of a loop. 
    *       They give you "fine-grained"control over when to stop or skip parts of your code.
    *   'Break'
    *   Purpose: immediately terminates the loop (or switch) and jumps to the first line of code after the loop's closing brace.
    *   Syntax: break;
    *   Use case: Use 'break;' when you've found what you're looking for (ex: searching for a specific value in a list)
    *   Or if an error condition occurs that requires stopping the loop entirely.
    *   'Continue'
    *   Purpose: Skips the rest of the code in the current iteraltion and jumps straight to the loops+'s "update" step (in a for loop) or to "test" step (in a while loop).
    *   Syntax: continue;
    *   Use case: Use 'continue' to skip specific 'bad' or 'unwanted' data without stopping the entire loop 
    *   (ex: skipping negative numbers while calculating a sum) 
    *   Statement           Effect on loop      What happens next
    *   break:                  Exit            The loop ends completely.
    *   continue                Skip            The loop moves to the next iteration
    * 
    *   
    * 
    */
}