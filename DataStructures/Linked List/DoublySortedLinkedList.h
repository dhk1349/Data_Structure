#pragma once
#ifndef _DOUBLY_
#define _DOUBLY_
#include<iostream>
using namespace std;

template<typename T>
class DoublyIterator;

template<typename T>
struct DoubleNode{
	T info;
	DoubleNode *prev;
	DoubleNode* next;
};

template<typename T>
class DoublyLinked {
	friend class DoublyIterator<T>;
public:
	DoublyLinked() {
		head = new DoubleNode<T>;
		tail=new DoubleNode<T>;
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
	}
	~DoublyLinked() { MakeEmpty(); }
	void MakeEmpty();
	int Add(T data);
	int Delete(T data);
	int Retrieve(T& data);
	void  print();
private:
	DoubleNode<T>* head;
	DoubleNode<T>* tail;
};

template<typename T>
void DoublyLinked<T>::MakeEmpty() {}

template<typename T>
int DoublyLinked<T>::Add(T data) {
	DoublyIterator<T> Iter(*this);
	DoubleNode<T>* temp=new DoubleNode<T>;
	DoubleNode<T>* newadd=new DoubleNode<T>;
	newadd->info = data;
	while (Iter.NextNotNull()) {
		Iter.GetNextItem();
		if (data < Iter.Cur_pointer->info) {
			temp = Iter.Cur_pointer;

			temp->prev->next = newadd;
			newadd->prev = temp->prev;
			newadd->next = temp;
			temp->prev = newadd;
			print();
			return 1;	
		}
		else if (data== Iter.Cur_pointer->info) {
			cout << "\t=====Item With Same Name Exits!!=====\n";
			print();
			return 0;
		}
	}
	Iter.GetNextItem();
	temp = Iter.Cur_pointer;
	temp->prev->next = newadd;
	newadd->prev = temp->prev;
	newadd->next = temp;
	temp->prev = newadd;
	print();
	return 1;
}

template<typename T>
int DoublyLinked<T>::Delete(T data) {
	DoublyIterator<T> Iter(*this);
	DoubleNode<T>* temp=new DoubleNode<T>;
	while (Iter.NextNotNull()) {
		Iter.GetNextItem();
		if (Iter.Cur_pointer->info==data) {
			cout << "\t=====Item Deleted!!=====\n";
			temp = Iter.Cur_pointer;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			print();
			return 1;
		}
	}
	cout << "\t=====No Such Item=====\n";
	return 0;
}

template<typename T>
int DoublyLinked<T>::Retrieve(T& data) {
	DoublyIterator<T> Iter(*this);
	while (Iter.NextNotNull()) {
		Iter.GetNextItem();
		if (Iter.Cur_pointer->info==data) {
			cout << "\t=====Item Found=====\n";
			data = Iter.Cur_pointer->info;
			return 1;
		}
	}
	cout << "\t=====No Such Item=====\n";
	return 0;
}

template<typename T>
void DoublyLinked<T>::print() {
	DoublyIterator<T> Iter(*this);
	cout << "\t=====List Top=====\n";
	while (Iter.NextNotNull()) {
		Iter.GetNextItem();
		if (Iter.Cur_pointer->next!=nullptr) {
			cout << "\t data : " << Iter.Cur_pointer->info << endl;
		}
	}
	cout << "\t====List Bottom====\n";
}
#endif