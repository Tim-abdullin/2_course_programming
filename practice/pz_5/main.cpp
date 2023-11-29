#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Object.h"

int main() {
    int n = 0;
    std::cin >> n;
    std::cin.ignore();

    std::vector<Object> objects_list;

    for (int i = 0; i < n; i++) {
        std::string input;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        // тут можно добавить проверку на правильность считывания строки
        std::string name;
        int length, width, height;
        float weight;

        ss >> name >> length >> width >> height >> weight;

        Object obj_name(name, length, width, height, weight);
        objects_list.push_back(obj_name);
    }


    return 0;
}
