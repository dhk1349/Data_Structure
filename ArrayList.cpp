#include "ItemType.h"

// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > size - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if (size == 0) {
		size += 5;
		m_Array = new ItemType[size];
	}
	if(!IsFull())
	{
		ItemType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while(m_CurPointer<=m_Length) //처음부터 끝까지
		{	
			if (CurItem.CompareByID(inData) == EQUAL)//같다면
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if(CurItem.CompareByID(inData)==GREATER || m_CurPointer==m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for(int i=m_Length;i>m_CurPointer;i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i]=m_Array[i-1];	//배열 밀기
				m_Array[m_CurPointer]=inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	}
	else//꽉 찬 경우
	{
		//동적할당의 크기를 재조정
		ItemType *temp;
		temp = new ItemType[size];
		for (int i = 0; i < size; i++) {
			temp[i] = m_Array[i];
		}
		delete[] m_Array;
		size += 5;
		m_Array = new ItemType[size];
		for (int i = 0; i < size-5; i++) {
			m_Array[i] = temp[i];
		}
		delete[] temp;


		//새 폴더를 추가
		ItemType CurItem;
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
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == m_Length)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//id가 일치하는 item을 찾아서 반환함
int ArrayList::Get(ItemType& data)
{
	ItemType CurItem;
	
	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while(m_CurPointer<m_Length)	//처음부터 끝까지
	{
		switch(CurItem.CompareByID(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data=CurItem;	//data에 현재 아이템을 반환
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
int ArrayList::Delete(ItemType data)
{
	if(Get(data))	//id가 일치하는 item을 발견한다면(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i]=m_Array[i+1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item의 내용을 교체시킴
int ArrayList::Replace(ItemType data)
{
	ItemType tmp(data);	//입력받은 item을 백업

	if(Get(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer]=tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item을 이진탐색으로 검색해서 반환한다.
int ArrayList::GetBinarySearch( ItemType& data )
{
	if(m_Length==0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos=m_Length/2;	//배열의 중간부터 시작
	while(1)
	{
		switch(m_Array[currentPos].CompareByID(data))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 id가 일치한다면
			data=m_Array[currentPos];	//data에 발견한 값을 리턴
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 입력 아이템의 id보다 크다면
			if(currentPos==0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos/=2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 id가 입력 아이템의 id보다 작다면
			if(currentPos==m_Length-1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos=(currentPos+m_Length)/2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}
