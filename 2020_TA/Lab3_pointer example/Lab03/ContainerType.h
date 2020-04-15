#pragma once
#include "SortedListWithPointer.h"
class ContainerType
{
private:
	int							id;
	string							position;
	UnsortedList<SimpleItemType>	sItemList;
	UnsortedList<string>			photoList;
	SortedList<ContainerType> *SubContainerList;
public:
	ContainerType();
	~ContainerType();

	int GetId() const;
	string GetPosition() const;
	void SetId(int _id);
	void SetPosition(string _name);

	void SetIdFromKB();
	void SetPositionFromKB();
	void SetRecordFromKB();

	void AddsItem(SimpleItemType& _item);
	void DeletesItem(SimpleItemType& _item);
	void UpdatesItem(SimpleItemType& _item);

	void AddPhoto(string photo);
	void DeletePhoto(string photo);

	void DisplayAllPhoto();
	void DisplayAllsItem();
	void DisplayAllDetailsItem(SortedList_p<ItemType*> ref);

	//dhk1349
	void DisplySubContainers();
	void AddSubContainer();

	bool operator==(const ContainerType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const ContainerType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const ContainerType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const ContainerType& _item) {
		id = _item.GetId();
		position = _item.GetPosition();
		sItemList = _item.sItemList;
		photoList = _item.photoList;
	}
};

