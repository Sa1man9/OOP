#include "MyString.h"
#include<cstring> //strcpy
#include<utility>// for std::swap

// definitions of all the functions

MyString::MyString(){
   data= new char[1];
   length=0; 
   data[0]='\0';
}

//parametrized constructor
MyString::MyString( const char *str){
   data= new char[strlen(str)+1];
    length = strlen(str); 
   strcpy(data, str);
}

//copy constructor
MyString::MyString(const MyString & other){
    data= new char[other.length+1];
    length=other.length;
    strcpy(data, other.data);
}

MyString::~MyString(){
   delete[] data;
}

size_t MyString :: size() const{
    return length;
}
 bool MyString :: empty() const{
    return length==0;
 }

const char *MyString::c_str() const{
    return data;
}

char MyString::operator[](size_t index){
if(index>=length){
    return '\0';
}
return data[index];
}

MyString &MyString :: operator=(const MyString &other){
if(this==&other){
    return *this;
}
delete[] data;

data =new char[other.length +1];
length=other.length;
strcpy(data,other.data);

return *this;
}

MyString &MyString :: operator+=(const MyString &other){
    char *newData = new char[length + other.length +1];
    strcpy(newData,data);
    strcat(newData,other.data);

    delete[] data;

    data=newData;
    length += other.length;

    return *this;
}

size_t MyString:: find(const MyString &substr) const{
    if(substr.length>length){
        return -1;
    }
    for(size_t i=0; i<=length-substr.length;i++){
        size_t j;
        for( j=0;j<substr.length;j++){
            if(data[i+j] !=substr.data[j]){
                break;
            }
        }
        if(j==substr.length){
            return i;
        }
    }
    return -1;
}

void MyString :: append(const MyString &other){
    *this +=other;
}

void MyString :: erase(size_t pos, size_t len){
    if(pos>=length){
        throw std :: out_of_range("position out of range");
    }

    if(len==0){
        return;
    }

    if(len>length-pos){
        len=length-pos;
    }

    size_t newLength= length-len;

    char *newData= new char[newLength +1];

    strncpy(newData, data, pos);

    strcpy(newData + pos, data +pos +len);

    newData[newLength]='\0';

    delete[] data;
    data = newData;

    length = newLength;
    
}

std:: ostream& operator<<(std:: ostream&os, const MyString &str){
    os << str.c_str();
    return os;
 }
