#include<iostream>
using namespace std;

template<class T>
class queue {
    private:
        int capacity = 100;
        int number = 0;
        T buffer[100];
    public:
        bool empty() {
            return number == 0;
        }
        T top() {
            return buffer[0];
        }
        void push(T element) {
            for(int i=0; i<number; i++)
                buffer[i+1] = buffer[i];
            buffer[0] = element;           
        }
        void pop() {
            for(int i=0; i<number-1; i++)
                buffer[i] = buffer[i+1];
        }
}