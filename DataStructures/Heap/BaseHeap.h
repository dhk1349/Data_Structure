#pragma once
#ifndef _BASEHEAP_
#define _BASEHEAP_
#include<iostream>
using namespace std;

template<typename T>
class BaseHeap {
public:
	BaseHeap();
	virtual ~BaseHeap();

	bool IsEmpty();
	bool IsFull();
	int GetLength() const;
	void MakeEmpty();
	virtual int Add(T item);
	virtual int Delete(T item);
	virtual T Dequeue();
	virtual void Retrieve(T&  item, bool& found);
	virtual void print();
	virtual void ReHeapUp(int root, int bottom) = 0;
	virtual void ReHeapDown(int root, int bottom) = 0;
	virtual void Delete(T item, bool &found, int parent) = 0;
	virtual void Retrieve(T& item, bool& found, int parent) = 0;
protected:
	T* Container;
	int Length;
	int Max;
};
template<typename T>
BaseHeap<T>::BaseHeap() {
	Length = 0;
}

template<typename T>
BaseHeap<T>::~BaseHeap() {
	MakeEmpty();
}

template<typename T>
bool BaseHeap<T>::IsEmpty() {
	if (Length = 0)
		return true;
	return false;
}

template<typename T>
bool BaseHeap<T>::IsFull() {
	return false;
}

template<typename T>
int BaseHeap<T>::GetLength() const {
	return Length;
}

template<typename T>
void BaseHeap<T>::MakeEmpty() {
	delete[] Container;
}

template<typename T>
int BaseHeap<T>::Add(T item) {
	Container[Length] = item;
	ReHeapUp(0,Length);
	Length++;
	return 1;
}

template<typename T>
int BaseHeap<T>::Delete(T item) {
	bool found = false;
	Delete(item, found, 0);

	if (found == true)
		Length--;
	else
		return 0;
	return 1;
}

template<typename T>
T BaseHeap<T>::Dequeue() {
	T temp = Container[0];
	Container[0] = Container[Length - 1];
	ReHeapDown(0,Length-2);
	Length--;

	return temp;
}

template<typename T>
void BaseHeap<T>::Retrieve(T&  item, bool& found) {
	Retrieve(item, found, 0);
	if (found==true) {
		cout << item;
	}
	else { cout << "\t Item  Not Found!\n"; }
}

template<typename T>
void BaseHeap<T>::print() {
	for (int i = 0;i<Length;i++) {
		cout << Container[i] <<endl;
	}
}
#endif
