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

	/*	@brief ����Ʈ�� �ʱ�ȭ
*	@pre	����
*	@post  length�� 0�� �ȴ�.
*	@param ����
*	@return	����.
*/
	void MakeEmpty();

	/*	@brief ����Ʈ�� ���ִ��� Ȯ��
*	@pre	����
*	@post  ����
*	@param ����
*	@return	�� �������� true, �ƴϸ� false
*/
	bool IsFull();

	/*	@brief ����Ʈ�� ����ִ��� Ȯ��
*	@pre	����
*	@post  ����
*	@param ����
*	@return	��������� true, �ƴϸ� false
*/
	bool IsEmpty();

	/*	@brief ����Ʈ�� ���� ������ ����
*	@pre	����
*	@post  ����
*	@param ����
*	@return	length�� ����
*/
	int GetLength() const;

	/*	@brief ����Ʈ�� �����ϴµ� ���. i ���� ���Ҹ� pushback�Ѵ�.
*	@pre	����
*	@post i��° �ε����� item�� ���Եǰ� �� ���ҵ��� �� ĭ�� �и���.
*	@param int i �� �������� ������ ��ġ, item�� ������ ������
*	@return 1����.
*/
	int Pushback(int i,T item) {//item�� i�ڸ��� �ְ� �� �ڷ�  �� ĭ�� �̷�� �Լ�
		for (int i = length - 1;i>i;i++) {
			info[i + 1] = info[i];
		}
		info[i] = item;
		return 1;
	}
	
	/*	@brief ����Ʈ���� ������ �˻�
*	@pre	����
*	@post  ����
*	@param �˻��� �������� �̸��� �޾Ƽ� input���� �޴´�.
*	@return	ã���� �ش� �������� ����, �ƴϸ� nullptr����
*/
	T Get(T item);

	/*	@brief ����Ʈ�� ������ �߰�
*	@pre	����
*	@post  ����Ʈ�� �������� �߰� �ȴ�.
*	@param �߰��� �������� �Է°����� �޴´�.
*	@return	�����ϸ� 1, �ƴϸ� 0�� ����
*/
	int Add(T item);

	/*	@brief  ����Ʈ���� ������ ����.
*	@pre	����
*	@post  ������ �������� ����Ʈ�� ������ �����ȴ�.
*	@param ������ �������� �̸��� ������ �Է°��� �Ķ���ͷ� ���´�.
*	@return	������ 1, �ƴϸ� 0�� ����.
*/
	int Delete(T item);

	/*	@brief  ����Ʈ���� ������ ��ü.
*	@pre	����
*	@post  ��ü�� �������� ����Ʈ�� ������ �ش� �������� ������ �����۰� �ٲ�.
*	@param ��ü�� �������� �̸��� ������ �Է°��� �Ķ���ͷ� ���´�.
*	@return	������ 1, �ƴϸ� 0�� ����.
*/
	int Replace(T item);
	
	/*	@brief  ����Ʈ�� ���Ҹ� �ϳ��� ȭ�鿡 ���
*	@pre	����
*	@post  ����
*	@param ����
*	@return	����.
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
	//�� �Ʒ� ���̽��� �� ���� �־�� �ϴ� ���
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
