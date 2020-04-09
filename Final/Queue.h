#pragma once

#ifndef _QUEUE_H
#define _QUEUE_H
#include<iostream>
using namespace std;

template <typename T>
class Queue {
private:
	T *list[100];
	int index;
public:

	/*
	* default constructor
	*/
	Queue() {index = -1;}

	/*
	* destructor
	*/
	~Queue() {}

	/**	
*	@brief ť�� ������ �߰��Ѵ�.
*	@pre	temp�� ������ �����̴�.
*	@post	ť�� temp�� �Էµȴ�.
*	@param ť�� �Է��� ����. 
*	@return	�����ϸ� 1�� ��ȯ�Ѵ�. ť �����÷ο찡 ����� 0 ��ȯ.
*/
	int enque(T* temp);

	/**
*	@brief ť���� ���� ���� �Է� �� ������ ������.
*	@pre	����
*	@post	ť���� ���� ���� �Էµ� ������ ����������, ť�� ���̰� 1 �پ���. 
*	@return	Type T�� �������� ���� ���� �Էµ� ������ ����������, ť�� ����ִٸ� ����ִ� type T�� ���ϵȴ�.
*/
	T* deque();
	
	/**
*	@brief ť�� ũ�⸦ ������ ���� (����-1)
*	@pre	����
*	@post	����
*	@return ť�� ũ�⸦ ����(index)
*/
	int Getindex();
	
	/**
*	@brief in��° �ε����� ������ ����.
*	@pre	����
*	@post	in��° �ε����� ������ ��ȯ�ȴ�.
*	@return	in�� ° �����͸� ������ �������� ��ȯ�Ѵ�.
*/
	T* Get(int in);
	
	/**
*	@brief ť�� ũ��(index)�� �ϳ� �����Ѵ�. 
*	@pre	����
*	@post	index-=1;
*	@return	1�� ��ȯ�Ѵ�.
*/
	int DecreaseIndex();
	
	/**
*	@brief ť�� �ִ� �����͸� ���������� ȭ�鿡 ���. �溹�� ������
*	@pre	����
*	@post	ť�� �����Ͱ� ��� ���
*	@return	����.
*/
	void print();

	/**
*	@brief ť�� �ʱ�ȭ
*	@pre	����
*	@post	ť�� �ε����� -1�̵�
*	@return	����.
*/
	void Reset() {
		index = -1;
	}
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