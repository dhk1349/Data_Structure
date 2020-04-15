#include "pch.h"
#include "ContainerType.h"

ContainerType::ContainerType()
{
	id = -1;
	position = "";
	SubContainerList = nullptr;
}

ContainerType::~ContainerType()
{
}

int ContainerType::GetId() const
{
	return id;
}

string ContainerType::GetPosition() const
{
	return position;
}

void ContainerType::SetId(int _id)
{
	id = _id;
}

void ContainerType::SetPosition(string _name)
{
	position = _name;
}

void ContainerType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> id;
}

void ContainerType::SetPositionFromKB()
{
	cout << "\tPosition : ";
	cin >> position;
}

void ContainerType::SetRecordFromKB()
{
	SetIdFromKB();
	SetPositionFromKB();
}

void ContainerType::AddsItem(SimpleItemType& _item)
{
	sItemList.Add(_item);
}

void ContainerType::DeletesItem(SimpleItemType& _item)
{
	sItemList.Delete(_item);
}

void ContainerType::UpdatesItem(SimpleItemType& _item)
{
	sItemList.Replace(_item);
}

void ContainerType::AddPhoto(string photo)
{
	photoList.Add(photo);
}

void ContainerType::DeletePhoto(string photo)
{
	photoList.Delete(photo);
}

void ContainerType::DisplayAllPhoto()
{
	cout << photoList;
}

void ContainerType::DisplayAllsItem()
{
	SimpleItemType tmpItem;
	sItemList.ResetList();
	while (sItemList.GetNextItem(tmpItem) != -1) {
	
		cout << tmpItem << endl;
	}
}

void ContainerType::DisplayAllDetailsItem(SortedList_p<ItemType*> ref)
{
	SimpleItemType tmpItem;
	sItemList.ResetList();
	while(sItemList.GetNextItem(tmpItem) != -1) {
		ItemType* detail;
		detail = new ItemType;

		detail->SetId(tmpItem.GetId());
		if (ref.Get(detail) == 1) {
			cout << "printing item\n";
			cout <<"\tAddr: " <<detail<<endl;
			cout << *detail << endl;
		}
		else { cout << "Not same container\n"; }
	}
}

void ContainerType::DisplySubContainers() {
	/*
	ContainerType subcont;
	SubContainerList->ResetList();

	while (SubContainerList->GetNextItem(subcont) != -1) {
		cout<<subcont.GetId()<<endl;
		cout<<subcont.GetPosition()<<endl;
		cout << "\t>>SubContainer의 ITEM목록을 출력하는 함수 작성.\n" << endl;
	}
	*/
}


void ContainerType::AddSubContainer() {
	/*
	ContainerType SubContainer;
	SubContainer.SetRecordFromKB();
	SubContainer.SetId(GetId()*100+SubContainer.GetId());
	SubContainer.SetPosition(GetPosition()+"_"+SubContainer.GetPosition());
	SubContainerList->Add(SubContainer);
	*/
}