//
// Created by Тимур Абдуллин on 03.10.2023.
//
#include <iostream>
#include "List.h"

template<typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::List(const List &other) {
    size = 0;
    head = nullptr;

    Node* otherCurrent = other.head;
    while (otherCurrent) {
        push_back(otherCurrent -> data);
        otherCurrent = otherCurrent->ptrNext;
    }
}


template<typename T>
List<T>::List(List&& other) {
    size = other.size;
    head = other.head;

    other.size = 0;
    other.head = nullptr;
}

template<typename T>
List<T>::~List(){
    while (head) {
        Node* temp = head;
        head = head -> ptrNext;
        delete temp;
    }
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr){
        head = new Node(data);
    }
    else {
        Node* current = this -> head;
        while(current -> ptrNext != nullptr) {
            current = current->ptrNext;
        }
        current -> ptrNext = new Node(data);
    }
    size++;
}

template<typename T>
T &List<T>::operator[](int index) {
    int counter = 0;
    Node *current = this -> head;

    while(current != nullptr) {
        if (counter == index) {return current -> data;}
        current = current -> ptrNext;
        counter++;
    }
}

template<typename T>
void List<T>::print_list() {
    Node* current = this -> head;

    while (current){
        std::cout << current->data << "  ";
        current = current -> ptrNext;
    }
    std::cout << std::endl;

}

template<typename T>
void List<T>::insert_node(T data, int pos) {
    if (pos == 0){
        Node* newNode = new Node(data, head);
        head = newNode;
    }
    else{
        Node* prev = nullptr;
        Node* current = this -> head;
        for (int i = 0; i < pos; i++){
            prev = current;
            current = current->ptrNext;
        }
        Node* newNode = new Node(data, current);
        prev->ptrNext = newNode;
    }
    size++;
}

template<typename T>
void List<T>::remove_node(int pos) {
    if (pos == 0){
        Node* temp = head;
        head = head->ptrNext;
        delete temp;
    }
    else{
        Node* prev = nullptr;
        Node* current = head;
        for(int i = 0; i < pos; i++){
            prev = current;
            current = prev->ptrNext;
        }

        prev->ptrNext = current->ptrNext;
        delete current;
    }
    size --;
}