#include<iostream>
#include "Jeffrey's_search.hpp"
using namespace std;

int main() {
    cout << "Please input the number of elements: ";
    int n;
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    cout << "Please input all elements: " << endl;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    cout << "Please input the element you would like to look for: ";
    int e;
    cin >> e;

    //使用顺序查找
    int index_order = InOrderSearch(a, e, n);
    int index_binary = BinarySearch(b, e, n);

    //判断是否找到
    if(index_order == -1) {
        cout << "Element not found using ordered search!" << endl;
    }
    else {
        cout << "The location using ordered search of the element is: " << index_order << endl;
    }
    if(index_binary == -1) {
        cout << "Element not found using binary search!" << endl;
    }
    else {
        cout << "The location using binary search of the element is: " << index_binary << endl;
    }

    return 0;
}