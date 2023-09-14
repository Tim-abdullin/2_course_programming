//
// Created by Тимур Абдуллин on 06.09.2023.
//

#include <iostream>
#include <string>

using namespace std;

int var_number_1 (string surname, int var){
    int length_surname = 0;
    for (int i = 0; i < surname.length(); i++){
        length_surname += surname[i];
    }
    return length_surname % var + 1;
}

int var_number_2 (string surname, int var){
    return surname[0] % var + 1;
}

int main(){
    string surname;
    int amount_var = 0;
    int type = 0;
    cout << "Student surname: ";
    cin >> surname;
    cout << "Amount of variants: ";
    cin >> amount_var;
    cout << "Choose variant definition type (1 or 2): ";
    cin >> type;

    cout << "\nStudent's variant: ";
    if (type == 1)
        cout << var_number_1 (surname, amount_var) << endl;
    if (type == 2)
        cout << var_number_2 (surname, amount_var) << endl;

    return 0;
}