#include <iostream>
#include <map>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    map<string, int> countWord;

    string temp = "";   // временная переменная для формирования слова
    for (auto x : input) {
        if (x == ' '){
            if(!temp.empty()) {
                countWord[temp]++;  // если слова не было, сформируется новая пара, если же есть, то инкрементируется
                temp = "";  // обнуляем слово, когда встретили пробел
            }
        } else {
            temp += x;  // формируем слово
        }
    }
    if(!temp.empty()) {
        countWord[temp]++;  // добавляем последнее слово (цикл закончился, а слово только сформировалось)
    }

    for (auto &x : countWord) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
