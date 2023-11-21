#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void print_graph (const map<int, vector<int>>& graph) {
    for (const auto& pair : graph) {
        cout << pair.first << ": ";
        for (int num : pair.second) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void print_table (const vector<vector<int>>& table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.size(); ++j) {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
}

// алгоритм для построения матрицы достижимости (предполагает, что если есть путь от i до k и от k до j, то от i до j есть путь)
void floyd_warshell_algorithm(vector<vector<int>>& table) {
    int n = table.size();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = table[i][j] || (table[i][k] && table[k][j]);
            }
        }
    }
    print_table(table);
}

int main() {
    int n = 0;
    cin >> n;
    string input;
    map<int, vector<int>> graph {};
    vector<vector<int>> table (n, vector<int> (n));
    cin.ignore();

//  Заполнение графа
    for (int i = 1; i < n+1; i++) {
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> temp;

        while (ss >> num) {
            temp.push_back(num);
        }
        graph.emplace(i,temp);
    }

//  Построение таблицы доступных путей для конкретного узла
    for (const auto& pair :graph) {
        int i = pair.first - 1;
        table[i][i] = 1;    // заполнение пути самого в себя
        for (int connectedNode : pair.second) {
            int j = connectedNode - 1;
            table[i][j] = 1;    // заполнение пути в доступные узлы
        }
    }

    floyd_warshell_algorithm(table);

    return 0;
}