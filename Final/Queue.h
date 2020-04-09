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
*	@brief 큐에 정보를 추가한다.
*	@pre	temp는 포인터 형식이다.
*	@post	큐에 temp가 입력된다.
*	@param 큐에 입력할 정보. 
*	@return	성공하면 1을 반환한다. 큐 오버플로우가 생기면 0 반환.
*/
	int enque(T* temp);

	/**
*	@brief 큐에서 가장 먼저 입력 된 정보를 빼낸다.
*	@pre	없음
*	@post	큐에서 가장 먼저 입력된 정보가 빠져나가고, 큐의 길이가 1 줄어든다. 
*	@return	Type T의 형식으로 가장 먼저 입력된 정보가 빠져나가고, 큐가 비어있다면 비어있는 type T가 리턴된다.
*/
	T* deque();
	
	/**
*	@brief 큐의 크기를 정보를 제공 (길이-1)
*	@pre	없음
*	@post	없음
*	@return 큐의 크기를 리턴(index)
*/
	int Getindex();
	
	/**
*	@brief in번째 인덱스의 정보를 제공.
*	@pre	없음
*	@post	in번째 인덱스의 정보가 반환된다.
*	@return	in번 째 데이터를 포인터 형식으로 반환한다.
*/
	T* Get(int in);
	
	/**
*	@brief 큐의 크기(index)를 하나 감소한다. 
*	@pre	없음
*	@post	index-=1;
*	@return	1을 반환한다.
*/
	int DecreaseIndex();
	
	/**
*	@brief 큐에 있는 데이터를 순차적으로 화면에 출력. 충복된 데이터
*	@pre	없음
*	@post	큐의 데이터가 모두 출력
*	@return	없음.
*/
	void print();

	/**
*	@brief 큐를 초기화
*	@pre	없음
*	@post	큐의 인덱스가 -1이됨
*	@return	없음.
*/
	void Reset() {
		index = -1;
	}
};

template<typename T>
int Queue<T>::enque(T* temp) {
	if (index < 10) {//더 넣을 수 있음.
		for (int i = 0;i<index+1;i++) {//겹치는 거 있나 확인.
			if (temp->GetName()==list[i]->GetName()) {//겹칠 때
				int j;
				for (j = i ; j<index; j++) {//삭제
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
	else//더 넣을 수 없음
	{
		return 0;
	}
}

template<typename T>
T* Queue<T>::deque() {
	T *temp;
	temp = new T;
	if (index>=0) {//뺄 것이 있다.
		temp = list[0];
		for (int i = 0;i<index;i++) {
			list[i] = list[i + 1];
		}
		index--;
		return temp;
	}
	else {//뺄 것이 없다.
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