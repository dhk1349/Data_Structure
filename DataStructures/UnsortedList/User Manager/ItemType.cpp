#include <iostream>
#include <string>
#include <fstream>
#include "ItemType.h"
using namespace std;

ItemType::ItemType() {
	m_Id = -1;
	m_sAddress = "NONE";
	m_sName = "NONAME";
}
ItemType::~ItemType() {}

int ItemType::GetId() const { return m_Id; }
string ItemType::GetName() { return m_sName; }
string ItemType::GetAddress() { return m_sAddress; }
void ItemType::SetId(int inld) { m_Id = inld; }
void ItemType::SetName(string inName) {
	m_sName = inName;
}
void ItemType::SetAddress(string inAddress) {
	m_sAddress = inAddress;
}
void ItemType::SetRecord(int inId, string inName, string inAddress) {
	SetId(inId);
	SetAddress(inAddress);
	SetName(inName);
}
void ItemType::DisplayIdOnScreen() {
	cout << "ID: " << m_Id<<endl;
}
void ItemType::DisplayNameOnScreen() {
	cout << "NAME: " << m_sName << endl;
}
void ItemType::DisplayAddressOnScreen() {
	cout << "ADDR: " << m_sAddress << endl;
}
void ItemType::DisplayRecordOnScreen() {
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
	cout << endl;
}
void ItemType::SetIdFromKB() {
	int input;
	cout << "TYPE ID: ";
	cin >> input;
	m_Id = input;
}
void ItemType::SetNameFromKB() {
	string input;
	cout << "TYPE NAME: ";
	cin >> input;
	m_sName = input;
}
void ItemType::SetAddressFromKB() {
	string input;
	cout << "TYPE ADDR: ";
	cin >> input;
	m_sAddress = input;
}
void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}
int ItemType::ReadDataFromFile(ifstream& fin) { return 1; }
int ItemType::WriteDataToFile(ofstream& fout) { return 1; }
RelationType ItemType::CompareByID(const ItemType& data) {
	if (this->GetId() > data.GetId()) { return GREATER; }
	else if (this->GetId() == data.GetId()) { return EQUAL; }
	else { return LESS; }
}

