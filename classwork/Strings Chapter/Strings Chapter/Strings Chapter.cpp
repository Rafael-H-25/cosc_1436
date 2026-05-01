#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

// Characters and strings
// Strings are different to interact with it, hard.
// 
// How C does it
//
// 
// 
// How C++ works on strings: Very difficult to work with. B
// How C++ strings store it: 
// 
// Char: 1 byte, can hold 0-255 values ( S = 85, etc)   The numeric number of the letters, latin, symbols and more. Can't be printed: \ and such. 
// 41 -> '0' to 50 -> '9', 63 -> is 'A' to 'Z', then 97 -> 'a' to 'z'.
// Must be stored in a single byte system.
// The difference is different when you ask for the string.
// 
// Char set: a numeric value that goes to that character set. An encoding. 
// We have been using ANSI set. 
//  ACS 2
// Both are one byte and uses char type.
// Issue there is more than 256 different values.
// Ex: ANSI works for English and is very limited.
// 
// MBCS: Multi Byte Char Set- Hiddious to work with
// How it works: We still use the char data type, which we still use one byte, but we need to support different languages.
// If the first byte is 255
// And the next is another byte if it has FF, making char not working
// 
// We can define code pages: byte -> char mapping. Store the same values but store them differently.
// 1252 means English, but 1498 could mean Japanese
// 
// Unicode: We use that today: stores every char in 2 bytes, with that we can store every character in every language.
// Like ANSI but with ANSI, so 0 to 255 are the same, after that it has another set for the other values for the other languages. 
// If you want to use anyother code outside english needs Unicode
// Not interchangeable with ANSI
// Unicode uses several formats of Unicode:
// UTF8 (1 byte), UTF16 (2 bytes), UTF32 (4 bytes)
// UTF8: 
// Reason why they are here: 
// 
// 
// 
//

bool IsvalidIdentifier(std::string const value)
{
        // Starts with _ or letter
        // Consists of only _, letter and digits.
    if (value == "")
        return false;
    
    if (value[0] != '_' && !isalpha(value[0]))
        return false;
    
    for (int index = 1; index < value.length(); ++index)
            if (value[index] != '_' && !isalnum(value[index]))
                return false;
    
    return true;
}

void ClassifiedChars()
{
    // Value Classify
    std::cout << std::setw(7) << "Value "
        << std::setw(7) << "Letter? "
        << std::setw(7) << "Digit? "
        << std::setw(7) << "isalnum? "
        << std::setw(7) << "isspace? "
        << std::setw(7) << "islower? "
        << std::setw(7) << "isupper? "
        << std::endl;

    // Char classify functions
    // int func(int ch); 0 = false, everything else = true (1)
    // isalpha() -> letter              //Unicode version (iswalpha)
    // isdigit() -> number
    // isalnum() -> letter or number
    // isspace() -> whitespace
    // islower() -> lowercase letter
    // isupper() -> uppercase letter
    //
    // tolower() -> lower case a letter
    // toupper() -> upper cases a letter

    std::string value;
    std::getline(std::cin, value);


    for (int index = 0; index < value.length(); ++index)
    {
        char input = value[index];
        
        std::cout << std::setw(7) << input
            << std::setw(7) << (isalpha(input) ? "Y" : "N")
            << std::setw(7) << (isdigit(input) ? "Y" : "N")
            << std::setw(7) << (isalnum(input) ? "Y" : "N")
            << std::setw(7) << (isspace(input) ? "Y" : "N")
            << std::setw(7) << (islower(input) ? "Y" : "N")
            << std::setw(7) << (isupper(input) ? "Y" : "N")
            << std::setw(7) << (tolower(input) ? "Y" : "N")
            << std::setw(7) << (toupper(input) ? "Y" : "N")
            << std::endl;


        //if (tolower(input) == 'q')
        //if (input == 'Q' || input == 'q')
          //  break;
    } 
    std::cout << "C++ simplifier? " << (IsvalidIdentifier(value) ? "Y" : "N") << std::endl;
}


// C strings
// Functions used in C
// C++ String fuctions
// 

void CStringDemo()
{
    char letterGrades[5] = {'A', 'B', 'C', 'D', 'F'};
    char* pLetterGrades = letterGrades;         // A string in C strings
    
    // Every string like this ends with a NULL terminator
    char const* name = "Bob";       // Length 4 B,o,b and the NULL

    // Only time where implicit string important
    char fixedName[] = "Jean";      // Lenght 5 J,e,a,n and the NULL


    // Cout sees the string not the pointer array.
    //std::cout << letterGrades << std::endl;
    //std::cout << name << std::endl;

    //Common C functions
    //  string functiond start with str
    // strlen(str) returns # of bytes/chars in the string, excluding NULL.
    int len = strlen(fixedName);        // 4


    char name1[100] = "Mark";
    char name2[200] = {0};

    //Copying a string
    //strcpy(name2, name1);       // strcpy(target, src) copies scr to target, better be big enough. Null terminate the string
    // A very dangerous function and the compiler will flag it.
    // Alternate version:
    //strncpy(name2, name1, 100)      // strncpy(target, src, size) copies scr to target up to size.
        // Do not use and won't compile.
    // The safe function
    strncpy_s(name2, 200, name1, 100); //strncpy_s(target, size, src, size) <---  In C style.
    
    // Concat Strings:  (str +=v)
    
    // The size of the strings are more important.
    //strcat(name2, name1);   // strcat(target, scr) concats source to target.
    // Need to be aware of how many characters are in the array. Very dangerous.
    //strncat(name2, name1, 100); // strncat(target, scr, size)
    // Not safe and won't compile here.
    strncat_s(name2, 200, name1, 100);  // strncat_s(target, size, src, size)

    //String Comparison: C++, (x == y)
    int areEqual = _stricmp(name2, name1);      // _stricmp(str1, str2) int(<0 str1 < str2, = 0 str1 == str2, > 0 str1 > str2)
    areEqual = strcmp(name2, name1);    //Case sensitive version

    char fullName[] = "Bob Miller";
    char* pSpace = strstr(fullName, " ");  // strstr(target, stringtofind) char*, pointer to substring or nullptr, case sensitive
    // Example a school name and filter the school name or college, It won't support that.
    if (pSpace)
    {
        std::cout << "Last name = " << pSpace << std::endl;
    } else {
        std::cout << "No last name" << std::endl;
    }

    //Number conversion
    char number[100] = {0};
    do
    {
        std::cin >> number;
        //int valueEntered = atoi(number);        // atoi (Ascii to Int)         Returns the number until it isn't a number: ex 123wer4 -> stops at 123.
        //double valueEntered = atof(number);       //atof (Ascii to floating point)
        
        char* endPtr = nullptr;
        int valueEntered = strtol(number, &endPtr, 10);
        std::cout << "Interger value = " << valueEntered << std::endl;      
        if (valueEntered == 0)
            break;
    } while (true);

    //int to string
    //_itoa(100, number, 10);     // "100"
    // Unsafe
    _itoa_s(100, number, 100, 10);

}

void CppStringDemo()
{
    std::string name = "Bob";

    // Get the length
    int len = name.length();        //.length() -> # of chars in the string (strlen)

    // Case insensitive comparison _stricmp
    // .c_str() char* returns pointer to C string equivalent
    std::string value1 = "Hello", value2 = "hello";
    bool areEqual = value1 == value2;
    //areEqual = stricmp(value1.c_str(), value2.c_str()) == 0;

    // Assignment (strncpy_s)
    name = "Sue";

    // Concatrnation (strncat_s)
    name += " Miller";
    name.append(" Jr");

    //Clear a string (strcpy(buffer, "");)
    name = "";
    name.clear();

    name = "Sue Miller";

    // Find in string (strstr)
    int index = name.find(" ", 0);      //find(stringtofind, index) -> zero-based index of substring
    if (index >= 0)
    {
        std::string firstName = name.substr(0, index);
        std::string lastName = name.substr(index);      //substr(start, count) returns substring starting at start to count
        std::cout << "First Name = " << firstName
            << " Last name = " << lastName << std::endl;
    }
}

int main()
{
    CppStringDemo();
    //CStringDemo();

    //ClassifiedChars();

    // C++ string (ANSI- 1 byte per char):
    char absuChar = 'A';
    std::string programName = "StringDemo";     // 10 chars = 10 bytes
    for (int index = 0; index < 10; ++index)
        std::cout << programName[index];
 
    // Unicode- 2 bytes per char
    // Microsoft only solution
    wchar_t unicodeChar = 'A';
    // To declare a string:
    std::wstring programNameUnicode = L"StringDemo";     // 20 bytes
    for (int index = 0; index < 10; ++index)
        std::cout << programNameUnicode[index];

    // Other varients of Unicode
    //char8_t uft8;
    char16_t utf16;
    char32_t utf32;

    std::string name;
    std::cin >> name;

    std::wstring nameUnicode;
    std::wcin >> nameUnicode;       //Reading unicode string

    //std::cin >> uft32;
}


