#include<iostream>
#include"Jeffrey's_queue.hpp"
using namespace std;

int main() {
    cout << "Please input the number of elements: ";
    int n;
    cin >> n;
    queue<int> q;
    int *array = new int[n];
    cout << "Please input the elements: " << endl;
    for(int i=0; i<n; i++) {
        cin >> array[i];
        q.push(array[i]);
    }
    cout << "size: " << q.size() << endl;
    if(q.empty()) 
        cout << "The stack is empty." << endl;
    else
        cout << "Succeeded pushing the elements into the queue!" << endl;
    for (int i=0; i<n; i++) {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;
    cout << "size: " << q.size() << endl;

    return 0;
}