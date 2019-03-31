#pragma once


#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

/**
*	array based simple unsorted list.
*/

template <typename T>
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		m_CurPointer = -1;
		m_Length = 0;
		size = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList()	{}

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmpty();

	/**
	*	@brief	�ش� Ŭ���� ����Ʈ�� Length ������ ����.
	*	@pre	none.
	*	@post	none.
	*	@return	���� ����Ʈ�� ���̸� �����Ѵ�.
	*/
	int GetLength();

	/**
	*	@brief	���� ����Ʈ�� �� ã���� Ȯ���Ѵ�. (size�� ��)
	*	@pre	none.
	*	@post	none.
	*	@return	�� ���� true, ���� �ʾ����� false.
	*/
	bool IsFull();

	/**
	*	@brief	ItemType ����Ʈ�� ������ �߰�.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��ִ�.
	*	@post	���ο� �����Ͱ� ����Ʈ�� �߰���.
	*	@param	data	new data.
	*	@return	����� ���� 1�� ����, �ƴϸ� 0�� ����.
	*/
	int Add(T data);

	/**
	*	@brief	list iterator �ʱ�ȭ.
	*	@pre	����Ʈ�� ���ǵǾ��ִ� �����̴�.
	*	@post	iterator �ʱ�ȭ.
	*/
	void ResetList();

	/**
	*	@brief	iterator�� ���� ������ �̵��ϰ�, �ش� ������ �����͸� �����´�.
	*	@pre	list�� list iterator�� �ʱ�ȭ�Ǿ �ȵȴ�.
	*	@post	iterator�� ���� ������ item ��ġ�� �Ѿ��.
	*	@param	data�� iterator�� ��ġ���ִ� ���� �����͸� �����Ѵ�. �ʱ�ȭ �� �ʿ� ����.
	*	@return	���� iterator�� �ε����� ��ȯ, �ε��� ������ ������ -1�� ��ȯ.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��. 
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	id�� ��ġ�ϴ� list�� item�� ã�Ƽ� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� �Ѱܹ��� item�� �������� ����ȴ�.
	*	@param	data	��ü�ϰ��� �ϴ� id�� ���ڵ带 ���� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(T data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetBinarySearch(T& data);
private:
	T *m_Array;  
	int size;
	int m_Length;			
	int m_CurPointer;			
};

// Make list empty.
template <typename T>
void ArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
template <typename T>
int ArrayList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template <typename T>
bool ArrayList<T>::IsFull()
{
	if (m_Length > size - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template <typename T>
int ArrayList<T>::Add(T inData)
{
	if (size == 0) {
		size += 5;
		m_Array = new T [size];
	}
	if (!IsFull())
	{
		T CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem.CompareByID(inData) == EQUAL)//���ٸ�
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if (CurItem.CompareByID(inData) == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
	}
	else//�� �� ���
	{
		//�����Ҵ��� ũ�⸦ ������
		T *temp;
		temp = new T[size];
		for (int i = 0; i < size; i++) {
			temp[i] = m_Array[i];
		}
		delete[] m_Array;
		size += 5;
		m_Array = new T[size];
		for (int i = 0; i < size - 5; i++) {
			m_Array[i] = temp[i];
		}
		delete[] temp;


		//�� ������ �߰�
		T CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem.CompareByID(inData) == EQUAL)//���ٸ�
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if (CurItem.CompareByID(inData) == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
	}

	return 1;
}


// Initialize list iterator.
template <typename T>
void ArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
template <typename T>
int ArrayList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == m_Length)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
template <typename T>
int ArrayList<T>::Get(T& data)
{
	T CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		switch (CurItem.CompareByID(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� id�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ������
template <typename T>
int ArrayList<T>::Delete(T data)
{
	if (Get(data))	//id�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
template <typename T>
int ArrayList<T>:: Replace(T data)
{
	T tmp(data);	//�Է¹��� item�� ���

	if (Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
template <typename T>
int ArrayList<T>::GetBinarySearch(T& data)
{
	if (m_Length == 0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos = m_Length / 2;	//�迭�� �߰����� ����
	while (1)
	{
		switch (m_Array[currentPos].CompareByID(data))
		{
		case EQUAL:	//���� �����۰� �Է� �������� id�� ��ġ�Ѵٸ�
			data = m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �Է� �������� id���� ũ�ٸ�
			if (currentPos == 0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� id�� �Է� �������� id���� �۴ٸ�
			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}
