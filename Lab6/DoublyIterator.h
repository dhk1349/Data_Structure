#pragma once
#ifndef  _DOUBLY_ITER_
#define _DOUBLY_ITER
#include "DoublyLinkedList.h"
/**
*	template 참조 에러 방지
*/
template <typename T>
class DoublySortedLinkedList;

/**
*	template 참조 에러 방지
*/
template <typename T>
struct DoublyNodeType;


template <typename T>
class DoublyIterator {
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	Initialize m_List and m_pCurPointer. (constructor overloading)
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}

	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NotNull();

	/**
	*	@brief	현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
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
	*	@brief	Get current data of the list and go to the next node. 현재 노드. 객체반환은 return by value
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to next node.
	*	@return	Return current data of the list.
	*/
	DoublyNodeType<T> GetCurrentNode();

private:
	const DoublySortedLinkedList<T>& m_List;	///< 사용할 리스트의 참조 변수
	DoublyNodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
};

template <typename T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr) { return false; }
	return true;
}

// 다음 원소가 null인지 검사
template <typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->next == nullptr) { return false; }
	return true;
}

// 첫 번째 node
template <typename T>
T DoublyIterator<T>::First() {
	return m_List->m_pFirst->data;
}

// 다음 node로 이동 후 item을 return.
template <typename T>
T DoublyIterator<T>::Next() {
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

// 현재 node를 return
template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() {
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->pre->data;
}


#endif 
