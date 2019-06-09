#pragma once

#ifndef _STACK_H
#define _STACK_H
#include<iostream>
using namespace std;

template <typename T>
class Stack {
private:
	T *list[10];
	int index1;
	int index2;
public:

	/*
	* default constructor
	*/
	Stack() { index1 = -1; index2 = -1; }

	/*
	* destructor
	*/
	~Stack() {}

	/**
*	@brief ���ÿ� ������ �߰��Ѵ�.
*	@pre	temp�� ������ �����̴�.
*	@post	���ÿ� temp�� �Էµȴ�.
*	@param ���ÿ� �Է��� ����.
*	@return	�����ϸ� 1�� ��ȯ�Ѵ�. ���� �����÷ο찡 ����� 0 ��ȯ.
*/
	int push(T* temp);

	T* pop();



	/**
*	@brief ������ ũ�⸦ ������ ���� (����-1)
*	@pre	����
*	@post	����
*	@return ������ ũ�⸦ ����(index)
*/
	int Getindex();

	/**
*	@brief index2 ������ ����
*	@pre	����
*	@post	����
*	@return index2
*/
	int Getindex2();

	/**
*	@brief Index2���� index1���� �ִ´�.
*	@pre	����
*	@post	index2=index1;
*	@return 1
*/
	int EqualizeIndex();

	/**
*	@brief in��° �ε����� ������ ����.
*	@pre	����
*	@post	in��° �ε����� ������ ��ȯ�ȴ�.
*	@return	in�� ° �����͸� ������ �������� ��ȯ�Ѵ�.
*/
	T* Get(int in);

	/**
*	@brief ������ ũ��(index)�� �ϳ� �����Ѵ�.
*	@pre	����
*	@post	index+=1;
*	@return	1�� ��ȯ�Ѵ�.
*/
	int IncreaseIndex();

	/**
*	@brief ������ ũ��(index)�� �ϳ� �����Ѵ�.
*	@pre	����
*	@post	index-=1;
*	@return	1�� ��ȯ�Ѵ�.
*/
	int DecreaseIndex();

	/**
*	@brief index2�� ũ�⸦ �����Ѵ�..
*	@pre	����
*	@post	index=innumber;
*	@params innumber�� index2�� ���ڰ� �ȴ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int SetIndex2(int innumber);

	/**
*	@brief ���ÿ� �ִ� �����͸� ���������� ȭ�鿡 ���. �溹�� ������
*	@pre	����
*	@post	������ �����Ͱ� ��� ���
*	@return	����.
*/
	void print();

	/**
*	@brief ������ �ʱ�ȭ
*	@pre	����
*	@post	������ �ʱ�ȭ�ȴ�.
*	@return	����.
*/
	void Reset();
};

template<typename T>
int Stack<T>::push(T* temp) {
	if (index1 < 10) {//�� ���� �� ����.
		/*
		for (int i = 0; i < index1 + 1; i++) {//��ġ�� �� �ֳ� Ȯ��.
			if (temp->GetName() == list[i]->GetName()) {//��ĥ ��
				int j;
				for (j = i; j < index1; j++) {//����
					list[j] = list[j + 1];
				}
				list[index1] = temp;
				return 1;
			}
		}
		*/
		index1 += 1;
		list[index1] = temp;
		return 1;
	}
	else//�� ���� �� ����
	{
		return 0;
	}
}

template<typename T>
T* Stack<T>::pop() {
	DecreaseIndex();
	return Get(index1+1);
}


template<typename T>
int Stack<T>::Getindex() {
	return index1;
}

template<typename T>
int Stack<T>::Getindex2() {
	return index2;
}

template<typename T>
int Stack<T>::IncreaseIndex() {
	index1 += 1;
	return 1;
}

template<typename T>
int Stack<T>::DecreaseIndex() {
	index1 -= 1;
	return 1;
}

template<typename T>
int Stack<T>::SetIndex2(int innumber) {
	index2 = innumber;
	return 1;
}

template<typename T>
int Stack<T>::EqualizeIndex() {
	index2 = index1;
	return 1;
}
template<typename T>
T* Stack<T>::Get(int in) {
	return list[in];
}

template<typename T>
void Stack<T>::Reset() {
	index1 = 0;
	index2 = -1;
}

template<typename T>
void Stack<T>::print() {
	for (int i = 0; i < index1 + 1; i++) {
		cout << "\t" << i + 1 << ":  ";
		cout << list[i]->GetName() << endl;;
	}
}


#endif _