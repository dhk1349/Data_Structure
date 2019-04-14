#include "FolderType.h"


int FolderType::AddFolder() {
	//if (subfoldernum == 0) 
		
	FolderType data;
	data.SetNameFromKB();
	data.Setpath(path+"\\"+data.name);
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
int FolderType::PaseteFolder(FolderType* indata) {
    //�̺κ��� ��� �ٲپ�������� ���ؼ� ����� ��.
	FolderType temp = *indata;
	temp.Setpath(path + "\\" + temp.name);
	while (true) {
		if (fdFolderList->Add(temp) == 1) {
			subfoldernum++;
			memory++;
			DisplayAllFolderName();
			DisplayAllFileName();
			return 1;
		}
		else {
			//�Ȱ��� ������ �����Ѵٸ� �̸� �ڿ� ���� �߰��ؼ� �ٽ� �߰��Ѵ�.
			temp.Setname(temp.name + "_1");
			temp.Setpath(path + "\\" + temp.name);
		}
	}
}
int FolderType::Addtextfile() {
	FolderType mock;
	mock.SetNameFromKB();
	mock.Setpath(path+"\\"+mock.name);

	//txt�� �ִ� ��
	FileType data;
	data.Setname(mock.GetName());
	data.Setpath(mock.GetPath());
	data.Settime(mock.Gettime()) ;
	data.Setext(".txt");
	string textname=data.Getpath();
	for (int i = 0; i < textname.length(); i++) {
		if (textname[i] == '\\') {
			textname[i] = '+';
		}
	}
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

int FolderType::DeleteFiles() {
	FileType temp;
	temp.SetNameFromKB();

	int result = fdFileList->Delete(temp);
	if (result == 0) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	else {
		cout << "\tDeleted Successfully!\n";
		filenum--;
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

FolderType* FolderType::SearchFolder(FolderType *temp) {
	temp->SetNameFromKB();
	return  fdFolderList->Get(temp);
}

FileType* FolderType::SearchFile(FileType *temp) {
	temp->SetNameFromKB();
	return  fdFileList->Get(temp);
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

	if (fdFileList->Get(temp) != NULL) {//ã���� ��
		cout << "\tFound\n";
		ifstream indata;
		indata.open(temp->Getaccess() + ".txt");
		if (!indata.is_open()) {
			cout << "\t������ �ȿ��Ⱦ��,,\n";
		}
		string temp;
		while (indata.peek() != EOF) {
			// std::getline�� �Է� ��Ʈ������ string���� �� ���� �н��ϴ�.
			getline(indata, temp);
			cout <<"\t"<< temp << endl;
		}
		return 1;
	}
	else {//�� ã���� ��
		cout << "\tNo Such File!\n";
		return 0;
	}


}

int FolderType::ChagneSubfolderName() {
	FolderType temp;
	DisplayAllFolderName();
	cout << "\t�̸� �ٲ� ���� ����\n";
	temp.SetNameFromKB();
	fdFolderList->Replace(temp);
	return 0;
}

int FolderType::ChangeFileName() {
	FileType temp;
	DisplayAllFileName();
	cout << "\t�ٲ� ���� ����\n";
	temp.SetNameFromKB();
	fdFileList->Replace(temp);
	return 0;
}

int FolderType::IncludeMusic() {
	ifstream indata;
	indata.open("PlayList.txt");
	string temp;
	while (indata.peek() != EOF) {
		// std::getline�� �Է� ��Ʈ������ string���� �� ���� �н��ϴ�.
		getline(indata, temp);
		cout << "\t" << temp << endl;
	}
	indata.close();
	string inmusic;
	cout << "\t�߰��� ������ �����ϼ���.\n";
	cout << "\t";
	cin >> inmusic;

	indata.open("PlayList.txt");
	bool add = false;
	while (indata.peek() != EOF) {
		// std::getline�� �Է� ��Ʈ������ string���� �� ���� �н��ϴ�.
		getline(indata, temp);
		if (temp==inmusic) {
			add = true;
			break;
		}
	}
	indata.close();

	if (add==true) {
		FolderType mock;
		mock.Setname(inmusic);
		mock.Setpath(path + "\\" + mock.name);

		//txt�� �ִ� ��
		FileType data;
		data.Setname(mock.GetName());
		data.Setpath(mock.GetPath());
		data.Settime(mock.Gettime());
		data.Setext("wav");
		fdFileList->Add(data);
		filenum++;
		DisplayAllFolderName();
		DisplayAllFileName();
		return 1;
	}
	else {
		cout << "\t�׷� �̸��� ������ �߰��� �� �����ϴ�.\n";
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