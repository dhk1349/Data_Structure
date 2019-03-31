#pragma once

#ifndef _QUEUE_H
#define _QUEUE_H
#include<iostream>
using namespace std;

template <typename T>
class Queue {
private:
	T input;
	T list[10];
	int index;
public:
	Queue() {
		index = -1;
	}
	~Queue() {}
	int enque(T temp);
	int deque(T &temp);
	void print();
};

template<typename T>
int Queue<T>::enque(T temp) {
	if (index < 10) {//더 넣을 수 있음.
		for (int i = 0;i<index+1;i++) {//겹치는 거 있나 확인.
			if (temp.GetName()==list[i].GetName()) {//겹칠 때
				for (int j = i;j<index;j++) {//삭제
					list[j] = list[j + 1];
				}
				list[index] = temp;
				return 1;
			}
		}
		index += 1;
		list[index] = temp;
	}
	else//더 넣을 수 없음
	{
		cout << "QUEUE is FULL\n";
	}
}

template<typename T>
int Queue<T>::deque(T &temp) {
	if (index>=0) {//뺄 것이 있다.
		temp = list[0];
		for (int i = 0;i<index;i++) {
			list[i] = list[i + 1];
		}
		index--;
		return 1;
	}
	else {//뺄 것이 없다.
		cout << "QUEUE is EMPTY!!\n";
		return 0;
	}
}

template<typename T>
void Queue<T>::print() {
	cout << "=======최근 폴더=======\n";
	for (int i = 0;i<index+1;i++) {
		cout << i + 1 << ":  ";
		cout << list[i].GetName() << endl;;
	}
	cout << "=====================\n";
}


#endif _