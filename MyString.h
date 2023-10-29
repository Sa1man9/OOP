#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>


class MyString
{
private:
    char* data;
    size_t length;
public:

    MyString();

    MyString(const char * str);

    MyString(const MyString &other);

    ~MyString();

    size_t size() const;

    bool empty() const;

    const char *c_str() const;

    MyString &operator=(const MyString &other);

    MyString &operator+=(const MyString &other);

    char operator[](size_t index);

    size_t find(const MyString &substr) const;

    void append(const MyString &other);

    void erase(size_t pos, size_t len);

    //overloading of insertion operator for easy output
    friend std:: ostream &operator<<(std:: ostream&os, const MyString &str);

};

#endif