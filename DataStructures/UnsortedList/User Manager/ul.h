#pragma once
#ifndef ul_hpp
#define ul_hpp
#define MAXSIZE 5
#include "ItemType.h"

class ArrayList
{
public:
	ArrayList();
	~ArrayList();

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);
	void PrintAll();

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
};

#endif