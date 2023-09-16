//
// Created by Тимур Абдуллин on 13.09.2023.
//
// Write a class to work with string. Write tests for every method.

#include <iostream>
#include <cstring>

using namespace std;

class FooString{
private:
    char *buf;

public:
    FooString(char* tbuf);
    ~FooString();
    void show();
    int length();
    bool compare(const FooString& str);
    bool compare(char* str);
    void add(const FooString& str);
    void add(char* str);
};

FooString::FooString(char* tbuf){
    buf = new char[strlen(tbuf) + 1];
    strcpy(buf, tbuf);
}

FooString::~FooString(){
    delete[] buf;
}

void FooString::show(){
    cout << buf << endl;
}

int FooString::length(){
    return strlen(buf);
}

bool FooString::compare(const FooString& str){
    return strcmp(buf, str.buf) == 0;
}

bool FooString::compare(char* str){
    return strcmp(buf, str) == 0;
}

void FooString::add(const FooString& str){
    char *newBuf = new char[strlen(buf) + strlen(str.buf) + 1];
    strcpy(newBuf, buf);
    strcat(newBuf, str.buf);
    delete[] buf;
    buf = newBuf;
}

void FooString::add(char* str){
    char *newBuf = new char[strlen(buf) + strlen(str) + 1];
    strcpy(newBuf, buf);
    strcat(newBuf, str);
    delete[] buf;
    buf = newBuf;
}

int main(){
    FooString str1("Hello");
    if (str1.length() == 5){
        cout << "Test length() passed" << endl;
    }
    else{
        cout << "Test length() failed" << endl;
    }

    FooString str2("World");
    if (not str2.compare(str1)){
        cout << "Test compare() passed" << endl;
    }
    else{
        cout << "Test compare() failed" << endl;
    }

    char str3[] = "Hello";
    if (str1.compare(str3)){
        cout << "Test compare() passed" << endl;
    }
    else{
        cout << "Test compare() failed" << endl;
    }

    FooString str4(" from Timur Abdullin");
    str1.add(str4);
    if (str1.compare("Hello from Timur Abdullin")){
        cout << "Test add() passed" << endl;
    }
    else{
        cout << "Test add() failed" << endl;
    }

    char str5[] = " and C++";
    str1.add(str5);
    if (str1.compare("Hello from Timur Abdullin and C++")){
        cout << "Test add() passed" << endl;
    }
    else{
        cout << "Test add() failed" << endl;
    }
    return 0;
}
