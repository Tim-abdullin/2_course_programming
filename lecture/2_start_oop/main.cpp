//
// Created by Тимур Абдуллин on 13.09.2023.
//
// Write a class to work with string. Write tests for every method.

#include <iostream>
#include "FooString.h"

using namespace std;

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
