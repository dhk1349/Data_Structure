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
	if (index < 10) {//�� ���� �� ����.
		for (int i = 0;i<index+1;i++) {//��ġ�� �� �ֳ� Ȯ��.
			if (temp.GetName()==list[i].GetName()) {//��ĥ ��
				for (int j = i;j<index;j++) {//����
					list[j] = list[j + 1];
				}
				list[index] = temp;
				return 1;
			}
		}
		index += 1;
		list[index] = temp;
	}
	else//�� ���� �� ����
	{
		cout << "QUEUE is FULL\n";
	}
}

template<typename T>
int Queue<T>::deque(T &temp) {
	if (index>=0) {//�� ���� �ִ�.
		temp = list[0];
		for (int i = 0;i<index;i++) {
			list[i] = list[i + 1];
		}
		index--;
		return 1;
	}
	else {//�� ���� ����.
		cout << "QUEUE is EMPTY!!\n";
		return 0;
	}
}

template<typename T>
void Queue<T>::print() {
	cout << "=======�ֱ� ����=======\n";
	for (int i = 0;i<index+1;i++) {
		cout << i + 1 << ":  ";
		cout << list[i].GetName() << endl;;
	}
	cout << "=====================\n";
}


#endif _