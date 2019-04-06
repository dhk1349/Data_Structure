#include "FolderType.h"


int FolderType::AddFolder() {
	//if (subfoldernum == 0) 
		
	FolderType data;
	data.SetNameFromKB();
	data.Setpath(path+"/"+data.name);
	if (fdFolderList->Add(data)==1) {
		subfoldernum++;
		memory++;
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	else {
		cout << "\t���� �̸��� ������ �����մϴ�!\n";
	}
	return 1;
}

int FolderType::Addtextfile() {
	FolderType mock;
	mock.SetNameFromKB();
	mock.Setpath(path+"/"+mock.name);

	//txt�� �ִ� ��
	FileType data;
	data.Setname(mock.GetName());
	data.Setpath(mock.GetPath());
	data.Settime(mock.Gettime()) ;

	string textname=data.Getpath();
	for (int i = 0; i < textname.length(); i++) {
		if (textname[i] == '\\') {
			textname[i] = '+';
		}
	}
	textname += data.GetName();
	ofstream outdata;
	outdata.open(textname+".txt");
	data.Setaccess(textname);
	string test;
	cout << "EXIT�� �Է��ϸ� ����\n";
	while (true) {
		getline(cin, test);
		if (test == "EXIT") { break; }
		outdata << test << endl;
	}
	outdata.close();
	fdFileList->Add(data);
	filenum++;
	DisplayAllFolderName();
	DisplayAllFileName();
	return 0;
}

int FolderType::RetrieveFoldersByName() {

	FolderType temp;
	string inData;
	cout << "\tFolder Name: ";
	cin >> inData;
	int result = 0;

	fdFolderList->ResetList();//iterator �ʱ�ȭ
	while (true) //����Ʈ�� ���������� �ݺ�
	{
		int iter = fdFolderList->GetNextItem(temp);
		if (temp.name.find(inData) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
		if (iter == 0) { break; }
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
	fdFolderList->ResetList();
	cout << "\t======Current Folder List======\n";
	if (subfoldernum!=0) {
		while (true)
		{
			int iter = fdFolderList->GetNextItem(temp);
			temp.DisplayRecordOnScreen();
			if (iter == 0)
				break;
			//���⼭ ����
		}
	}
	cout << "\t==============================\n\n";
}
void FolderType::DisplayAllFileName() {
	FileType temp;
	fdFileList->ResetList();
	cout << "\t======Current File List=======\n";
	if (filenum != 0) {
		while (true)
		{
			int iter = fdFileList->GetNextItem(temp);
			cout << "\t"+temp.GetName()+"\n";
			if (iter == 0)
				break;
			//���⼭ ����
		}
	}
	cout << "\t==============================\n";
}
int FolderType::DeleteFolders() {
	FolderType temp;
	temp.SetNameFromKB();

	int result = fdFolderList->Delete(temp);
	if (result == 0) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	else {
		cout << "\tDeleted Successfully!\n";
		subfoldernum--;
		memory--;
		DisplayAllFolderName();
		DisplayAllFileName();
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
	int index=fdFolderList->Get(*temp);
	return index;
}

int FolderType::SearchFolderBinary(FolderType *temp) {
	/*
	temp->SetNameFromKB();
	int index=list.GetBinarySearch(*temp); //�����ϸ� 1, �����ϸ� 0�� ������ ���� ���̴�.
	if (index == 1) {
		cout << "\t======Found Folder======\n";
		temp->DisplayRecordOnScreen();
		cout << "\t=======================\n";
	}
	else {
		cout << "\tNo such folder!\n";
	}
	return 1;
	*/
	return 1;
}

int FolderType::Opentext() {
	DisplayAllFileName();
	FolderType data;
	data.SetNameFromKB();
	data.Setpath(path+"\\"+data.GetName());

	FileType *temp;
	temp = new FileType;
	string textname = data.GetPath();
	for (int i = 0; i < textname.length(); i++) {
		if (textname[i] == '\\') {
			textname[i] = '+';
		}
	}
	textname += data.GetName();
	temp->Setname(data.GetName());
	temp->Setaccess(textname);

	if (fdFileList->Get(*temp) == 1) {//ã���� ��
		cout << "\tFound\n";
		ifstream indata;
		indata.open(temp->Getaccess()+".txt");
		string temp;
		while (indata.peek() != EOF) {
			// std::getline�� �Է� ��Ʈ������ string���� �� ���� �н��ϴ�.
			getline(indata, temp);
			cout << temp << endl;
		}
		return 1;
	}
	else {//�� ã���� ��
		cout << "\tNo Such File!\n";
		return 0;
	}


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