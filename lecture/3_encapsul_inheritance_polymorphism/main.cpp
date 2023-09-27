//
// Created by Тимур Абдуллин on 23.09.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Reform.h"

using namespace std;

int main(){
    Reform example("question.txt");
    example.txtToGift();
    return 0;
}
