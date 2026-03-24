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
    * 
    * 
    */

}