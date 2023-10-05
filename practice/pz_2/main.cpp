// code from pz_1

#include <iostream>
#include <cstring>

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

    // возврат значения элемента
    int get_num(int i){
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
            throw invalid_argument("Value must be un range [-100, 100]");
        }
        if (!get_range_check(index)) {
            throw out_of_range("Index out of range");
        }
        arr[index] = num;

    }

    // добавление значения в конец массива с расширением его размера
    void append(int16_t newNum){
        if (!check_num(newNum)){
            throw invalid_argument("Value must be un range [-100, 100]");
        }
        auto *newArr = new int16_t[arr_size + 1];
        for (int i = 0; i < arr_size; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        delete[] newArr;
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
};

int main() {
    try{
        int size_1;
        cin >> size_1;
        if (size_1 < 0) {
            throw invalid_argument("Array 1 size must be 0 or positive integer");
        }
        DynamicArray mas_1(size_1);
        for (int i = 0; i < size_1; i++) {
            int16_t number;
            cin >> number;
            mas_1.set_num(number, i);
        }

        int size_2;
        cin >> size_2;
        if (size_2 < 0) {
            throw invalid_argument("Array 2 size must be 0 or positive integer");
        }
        DynamicArray mas_2(size_2);
        for (int i = 0; i < size_2; i++) {
            int16_t number;
            cin >> number;
            mas_2.set_num(number, i);
        }

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int command, arr_index;
            cin >> command >> arr_index;
            if (arr_index == 1) {
                if (command == 1) {
                    int index;
                    cin >> index;
                    if (index <0 || index >= size_1) {
                        throw out_of_range("Index out of Array 1 range");
                    }
                    cout << mas_1.get_num(index) << endl;
                } else if (command == 2) {
                    int index, newValue;
                    cin >> index >> newValue;
                    if (index <0 || index >= size_1) {
                        throw out_of_range("Index out of Array 1 range");
                    }
                    mas_1.set_num(newValue, index);
                } else if (command == 3) {
                    int newValue;
                    cin >> newValue;
                    mas_1.append(newValue);
                } else if (command == 4) {
                    mas_1.print_array();
                } else if (command == 5) {
                    mas_1.sum(mas_2);
                } else if (command == 6) {
                    mas_1.sub(mas_2);
                }
            }
            if (arr_index == 2) {
                if (command == 1) {
                    int index;
                    cin >> index;
                    if (index <0 || index >= size_2) {
                        throw out_of_range("Index out of Array 2 range");
                    }
                    cout << mas_2.get_num(index) << endl;
                } else if (command == 2) {
                    int index, newValue;
                    cin >> index >> newValue;
                    if (index <0 || index >= size_1) {
                        throw out_of_range("Index out of Array 2 range");
                    }
                    mas_2.set_num(newValue, index);
                } else if (command == 3) {
                    int newValue;
                    cin >> newValue;
                    mas_2.append(newValue);
                } else if (command == 4) {
                    mas_2.print_array();
                } else if (command == 5) {
                    mas_2.sum(mas_2);
                } else if (command == 6) {
                    mas_2.sub(mas_2);
                }
            }
        }
    }
    catch (const invalid_argument &e) {
        cerr << "Invalid argument: " << e.what() << endl;
    }
    catch (const out_of_range &e) {
        cerr << "Out of range: " << e.what() << endl;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}