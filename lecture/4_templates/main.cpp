#include <iostream>
#include "List.cpp"

using namespace std;

int main(){
    List<double> lst;
    lst.push_back(5.05);
    lst.push_back(90.999);
    lst.push_back(7.77777);

    cout << "Second element = " << lst[2] << endl;

    lst.print_list();
    cout << "Size = " << lst.get_size() << endl;

    lst.insert_node(444.444444, 2);
    lst.print_list();
    cout << "Size = " << lst.get_size() << endl;

    lst.remove_node(1);
    lst.print_list();
    cout << "Size = " << lst.get_size() << endl;

    return 0;
}
