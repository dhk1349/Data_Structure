#pragma once
#ifndef  _STACK_
#define _STACK_
#include<iostream>
#define size 10
using namespace std;
template <typename T>
class Stack {
public:
	Stack() {
		space = size;
		length = -1;
	}
	Stack(int input) {
		info[input];
		space = input;
		length = -1;
	}
	~Stack() {}

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int IsEmpty();
	int push(T data);
	int pop(T& data);
	void print();
private:
	int length;
	T info[size];
	int space;
};

template<typename T>
void Stack<T>::MakeEmpty() {
	length = -1;
}

template<typename T>
int Stack<T>::GetLength() {
	return length;
}

template<typename T>
bool Stack<T>::IsFull() {
	if (length == space- 1) { return true; }
	return false;
}

template<typename T>
int Stack<T>::IsEmpty() {
	if (length == -1) { return true; }
	return false;
}

template<typename T>
int Stack<T>::push(T data) {
	if (!IsFull()) { 
		length++;
		info[length] = data;
		print();
		return 1;
	}
	else {
		cout << "\tList Full\n";
		return 0; 
	}
}

template<typename T>
int Stack<T>::pop(T& data) {
	if (!IsEmpty()) {
		data = info[length];
		length--;
		cout << "\tData Popped : " << data << endl << endl;
		print();
		return 1;
	}
	else { cout << "\tList Empty\n"; }
	return 0;
}

template<typename T>
void Stack<T>::print() {
	cout << "\t=====Stack Top=====\n";
	for (int i = length;i>-1;i--) {
		cout <<"\t"<<i+1<<" Data : "<<info[i]<<endl;
	}
	cout << "\t=====Stack Bottom=====\n";
}
#endif
