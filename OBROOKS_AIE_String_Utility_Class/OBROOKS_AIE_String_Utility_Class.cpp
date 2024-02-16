#include <iostream>
#include "String.h"

int main()
{
    //Initialize Variables
    String* s1 = new String("Hello");
    String* s2 = new String(", ");
    String* s3 = new String("World\n");
    int num = 0;

    //(*s2).Prepend(*s1).Append(*s3).WriteToConsole(); //Hello, World

    //Tests
    /*std::cout << "Length()\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    std::cout << (*s1).Length() << "\n\n";

    std::cout << "CharacterAt(size_t _index)\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Index: "; std::cin >> num;
    std::cout << (*s1).CharacterAt(num) << "\n\n";

    std::cout << "EqualTo(const String& _other)\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole();
    if ((*s1).EqualTo(*s2)) { std::cout << "Strings Are Equal\n\n"; }
    else { std::cout << "Strings Are Not Equal\n\n"; }*/

    std::cout << "Append(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter String to Append: ";  *s2 = String::ReadFromConsole();
    (*s1).Append(*s2).WriteToConsole(); std::cout << "\n\n";

    /*std::cout << "Prepend(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter String to Prepend: ";  *s2 = String::ReadFromConsole();
    (*s1).Prepend(*s2).WriteToConsole(); std::cout << "\n\n";*/

    std::cout << "ToLower()\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    (*s1).ToLower().WriteToConsole(); std::cout << "\n\n";

    std::cout << "ToUpper()\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    (*s1).ToUpper().WriteToConsole(); std::cout << "\n\n";

    std::cout << "Find(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Substring: ";  *s2 = String::ReadFromConsole();
    std::cout << (*s1).Find(*s2) << "\n";

    std::cout << "Find(size_t _startIndex, const String& _str)\n";
    std::cout << "Enter Index: "; std::cin >> num;
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Substring: ";  *s2 = String::ReadFromConsole();
    std::cout << (*s1).Find(num, *s2) << "\n";

    /*std::cout << "Replace(const String& _find, const String& _replace)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Substring to Find & Replace: ";  *s2 = String::ReadFromConsole();
    std::cout << "Enter Replacing Substring: ";  *s3 = String::ReadFromConsole();
    (*s1).Replace(*s2, *s3).WriteToConsole(); std::cout << "\n\n";*/

    delete s1; s1 = nullptr;
    delete s2; s2 = nullptr;
    delete s3; s3 = nullptr;
    //test
}