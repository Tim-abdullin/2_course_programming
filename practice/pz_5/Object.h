//
// Created by Тимур Абдуллин on 29.11.2023.
//
#pragma once

#include "iostream"

#ifndef PZ_5_OBJECT_H
#define PZ_5_OBJECT_H

class Object {
private:
    std::string name = "";
    int length = 0;
    int width = 0;
    int height = 0;
    float weight = 0;

public:
    // конструктор по умолчанию
    Object();
    // конструктор
    Object(std::string name, int length, int width, int height, float weight);
    // конструктор копирования
    // деструктор
    int get_len() const;
    int get_width() const;
    int get_height() const;
    float get_weight() const;
};

#endif //PZ_5_OBJECT_H
