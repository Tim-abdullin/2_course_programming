//
// Created by Тимур Абдуллин on 23.09.2023.
//

#include "Reform.h"
#include <iostream>
#include <string>

using namespace std;

Reform::Reform(string oldName){
    oldFileName = oldName;
    newFileName = oldName.substr(0, oldName.length()-4) + ".gift";
}

void Reform::txtToGift(){
    oldFile.open(oldFileName);
    newFile.open(newFileName);

    if(!oldFile.is_open()){
        cerr << "Faild to open .txt file" << oldFileName << endl;
    }
    if(!newFile.is_open()){
        cerr << "Faild to open .gift file" << newFileName << endl;
    }

    string tempStr;
    while(getline(oldFile, tempStr)){
        if(tempStr.empty()){
            continue;
        }
        newFile << tempStr << '{' << endl;

        char answerPref;
        while(getline(oldFile, tempStr) && !tempStr.empty()) {
            if (tempStr[0] == '+') {
                answerPref = '=';
            } else {
                answerPref = '~';
            }
            newFile << answerPref << " " << tempStr.substr(2) << endl;
        }
        newFile << '}' << endl;
    }
    oldFile.close();
    newFile.close();
}