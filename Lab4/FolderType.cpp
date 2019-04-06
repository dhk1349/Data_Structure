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
		cout << "\t같은 이름의 폴더가 존재합니다!\n";
	}
	return 1;
}

int FolderType::Addtextfile() {
	FolderType mock;
	mock.SetNameFromKB();
	mock.Setpath(path+"/"+mock.name);

	//txt를 넣는 곳
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
	cout << "EXIT을 입력하면 종료\n";
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

	fdFolderList->ResetList();//iterator 초기화
	while (true) //리스트의 마지막까지 반복
	{
		int iter = fdFolderList->GetNextItem(temp);
		if (temp.name.find(inData) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
		if (iter == 0) { break; }
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
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
			//여기서 문제
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
			//여기서 문제
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
	int index=list.GetBinarySearch(*temp); //성공하면 1, 실패하면 0을 값으로 가질 것이다.
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

	if (fdFileList->Get(*temp) == 1) {//찾았을 때
		cout << "\tFound\n";
		ifstream indata;
		indata.open(temp->Getaccess()+".txt");
		string temp;
		while (indata.peek() != EOF) {
			// std::getline은 입력 스트림에서 string으로 한 줄을 읽습니다.
			getline(indata, temp);
			cout << temp << endl;
		}
		return 1;
	}
	else {//못 찾았을 때
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