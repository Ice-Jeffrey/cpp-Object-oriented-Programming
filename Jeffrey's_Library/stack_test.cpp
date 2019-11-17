#include<iostream>
#include"Jeffrey's_stack.hpp"
using namespace std;

int main() {
    cout << "Please input the number of elements: ";
    int n;
    cin >> n;
    stack<int> s;
    int *array = new int[n];
    cout << "Please input the elements: " << endl;
    for(int i=0; i<n; i++) {
        cin >> array[i];
        s.push(array[i]);
    }
    cout << "size: " << s.size() << endl;
    if(s.empty()) 
        cout << "The stack is empty." << endl;
    else
        cout << "Succeeded pushing the elements into the stack!" << endl;
    for (int i=0; i<n; i++) {
        int element = s.top();
        s.pop();
        cout << element << " ";
    }
    cout << endl;
    cout << "size: " << s.size() << endl;

    return 0;
}