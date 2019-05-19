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
	UnsortedList();
	~UnsortedList();
	void MakeEmpty();
	bool IsFull();
	bool IsEmpty();
	int GetLength() const;
	int Pushback(int i,T item) {//item을 i자리에 넣고 그 뒤로  한 칸씩 미루는 함수
		for (int i = length - 1;i>i;i++) {
			info[i + 1] = info[i];
		}
		info[i] = item;
		return 1;
	}
	
	T Get(T item);
	int Add(T item);
	int Delete(T item);
	int Replace(T item);
	
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
