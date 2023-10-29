#include<iostream>
#include "MyString.h"

using namespace std;
int main()
{
    MyString a="String";
    MyString b="New";
    a+=b;
    cout<<a<<endl;
    return 0;
}