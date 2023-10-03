//
// Created by Тимур Абдуллин on 03.10.2023.
//
#pragma once

#ifndef INC_4_TEMPLATES_LIST_H
#define INC_4_TEMPLATES_LIST_H

template<typename T>
class List{
public:
    List();
    List(const List& other);
    List(List&& other);
    ~List();

    void push_back(T data);
    int get_size() {return size;};

    T& operator[](int index);     // перегрузил[], чтобы выводить элемент как из обычного массива
    void print_list();

    void insert_node(T data, int pos);
    void remove_node(int pos);

private:

    class Node {
    public:
        Node *ptrNext;
        T data;

        Node(T data = T(), Node *ptrNew = nullptr)
                : data(data), ptrNext(ptrNew) {}
    };

    int size;
    Node *head;
};

#endif //INC_4_TEMPLATES_LIST_H
