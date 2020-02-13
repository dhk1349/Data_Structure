#include "ul.h"
#include<iostream>
ArrayList::ArrayList() {
	m_Length = 0;
	m_CurPointer = -1;
}
ArrayList::~ArrayList() {}

void ArrayList::MakeEmpty() {
	m_Length = 0;
}
int ArrayList::GetLength() { return m_Length; }
bool ArrayList::IsFull() { if (MAXSIZE == m_Length) { return true; } return false; }
int ArrayList::Add(ItemType data) { if (!IsFull()) { m_Array[m_Length] = data; m_Length++;  return 1; } else { return 0; } }
void ArrayList::ResetList() {
	m_CurPointer = 0;
}
int ArrayList::GetNextItem(ItemType& data) {
	data = m_Array[m_CurPointer];
	if (m_CurPointer + 1 == m_Length) {
		ResetList();
		return 0;
	}
	m_CurPointer++;
	return 1;
}
void ArrayList::PrintAll() {
	if (m_Length != 0) {
		ResetList();
		ItemType tmp;
		while (GetNextItem(tmp) == 1) {
			tmp.DisplayRecordOnScreen();
		}
		tmp.DisplayRecordOnScreen();
	}
	else { cout << "LIST IS EMPTY!!\n"; }
}



