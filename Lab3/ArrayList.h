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
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	리스트가 비워진다.
	*/
	void MakeEmpty();

	/**
	*	@brief	해당 클래스 리스트의 Length 정보를 제공.
	*	@pre	none.
	*	@post	none.
	*	@return	현재 리스트의 길이를 리턴한다.
	*/
	int GetLength();

	/**
	*	@brief	현재 리스트가 꽉 찾는지 확인한다. (size와 비교)
	*	@pre	none.
	*	@post	none.
	*	@return	꽉 차면 true, 차지 않았으면 false.
	*/
	bool IsFull();

	/**
	*	@brief	ItemType 리스트에 데이터 추가.
	*	@pre	리스트가 초기화 되어있다.
	*	@post	새로운 데이터가 리스트에 추가됨.
	*	@param	data	new data.
	*	@return	제대로 들어가면 1을 리턴, 아니면 0을 리턴.
	*/
	int Add(T data);

	/**
	*	@brief	list iterator 초기화.
	*	@pre	리스트가 정의되어있는 상태이다.
	*	@post	iterator 초기화.
	*/
	void ResetList();

	/**
	*	@brief	iterator가 다음 번지로 이동하고, 해당 번지의 데이터를 가져온다.
	*	@pre	list와 list iterator가 초기화되어선 안된다.
	*	@post	iterator가 다음 번지의 item 위치로 넘어간다.
	*	@param	data는 iterator가 위치해있는 곳의 데이터를 저장한다. 초기화 할 필요 없다.
	*	@return	현재 iterator의 인덱스를 반환, 인덱스 밖으로 나가면 -1을 반환.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값. 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	id가 일치하는 list내 item을 찾아서 변경한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 id와 레코드를 가진 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
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

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{
			if (CurItem.CompareByID(inData) == EQUAL)//같다면
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if (CurItem.CompareByID(inData) == GREATER || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i - 1];	//배열 밀기
				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	}
	else//꽉 찬 경우
	{
		//동적할당의 크기를 재조정
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


		//새 폴더를 추가
		T CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{
			if (CurItem.CompareByID(inData) == EQUAL)//같다면
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if (CurItem.CompareByID(inData) == GREATER || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i - 1];	//배열 밀기
				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
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
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == m_Length)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//id가 일치하는 item을 찾아서 반환함
template <typename T>
int ArrayList<T>::Get(T& data)
{
	T CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		switch (CurItem.CompareByID(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 id가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}

//id가 일치하는 item을 찾아서 제거함
template <typename T>
int ArrayList<T>::Delete(T data)
{
	if (Get(data))	//id가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item의 내용을 교체시킴
template <typename T>
int ArrayList<T>:: Replace(T data)
{
	T tmp(data);	//입력받은 item을 백업

	if (Get(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer] = tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item을 이진탐색으로 검색해서 반환한다.
template <typename T>
int ArrayList<T>::GetBinarySearch(T& data)
{
	if (m_Length == 0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos = m_Length / 2;	//배열의 중간부터 시작
	while (1)
	{
		switch (m_Array[currentPos].CompareByID(data))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 id가 일치한다면
			data = m_Array[currentPos];	//data에 발견한 값을 리턴
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 입력 아이템의 id보다 크다면
			if (currentPos == 0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos /= 2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 id가 입력 아이템의 id보다 작다면
			if (currentPos == m_Length - 1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos = (currentPos + m_Length) / 2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}
