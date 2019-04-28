#pragma once
#ifndef  _DOUBLY_ITER_
#define _DOUBLY_ITER
#include "DoublyLinkedList.h"
/**
*	template ���� ���� ����
*/
template <typename T>
class DoublySortedLinkedList;

/**
*	template ���� ���� ����
*/
template <typename T>
struct DoublyNodeType;

/**
*	Iterator class for DoublySortedLinkedList.  (not using header and trailer nodes).
*	���õ� ADT�� ���� ����
*	- ��ü return�ϴ� �޼��忡�� ����� null�� ��� return�� ���� ���� �߻�
*	- ��ü ���ٴ� �����Ͱ� (nullptr�� ����) �� �������� �б⹮ ������ ���� ���� �� ����.
*/
template <typename T>
class DoublyIterator {
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	Initialize m_List and m_pCurPointer. (constructor overloading)
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}

	/**
	*	@brief	���� ��带 ����Ű�� �����Ͱ� null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NotNull();

	/**
	*	@brief	���� ��� �������� ���� ��尡 null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NextNotNull();

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
	*	@brief	Get current data of the list and go to the next node. ���� ���. ��ü��ȯ�� return by value
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to next node.
	*	@return	Return current data of the list.
	*/
	DoublyNodeType<T> GetCurrentNode();

private:
	const DoublySortedLinkedList<T>& m_List;	///< ����� ����Ʈ�� ���� ����
	DoublyNodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
};

template <typename T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr) { return false; }
	return true;
}

// ���� ���Ұ� null���� �˻�
template <typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->Next == NULL) { return false; }
	return true;
}

// ù ��° node
template <typename T>
T DoublyIterator<T>::First() {
	return m_List->m_pFirst->data;
}

// ���� node�� �̵� �� item�� return.
template <typename T>
T DoublyIterator<T>::Next() {
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

// ���� node�� return
template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() {
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->pre->data;
}


#endif 
