#pragma once
class SimpleItemType;
class ItemType
{
private:
	ITEMKIND	kind;			///< item kind.
	string		date;			///< item's buy date
	int			num;			///< item number.
	int			containerID;	///< container(which have this item)'s ID. ������ ��ġ�� �ǹ�.


//dhk1349
protected:
	int			id;				///< item ID.
	string		name;			///< item name.

public:
	ItemType();
	~ItemType();

	int GetId() const;
	ITEMKIND GetKind() const;
	string GetDate() const;
	string GetName() const;
	int GetNum() const;
	int GetContainerID() const;
	//dhk1349
	SimpleItemType GetSimpleData();

	void SetId(int _id);
	void SetKind(ITEMKIND _kind);
	void SetDate(string _date);
	void SetName(string _name);
	void SetNum(int _num);
	void SetContainerID(int _cID);
	void SetRecord(int _id, ITEMKIND _kind, string _date, string _name, int _num, int _cID);

	void SetIdFromKB();
	void SetKindFromKB();
	void SetDateFromKB();
	void SetNameFromKB();
	void SetNumFromKB();
	void SetContainerIDFromKB();
	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	bool operator==(const ItemType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const ItemType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const ItemType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const ItemType& _item) {
		id = _item.GetId();
		kind = (ITEMKIND)_item.GetKind();
		date = _item.GetDate();
		name = _item.GetName();
		num = _item.GetNum();
		containerID = _item.GetContainerID();
	}
	friend ostream& operator<<(ostream& os, const ItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tKind   : " << _item.GetKind() << endl;
		os << "\tDate   : " << _item.GetDate() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		os << "\tNum   : " << _item.GetNum() << endl;
		os << "\tContainer   : " << _item.GetContainerID() << endl;
		return os;
	}
	friend ostream& operator<<(ostream& os, ItemType* _item) {
		os << "\tID   : " << _item->GetId() << endl;
		os << "\tKind   : " << _item->GetKind() << endl;
		os << "\tDate   : " << _item->GetDate() << endl;
		os << "\tName   : " << _item->GetName() << endl;
		os << "\tNum   : " << _item->GetNum() << endl;
		os << "\tContainer   : " << _item->GetContainerID() << endl;
		return os;
	}
};

