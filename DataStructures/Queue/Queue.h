#pragma once
#ifndef _QUEUE_
#define _QUEUE_
#include<iostream>
#define size 10
using namespace std;

template<typename T>
class Queue {
public:
	Queue() {
		space = size;
		location = -1;
		lst[size];
	}
	~Queue() { MakeEmpty(); }
	void MakeEmpty();
	int GetLength();
	int Enque(T data);
	int Deque(T& data);
	void print();

private:
	T lst[size];
	int space;
	int location;
};
template<typename T>
void Queue<T>::MakeEmpty() {
	location = -1;
}



template<typename T>
int Queue<T>::GetLength() {
	return location;
}

template<typename T>
int Queue<T>::Enque(T data) {
	if (space>location+1) {
		location++;
		lst[location] = data;
		print();
		return 1;
	}
	else {
		cout<<"\t=====Queue Is Full!\n";
		return 0;
	}
}

template<typename T>
int Queue<T>::Deque(T& data) {
	if (location>-1) {
		data = lst[0];
		cout << "\tDequeued Item : " << data << endl;
		for (int i = 0;i<location;i++) {
			lst[i] = lst[i + 1];
		}
		location--;
		print();
		return 1;
	}
	else {
		cout << "\t=====Queue Is Empty!=====\n";
		return 0;
	}
}

template<typename T>
void Queue<T>::print(){
	if (location>-1) {
		cout << "\t=====Queue Begins=====\n";
		for (int i = 0;i<=location;i++) {
			cout <<"\t"<< i + 1 << " Data : " << lst[i] << endl;
		}
		cout << "\t=====Queue Ends=====\n\n";

	}
	else {
		cout << "\t=====Nothing in the Queue!=====\n";
	}
}
#endif