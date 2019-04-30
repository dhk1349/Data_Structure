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
	*	@brief	����Ʈ�� �� ���·� �ʱ�ȭ �Ѵ�.
	*	@pre	None
	*	@post	����Ʈ�� �� ���°� �ȴ�.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ������ �ִ� ������ ������ ����
	*	@pre	None.
	*	@post	Function value = ����Ʈ ������ ������ ����.
	*	@return	����Ʈ ������ ���� ����.
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� ������ ��ġ�� .
	*	@pre	����Ʈ�� ���� ���� ������, ������ �������� ����Ʈ�� ����.
	*	@post	����Ʈ�� �������� ���Եȴ�.
	*	@return	����� �߰��Ǹ� 1��, �׷��� ������ 0�� ����.
	*/
	int Add(T item);

	/**
	*	@brief	����Ʈ���� �������� �����Ѵ�.
	*	@pre	����Ʈ�� ������� ������, ������ �������� ����Ʈ �ȿ� �����Ѵ�.
	*	@post	�������� ����Ʈ���� �����ȴ�.
	*	@return	����� �����Ǹ� 1��, �׷��� ������ 0�� ����.
	*/
	int Delete(T item);

	/**
	*	@brief	����Ʈ �ȿ� �ִ� �������� ���� �����Ѵ�.
	*	@pre	����Ʈ�� ������� ������, ������ �������� ����Ʈ �ȿ� �����Ѵ�.
	*	@post	�������� ���� ����ȴ�.
	*	@return	�Լ��� ����� �۵������� 1��, �׷��� ������ 0�� ����.
	*/
	int Replace(T item);

	/**
	*	@brief	����Ʈ���� ������ Ű�� ��ġ�ϴ� ���Ұ� ������ ã�Ƴ���.
	*	@pre	�������� primary key�� �ʱ�ȭ �Ǿ��ִ�.
	*	@post	����Ʈ �ȿ� ã���� �ϴ� key�� ��ġ�ϴ� ���Ұ� �ִٸ� item������ �� ���� ����ȴ�.
	*	@return	ã�� ���Ұ� �־ ���縦 �ߴٸ� �ش� ���Ҹ�, �׷��� ������ NULL�� �����Ѵ�.
	*/
	T* Get(T* item);

	/**
	*	@brief	iteration�� ���ؼ� �ش� ����Ʈ�� �����͸� �ʱ�ȭ�Ѵ�.
	*	@pre	����
	*	@post	���� �����ʹ� ����Ʈ �տ� �����ϸ�, �����Ͱ� �ʱ�ȭ �Ǿ���. 
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ���� ���� ���Ҹ� �����´�.
	*	@pre	���� ������(current pointer)�� ���� �Ǿ��ִ�. ���� �������� ��ġ�� ����Ʈ�� �������� �ƴϴ�.
	*	@post	current pointer�� ���� ��ġ�� �̵��Ѵ�. current pointer�� item�� ����ȴ�.
	*	@param Item�� ���Ӱ� �̵��� current pointer�� ������ ����ȴ�.
	*	@�����ϸ� 1�� ����, �ƴϸ� 0�� ����.
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
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)    //���⼭ ����
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
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node=new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (m_nLength==0)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);
			//���⼭ curpointer�� null�̸� �Ǿ��� ���� ����Ų��.
			if (m_pCurPointer->data.GetName()== node->data.GetName()) {
				return 0;
			}
			if (m_pCurPointer->data.GetName() > node->data.GetName())//curpoint�� ������ ��庸�� �ڿ��־�� �� ��.
			{
				if (pre == NULL)//�Ǿ����� curpoint��  �� �ִ� ���� �� ������ ��尡 �Ǿ����� ������ ��.
				{
					node->next = m_pCurPointer;
					m_pList = node;  //������ ��� ����
					break;
				}	//���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
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
	NodeType<T>* pre = NULL;	//���� ����

	m_pCurPointer = m_pList;//�� ������
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item.GetName() == m_pCurPointer->data.GetName())	//���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;	//ã�����Ƿ� found �� ����
			if (pre == NULL){
				//���⼭ memory loss�� �����.
				//delete[] m_pList;
				m_pList = m_pCurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			}
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}

//Change value of item which is in this list.
template <typename T>
int LinkedList<T>::Replace(T item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item.GetName() == location->data.GetName())
		{
			found = true;
			item.SetNameFromKB();
			location->data.Setname( item.GetName());
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
T* LinkedList<T>::Get(T* item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item->GetName() == location->data.GetName())
		{
			found = true;
			item = &location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return item;
	else
		return NULL;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
int LinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
	if (m_pCurPointer->next == NULL) {
		return 0;
	}
	return 1;
}


#endif	// LINKED_LIST