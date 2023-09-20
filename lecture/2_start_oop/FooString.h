//
// Created by Тимур Абдуллин on 16.09.2023.
//
#pragma once

#ifndef INC_2_START_OOP_FOOSTRING_H
#define INC_2_START_OOP_FOOSTRING_H

class FooString {
    char *buf;
public:
    FooString(char* tbuf);
    void show();
    int length();
    bool compare(const FooString& str);
    bool compare(char* str);
    void add(const FooString& str);
    void add(char* str);
};

#endif //INC_2_START_OOP_FOOSTRING_H
