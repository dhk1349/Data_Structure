#pragma once
class TempType
{
private:
	int numOfItems;
	CircularQueue<ItemType*> tItemList;

public:
	TempType();
	~TempType();

	void AddtItem(ItemType* _tItem);
	ItemType* DequeueFromtItemList();
	void PrinttItemList();

};