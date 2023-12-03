#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Object.h"

void search(const std::vector<Object*>& object_list, int param, char op, const std::string& value, std::vector<Object*>& filtered_list, bool searchPerformed) {
    std::vector<Object*> temp_list;

    for (const auto& obj : object_list) {
        std::string obj_name;
        float obj_value = 0;
        switch (param) {
            case 1: obj_name = obj->get_name(); break;
            case 2: obj_value = obj->get_len(); break;
            case 3: obj_value = obj->get_width(); break;
            case 4: obj_value = obj->get_height(); break;
            case 5: obj_value = obj->get_weight(); break;
        }
        if ((param == 1 && obj_name == value) ||
            (param != 1 && ((op == '>' && obj_value > std::stof(value)) ||
                            (op == '<' && obj_value < std::stof(value)) ||
                            (op == '=' && obj_value == std::stof(value))))) {
            temp_list.push_back(obj);
        }
    }
    if (searchPerformed) {
        std::vector<Object *> intersection;
        for (const auto &obj: temp_list) {
            if (std::find(filtered_list.begin(), filtered_list.end(), obj) != filtered_list.end()) {
                intersection.push_back(obj);
            }
        }
        filtered_list = intersection;
    } else {
        filtered_list = temp_list;
    }
}

void show(const std::vector<Object*>& list) {
    for (const auto& obj : list) {
        std::cout << obj->get_name() << ' '
                  << obj->get_len() << ' '
                  << obj->get_width() << ' '
                  << obj->get_height() << ' '
                  << obj->get_weight() << std::endl;
    }
}

void reset(std::vector<Object*>& filtered_list) {
    filtered_list.clear();
}

void commandProcessing (const std::vector<Object*>& object_list, std::vector<Object*>& filtered_list, int n) {
    bool searchPerformed = false;
    for (int i = 0; i < n; i++) {
        short command;
        std::cin >> command;
        if (command == 1) {
            int param;
            char op;
            std::string value;
            std::cin >> param >> op >> value;
            search(object_list, param, op, value, filtered_list, searchPerformed);
            searchPerformed = true;
        }
        if (command == 2) {
            if (searchPerformed) {
                if (!filtered_list.empty()) {
                    show(filtered_list);
                } else {
                    std::cout << "empty" << std::endl;
                }
            } else {
                show(object_list);
            }
        }
        if (command == 3) {
            reset(filtered_list);
        }
    }
}


int main() {
    int n_obj = 0;
    int n_comm = 0;
    std::cin >> n_obj;
    std::cin.ignore();

    std::vector<Object*> objects_list;
    std::vector<Object*> filtered_list;

    for (int i = 0; i < n_obj; i++) {
        std::string input;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        // тут можно добавить проверку на правильность считывания строки
        std::string name;
        int length, width, height;
        float weight;

        ss >> name >> length >> width >> height >> weight;

        Object* obj_name = new Object(name, length, width, height, weight);
        objects_list.push_back(obj_name);
    }

    std::cin >> n_comm;

    //  функция обработка команд
    commandProcessing(objects_list, filtered_list, n_comm);

    // очистка памяти
    for (Object* obj : objects_list) {
        delete obj;
    }
    objects_list.clear();

    return 0;
}
