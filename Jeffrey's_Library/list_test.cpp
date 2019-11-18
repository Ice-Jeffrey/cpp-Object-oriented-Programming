#include<iostream>
#include"Jeffrey's_list.hpp"
using namespace std;

int main() {
    cout << "Please input the number of characters" << endl;
    int n;
    cin >> n;
    list<int> l;
    for(int i=0; i<n; i++) 
        l.push_back(i);
    cout << l.size() << endl;

}