#include <iostream>

#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
    public:
        String();
        String(const char* _str);
        String(const String& _other);
        ~String();
    public:
        size_t Length() const
        {
            return strlen(CStr()); //Length of the char array.
        }
        char& CharacterAt(size_t _index);
        const char& CharacterAt(size_t _index) const
        {
            return CStr()[_index]; //Array index in the char array.
        }
        bool EqualTo(const String& _other) const
        {
            return strcmp(CStr(), _other.CStr()) == 0; //If the strcmp of both string's char arrays is 0 (and therefore the char arrays have the same contents).
        }
        String& Append(const String& _str);
        String& Prepend(const String& _str);
        const char* CStr() const;
        String& ToLower();
        String& ToUpper();
        size_t Find(const String& _str);
        size_t Find(size_t _startIndex, const String& _str);
        String& Replace(const String& _find, const String& _replace);
        String& ReadFromConsole();
        String& WriteToConsole()
        {
            std::cout << CStr();
        }
    public:
        bool operator==(const String& _other);
        bool operator!=(const String& _other);
        String& operator=(const String& _str);
        char& operator[](size_t _index);
        const char& operator[](size_t _index) const;
    private:
        /*
        * Put your internal data structures and members here
        */
};
#endif

int main()
{
    std::cout << "Hello World!\n";
}
