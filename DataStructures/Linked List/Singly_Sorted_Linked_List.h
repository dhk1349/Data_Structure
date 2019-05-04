#pragma once
#ifndef _SINGLYLINKEDLIST_
#define _SINGLYLINKEDLIST_
#include<iostream>
using namespace std;

template<typename T>      
struct Nodes {
	T info;
	Nodes* next;
};

/*
=======This is Singly Linked "Sorted" List=======
*/
template<typename T>
class SinglyLinkedList {
public:
	SinglyLinkedList(){
		Length = 0;
		header = new Nodes<T>;
		Iterator= new Nodes<T>;
		header->next = nullptr;
	}
	~SinglyLinkedList() { MakeEmpty(); }

	void MakeEmpty();
	int GetLength();
	int Add(T data);
	int Delete(T data);
	void Retrieve(T& data);
	T* GetNextItem();
	void ResetList();
	void print();
private:
	Nodes<T>* header;///header���� �ƹ� ������ ����.	
	Nodes<T>* Iterator;
	int Length;
};
template<typename T>
void SinglyLinkedList<T>::MakeEmpty() {
	Nodes<T>* temp=new Nodes<T>;
	Nodes<T>* preaddress = new Nodes<T>;

	while (Iterator->next!=nullptr) {
		ResetList();
		GetNextItem();
		temp = Iterator;
		header->next = Iterator->next;
		delete temp;
	}
	cout << "\t=====Destructor Activated======\n";
}

template<typename T>
int SinglyLinkedList<T>::GetLength() {
	return Length;
}

template<typename T>
int SinglyLinkedList<T>::Add(T data) {
	Nodes<T>* temp = new Nodes<T>;
	temp->info = data;
	temp->next = nullptr;
	Nodes<T>* preaddress=new Nodes<T>;

	ResetList();
	if (Length==0) {
		Iterator->next = temp;
		Length++;
		print();
		return 1;
	}
	while (Iterator->next != nullptr) {
		preaddress = Iterator;
		GetNextItem();
		if (data < Iterator->info) {
			preaddress->next = temp;//temp�� �� �� ����� next�� ����.
			temp->next = Iterator;      //temp�� ���� �ּ� ���� ���� iterator�� ����.
			Length++;
			print();
			return 1;
		}
		else if (data==Iterator->info) {
			cout << "\t=====Same Primary Key Exist!!=====\n";
			print();
			return 0;
		}
	}
	//������ �߰��� ���ϸ� �� �ڿ� �߰��� �ؾ� �Ѵ�.
	Iterator->next = temp;
	Length++;
	print();
	return 1;
}

template<typename T>
int SinglyLinkedList<T>::Delete(T data) {
	Nodes<T>* preaddress=new Nodes<T>;
	Nodes<T>* temp=new Nodes<T>;
	ResetList();
	while (Iterator->next!= nullptr) {
		preaddress = Iterator;
		GetNextItem();
		if (Iterator->info == data) {
			temp = Iterator;
			preaddress->next = Iterator->next;
			delete temp;
			Length--;
			cout << "\t=====Item Deleted=====\n";
			print();
			return 1;
		}
	}
	cout << "\t!!!!!!!!!!!!!!!!!No Such Item!!!!!!!!!!!!!!!!!\n";
	print();
	return 0;
}

template<typename T>
void SinglyLinkedList<T>::Retrieve(T& data) {
	bool found = false;
	ResetList();
	while (Iterator->next!=nullptr) {
		GetNextItem();
		if (Iterator->info==data) {
			cout << "\t=====Item Found=====\n";
			data = Iterator->info;
			found = true;
			break;
		}
	}
	cout << "\t==================\n";
}

template<typename T>
T* SinglyLinkedList<T>::GetNextItem() {
	Iterator = Iterator->next;
	return &Iterator->info;
}

template<typename T>
void SinglyLinkedList<T>::ResetList() {
	Iterator = header;
}

template<typename T>
void SinglyLinkedList<T>::print() {
	ResetList();
	cout << "\t=====Sorted List=====\n";
	while (Iterator->next!=nullptr) {
		GetNextItem();
		cout <<"\t Data : "<< Iterator->info<<endl;
	}
	cout << "\t======================\n\n";

}
#endif // !_SINGLYLINKEDLIST_
