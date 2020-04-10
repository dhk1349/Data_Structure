#pragma once
#pragma once
#ifndef _ITEM_H
#include "_Library.h"

class ItemType :SimpleItemType {
public:
	ItemType() {}
	~ItemType() {}

	int GetType();
	string GetDate();
	string GetName();

	int GetNum();

private:
	int type;
	string date;
	string name;
	int num;
};

#endif // !_ITEM_H
