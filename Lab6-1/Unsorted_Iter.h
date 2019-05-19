#pragma once
#ifndef _UNSORTITER_
#define _UNSORTITER_
#include<iostream>
using namespace std;
template <typename T>
class UnsortedList;

template<typename T>
class Unsorted_Iterator {
	friend class UnsortedList<T>;
public:
	Unsorted_Iterator(const UnsortedList<T>&list) :Iter_list(list),Cur_pointer(0),size(list.GetLength()) {}

	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NotNull();

	/**
	*	@brief	Get first data of the list.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the first node.
	*	@return	Return first data of the list.
	*/
	T First();
	/**
	*	@brief	Get next data of the current pointer.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the next node.
	*	@return	Return next data of the list.
	*/
	T Next();

	/**
	*	@brief	Get current data of the list and go to the next node. 현재 노드. 객체반환은 return by value
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to next node.
	*	@return	Return current data of the list.
	*/
	T GetCurrentNode();

	bool NextNotNull();

	int GetCur_pointer() { return Cur_pointer; }
private:
	const UnsortedList<T>&  Iter_list;
	int Cur_pointer;
	int size;
};

template<typename T>
bool Unsorted_Iterator<T>::NotNull() {
	if (Iter_list.GetLength() == 0)
	{
		return false;
	}
	return true;
}

template<typename T>
T Unsorted_Iterator<T>::First() {
	return Iter_list[0];
}

template<typename T>
T Unsorted_Iterator<T>::Next() {
	if (Iter_list.GetLength()-1>(Cur_pointer+1)) {//하나 뒤로 이동 가능
		Cur_pointer += 1;
		return Iter_list.info[Cur_pointer];
	}
	Cur_pointer += 1;
	return nullptr;
}

template<typename T>
T Unsorted_Iterator<T>::GetCurrentNode() {
	if (NotNull()) {
		return Iter_list.info[Cur_pointer];
	}
	return nullptr;
}

template<typename T>
bool Unsorted_Iterator<T>::NextNotNull() {
	if (Iter_list.GetLength() - 1 >= Cur_pointer + 1) {
		return true;
	}
	return false;
}
#endif // !_UNSORTITER_
