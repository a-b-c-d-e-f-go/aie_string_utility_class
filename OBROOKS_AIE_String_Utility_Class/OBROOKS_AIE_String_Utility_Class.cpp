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
    ~String()
    {
        delete cstr;
        cstr = nullptr;
    }
public: //External Functions
    size_t Length() const
    {
        return strlen(CStr()); //Length of the char array.
    }
    char& CharacterAt(size_t _index)
    {
        char null = 0; //Null character.
        if (_index < 0 || _index > Length()) { return (char&)null; } //Return the null character if index is less than 0 or greater than the length.
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
    String& Append(const String& _str)
    {
        const size_t size1 = sizeof(cstr) / sizeof(cstr[0]); //Size of the original cstring's array.
        const size_t size2 = sizeof(_str.cstr) / sizeof(_str.cstr[0]); //Size of the added cstring's array.
        char newstr[size1 + size2] = ""; //Combined size because the strings will be joined.

        size_t i = 0;
        for (i = 0; i < size1; i++) //Original string.
        {
            newstr[i] = cstr[i];
        }
        for (size_t j = 0; j < size2; j++) //Appended string, continuing after the last one.
        {
            newstr[i + j] = _str.cstr[j];
        }
        return (String&)String(newstr);
    }
    String& Prepend(const String& _str)
    {
        const size_t size1 = sizeof(cstr) / sizeof(cstr[0]); //Size of the original cstring's array.
        const size_t size2 = sizeof(_str.cstr) / sizeof(_str.cstr[0]); //Size of the added cstring's array.
        char newstr[size2 + size1] = ""; //Combined size because the strings will be joined.

        size_t i = 0;
        for (i = 0; i < size2; i++) //Prepended string, continuing after the last one.
        {
            newstr[i] = _str.cstr[i];
        }
        for (size_t j = 0; j < size1; j++) //Original string, continuing after the last one.
        {
            newstr[i + j] = cstr[j];
        }
        return (String&)String(newstr);
    }
    const char* CStr() const
    {
        return cstr; //Returns internal variable. This way, it is encapsulated. Not sure why you would want to do this when there's an = operator that changes it anyway, but here you go.
    }
    String& ToLower()
    {
        signed char offset = 'a' - 'A'; //Offset from capital to lowercase.
        const size_t size = sizeof(cstr) / sizeof(cstr[0]); //Size of the original cstring's array.
        char newstr[size] = ""; //New cstr that can be modified.

        for (size_t i = 0; i < size; i++)
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
        const size_t size = sizeof(cstr) / sizeof(cstr[0]); //Size of the original cstring's array.
        char newstr[size] = ""; //New cstr that can be modified.

        for (size_t i = 0; i < size; i++)
        {
            newstr[i] = cstr[i]; //Transfer character to new cstr.
            if (cstr[i] >= 'a' && cstr[i] <= 'z') //If lowercase letter.
            {
                newstr[i] += offset; //Convert lowercase to capital.
            }
        }
        return (String&)String(newstr);
    }
    size_t Find(const String& _str) //Find from the entire string.
    {
        return Find(0, _str); //Effectively the same as starting at zero.
    }
    size_t Find(size_t _startIndex, const String& _str)
    {
        const size_t size = sizeof(cstr) / sizeof(cstr[0]);
        for (size_t i = _startIndex; i < size; i++)
        {
            if (RecursiveFind(_startIndex, i, _str)) //If the substring was found starting at i.
            {
                return i; //Return the index of the substring.
            }
        }
    }
    bool RecursiveFind(size_t _startIndex, size_t _index, const String& _str)
    {
        if (_index > Length()) //If beyond the end of the string.
        {
            return false;
        }
        //If the character at i for the main string and i - _startIndex from the potential substring are the same.
        else if (CCharacterAt(_index) == _str.CCharacterAt(_index - _startIndex)) //We subtract startIndex here because it is the starting value of i in Find().
        {
            if (_index - _startIndex == _str.Length()) { return true; } //At the end of the potential substring, end recursion.
            else { return RecursiveFind(_startIndex, _index + 1, _str); } //Otherwise, continue recursion.
        }
        return false;
    }
    String& Replace(const String& _find, const String& _replace)
    {
        size_t find_start = Find(_find); //Get the index of the substring to replace.
        size_t find_end = find_start + _find.Length(); //Replaceable substring end.

        const size_t length_offset = (sizeof(_replace.cstr) / sizeof(_replace.cstr[0])) - (sizeof(_find.cstr) / sizeof(_find.cstr[0])); //The size of the replacing substring minus the size of the replaced substring (how much longer/shorter the returned string will be)
        const size_t size = ((sizeof(cstr) / sizeof(cstr[0])) + length_offset); //The size of the original string plus the length offset.
        char newstr[size] = ""; //New cstr that can be modified.

        for (size_t i = 0; i < find_start; i++) //Replicate the string as normal up until the replaced portion.
        {
            newstr[i] = cstr[i]; //Transfer character to new cstr.
        }
        for (size_t i = find_start; i < (find_end + length_offset); i++) //For the length of the replacing substring, add its characters until complete.
        {
            newstr[i] = _replace.cstr[i - find_start]; //Transfer character to new cstr.
        }
        for (size_t i = (find_end + length_offset); i < size; i++) //Finally, replicate the original string as normal afterwards, skipping the replaced substring.
        {
            newstr[i] = cstr[i - length_offset]; //Transfer character to new cstr.
        }
        return (String&)String(newstr);
    }
    String& ReadFromConsole()
    {
        std::string newstr; //New std:string.
        std::cin >> newstr; //Get std:string's contents from console input.
        return (String&)String(newstr.c_str()); //Get the std:string's cstr and make a string out of it.
    }
    void WriteToConsole()
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
