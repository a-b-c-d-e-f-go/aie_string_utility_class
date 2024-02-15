#include <iostream>
#include <vector>
#include <string>

#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
public: //External Constructors
    String() //No input.
    {
        SetVStr("", 1);
    }
    String(const char* _str, size_t len) //Input is another cstr.
    {
        SetVStr(_str, len);
    }
    String(const String& _other) //Input is another string.
    {
        vstr = _other.vstr;
    }
    String(const std::vector<char> _str) //Input is a char vector.
    {
        vstr = _str;
    }
    ~String()
    {
        vstr.clear(); //Remove all elements.
        vstr.shrink_to_fit(); //Free memory.
    }
public: //External Functions
    const size_t Length() const //Returns an integer representing the count of characters up to the null termination character.
    {
        return vstr.size();
    }
    char& CharacterAt(size_t _index)
    {
        return (char&)CCharacterAt(_index); //Returns the CCharacterAt as a non-constant.
    }
    const char& CCharacterAt(size_t _index) const //Const version of CharacterAt, for all your const needs. Really don't know why this was in the assignment template.
    {
        if (_index < 0 || _index >= Length()) { return '\0'; } //If index is less than 0 or greater than length, return '\0'.
        return CStr()[_index]; //Array index in the char array.
    }
    bool EqualTo(const String& _other) const //Returns true if _other contains the same characters.
    {
        return (strcmp(CStr(), _other.CStr()) == 0); //If the strcmp of both string's char arrays is 0 (and therefore the char arrays have the same contents).
    }
    String Append(const String& _str) //Adds _str to the end of the string.
    {
        std::vector<char> newstr = {}; //Undefined size, can still be used as an array later.
        size_t i = 0;
        size_t j = 0;

        while (vstr[i] != 0) //Original string. Loops until the null character.
        {
            newstr.push_back(vstr[i]);
            i++;
        }
        while (_str.vstr[j] != 0) //Appended string, continuing after the last one.
        {
            newstr.push_back(_str.vstr[j]);
            j++;
        }
        newstr.push_back(0); //Add null character.
        return String(newstr);
    }
    String Prepend(const String& _str) //Adds _str to the beginning of the string.
    {
        std::vector<char> newstr = {}; //Undefined size, can still be used as an array later.
        size_t i = 0;
        size_t j = 0;

        while (_str.vstr[i] != 0) //Prepended string. Loops until the null character.
        {
            newstr.push_back(_str.vstr[i]);
            i++;
        }
        while (vstr[j] != 0) //Original string, continuing after the last one.
        {
            newstr.push_back(vstr[j]);
            j++;
        }
        newstr.push_back(0); //Add null character.
        return String(newstr);
    }
    const char* CStr() const //Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
    {
        return vstr.data(); //Returns internal variable. This way, it is encapsulated. Not sure why you would want to do this when there's an = operator that changes it anyway, but here you go.
    }
    String ToLower() //Convert all characters to lowercase.
    {
        std::vector<char> newstr = vstr; //Copy of cstr.
        signed char offset = 'a' - 'A'; //Offset from capital to lowercase.
        size_t i = 0;

        while (vstr[i] != 0) //Loops until the null character.
        {
            if (vstr[i] >= 'A' && vstr[i] <= 'Z') //If capital letter.
            {
                newstr[i] += offset; //Convert capital to lowercase.
            }
            i++;
        }
        return String(newstr);
    }
    String ToUpper() //Convert all characters to uppercase.
    {
        std::vector<char> newstr = vstr; //Copy of cstr.
        signed char offset = 'A' - 'a'; //Offset from lowercase to capital.
        size_t i = 0;

        while (vstr[i] != 0) //Loops until the null character.
        {
            if (vstr[i] >= 'a' && vstr[i] <= 'z') //If lowercase letter.
            {
                newstr[i] += offset; //Convert lowercase to capital.
            }
            i++;
        }
        return String(newstr);
    }
    int Find(const String& _str) //Find from the entire string.
    {
        return Find(0, _str); //Effectively the same as starting at zero.
    }
    int Find(size_t _startIndex, const String& _str) //Returns the location of _str. Beginning the search from _startIndex.
    {
        size_t i = _startIndex;
        while (vstr[i] != 0) //Loops until the null character.
        {
            //std::cout << "i = " << i << "\n"; //Debug - displays i.
            if (RecursiveFind(i, 0, _str)) //If the substring was found starting at i.
            {
                return (int)i; //Return the index of the substring.
            }
            i++;
        }
        return -1; //If not found, return -1.
    }
    String SingleReplace(const String& _find, const String& _replace) //Replaces only one instance.
    {
        size_t find_start = Find(_find); //Get the index of the substring to replace.
        if (find_start != -1) //If the substring to replace exists.
        {
            size_t find_end = find_start + _find.Length(); //Replaceable substring end.

            const int length_offset = (int)_replace.vstr.size() - (int)_find.vstr.size(); //The size of the replacing substring minus the size of the replaced substring (how much longer/shorter the returned string will be).
            const size_t total_length = vstr.size() + length_offset; //Final length of the returned string, given the length offset.
            std::vector<char> newstr; //New vstr that can be modified.

            for (size_t i = 0; i < find_start; i++) //Replicate the string as normal up until the replaced portion.
            {
                newstr.push_back(vstr[i]); //Transfer character to new vstr.
            }
            for (size_t i = find_start; i < find_end + length_offset - 1; i++) //For the length of the replacing substring, add its characters until complete.
            {
                newstr.push_back(_replace.vstr[i - find_start]); //Transfer character to new vstr.
            }
            for (size_t i = (find_end + length_offset - 1); i < total_length; i++) //Finally, replicate the original string as normal afterwards, skipping the replaced substring.
            {
                newstr.push_back(vstr[i - length_offset]); //Transfer character to new vstr.
            }
            return String(newstr);
        }
        return (*this);
    }
    String Replace(const String& _find, const String& _replace) //Replaces all occurrences of _find with _replace.
    {
        String replaced = (*this);
        while (replaced.SingleReplace(_find, _replace) != replaced) //TODO: Literally anything better performance-wise than this.
        {
            replaced = replaced.SingleReplace(_find, _replace);
        }
        return replaced;
    }

    static String ReadFromConsole() //Wait for input in the console window and store the result
    {
        std::string newstr; //New std:string.
        std::getline(std::cin, newstr); //Get std:string's contents from console input.
        return String(newstr.c_str(), newstr.length() + 1); //Get the std:string's cstr and make a string out of it. Length is increased by 1 for the \0.
    }
    void WriteToConsole() //Write the string to the console window.
    {
        std::cout << CStr(); //Writes the char array to the console.
    }
public: //External Operators
    bool operator==(const String& _other) //Returns true if lhs == rhs.
    {
        return EqualTo(_other); //Equal.
    }
    bool operator!=(const String& _other)
    {
        return !(EqualTo(_other)); //Not equal.
    }
    void operator=(const String& _str)
    {
        vstr = _str.vstr; //Set to new string.
    }
    char& operator[](size_t _index) //Returns the character located at position n.
    {
        return CharacterAt(_index); //Individual character.
    }
    const char& operator[](size_t _index) const //Returns the character located at position n.
    {
        return CCharacterAt(_index); //Individual character.
    }
    bool operator<(const String& _str) //Returns true if this string comes before rhs in the alphabet.
    {
        return false;
    }
    bool operator>(const String& _str) //Returns true if this string comes after rhs in the alphabet.
    {
        return false;
    }
public: //Internal Variables
    std::vector<char> vstr;
    void SetVStr(const char* arr, size_t len) //Converts char array to char vector.
    {
        for (int i = 0; i < len; i++) //For the array length.
        {
            vstr.push_back(arr[i]); //Add element to vector.
        }
    }
    bool RecursiveFind(size_t _mainIndex, size_t _subIndex, const String& _str) //At every character, it loops through subsequent characters to see if there is a matching string.
    {
        //std::cout << _mainIndex << ": Is " << CCharacterAt(_mainIndex) << " equal to " << _str.CCharacterAt(_subIndex) << "?\n"; //Debug - displays what the recursive function is searching for.
        if (CCharacterAt(_mainIndex) == _str.CCharacterAt(_subIndex)) //If the character at _mainIndex for the main string and _subIndex for the potential substring are the same.
        {
            //std::cout << "Yes\n"; //Debug - displays if the right character was found.
            if (_subIndex >= _str.Length() - 2) { return true; } //If t the end of the potential substring, return true.
            else if (_mainIndex >= Length() - 1) { return false; } //If at the end of the main string and not the potential substring, return false.
            else { return RecursiveFind(_mainIndex + 1, _subIndex + 1, _str); } //Otherwise, continue recursion and iterate both variables.
        }
        return false;
    }
};
#endif

int main()
{
    //Initialize Variables
    String* s1 = new String("Hello", 6);
    String* s2 = new String(", ", 3);
    String* s3 = new String("World\n", 7);
    int num = 0;

    (*s2).Prepend(*s1).Append(*s3).WriteToConsole(); //Hello, World

    //Tests
    std::cout << "Length()\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    std::cout << (*s1).Length() << "\n\n";

    std::cout << "CharacterAt(size_t _index)\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Index: "; std::cin >> num;
    std::cout << (*s1).CharacterAt(num) << "\n\n";

    std::cout << "CCharacterAt(size_t _index)\n";
    std::cout << "Enter String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Index: "; std::cin >> num;
    std::cout << (*s1).CCharacterAt(num) << "\n\n";

    std::cout << "EqualTo(const String& _other)\n";
    std::cout << "Enter String 1: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter String 2: ";  *s2 = String::ReadFromConsole();
    if ((*s1).EqualTo(*s2)) { std::cout << "Strings Are Equal\n\n"; }
    else { std::cout << "Strings Are Not Equal\n\n"; }

    std::cout << "Append(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter String to Append: ";  *s2 = String::ReadFromConsole();
    (*s1).Append(*s2).WriteToConsole(); std::cout << "\n\n";

    std::cout << "Prepend(const String& _str)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter String to Prepend: ";  *s2 = String::ReadFromConsole();
    (*s1).Prepend(*s2).WriteToConsole(); std::cout << "\n\n";

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

    std::cout << "Replace(const String& _find, const String& _replace)\n";
    std::cout << "Enter Main String: ";  *s1 = String::ReadFromConsole();
    std::cout << "Enter Substring to Find & Replace: ";  *s2 = String::ReadFromConsole();
    std::cout << "Enter Replacing Substring: ";  *s3 = String::ReadFromConsole();
    (*s1).Replace(*s2, *s3).WriteToConsole(); std::cout << "\n\n";

    //Cleanup
    delete s1; s1 = nullptr;
    delete s2; s2 = nullptr;
    delete s3; s3 = nullptr;
}
