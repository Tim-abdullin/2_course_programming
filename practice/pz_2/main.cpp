// code from pz_1

#include <iostream>

using namespace std;

class DynamicArray{
private:
    int arr_size{};
    int16_t *arr;

public:
    // Конструктор
    DynamicArray(int mas_size){
        try{
            arr_size = mas_size;
            arr = new int16_t[arr_size];
        }
        catch(bad_alloc &e){
            cerr << "Falled to allocate memory: " << e.what() << endl;
            throw;
        }

    }

    // Конструктор копирования
    DynamicArray(DynamicArray &mas){
        arr_size = mas.get_size();
        arr = new int16_t[arr_size];
        for (int i = 0; i < arr_size; i++){
            arr[i] = mas.get_num(i);
        }
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
        if (i < 0 || i > arr_size) {
            cout << "Out of range. Returned -1" << endl;
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
        try {
            int16_t *newArr = new int16_t[arr_size + 1];
            for (int i = 0; i < arr_size; i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            delete[] newArr;
            arr[arr_size] = newNum;
            arr_size++;
        }
        catch (bad_alloc &e){
            cerr << "Failed to allocate memory: " << e.what() << endl;
            throw;
        }
    }

    // сложение двух массивов
    void sum(DynamicArray &mas) {
        for (int i = 0; i < mas.get_size();i++){
            arr[i] += mas.get_num(i);}
    }

    // вычитание двух массивов
    void sub(DynamicArray &mas) {
        for (int i = 0; i < mas.get_size();i++){
            arr[i] -= mas.get_num(i);}
    }
};

int main(){
    int size_1;
    cin >> size_1;
    DynamicArray mas_1(size_1);
    for (int i = 0; i < size_1; i++){
        int16_t number;
        cin >> number;
        mas_1.set_num(number, i);
    }

    int size_2;
    cin >> size_2;
    DynamicArray mas_2(size_2);
    for (int i = 0; i < size_1; i++){
        int16_t number;
        cin >> number;
        mas_2.set_num(number, i);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int command, arr_index;
        cin >> command >> arr_index;
        if (arr_index == 1){
            if (command == 1){
                int index;
                cin >> index;
                cout << mas_1.get_num(index) << endl;
            }
            else if (command == 2){
                int index, newValue;
                cin >> index >> newValue;
                mas_1.set_num(newValue, index);
            }
            else if (command == 3){
                int newValue;
                cin >> newValue;
                mas_1.append(newValue);
            }
            else if (command == 4){
                mas_1.print_array();
            }
            else if (command == 5){
                mas_1.sum(mas_2);
            }
            else if (command == 6) {
                mas_1.sub(mas_2);
            }
        }
        if (arr_index == 2){
            if (command == 1){
                int index;
                cin >> index;
                cout << mas_2.get_num(index) << endl;
            }
            else if (command == 2){
                int index, newValue;
                cin >> index >> newValue;
                mas_2.set_num(newValue, index);
            }
            else if (command == 3){
                int newValue;
                cin >> newValue;
                mas_2.append(newValue);
            }
            else if (command == 4){
                mas_2.print_array();
            }
            else if (command == 5){
                mas_2.sum(mas_2);
            }
            else if (command == 6){
                mas_2.sub(mas_2);
            }
        }
    }
    return 0;
}