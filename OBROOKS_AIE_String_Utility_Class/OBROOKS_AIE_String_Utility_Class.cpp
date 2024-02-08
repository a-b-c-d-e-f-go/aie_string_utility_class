#include <iostream>

#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
    public: //External Constructors
        String() //No input.
        {
            cstr = "";
        }
        String(const char* _str) //Input is another cstr.
        {
            cstr = _str;
        }
        String(const String& _other) //Input is another string.
        {
            cstr = _other.CStr();
        }
        ~String();
    public: //External Functions
        size_t Length() const
        {
            return strlen(CStr()); //Length of the char array.
        }
        char& CharacterAt(size_t _index)
        {
            return (char&)CCharacterAt(_index); //Returns the CCharacterAt as a non-constant.
        }
        const char& CCharacterAt(size_t _index) const //Const version of CharacterAt, for all your const needs.
        {
            return CStr()[_index]; //Array index in the char array.
        }
        bool EqualTo(const String& _other) const
        {
            return strcmp(CStr(), _other.CStr()) == 0; //If the strcmp of both string's char arrays is 0 (and therefore the char arrays have the same contents).
        }
        String& Append(const String& _str);
        String& Prepend(const String& _str);
        const char* CStr() const
        {
            return cstr; //Returns internal variable. This way, it is encapsulated. Not sure why you would want to do this when there's an = operator that changes it anyway, but here you go.
        }
        String& ToLower()
        {
            signed char offset = 'a' - 'A'; //Offset from capital to lowercase.
            const unsigned int size = sizeof(cstr) / sizeof(cstr[0]); //Size of the original cstring's array.
            char newstr[size] = ""; //New cstr that can be modified.

            for (unsigned int i = 0; i < size; i++)
            {
                newstr[i] = cstr[i]; //Transfer character to new cstr.
                if (cstr[i] >= 'A' && cstr[i] <= 'Z') //If capital letter.
                {
                    newstr[i] += offset; //Convert capital to lowercase.
                }
            }
            return (String&)String(newstr);
        }
        String& ToUpper()
        {
            signed char offset = 'A' - 'a'; //Offset from lowercase to capital.
            const unsigned int size = sizeof(cstr) / sizeof(cstr[0]); //Size of the original cstring's array.
            char newstr[size] = ""; //New cstr that can be modified.

            for (unsigned int i = 0; i < size; i++)
            {
                newstr[i] = cstr[i]; //Transfer character to new cstr.
                if (cstr[i] >= 'a' && cstr[i] <= 'z') //If lowercase letter.
                {
                    newstr[i] += offset; //Convert lowercase to capital.
                }
            }
            return (String&)String(newstr);
        }
        size_t Find(const String& _str);
        size_t Find(size_t _startIndex, const String& _str);
        String& Replace(const String& _find, const String& _replace);
        String& ReadFromConsole();
        String& WriteToConsole()
        {
            std::cout << CStr(); //Writes the char array to the console.
        }
    public: //External Operators
        bool operator==(const String& _other)
        {
            return EqualTo(_other); //Equal.
        }
        bool operator!=(const String& _other)
        {
            return !(EqualTo(_other)); //Not equal.
        }
        String& operator=(const String& _str)
        {
            return (String&)String(_str); //Returns the String inputted as a String&.
        }
        char& operator[](size_t _index)
        {
            return CharacterAt(_index); //Individual character.
        }
        const char& operator[](size_t _index) const
        {
            return CCharacterAt(_index); //Individual character.
        }
    private: //Internal Variables
        const char* cstr;
};
#endif

int main()
{
    std::cout << "Hello World!\n";
}
