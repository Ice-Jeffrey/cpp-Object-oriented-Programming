#include<iostream>
using namespace std;

template<typename T>
class stack{
    private:
        int capacity = 100;
        int number = 0;
        T buffer[100];
    public:
        bool empty() {
            return number == 0;
        }
        int size() {
            return number;
        }
        T top() {
            return buffer[number - 1];
        }
        void push(T element) {
            if(number < capacity) {
                buffer[number] = element;
                number++;
            }
            else
                cout << "The stack is full, new element cannot be pushed." << endl;                
        }
        void pop() {
            number--;
        }
};