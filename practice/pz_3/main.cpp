#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int hash_str(const string& str){
    int hashKey = 0;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        hashKey *= len;
        hashKey += str[i];
    }

    return hashKey;
}

string generate_rand() {
    int min = 3;
    int max = 7;
    string str;
    int strLen = min + rand() % (max - min + 1);

    for (int j = 0; j < strLen; j++) {
        if (rand() % 2 == 0) {
            str.push_back('a' + rand() % 26);
        } else {
            str.push_back('0' + rand() % 10);
        }
    }
    return str;
}

int main() {
    srand(time(NULL));

    string user_string;
    int n_word = 10;

//    cin >> user_string;
//    cout << hash_str(user_string);

    for (int i = 0; i < n_word; i++) {
        cout << generate_rand() << endl;
    }

    return 0;
}
