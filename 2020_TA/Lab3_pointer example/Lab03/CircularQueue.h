#pragma once
template <typename T>
class CircularQueue
{
private:
	int m_iFront;		///< index of one infront of the first element.
	int m_iRear;		///< index of the last element.
	int m_nMaxQueue;	///< max size of the queue.
	int m_CurPointer;	///< iterator pointer.
	T* m_pItems;		///< pointer for dynamic allocation.

public:
	CircularQueue();
	CircularQueue(int max);
	~CircularQueue();

	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront, m_CurPointer, and m_iRear are set same value as Constructer.
	*/
	void ResetQueue();

	/**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer�� m_iFront ������ �ʱ�ȭ�ȴ�.
	*/
	void ResetCurrentPointer();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void AddToCircularQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeleteFrCircularQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void PlayInsertOrder();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& item);
};

template<typename T>
CircularQueue<T>::CircularQueue()
{
	m_nMaxQueue = MAXQUEUE;
	m_CurPointer = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.
	m_pItems = new T[m_nMaxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
}

template<typename T>
CircularQueue<T>::CircularQueue(int max)
{
	m_nMaxQueue = max;
	m_CurPointer = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.
	m_pItems = new T[max];	//m_pItems�� ũ�Ⱑ max�� �迭�� �����.
}

template<typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_pItems;
}

template<typename T>
bool CircularQueue<T>::IsFull()
{
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
		return 1;	//m_iFront�� m_iRear���� 1 ���϶��� �� �����̹Ƿ� 1�� �����Ѵ�. m_iFront�� 0�϶��� m_iRear�� m_nMaxQueue-1�� ������ �� �����̴�.
	return 0;	//�� ���� �ʾ����� 0�� �����Ѵ�.
}

template<typename T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront�� m_iRear�� ���� ���� queue�� ����ִ� �����̹Ƿ� 1�� �����Ѵ�.
	return 0;	//������� ������ 0�� �����Ѵ�.
}

template<typename T>
void CircularQueue<T>::ResetQueue()
{
	m_iFront = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//�����ڿ� ���� ������ m_iFront�� m_iRear�� �������ش�.
	delete[] m_pItems;	//�����Ҵ��ߴ� �޸𸮸� �������ش�.
	m_pItems = new T[m_nMaxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
}

template<typename T>
void CircularQueue<T>::ResetCurrentPointer()
{
	m_CurPointer = m_iFront;
}

template<typename T>
void CircularQueue<T>::AddToCircularQueue(T item)
{
	if (IsFull()) {
		// FullQueue().print();	//�� á���� throw FullQueue
		DeleteFrCircularQueue(item);
	}
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear�� 1���������ְ� item���� �־��ش�.
}

template<typename T>
void CircularQueue<T>::DeleteFrCircularQueue(T& item)
{
	if (IsEmpty())
		return ;
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront�� 1 ���������ְ� ������ ���� item�� �������ش�.
	return;
}

template<typename T>
void CircularQueue<T>::PlayInsertOrder()
{
	if (IsEmpty())
		return;
	if (m_iFront > m_iRear)	//m_iFront�� m_iRear���� Ŭ��
	{
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++)
		{
			cout << m_pItems[i]<<endl;
			cout << *m_pItems[i]<<endl<<endl;
		}	//m_iFront ���� �׸���� �迭�� ������ ����Ѵ�.
		for (int i = 0; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << endl;
			cout << *m_pItems[i] << endl << endl;
		}	//�迭�� ó������ m_iRear���� ������ش�.
	}
	else	//m_iRear�� m_iFront���� Ŭ��
	{
		for (int i = m_iFront + 1; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << endl;
			cout << *m_pItems[i] << endl << endl;
		}	//m_iFront+1�������� m_iRear���� ���
	}
	cout << endl;
}

template<typename T>
int CircularQueue<T>::GetNextItem(T& item)
{
	if (IsEmpty()) {
		return -1;
	}

	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	item = m_pItems[m_CurPointer];	//m_iFront���� 1 ������ index�� m_pItem�� item�� �������ش�.
	if (m_CurPointer == m_iRear) {
		this->ResetCurrentPointer();
		return 0;
	}
	return 1;
}
