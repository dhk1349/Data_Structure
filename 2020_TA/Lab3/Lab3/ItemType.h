#pragma once
#pragma once
#ifndef _ITEM_H
#include "_Library.h"

class ItemType{
public:
	ItemType() {}
	~ItemType() {}

	int GetType();
	string GetDate();
	string GetName();
	string GetPkey();
	int GetNum();
	
	/*
	Function below is made to extract necessary data from object to make SimpleItem Object.
	�켱 pkey�� �����ϵ��� ®���� ���Ŀ� ��� ���� ����.
	*/
	string GetData();

	int SetRecordFromKB();

	bool operator==(ItemType& object);

private:
	int type;
	string date;
	string name;
	string pkey;
	int num;
};

#endif // !_ITEM_H
