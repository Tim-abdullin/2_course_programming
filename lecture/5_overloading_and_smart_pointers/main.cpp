//
// Created by Тимур Абдуллин on 03.10.2023.
//
#include <iostream>

template <typename T>
class SmartPointer{
private:
    T* ptr;
public:
    SmartPointer(T* ptr){
        this->ptr = ptr;
    }
    
    ~SmartPointer(){
        delete ptr;
    }

    T& operator*(){
        return *ptr;
    }
};

int main(){
    SmartPointer<int> pointer_a = new int(5);

    std::cout << *pointer_a << std::endl;

    return 0;
}