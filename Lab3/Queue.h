#pragma once

#ifndef _QUEUE_H
#define _QUEUE_H
#include<iostream>
using namespace std;

template <typename T>
class Queue {
private:
	T *list[10];
	int index;
public:
	Queue() {
		index = -1;
	}
	~Queue() {}
	int enque(T* temp);
	T* deque();
	int Getindex();
	T* Get(int in);
	int DecreaseIndex();
	void print();
};

template<typename T>
int Queue<T>::enque(T* temp) {
	if (index < 10) {//�� ���� �� ����.
		for (int i = 0;i<index+1;i++) {//��ġ�� �� �ֳ� Ȯ��.
			if (temp->GetName()==list[i]->GetName()) {//��ĥ ��
				int j;
				for (j = i ; j<index; j++) {//����
					list[j] = list[j + 1];
				}
				list[index] = temp;
				return 1;
			}
		}
		index += 1;
		list[index] = temp;
		return 1;
	}
	else//�� ���� �� ����
	{
		return 0;
	}
}

template<typename T>
T* Queue<T>::deque() {
	T *temp;
	temp = new T;
	if (index>=0) {//�� ���� �ִ�.
		temp = list[0];
		for (int i = 0;i<index;i++) {
			list[i] = list[i + 1];
		}
		index--;
		return temp;
	}
	else {//�� ���� ����.
		cout << "QUEUE is EMPTY!!\n";
		return temp;
	}
}
template<typename T>
int Queue<T>::Getindex() {
	return index;
}

template<typename T>
int Queue<T>::DecreaseIndex() {
	index -= 1;
	return 1;
}

template<typename T>
T* Queue<T>::Get(int in) {
	return list[in];
}


template<typename T>
void Queue<T>::print() {
	for (int i = 0;i<index+1;i++) {
		cout <<"\t"<< i + 1 << ":  ";
		cout << list[i]->GetName() << endl;;
	}
}


#endif _