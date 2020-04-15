#include "pch.h"
#include "TempType.h"

TempType::TempType()
{
	numOfItems = 0;
}

TempType::~TempType()
{
}

void TempType::AddtItem(ItemType* _tItem)
{
	tItemList.AddToCircularQueue(_tItem);
	numOfItems++;
}

ItemType* TempType::DequeueFromtItemList()
{
	ItemType* tmp;
	tmp = new ItemType;

	tItemList.DeleteFrCircularQueue(tmp);
	numOfItems--;
	return tmp;
}

void TempType::PrinttItemList()
{
	tItemList.PlayInsertOrder();
}
