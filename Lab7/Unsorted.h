#pragma once
#ifndef _UNSORTED_
#define _UNSORTED_
#define MAX 10
#include"Unsorted_Iter.h"
template<typename T>
class Unsorted_Iterator;

template <typename T>
class UnsortedList {
	friend class Unsorted_Iterator<T>;
private:
	int length;
	T info[10];
public:
	/*
	constructor
	*/
	UnsortedList();

	/*
	destructor
	*/
	~UnsortedList();

	/*	@brief 리스트를 초기화
*	@pre	없음
*	@post  length가 0이 된다.
*	@param 없음
*	@return	없음.
*/
	void MakeEmpty();

	/*	@brief 리스트가 차있는지 확인
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	꽉 차있으면 true, 아니면 false
*/
	bool IsFull();

	/*	@brief 리스트가 비어있는지 확인
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	비어있으면 true, 아니면 false
*/
	bool IsEmpty();

	/*	@brief 리스트의 길이 정보를 제공
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	length를 리턴
*/
	int GetLength() const;

	/*	@brief 리스트를 삽입하는데 사용. i 뒤의 원소를 pushback한다.
*	@pre	없음
*	@post i번째 인덱스에 item이 삽입되고 그 원소들은 한 칸씩 밀린다.
*	@param int i 는 아이템을 삽입할 위치, item은 삽입할 아이템
*	@return 1리턴.
*/
	int Pushback(int i,T item) {//item을 i자리에 넣고 그 뒤로  한 칸씩 미루는 함수
		for (int i = length - 1;i>i;i++) {
			info[i + 1] = info[i];
		}
		info[i] = item;
		return 1;
	}
	
	/*	@brief 리스트에서 아이템 검색
*	@pre	없음
*	@post  없음
*	@param 검색할 아이템의 이름을 받아서 input으로 받는다.
*	@return	찾으면 해당 아이템을 리턴, 아니면 nullptr리턴
*/
	T Get(T item);

	/*	@brief 리스트에 아이템 추가
*	@pre	없음
*	@post  리스트에 아이템이 추가 된다.
*	@param 추가할 아이템을 입력값으로 받는다.
*	@return	성공하면 1, 아니면 0을 리턴
*/
	int Add(T item);

	/*	@brief  리스트에서 아이템 삭제.
*	@pre	없음
*	@post  삭제할 아이템이 리스트에 있으면 삭제된다.
*	@param 삭제할 아이템의 이름을 가지는 입력값을 파라미터로 갖는다.
*	@return	성공시 1, 아니면 0을 리턴.
*/
	int Delete(T item);

	/*	@brief  리스트에서 아이템 대체.
*	@pre	없음
*	@post  대체할 아이템이 리스트에 있으면 해당 아이템이 지정한 아이템과 바뀜.
*	@param 대체할 아이템의 이름을 가지는 입력값을 파라미터로 갖는다.
*	@return	성공시 1, 아니면 0을 리턴.
*/
	int Replace(T item);
	
	/*	@brief  리스트의 원소를 하나씩 화면에 출력
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	없음.
*/
	void print() {
		for (int i = 0;i<length;i++) {
			info[i]->DisplayRecordOnScreen();

		}
	}
};

template<typename T>
UnsortedList<T>::UnsortedList() {
	length = 0;
}

template<typename T>
UnsortedList<T>::~UnsortedList() {
	MakeEmpty();
}

template<typename T>
void UnsortedList<T>::MakeEmpty() {
	length = 0;
}

template<typename T>
bool UnsortedList<T>::IsFull() {
	if (length >= MAX)
		return true;
	return  false;
}
template<typename T>
bool UnsortedList<T>::IsEmpty() {
	if (length ==0)
		return true;
	return  false;
}
template<typename T>
int UnsortedList<T>::GetLength() const {
	return length;
}

template<typename T>
T UnsortedList<T>::Get(T item) {
	
	Unsorted_Iterator<T> list(*this);
	bool found = false;
	if (list.GetCurrentNode()->GetName() == item->GetName()) {
		cout << "\t=====Item Found!=====\n";
		item = list.GetCurrentNode();
		found = true;
	}
	while (list.NextNotNull()) {
		list.Next();
		if (list.GetCurrentNode()->GetName() == item->GetName()) {
			cout << "\t=====Item Found!=====\n";
			item = list.GetCurrentNode();
			found = true;
		}
	}
	if (found==true) {
		return item;
	}
	cout << "\t======No Such Item=====\n";
	return nullptr;
}

template<typename T>
int UnsortedList<T>::Add(T item) {
	Unsorted_Iterator<T> list(*this);
	if (!list.NotNull()) { 
		info[0] = item; 
		length++; 
		cout << "\t=====Item Added!=====\n";
		return 1;
	}
	if (list.GetCurrentNode()->GetName()==item->GetName()) {
		cout << "\t=====Same Item Already Exist!=====\n";
		return 0;
		
	}
	else if (list.GetCurrentNode()->GetName() >item->GetName()) {
		for (int i = length;i>0;i--) {
			info[i] = info[i - 1];
		}
		info[0] = item;
		length++;
		cout << "\t=====Item Added!=====\n";
		return 1;
	}
	while (list.NextNotNull()) {
		list.Next();
		if (list.GetCurrentNode()->GetName() == item->GetName()) {
			cout << "\t=====Same Item Already Exist!=====\n";
			return 0;
		}
		else if (list.GetCurrentNode()->GetName() > item->GetName()) {
			for (int i = length; i > list.GetCur_pointer(); i--) {
				info[i] = info[i - 1];
			}
			info[list.GetCur_pointer()] = item;
			length++;
			cout << "\t=====Item Added!=====\n";
			return 1;
		}
	}
	//이 아래 케이스는 맨 끝에 넣어야 하는 경우
	info[length] = item;
	length++;
	cout << "\t=====Item Added!=====\n";
	
	return 1;
}

template<typename T>
int UnsortedList<T>::Delete(T item) {
	//Unsorted_Iterator<T> list(*this);
	//if (list.GetCurrentNode()) {}
	return 1;
}

template<typename T>
int UnsortedList<T>::Replace(T item) {
	return 1;
}

#endif // !_UNSORTED_
