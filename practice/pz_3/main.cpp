#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;

int calculate_hash(const string& str){
    int hashKey = 10783;
//    int len = str.length();
    for (char ch : str) {
        hashKey = (((hashKey << 5) + hashKey) + ch);
    }

    return hashKey;
}

string generate_rand(mt19937 &gen, int mode) {
    int strLen = 0;
    string str;

    if (mode == 0) {
        uniform_int_distribution<> lenDistribution(3, 7);
        strLen = lenDistribution(gen);
    }
    else {
        strLen = mode;
    }

    for (int j = 0; j < strLen; j++) {
        if (gen() % 2 == 0) {
            str.push_back('a' + rand() % 26);
        } else {
            str.push_back('0' + rand() % 10);
        }
    }
    return str;
}

// Генерация рандомного числа в заданных приделах (для вектора и строки)
int get_random_index(mt19937 &gen, int len) {
    uniform_int_distribution<> randIndex(0, len);
    int index = randIndex(gen);
    return index;
}

// получение 100 рандомных строк и их сохранение
string choose_random_string(mt19937 &gen, const vector<string> &strings, vector<string> &stringsToChange) {
    int strIndex = get_random_index(gen, strings.size());
    string strToChange = strings[strIndex];
    stringsToChange.push_back(strToChange);
    return strToChange;
}

void modify_string(mt19937 &gen, vector<string> &stringsToChange, int word_index, int symbolIndex, vector<string> &strings) {
    string strToChange = stringsToChange[word_index];

    for (int j = 'a'; j <= 'z'; j++) {
        string temp = strToChange;
        if (j != strToChange[symbolIndex]) {
            temp[symbolIndex] = j;
            strings.push_back(temp);
        }
    }
    for (int j = '0'; j <= '9'; j++) {
        string temp = strToChange;
        if (j != strToChange[symbolIndex]) {
            temp[symbolIndex] = j;
            strings.push_back(temp);
        }
    }
}

//bool find_values (const int value, const vector<int> &data) {
//    for (const auto& values : data) {
//        if (value == values)
//            return true;
//    }
//    return false;
//}

int collisions_count(const vector<int> &hashes, const vector<string> &strings) {
    int count = 0;
    for (int i = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings.size(); j++) {
            if (i != j && (hashes[i] == hashes[j]) && (strings[i] != strings[j]) ) {
                count++;
                //cout << "Коллизия между " << i << " и " << j << endl;
            }
        }
    }
    cout << "\nВсего коллизий: ";
    return count/2;
}

template <typename  T>
void compare_data(const vector<T> &data) {
    int count = 0;
    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] == data[j]) {
                // Что-то делаем...
                count++;
            }
        }
    }
    auto end_time = chrono::steady_clock::now();
    auto diff = end_time - start_time;
    cout << "Время сравнения: " << chrono::duration <double, milli> (diff).count() << " ms " << count << endl;
}

// вывод векторы типа Т
template <typename T>
void print_vector(const vector<T> &data) {
    for (auto const &value : data) {
        cout << value << endl;
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    const int all_word = 10000;     // кол-во слов
    const int choose_word = 100;
    vector<string> strings; // хранение строк исходных
    vector<string> stringsToChange;
    vector<int> hashes;

    for (int k = 0; k <= 7; k++){
        if (k == 1 or k == 2){
            continue;
        }
        cout << k << "-Й ПРОГОН ПРОГРАММЫ:\n" << endl;

        // генерация 10000 строк
        for (int i = 0; i < all_word; i++) {
            string generatedString = generate_rand(gen, k);
            strings.push_back(generatedString);
        }

        // получаем 100 случайных строк их измененных копий, сохранение их в новый вектор
        for (int i = 0; i < choose_word; i++) {
            string strToChange = choose_random_string(gen, strings, stringsToChange);

            int symbolIndex = get_random_index(gen, (int)strToChange.length() - 1);
            modify_string(gen, stringsToChange, i, symbolIndex, strings);
        }

        // получим хэши
        for (int i = 0; i < strings.size(); i++) {
            int hash = calculate_hash(strings[i]);
            hashes.push_back(hash);
        }

        // получим кол-во коллизий
        cout << collisions_count(hashes, strings) << endl;

        // сравнение строк
        cout << "\nСравнение строк:" << endl;
        compare_data(stringsToChange);

        cout << "\nСравнение хэшей:" << endl;
        compare_data(hashes);

        // очистка памяти
        strings.clear();
        stringsToChange.clear();
        hashes.clear();

        cout << "\n\n\n\n\n\n";
    }

    return 0;
}
