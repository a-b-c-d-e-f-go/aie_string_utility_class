#include <iostream>
#include "String.h"

int main()
{
    //Initialize Variables
    String* s1 = new String("Hello");
    String* s2 = new String(", ");
    String* s3 = new String("World\n");
    int num = 0;

    s2->Prepend(*s1).Append(*s3).WriteToConsole(); //Hello, World

    //Testing Methods
    std::cout << "Length()\n"; //See Length() in String.h
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << s1->Length() << "\n\n"; //Output

    std::cout << "CharacterAt(size_t _index)\n"; //See CharacterAt() in String.h
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter Index: "; std::cin >> num; String::ReadFromConsole(); //Parameter
    std::cout << s1->CharacterAt(num) << "\n\n"; //Output

    std::cout << "EqualTo(const String& _other)\n"; //ect.
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //Parameter
    if (s1->EqualTo(*s2)) { std::cout << "Strings Are Equal\n\n"; }
    else { std::cout << "Strings Are Not Equal\n\n"; } //Output

    std::cout << "Append(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter String to Append: ";  *s2 = String::ReadFromConsole(); //Parameter
    s1->Append(*s2).WriteToConsole(); std::cout << "\n\n"; //Output

    std::cout << "Prepend(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter String to Prepend: ";  *s2 = String::ReadFromConsole(); //Parameter
    s1->Prepend(*s2).WriteToConsole(); std::cout << "\n\n"; //Output

    std::cout << "ToLower()\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole(); //String
    s1->ToLower().WriteToConsole(); std::cout << "\n\n"; //Output

    std::cout << "ToUpper()\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole(); //String
    s1->ToUpper().WriteToConsole(); std::cout << "\n\n"; //Output

    std::cout << "Find(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter Substring: ";  *s2 = String::ReadFromConsole(); //Parameter
    std::cout << s1->Find(*s2) << "\n"; //Output

    std::cout << "Find(size_t _startIndex, const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter Substring: ";  *s2 = String::ReadFromConsole(); //Parameters
    std::cout << "Enter Index: "; std::cin >> num; String::ReadFromConsole();
    std::cout << s1->Find(num, *s2) << "\n"; //Output

    std::cout << "Replace(const String& _find, const String& _replace)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole(); //String
    std::cout << "Enter Substring to Find & Replace: ";  *s2 = String::ReadFromConsole(); //Parameters
    std::cout << "Enter Replacing Substring: ";  *s3 = String::ReadFromConsole();
    s1->Replace(*s2, *s3).WriteToConsole(); std::cout << "\n\n"; //Output

    //Testing Operators
    std::cout << "Operator ==\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //lhs
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //rhs
    if (*s1 == *s2) { std::cout << "Strings Are Equal\n\n"; } //Output
    else { std::cout << "Strings Are Not Equal\n\n"; }

    std::cout << "Operator !=\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //lhs
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //rhs
    if (*s1 != *s2) { std::cout << "Strings Are Inequal\n\n"; } //Output
    else { std::cout << "Strings Are Not Inequal\n\n"; }

    std::cout << "Operator []\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Index: "; std::cin >> num; String::ReadFromConsole();
    std::cout << (*s1)[num] << "\n\n";

    std::cout << "Operator <\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //lhs
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //rhs
    if (*s1 < *s2) { std::cout << "Less Than\n\n"; } //Output
    else { std::cout << "Not Less Than\n\n"; }

    std::cout << "Operator >\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //lhs
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //rhs
    if (*s1 > *s2) { std::cout << "Greater Than\n\n"; } //Output
    else { std::cout << "Not Greater Than\n\n"; }

    std::cout << "Operator +\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //lhs
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //rhs
    *s3 = *s1 + *s2; s3->WriteToConsole(); std::cout << "\n\n";  //Output

    std::cout << "Operator +=\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole(); //lhs
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole(); //rhs
    *s1 += *s2; s1->WriteToConsole(); std::cout << "\n\n";  //Output

    //Cleanup
    delete s1; s1 = nullptr;
    delete s2; s2 = nullptr;
    delete s3; s3 = nullptr;
}