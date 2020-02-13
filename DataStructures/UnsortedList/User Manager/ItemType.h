#pragma once
#ifndef Itemtype_hpp
#define Itemtype_hpp
#include <string>
using namespace std;
enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
public:
	ItemType();
	~ItemType();

	int GetId() const;
	string GetName();
	string GetAddress();
	void SetId(int inld);
	void SetName(string inName);
	void SetAddress(string inAddress);
	void SetRecord(int inId, string inName, string inAddress);
	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen();
	void SetIdFromKB();
	void SetNameFromKB();
	void SetAddressFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	RelationType CompareByID(const ItemType& data);

private:
	int m_Id;
	string m_sName;
	string m_sAddress;

};

#endif