#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

int calculate_hash(const string& str){
    int hashKey = 10783;
//    int len = str.length();
    for (char ch : str) {
        hashKey = (((hashKey << 5) + hashKey) + ch);
    }

    return hashKey;
}

string generate_rand(mt19937 &gen) {
    uniform_int_distribution<> lenDistribution(3, 7);
    int strLen = lenDistribution(gen);
    string str;

    for (int j = 0; j < strLen; j++) {
        if (gen() % 2 == 0) {
            str.push_back('a' + rand() % 26);
        } else {
            str.push_back('0' + rand() % 10);
        }
    }
    return str;
}

// Генерация рандомного числа в заданых приделах (для вектора и строки)
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

void modify_string(mt19937 &gen, vector<string> &stringsToChange, int word_index, int symbolIndex) {
    string strToChange = stringsToChange[word_index];

    for (int j = 'a'; j <= 'z'; j++) {
        string temp = strToChange;
        if (j != strToChange[symbolIndex]) {
            temp[symbolIndex] = j;
            stringsToChange.insert(stringsToChange.begin() + word_index + 1, temp);
        }
    }
    for (int j = '0'; j <= '9'; j++) {
        string temp = strToChange;
        if (j != strToChange[symbolIndex]) {
            temp[symbolIndex] = j;
            stringsToChange.insert(stringsToChange.begin() + word_index + 1, temp);
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

int collisions_count(const vector<int> &hashes) {
    int count = 0;
    for (int i = 0; i < hashes.size(); i++) {
        for (int j = 0; j < hashes.size(); j++) {
            if (i == j) {
                continue;
            }
            if (hashes[i] == hashes[j]) {
                count++;
                cout << "Коллизия между " << i << " и " << j << endl;
            }
        }
    }
    return count/2;
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

    // генерация 10000 строк
    for (int i = 0; i < all_word; i++) {
        string generatedString = generate_rand(gen);
        strings.push_back(generatedString);
    }

    // получаем 100 случайных строк их измененных копий, сохранение их в новый вектор
    for (int i = 0; i < choose_word; i++) {
        string strToChange = choose_random_string(gen, strings, stringsToChange);

        int symbolIndex = get_random_index(gen, (int)strToChange.length() - 1);
        modify_string(gen, stringsToChange, i*36, symbolIndex);
    }

    // получим хэши
    short group = 36;   // 36 - сумма кол-ва латинских букв и арабских цифр (a-z, 0-9)
    for (int i = 0; i < choose_word; i++) {
        for (int j = 0; j < group; j++) {
            int hash = calculate_hash(stringsToChange[j+i*group]);
            hashes.push_back(hash);
        }
    }

    // получим кол-во коллизий
    cout << collisions_count(hashes) << endl;

    return 0;
}
