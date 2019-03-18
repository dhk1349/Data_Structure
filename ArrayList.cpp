#include "ArrayList.h"


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
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

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
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}
int ArrayList::IsEmpty() {
	if (m_Length == 0) {
		return 0;
	}
	return 1;
}

int ArrayList:: Get(ItemType& data) {
	ItemType temp;
	temp.SetIdFromKB();
	ResetList();
	int index = 0;
	while (index != -1){
		index=GetNextItem(data);
		if (temp.GetId() == data.GetId()) {
			return index;
		}
	}
	return -1;
}

int ArrayList::Delete(ItemType data){
	int index = Get(data);
	if (index!=-1) {
		for (index;index<m_Length-1;index++) {
			m_Array[index] = m_Array[index + 1];
		}
		m_Length -= 1;
		return 0;
	}
	return -1;
}

int ArrayList::Replace(ItemType data) {
	ItemType temp;
	cout << "\n\tReplace with what data:  ";
	int index = Get(temp);
	if (index != -1) {
		m_Array[index] = data;
		return 0;
	}
	return -1;
}