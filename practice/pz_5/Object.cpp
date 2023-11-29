//
// Created by Тимур Абдуллин on 29.11.2023.
//
#include <iostream>
#include "Object.h"

// конструктор по умолчанию
Object::Object() = default;

// конструктор
Object::Object(std::string name, int length, int width, int height, float weight) :
name(name), length(length), width(width), height(height), weight(weight) {}

int Object::get_len() const {return length;}

int Object::get_width() const {return width;}

int Object::get_height() const {return height;}

float Object::get_weight() const {return weight;}
