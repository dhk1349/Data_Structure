#include "FolderType.h"


int FolderType::AddFolder() {
	//if (subfoldernum == 0) 
		
	FolderType data;
	data.SetNameFromKB();
	data.Setpath(path+"\\"+data.name);
	if (fdFolderList->Find(data)==false) {
		fdFolderList->Add(data);
		subfoldernum++;
		memory++;
		cout << endl;
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	else {
		cout << "\t���� �̸��� ������ �����մϴ�!\n";
	}
	return 1;
}
int FolderType::PaseteFolder(FolderType indata) {
    //�̺κ��� ��� �ٲپ�������� ���ؼ� ����� ��.
	FolderType temp = indata;
	temp.Setpath(path + "\\" + temp.name);
	while (true) {
		if (fdFolderList->Find(temp)==false) {
			fdFolderList->Add(temp);
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
	if (fdFileList->Find(data)==false){
		fdFileList->Add(data);
		filenum++;
		cout << "\t���� �߰� ����\n";
	}
	else { cout << "\t���� �߰� ����\n"; }
	DisplayAllFolderName();
	DisplayAllFileName();
	return 0;
}

int FolderType::RetrieveFoldersByName() {
	FolderType *temp=new FolderType;
	string inData;
	cout << "\tFolder Name: ";
	cin >> inData;
	temp->Setname(inData);
	int result = 0;
	temp = fdFolderList->Get(temp);
	if (temp!=NULL) {
		temp->DisplayRecordOnScreen();
		result = 1;
	}
	/*
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
		*/
	cout << "<====================================>" << endl;
	return result;
}

void FolderType::DisplayAllFolderName()
{
	if (subfoldernum == 0) {
		cout << "\t======Current Folder List======\n";
		//fdFolderList->print();
		cout << "\t==============================\n\n";
	}
	else {
		cout << "\t======Current Folder List======\n";
		fdFolderList->print();
		cout << "\t==============================\n\n";
	}
}
void FolderType::DisplayAllFileName() {
	if (filenum==0) {
		cout << "\t======Current File List======\n";
		//fdFileList->print();
		cout << "\t==============================\n\n";
	}
	else {
		cout << "\t======Current File List======\n";
		fdFileList->print();
		cout << "\t==============================\n\n";
	}
}

int FolderType::DeleteFolders() {
	FolderType temp;
	DisplayAllFolderName();
	temp.SetNameFromKB();

	bool result = fdFolderList->Find(temp);
	if (result ==false) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	else {
		fdFolderList->Delete(temp);
		cout << "\tDeleted Successfully!\n";
		subfoldernum--;
		memory--;
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	return result;
}

int FolderType::DeleteFolders2(FolderType temp) {

	int result = fdFolderList->Delete(temp);
	subfoldernum--;
	memory--;
	DisplayAllFolderName();
	DisplayAllFileName();
	return result;
}

int FolderType::DeleteFiles() {
	FileType temp;
	temp.SetNameFromKB();

	bool result = fdFileList->Find(temp);
	if (result == false) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
		DisplayAllFolderName();
		DisplayAllFileName();
	}
	else {
		fdFileList->Delete(temp);
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

FolderType* FolderType::SearchFolderWithInput(FolderType *temp) {
	return  fdFolderList->Get(temp);
}

FileType* FolderType::SearchFile(FileType *temp) {
	temp->SetNameFromKB();
	return  fdFileList->Get(temp);
}

FileType* FolderType::SearchFileWithInput(FileType *temp) {
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
	//FolderType data;
	//data.SetNameFromKB();
	/*
	data.Setpath(path+"\\"+data.GetName());
	//cout <<"data.path " << data.GetPath()<<endl;//���� ��
	FileType *temp;
	temp = new FileType;
	string textname = data.GetPath();
	for (int i = 0; i < textname.length(); i++) {
		if (textname[i] == '\\') {
			textname[i] = '+';
		}
	}
	//textname += data.GetName();
	//temp->Setaccess(textname);
	//cout << "textname: "<< textname;//���� ��
	temp->Setname(data.GetName());
	*/
	FileType *temp=new FileType;
	temp->SetNameFromKB();
	if (fdFileList->Get(temp) != nullptr) {//ã���� ��
		cout << "\tFound\n";
		ifstream indata;
		temp=fdFileList->Get(temp);
		indata.open(temp->Getaccess() + ".txt");
		if (!indata.is_open()) {
			//cout << temp->Getaccess() + ".txt";
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
	if (fdFolderList->Find(temp) == true){
		FolderType* temp2;
		temp2= fdFolderList->Get(&temp);
		temp2->SetNameFromKB();	
	}
	else {
		cout << "\tNo Such Folder\n";
	}
	return 0;
}

int FolderType::ChangeFileName() {
	FileType temp;
	DisplayAllFileName();
	cout << "\t�̸� �ٲ� ���� ����\n";
	temp.SetNameFromKB();
	if (fdFileList->Find(temp) == true) {
		FileType* temp2;
		temp2 = fdFileList->Get(&temp);
		temp2->SetNameFromKB();
	}
	else {
		cout << "\tNo Such File\n";
	}
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
		data.Setext(".wav");
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
