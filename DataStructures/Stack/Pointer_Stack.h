#pragma once
#ifndef _STACK2_
#define _STACK2_
#include<iostream>
using namespace std;

template<typename T>
struct Node {
	T info;
	Node* prev;
};

template<typename T>
class Stack2 {
public:
	Stack2() {
		space = 0;
	}
	~Stack2() { MakeEmpty(); }

	void MakeEmpty();
	int GetSize();
	int push(T data);
	int pop(T& data);
	void print();
private:
	Node<T>* topnode;
	int space;
};

template<typename T>
void Stack2<T>::MakeEmpty() {
	Node<T>* temp = new Node<T>;
	while(topnode->prev!=nullptr) {
		temp = topnode;
		topnode = topnode->prev;
		space--;
	}
	cout << "\tStack Cleared\n";
}

template<typename T>
int Stack2<T>::GetSize() {
	return space;
}

template<typename T>
int Stack2<T>::push(T data) {
	if (space == 0) {
		topnode = new Node<T>;
		topnode->prev = nullptr;
		topnode->info = data;
		space++;
		print();
	}
	else {
		Node<T>* newtop = new Node<T>;
		newtop->info = data;
		newtop->prev = topnode;
		topnode = newtop;
		space++;
		print();
	}
	return 1;
}

template<typename T>
int Stack2<T>::pop(T& data) {
	if (space >0) {
		data = topnode->info;

		Node<T>* temp = new Node<T>;
		temp = topnode;
		topnode = topnode->prev;
		cout << "\tStack Popped : "<<temp->info<<endl;
		delete temp;
		space--;
		print();
		return 1;
	}
	else {
		cout << "\t====Empty Stack=====\n";
		return 0;
	}
}

template<typename T>
void Stack2<T>::print() {
	if (space ==0) {
		cout << "\tEmpty Stack\n";
	}
	else if(space >0){
		Node<T>* temp = new Node<T>;
		int count = space;
		temp = topnode;
		cout << "\t====Stack Top=====\n";
		while(count>0) {
			cout << "\t"<<count << " data : " << temp->info << endl;
			count--;
			temp = temp->prev;
		}
		cout << "\t====Stack Top=====\n";
	}
}

#endif