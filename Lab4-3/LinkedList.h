#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include<iostream>
#include <string>
using namespace std;
/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	default constructor.
	*/
	LinkedList();

	/**
	*	destructor.
	*/
	~LinkedList();

	/**
	*	@brief	리스트를 빈 상태로 초기화 한다.
	*	@pre	None
	*	@post	리스트가 빈 상태가 된다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트가 가지고 있는 원소의 갯수를 리턴
	*	@pre	None.
	*	@post	Function value = 리스트 내부의 원소의 갯수.
	*	@return	리스트 내부의 원소 갯수.
	*/
	int GetLength() const;

	/**
	*	@brief	리스트의 적절한 위치에 .
	*	@pre	리스트가 꽉차 있지 않으며, 동일한 아이템이 리스트에 없다.
	*	@post	리스트에 아이템이 삽입된다.
	*	@return	제대로 추가되면 1을, 그렇지 않으면 0을 리턴.
	*/
	int Add(T item);

	/**
	*	@brief	리스트에서 아이템을 삭제한다.
	*	@pre	리스트가 비어있지 않으며, 삭제할 아이템이 리스트 안에 존재한다.
	*	@post	아이템이 리스트에서 삭제된다.
	*	@return	제대로 삭제되면 1을, 그렇지 않으면 0을 리턴.
	*/
	int Delete(T item);

	/**
	*	@brief	리스트 안에 있는 아이템의 값을 변경한다.
	*	@pre	리스트가 비어있지 않으며, 지정한 아이템이 리스트 안에 존재한다.
	*	@post	아이템의 값이 변경된다.
	*	@return	함수가 제대로 작동했으면 1을, 그렇지 않으면 0을 리턴.
	*/
	int Replace(T item);

	/**
	*	@brief	리스트에서 아이템 키와 일치하는 원소가 있으면 찾아낸다.
	*	@pre	아이템의 primary key가 초기화 되어있다.
	*	@post	리스트 안에 찾고자 하는 key와 일치하는 원소가 있다면 item변수에 그 값이 복사된다.
	*	@return	찾는 원소가 있어서 복사를 했다면 해당 원소를, 그렇지 않으면 NULL을 복사한다.
	*/
	T* Get(T* item);

	/**
	*	@brief	iteration을 위해서 해당 리스트의 포인터를 초기화한다.
	*	@pre	없음
	*	@post	현재 포인터는 리스트 앞에 존재하며, 포인터가 초기화 되었다. 
	*/
	void ResetList();

	/**
	*	@brief	리스트에서 다음 원소를 가져온다.
	*	@pre	현재 포인터(current pointer)가 정의 되어있다. 현재 포인터의 위치가 리스트의 마지막이 아니다.
	*	@post	current pointer가 다음 위치로 이동한다. current pointer가 item에 복사된다.
	*	@param Item에 새롭게 이동한 current pointer의 정보가 저장된다.
	*	@성공하면 1을 리턴, 아니면 0을 리턴.
	*/
	int GetNextItem(T& item);

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	//m_pCurPointer = new NodeType<T>;
	//m_pList = new NodeType<T>;
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (m_pList != NULL)    //여기서 에러
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int LinkedList<T>::Add(T item)
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node=new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (m_nLength==0)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);
			//여기서 curpointer가 null이면 맨앞의 값을 가리킨다.
			if (m_pCurPointer->data.GetName()== node->data.GetName()) {
				return 0;
			}
			if (m_pCurPointer->data.GetName() > node->data.GetName())//curpoint가 삽입할 노드보다 뒤에있어야 할 때.
			{
				if (pre == NULL)//맨앞으로 curpoint가  가 있는 상태 즉 삽입할 노드가 맨앞으로 가야할 때.
				{
					node->next = m_pCurPointer;
					m_pList = node;  //최전방 노드 변경
					break;
				}	//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}

//Delete item from this list.
template <typename T>
int LinkedList<T>::Delete(T item)
{
	bool moreToSearch, found;
	NodeType<T>* pre = NULL;	//변수 선언

	m_pCurPointer = m_pList;//맨 앞으로
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item.GetName() == m_pCurPointer->data.GetName())	//현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;	//찾았으므로 found 값 변경
			if (pre == NULL){
				//여기서 memory loss가 생긴다.
				//delete[] m_pList;
				m_pList = m_pCurPointer->next;	//항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			}
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_nLength--;	//리스트의 길이를 1 줄여준다.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if (found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.
}

//Change value of item which is in this list.
template <typename T>
int LinkedList<T>::Replace(T item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item.GetName() == location->data.GetName())
		{
			found = true;
			item.SetNameFromKB();
			location->data.Setname( item.GetName());
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
T* LinkedList<T>::Get(T* item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item->GetName() == location->data.GetName())
		{
			found = true;
			item = &location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return item;
	else
		return NULL;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
int LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
	if (m_pCurPointer->next == NULL) {
		return 0;
	}
	return 1;
}


#endif	// LINKED_LIST