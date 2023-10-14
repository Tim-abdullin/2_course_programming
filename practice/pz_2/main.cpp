// code from pz_1

#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class DynamicArray{
private:
    int arr_size;
    int16_t *arr;

public:
    // Конструктор
    DynamicArray(int mas_size){
        arr_size = mas_size;
        arr = new int16_t[arr_size];
    }

    // Конструктор копирования
    DynamicArray(const DynamicArray &mas){
        arr_size = mas.arr_size;
        arr = new int16_t[arr_size];
        memcpy(arr, mas.arr, sizeof(int16_t)*arr_size);
    }

    // Деструктор
    ~DynamicArray(){
        delete[] arr;
    }

    // вывод содержимого массива
    void print_array(){
        for (int i = 0; i < arr_size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // возврат длины массива
    int get_size(){
        return arr_size;
    }

    void set_size(int size){
        if (size < 0) {
            throw out_of_range("std:out_of_range");
        }

        auto* tempArr = new int16_t[size];
        memcpy(arr, tempArr, sizeof(int16_t)*arr_size);
        delete [] arr;
        arr = tempArr;
        arr_size = size;
    }

    // возврат значения элемента
    int get_num(int i){
        if (!get_range_check(i)) {
            throw out_of_range("std:out_of_range");
        }
        return arr[i];
    }

    // проверка выхода за границы
    int get_range_check(int i){
        if (i < 0 || i >= arr_size) {
            return 0;
        }
        return 1;
    }

    int check_num(int16_t num){
        if(num >= -100 && num <= 100) return 1;
        else return 0;
    }

    // Сеттер значения в промежутке [-100, 100] и проверяющий выход за границы
    void set_num(int16_t num, int index){
        if (!check_num(num)) {
            throw invalid_argument("std:invalid_argument");
        }
        if (!get_range_check(index)) {
            throw out_of_range("std:out_of_range");
        }
        arr[index] = num;

    }

    // добавление значения в конец массива с расширением его размера
    void append(int16_t newNum){
        if (!check_num(newNum)){
            throw invalid_argument("std:invalid_argument");
        }
        auto *newArr = new int16_t[arr_size + 1];
        for (int i = 0; i < arr_size; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        arr[arr_size] = newNum;
        arr_size++;
    }

    // сложение двух массивов
    void sum(DynamicArray &mas) {
        int opLength = arr_size;
        if (arr_size > mas.get_size()) {
            opLength = mas.get_size();
        }
        for (int i = 0; i < opLength; i++){
            arr[i] += mas.get_num(i);
        }
    }

    // вычитание двух массивов
    void sub(DynamicArray &mas) {
        int opLength = arr_size;
        if (arr_size > mas.get_size()) {
            opLength = mas.get_size();
        }
        for (int i = 0; i < opLength; i++){
            arr[i] -= mas.get_num(i);
        }
    }

    void input_array(){
        int newSize;
        cin >> newSize;

        if (newSize < 0) {
            throw out_of_range ("std:out_of_range");
        }
        set_size(newSize);

        for (int i = 0; i < newSize; i++) {
            int16_t number;
            cin >> number;
            set_num(number, i);
        }
    }
};

int main() {
    DynamicArray mas_1(0);
    DynamicArray mas_2(0);

    try {
        mas_1.input_array();
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }

    try {
        mas_2.input_array();
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        try {
            int command, arr_index;
            cin >> command >> arr_index;

            if (command == 1) {
                int index;
                cin >> index;
                cout << (arr_index==1?mas_1:mas_2).get_num(index) << endl;
            } else if (command == 2) {
                int index, newValue;
                cin >> index >> newValue;
                (arr_index==1?mas_1:mas_2).set_num(newValue, index);
            } else if (command == 3) {
                int newValue;
                cin >> newValue;
                (arr_index==1?mas_1:mas_2).append(newValue);
            } else if (command == 4) {
                (arr_index==1?mas_1:mas_2).print_array();
            } else if (command == 5) {
                (arr_index==1?mas_1:mas_2).sum(mas_2);
            } else if (command == 6) {
                (arr_index==1?mas_1:mas_2).sub(mas_2);
            }
        }
        catch (const invalid_argument &e) {
            cout << e.what() << endl;
        }
        catch (const out_of_range &e) {
            cout << e.what() << endl;
        }
        catch (const exception &e){
            cout << e.what() << endl;
        }
    }

    return 0;
}