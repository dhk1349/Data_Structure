#pragma once
#ifndef _DOUBLY_LINKED_LIST_H
#define   _DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType
{
	T data;	///< A data for each node.
	DoublyNodeType* prev;	///< A node pointer of previous node.
	DoublyNodeType* next;	///< A node pointer of next node.}
};
	
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;
public:
	/**
	*	default constructor.
	*/
	DoublySortedLinkedList();

	/**
	*	destructor.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	Determines whether the list is full.
	*	@pre	List has been initialized.
	*	@post	None.
	*	@return	If there is not memory left, throws bad_alloc exception and return true, otherwise false.
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the list is empty.
	*	@pre	List has been initialized.
	*	@post	None.
	*	@return	Return true if the list is empty, otherwise false.
	*/
	bool IsEmpty();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 삭제함.
	*	@pre	리스트가 존재/초기화 완료되어있는 상태여야 함.
	*	@post	일치하는 데이터가 리스트에 있을 경우 삭제됨.
	*	@param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	*	@return 삭제할 일치하는 데이터가 있으면 삭제 후 1, 없으면 0을 리턴.
	*/
	int Delete(T item);

	/**
	*	@brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 새로 채워넣음.
	*	@pre	리스트가 존재/초기화 완료되어있는 상태여야 함.
	*	@post	일치하는 데이터가 리스트에 있을 경우 새로운 데이터로 교체됨.
	*	@param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	*/
	void Replace(T item);


private:
	DoublyNodeType<T>* m_pFirst;	///< Pointer for pointing a first node.
	DoublyNodeType<T>* m_pLast; ///< Last node.
	int m_nLength;	///< Number of node in the list.
};

template<typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList() {
	m_pFirst = nullptr;
	m_pLast = nullptr;
	m_nLength = 0;
}

template<typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList() {
	MakeEmpty();
}

template<typename T>
bool DoublySortedLinkedList<T>::IsFull() {
	//우선 안만듬
}

template<typename T>
bool DoublySortedLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) { return true; }
	return false;
}

template<typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	DoublyIterator<T> iter(*this);
	DoublyNodeType<T> *tempnode=new DoublyNodeType<T>;
	while (iter.NotNull()) {
		tempnode = iter.m_pCurPointer;
		iter.Next();
		delete[] tempnode;
	}
}

template<typename T>
int DoublySortedLinkedList<T>::GetLength()const {
	return m_nLength;
}

template<typename T>
int DoublySortedLinkedList<T>::Add(T item) {
	DoublyIterator<T> iter(*this);
	DoublyNodeType<T> *tempnode=new DoublyNodeType<T>;
	tempnode->data = item;

	if (!iter.NextNotNull()) {//처음 노드가 null인 경우.
		this->m_pFirst->next= tempnode;
		tempnode->prev = m_pFirst;
		tempnode->next = m_pLast;
		m_pLast->prev = tempnode;
		return 1;
	}

	while (iter.NextNotNull()) {//리스트 안에 next값이 존재한다.
		iter.Next();//다음 노드로 이동
		if (tempnode->data<iter.m_pCurPointer) {//다음 노드로 이동할 필요 없음
			tempnode->prev = iter.m_pCurPointer->prev; //tempnode의 pre설정
			iter.m_pCurPointer->prev->next = tempnode; //이전 노드의 next를 tempnode로 설정
			tempnode->next = iter.m_pCurPointer;
			iter.m_pCurPointer->prev = tempnode;
			return 1;
		}
		else if(iter.m_pCurPointer->next==NULL){//맨 마지막이 경우
			tempnode->prev = iter.m_pCurPointer->prev;
			iter.m_pCurPointer->prev->next = tempnode;
			tempnode->next = iter.m_pCurPointer;//m_pLast와 같음.
			iter.m_pCurPointer->prev = tempnode;
			return 1;
		}
		else if(iter.m_pCurPointer->data==tempnode->data){
			cout << "\t동일한 이름이 이미 존재합니다!\n";
			return 1;
		}
	}
	cout << "\tUnexpected Case Occured\n";
	return 0;
}

template<typename T>
int DoublySortedLinkedList<T>::Get(T& item) {
	DoublyIterator<T> iter(*this);
	DoublyNodeType<T> *tempnode=new DoublyNodeType<T>;
	tempnode->data = item;
	bool found=false;
	while (iter.NextNotNull()) {//끝까지 돌아간다.
		iter.Next();
		if (iter.m_pCurPointer->data==tempnode->data) {
			item = iter.m_pCurPointer->data;
			found = true;
			break;
		}
	}
	if (found == true) {
		cout << "\t========Item Found!========\n";
		return 1;
	}
	cout << "\t========Item Not Found!========\n";
	return 0;
}

template<typename T>
void DoublySortedLinkedList<T>::Replace(T item) {
	DoublyIterator<T> iter(*this);
	DoublyNodeType<T> tempnode = item;
	bool found = false;
	while (iter.NextNotNull()) {//끝까지 돌아간다.
		iter.Next();
		if (iter.m_pCurPointer->data == tempnode.data) {
			item = iter.m_pCurPointer->data;
			found = true;
			break;
		}
	}
	if (found == true) {
		cout << "\t========Item Found!========\n";
		return 1;
	}
	cout << "\t========Item Not Found!========\n";
	return 0;
}

template<typename T>
int DoublySortedLinkedList<T>::Delete(T item) {}

#endif//