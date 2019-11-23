#include<iostream>
//#include<list>
#include"Jeffrey's_list.hpp"
using namespace std;

int main() {
    cout << "Please input the number of characters: ";
    int n;
    cin >> n;
    list<int> l1;
    for(int i=0; i<n; i++) 
        l1.push_back(i + 1);
    l1.push_front(0);  
    l1.remove(2);
    l1.test_print();
    l1.reverse();
    l1.test_print();      
    return 0;
}