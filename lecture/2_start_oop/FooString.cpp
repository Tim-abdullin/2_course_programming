//
// Created by Тимур Абдуллин on 16.09.2023.
//

#include <iostream>
#include "FooString.h"
#include <cstring>

using namespace std;

FooString::FooString(char* tbuf){
    buf = new char[strlen(tbuf) + 1];
    strcpy(buf, tbuf);
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

