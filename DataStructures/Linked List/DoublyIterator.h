#pragma once
#ifndef  _DOUBLYITER_
#define _DOBLYITER_
#include"DoublySortedLinkedList.h"
template<typename T>
class DoublyLinked;

template<typename T>
struct DoubleNode;

template<typename T>
class DoublyIterator {
	friend DoublyLinked<T>;
public:
	DoublyIterator(const  DoublyLinked<T> & list):container(list) {
		Cur_pointer = new DoubleNode<T>;
		Cur_pointer = list.head;
	}
	~DoublyIterator() {}
	bool NextNotNull();
	void ResetIter();
	T GetNextItem();

private:
	const DoublyLinked<T>& container;
	DoubleNode<T>* Cur_pointer;
};

template<typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (Cur_pointer->next == nullptr)
		return false;
	return true;
}

template<typename T>
void DoublyIterator<T>::ResetIter() {
	Cur_pointer = container.head;
}

template<typename T>
T DoublyIterator<T>::GetNextItem() {
	if (Cur_pointer->next != nullptr) {
		Cur_pointer = Cur_pointer->next;
	}
	//else //다음 포인터가 null이라는 뜻이니까 이터레이터는 tail에 있다.
		//cout << "\tIterator Ended\n";
	return Cur_pointer->info;
}
#endif
