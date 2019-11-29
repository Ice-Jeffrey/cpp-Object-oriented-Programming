#pragma once
#include<iostream>
using namespace std;

template<class T>
class queue {
private:
	int capacity;
	int number;
	T buffer[100];
public:
	queue(int c = 100) {
		number = 0;
		capacity = c;
	}
	bool empty() {
		return number == 0;
	}
	void push(T element) {
		buffer[number] = element;
		number++;
	}
	void pop() {
		for (int i = 0; i < number - 1; i++)
			buffer[i] = buffer[i + 1];
		number--;
	}
	T front() {
		return buffer[0];
	}
};