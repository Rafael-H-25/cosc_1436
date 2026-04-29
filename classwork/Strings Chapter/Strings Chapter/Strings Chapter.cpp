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
// Char set: a numeric value that goes to that character set.
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


int main()
{
    ClassifiedChars();

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


