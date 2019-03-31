#include "FolderType.h"


int FolderType::AddFolder() {
	//if (subfoldernum == 0)
		
	FolderType data;
	data.SetNameFromKB();
	data.Setpath(path+"/"+data.name);
	if (list->Add(data)) {
		subfoldernum++;
		memory++;
		DisplayAllFolderName();
	}
	return 1;
}

int FolderType::RetrieveFoldersByName() {
	FolderType tmp;
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

void FolderType::DisplayAllFolderName()
{
	FolderType temp;
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

int FolderType::DeleteFolders() {
	FolderType temp;
	temp.SetNameFromKB();

	int result = list->Delete(temp);
	if (result == 0) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
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
void FolderType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> name;
}


void FolderType::SetRecordFromKB() 
{
	SetNameFromKB();
	Setpath(name);

}

// Read a record from file.
int FolderType::ReadDataFromFile(ifstream& fin)
{
	fin >> name;
	fin >> path;
	fin >> memory;
	fin >> times;

	return 1;
};


// Write a record into file.
int FolderType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << name << " ";
	fout << path << " ";
	fout << memory << " ";
	fout << time;

	return 1;
}

int FolderType::SearchFolder(FolderType *temp) {
	temp->SetNameFromKB();
	int index=list->Get(*temp);
	return index;
}

// Compare two itemtypes.
RelationType FolderType::CompareByID(const FolderType &data)
{
	if(this->name > data.name)
		return GREATER;
	else if(this->name < data.name)
		return LESS;
	else
		return EQUAL;
}