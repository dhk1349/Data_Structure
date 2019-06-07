#include "FolderType.h"
using namespace std;

int FolderType::AddFolder() {
	//if (subfoldernum == 0) 
		
	AllType *data;
	data = new FolderType;
	data->SetNameFromKB();
	data->Setpath(path+"\\"+data->GetName());

	if (m_list->Add(data)==1) {
		subfoldernum++;
		memory++;
		cout << endl;
		DisplayAll();
	}
	else {
		cout << "\t���� �̸��� ������ �����մϴ�!\n";
	}
	return 1;
}
int FolderType::PasteFolder(AllType* indata) {
    //�̺κ��� ��� �ٲپ�������� ���ؼ� ����� ��.
	AllType *temp = new FolderType;
	temp=indata;
	temp->Setpath(path + "\\" + temp->GetName());
	while (true) {
		if (m_list->Add(temp) == 1) {
			subfoldernum++;
			memory++;
			DisplayAll();
			return 1;
		}
		else {
			//�Ȱ��� ������ �����Ѵٸ� �̸� �ڿ� ���� �߰��ؼ� �ٽ� �߰��Ѵ�.
			temp->Setname(temp->GetName() + "_1");
			temp->Setpath(path + "\\" + temp->GetName());
		}
	}
}
int FolderType::Addtextfile() {
	FolderType mock;
	mock.SetNameFromKB();
	mock.Setpath(path+"\\"+mock.name);

	//txt�� �ִ� ��
	AllType *data=new FileType;
	data->Setname(mock.GetName());
	data->Setpath(mock.GetPath());
	data->Settime(mock.Gettime()) ;
	data->Setext(".txt");
	string textname=data->Getpath();
	for (int i = 0; i < textname.length(); i++) {
		if (textname[i] == '\\') {
			textname[i] = '+';
		}
	}
	ofstream outdata;
	outdata.open(textname+".txt");
	data->Setaccess(textname);
	string test;
	cout << "EXIT�� �Է��ϸ� ����\n";
	while (true) {
		getline(cin, test);
		if (test == "EXIT") { break; }
		outdata << test << endl;
	}
	outdata.close();
	if (m_list->Add(data) == 1){
		filenum++;
		cout << "\t���� �߰� ����\n";
	}
	else { cout << "\t���� �߰� ����\n"; }
	DisplayAll();
	return 0;
}

int FolderType::RetrieveFoldersByName() {
	AllType *temp=new FolderType;
	string inData;
	cout << "\tFolder Name: ";
	cin >> inData;
	temp->Setname(inData);
	int result = 0;
	temp = m_list->Get(temp);
	if (temp->GetExt()!="NULL") {
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

void FolderType::DisplayAll()
{
	if (subfoldernum == 0&&filenum==0) {
		cout << "\t======Current List======\n";
		//fdFolderList->print();
		cout << "\t==============================\n\n";
	}
	else {
		cout << "\t======Current List======\n";
		m_list->print();
		cout << "\t==============================\n\n";
	}
}

int FolderType::DeleteFolders() {
	AllType *temp=new FolderType;
	DisplayAll();
	temp->SetNameFromKB();

	int result = m_list->Delete(temp);
	if (result == 0) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
		DisplayAll();
	}
	else {
		cout << "\tDeleted Successfully!\n";
		subfoldernum--;
		memory--;
		DisplayAll();
	}
	return result;
}

int FolderType::DeleteFolders2(AllType* temp) {

	int result = m_list->Delete(temp);
	subfoldernum--;
	memory--;
	DisplayAll();
	return result;
}

int FolderType::DeleteFiles() {
	AllType *temp=new FileType;
	temp->SetNameFromKB();

	int result = m_list->Delete(temp);
	if (result == 0) {
		cout << "\t=====[ERROR]=====\n";
		cout << "\t=There is no such file!!=\n";
		DisplayAll();
	}
	else {
		cout << "\tDeleted Successfully!\n";
		filenum--;
		memory--;
		DisplayAll();
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

AllType* FolderType::SearchAllType(AllType *temp) {
	temp->SetNameFromKB();
	return  m_list->Get(temp);
}

int FolderType::Opentext() {
	DisplayAll();
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
	AllType *temp=new FileType;
	temp->SetNameFromKB();
	if (m_list->Get(temp) != NULL) {//ã���� ��
		cout << "\tFound\n";
		ifstream indata;
		temp=m_list->Get(temp);
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

int FolderType::ChangeSubfolderName() {
	AllType *temp=new FolderType;
	DisplayAll();
	cout << "\t�̸� �ٲ� ���� ����\n";
	temp->SetNameFromKB();
	m_list->Replace(temp);
	return 0;
}

int FolderType::ChangeFileName() {
	AllType *temp=new FileType;
	DisplayAll();
	cout << "\t�ٲ� ���� ����\n";
	temp->SetNameFromKB();
	m_list->Replace(temp);
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
		AllType *data=new FileType;
		data->Setname(mock.GetName());
		data->Setpath(mock.GetPath());
		data->Settime(mock.Gettime());
		data->Setext("wav");
		m_list->Add(data);
		filenum++;
		DisplayAll();
		return 1;
	}
	else {
		cout << "\t�׷� �̸��� ������ �߰��� �� �����ϴ�.\n";
		return 0;
	}
}
// Compare two itemtypes.
