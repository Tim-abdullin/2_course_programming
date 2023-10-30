#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> arr;
    int num = -1;
    double sum = 0;
    double average;
    double temp = 0;
    double result;

    while (num != 0) {
        cin >> num;
        if (num != 0) {
            arr.push_back(num);
            sum += num;
        }
    }

    average = sum / arr.size();

    for (int i : arr) {
        temp += pow(i - average, 2);
    }
    result = sqrt(temp/(arr.size()-1.0));

    cout << result;

    return 0;
}