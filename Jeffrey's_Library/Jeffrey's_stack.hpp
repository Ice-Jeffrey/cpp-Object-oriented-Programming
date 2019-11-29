#pragma once
#include<iostream>
using namespace std;

template<class T>
class stack {
private:
	int capacity;
	int number;
	T buffer[100];
public:
	stack(int c = 100) {
		capacity = c;
		number = 0;
	}
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
        buffer[number] = element;
        number++;
	}
	void pop() {
		number--;
	}
};