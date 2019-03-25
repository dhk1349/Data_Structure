#include "ItemType.h"


int ItemType::AddFolder() {
	if (subfoldernum == 0)
		list = new ArrayList;
	ItemType data;
	data.SetNameFromKB();
	data.Setpath(path+"/"+data.name);
	if (list->Add(data)) {
		subfoldernum++;
		memory++;
		DisplayAllFolderName();
	}
	return 1;
}

int ItemType::RetrieveFoldersByName() {
	ItemType tmp;
	string inData;
	cout << "\tFolder Name: ";
	cin >> inData;
	int result = 0;

	list->ResetList();//iterator �ʱ�ȭ
	while (list->GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.name.find(inData) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

void ItemType::DisplayAllFolderName()
{
	ItemType temp;
	list->ResetList();
	int iter = list->GetNextItem(temp);
	cout << "\t======Current List======\n";
	while (iter != -1)
	{
		temp.DisplayRecordOnScreen();
		iter = list->GetNextItem(temp);
	}
	cout << "\t====================\n";
}

int ItemType::DeleteFolders() {
	ItemType temp;
	temp.SetNameFromKB();

	int result = list->Delete(temp);
	if (result == 0) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\tThere is no such file!!\n";
	}
	else {
		cout << "\tDeleted Successfully!\n";
		DisplayAllFolderName();
		subfoldernum--;
		memory--;
	}
	return result;
}
// Set student id from keyboard.
void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> name;
}


void ItemType::SetRecordFromKB() 
{
	SetNameFromKB();
	Setpath(name);

}

// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> name;
	fin >> path;
	fin >> memory;
	fin >> times;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << name << " ";
	fout << path << " ";
	fout << memory << " ";
	fout << time;

	return 1;
}


// Compare two itemtypes.
RelationType ItemType::CompareByID(const ItemType &data)
{
	if(this->name > data.name)
		return GREATER;
	else if(this->name < data.name)
		return LESS;
	else
		return EQUAL;
}