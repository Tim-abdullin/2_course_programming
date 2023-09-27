//
// Created by Тимур Абдуллин on 23.09.2023.
//
#pragma once

#ifndef INC_3_ENCAPSUL_INHERITANCE_POLYMORPHISM_REFORM_H
#define INC_3_ENCAPSUL_INHERITANCE_POLYMORPHISM_REFORM_H

#include <string>
#include <fstream>

using namespace std;

class Reform{
private:
    string oldFileName, newFileName;
    ifstream oldFile;
    ofstream newFile;
public:
    Reform(string oldFileName);
    void txtToGift();
};

#endif
