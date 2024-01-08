#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
    char* str;
    static int count;
    int field = 69;
public:
    MyString()
    {
        str = new char[field];
        count++;
    }
    MyString(const char* text)
    {
        str = new char[strlen(text) + 1];
        strcpy_s(str, strlen(text) + 1, text);
        count++;
    }

    MyString(const MyString& other)
    {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
        count++;
    }

    MyString operator++()
    {
        MyString result(*this);
        int overload = strlen(result.str);
        char* temp = new char[overload + 2];
        strcpy_s(temp, overload + 2, result.str);
        temp[overload] = 'x';
        temp[overload + 1] = '\0';
        delete[] result.str;
        result.str = temp;
        return result;
    }

    MyString operator--()
    {
        MyString result(*this);
        int overload = strlen(result.str);
        if (overload > 0)
        {
            char* temp = new char[overload];
            strncpy_s(temp, overload, result.str, overload - 1);
            temp[overload - 1] = '\0';
            delete[] result.str;
            result.str = temp;
        }
        return result;
    }

    MyString operator+(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        char* temp = new char[overload + n + 1];
        strcpy_s(temp, overload + n + 1, result.str);
        for (int i = overload; i < overload + n; ++i)
        {
            temp[i] = 'x';
        }
        temp[overload + n] = '\0';
        delete[] result.str;
        result.str = temp;
        return result;
    }

    MyString operator-(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        if (n < overload)
        {
            char* temp = new char[overload - n + 1];
            strncpy_s(temp, overload - n + 1, result.str, overload - n);
            temp[overload - n] = '\0';
            delete[] result.str;
            result.str = temp;
        }
        else
        {
            delete[] result.str;
            result.str = new char[1];
            result.str[0] = '\0';
        }
        return result;
    }

    void input()
    {
        char buffer[256];
        cout << "Enter your string: ";
        cin.getline(buffer, 256);
        str = new char[strlen(buffer) + 1];
        strcpy_s(str, strlen(buffer) + 1, buffer);
    }
    void output() const
    {
        cout << "String: " << str << endl;
    }

    static int getCount()
    {
        return count;
    }
    ~MyString()
    {
        delete[] str;
        count--;
    }
};

int MyString::count = 0;


int main()
{
    MyString str;
    str.input();
    str.output();
    cout << "Count: " << str.getCount();

}
