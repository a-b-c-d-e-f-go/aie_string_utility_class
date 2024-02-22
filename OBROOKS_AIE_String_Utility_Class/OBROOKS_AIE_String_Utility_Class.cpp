#include <iostream>
#include "String.h"
using namespace std;

//Inputs from console.
#define set_s1 *s1 = String::ReadFromConsole(); *sout = *s1
#define set_s2 *s2 = String::ReadFromConsole()
#define set_s3 *s3 = String::ReadFromConsole()
#define set_num cin >> num; String::ReadFromConsole()

// ##########
// # TASK 3 #
// ##########

void log_test(String* _str, const char* _func, std::string _output, String* _p1 = nullptr, String* _p2 = nullptr, String* _p3 = nullptr)
{
    String test = *_str + String(".") + _func + String("(");

    if (_p1 != nullptr) { //Parameter 1
        test += *_p1;
        if (_p2 != nullptr) { //Parameter 2
            test += (String(", ") + *_p2);
            if (_p3 != nullptr) { //Parameter 3
                test += *_p3;
            }
        }
    }
    test += String(") returned ") + String(_output) + "\n";
    test.WriteToConsole(); std::cout << "\n";
}

int main()
{
    //Initialize Variables
    String* s1 = new String("Hello");
    String* s2 = new String(", ");
    String* s3 = new String("World!\n\n");
    String* sout = new String(); //Output String

    //For conversions into text.
    char char_out[2] = { '\0', '\0' };
    std::string bool_out = "false";
    int num = 0;


    // ##########
    // # TASK 1 #
    // ##########

    s2->Prepend(*s1).Append(*s3).WriteToConsole(); //Hello, World!


    // ##########
    // # TASK 2 #
    // ##########

    //Testing Methods
    cout << "Length()\n"; //See Length() in String.h
    cout << "Enter String: "; set_s1; //String
    log_test(s1, "Length", to_string(sout->Length())); //Output

    cout << "CharacterAt(size_t _index)\n"; //See CharacterAt() in String.h
    cout << "Enter String: "; set_s1; //String
    cout << "Enter Index: "; set_num; //Parameter
    char_out[0] = sout->CharacterAt(num); //Convert character to string with length of 2 including null terminator.
    log_test(s1, "CharacterAt", char_out, new String(num)); //Output

    cout << "EqualTo(const String& _other)\n"; //ect.
    cout << "Enter String 1: "; set_s1; //String
    cout << "Enter String 2: "; set_s2; //Parameter
    bool_out = "false"; //Convert boolean to string.
    if (sout->EqualTo(*s2)) { bool_out = "true"; }
    log_test(s1, "EqualTo", bool_out, s2); //Output

    cout << "Append(const String& _str)\n";
    cout << "Enter Main String: "; set_s1; //String
    cout << "Enter String to Append: "; set_s2; //Parameter
    log_test(s1, "Append", sout->Append(*s2).CStr(), s2); //Output

    cout << "Prepend(const String& _str)\n";
    cout << "Enter Main String: "; set_s1; //String
    cout << "Enter String to Prepend: "; set_s2; //Parameter
    log_test(s1, "Prepend", sout->Prepend(*s2).CStr(), s2); //Output

    cout << "ToLower()\n";
    cout << "Enter String: "; set_s1; //String
    log_test(s1, "ToLower", sout->ToLower().CStr()); //Output

    cout << "ToUpper()\n";
    cout << "Enter String: "; set_s1; //String
    log_test(s1, "ToUpper", sout->ToUpper().CStr()); //Output

    cout << "Find(const String& _str)\n";
    cout << "Enter Main String: "; set_s1; //String
    cout << "Enter Substring: "; set_s2; //Parameter
    log_test(s1, "Find", to_string(sout->Find(*s2)), s2); //Output

    cout << "Find(size_t _startIndex, const String& _str)\n";
    cout << "Enter Main String: "; set_s1; //String
    cout << "Enter Substring: "; set_s2; //Parameters
    cout << "Enter Index: "; set_num;
    cout << s1->Find(num, *s2) << "\n"; //Output
    log_test(s1, "Find", to_string(sout->Find(num, *s2)), new String(num), s2); //Output

    cout << "Replace(const String& _find, const String& _replace)\n";
    cout << "Enter Main String: "; set_s1; //String
    cout << "Enter Substring to Replace: "; set_s2; //Parameters
    cout << "Enter Replacing Substring: "; set_s3;
    log_test(s1, "Replace", sout->Replace(*s2, *s3).CStr(), s2, s3); //Output

    //Testing Operators
    /*cout << "Operator ==\n";
    cout << "Enter String 1: "; set_s1; //lhs
    cout << "Enter String 2: "; set_s2; //rhs
    if (*s1 == *s2) { cout << "Strings Are Equal\n\n"; } //Output
    else { cout << "Strings Are Not Equal\n\n"; }

    cout << "Operator !=\n";
    cout << "Enter String 1: "; set_s1; //lhs
    cout << "Enter String 2: "; set_s2; //rhs
    if (*s1 != *s2) { cout << "Strings Are Inequal\n\n"; } //Output
    else { cout << "Strings Are Not Inequal\n\n"; }

    cout << "Operator []\n";
    cout << "Enter String: "; set_s1; //String
    cout << "Enter Index: "; cin >> num; String::ReadFromConsole(); //Within [] Brackets
    cout << (*s1)[num] << "\n\n";

    cout << "Operator <\n";
    cout << "Enter String 1: "; set_s1; //lhs
    cout << "Enter String 2: "; set_s2; //rhs
    if (*s1 < *s2) { cout << "Less Than\n\n"; } //Output
    else { cout << "Not Less Than\n\n"; }

    cout << "Operator >\n";
    cout << "Enter String 1: "; set_s1; //lhs
    cout << "Enter String 2: "; set_s2; //rhs
    if (*s1 > *s2) { cout << "Greater Than\n\n"; } //Output
    else { cout << "Not Greater Than\n\n"; }

    cout << "Operator +\n";
    cout << "Enter String 1: "; set_s1; //lhs
    cout << "Enter String 2: "; set_s2; //rhs
    *s3 = *s1 + *s2; s3->WriteToConsole(); cout << "\n\n"; //Output

    cout << "Operator +=\n";
    cout << "Enter String 1: "; set_s1; //lhs
    cout << "Enter String 2: "; set_s2; //rhs
    *s1 += *s2; s1->WriteToConsole(); cout << "\n\n"; //Output*/

    //Cleanup
    delete s1; s1 = nullptr;
    delete s2; s2 = nullptr;
    delete s3; s3 = nullptr;
    delete sout; sout = nullptr;
}