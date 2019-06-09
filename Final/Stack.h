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
*	@brief 스택에 정보를 추가한다.
*	@pre	temp는 포인터 형식이다.
*	@post	스택에 temp가 입력된다.
*	@param 스택에 입력할 정보.
*	@return	성공하면 1을 반환한다. 스택 오버플로우가 생기면 0 반환.
*/
	int push(T* temp);

	T* pop();



	/**
*	@brief 스택의 크기를 정보를 제공 (길이-1)
*	@pre	없음
*	@post	없음
*	@return 스택의 크기를 리턴(index)
*/
	int Getindex();

	/**
*	@brief index2 정보를 제공
*	@pre	없음
*	@post	없음
*	@return index2
*/
	int Getindex2();

	/**
*	@brief Index2값에 index1값을 넣는다.
*	@pre	없음
*	@post	index2=index1;
*	@return 1
*/
	int EqualizeIndex();

	/**
*	@brief in번째 인덱스의 정보를 제공.
*	@pre	없음
*	@post	in번째 인덱스의 정보가 반환된다.
*	@return	in번 째 데이터를 포인터 형식으로 반환한다.
*/
	T* Get(int in);

	/**
*	@brief 스택의 크기(index)를 하나 증가한다.
*	@pre	없음
*	@post	index+=1;
*	@return	1을 반환한다.
*/
	int IncreaseIndex();

	/**
*	@brief 스택의 크기(index)를 하나 감소한다.
*	@pre	없음
*	@post	index-=1;
*	@return	1을 반환한다.
*/
	int DecreaseIndex();

	/**
*	@brief index2의 크기를 설정한다..
*	@pre	없음
*	@post	index=innumber;
*	@params innumber는 index2의 숫자가 된다.
*	@return	1을 반환한다.
*/
	int SetIndex2(int innumber);

	/**
*	@brief 스택에 있는 데이터를 순차적으로 화면에 출력. 충복된 데이터
*	@pre	없음
*	@post	스택의 데이터가 모두 출력
*	@return	없음.
*/
	void print();

	/**
*	@brief 스택을 초기화
*	@pre	없음
*	@post	스택이 초기화된다.
*	@return	없음.
*/
	void Reset();
};

template<typename T>
int Stack<T>::push(T* temp) {
	if (index1 < 10) {//더 넣을 수 있음.
		/*
		for (int i = 0; i < index1 + 1; i++) {//겹치는 거 있나 확인.
			if (temp->GetName() == list[i]->GetName()) {//겹칠 때
				int j;
				for (j = i; j < index1; j++) {//삭제
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
	else//더 넣을 수 없음
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