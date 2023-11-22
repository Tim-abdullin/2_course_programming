#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stack>

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

// O(n^3) алгоритм Флойда-Уоршелла для построения матрицы достижимости (предполагает, что если есть путь от i до k и от k до j, то от i до j есть путь)
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

// O(n^2) поиск в глубину
void depth_search(const map<int, vector<int>>& graph, vector<vector<int>>& table ,int startNode = 1) {
    table[startNode-1][startNode-1] = 1;    // путь в самого себя
    stack<int> stack;
    vector<bool> visited (graph.size(), false);

    stack.push(startNode);
    visited[startNode] = true;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        for (int neighbor : graph.at(current)) {
            if (neighbor == 0) {
                continue;
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
                table[startNode - 1][neighbor - 1] = 1;
            }
        }
    }
//    cout << "Таблица изменена" << endl;
//    for (int i=0; i<table.size(); i++){
//        for (int j=0; j<table[i].size(); j++)
//            cout << table[i][j] << ' ';
//        cout << endl;
//    }
}

int main() {
    int n = 0;
    cin >> n;
    string input;
    map<int, vector<int>> graph {};
    vector<vector<int>> graph_table (n, vector<int> (n));
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
        graph_table[i][i] = 1;    // заполнение пути самого в себя
        for (int connectedNode : pair.second) {
            int j = connectedNode - 1;
            graph_table[i][j] = 1;    // заполнение пути в доступные узлы
        }
    }
//    vector<vector<int>> table_save (graph_table);     // сохранение состояния таблицы для будущих изменений

    floyd_warshell_algorithm(graph_table);

    vector<vector<int>> new_table(n, vector<int>(n, 0));
    for (int i = 1; i < n + 1; i++) {
        depth_search(graph, new_table, i);
    }

    cout << endl << "Матрица достижимости по алгоритму Флойда-Уоршелла:" << endl;
    print_table(graph_table);


    cout << endl << "Матрица достижимости по поиску в глубину:" << endl;
    print_table(new_table);

    return 0;
}