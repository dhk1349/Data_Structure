#include "Application.h"


// Program driver.
void Application::Run()
{
	
	while(1)
	{
		cout << "\n\t=====================\n";
		m_curFolder->DisplayPathOnScreen();
		cout << "\t=====================";
		m_Command = GetCommand();
		
		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			NewFolder();
			break;
		case 2:		//search by id.
			DeleteFolder();
			break;
		case 3:	
			OpenFolder();
			break;
		case 4:		//search by name.
			RetrieveFolderByName();
			break;
		case 5:		
			RecentRecord();
			break;
		case 6:		//replace
			DisplayProperty();
			break;
		case 7:		// display all the records in list on screen.
			MoveBack();
			break;
		case 8:
			DisplayAll();
			break;
		case 9:
			BinarySearch();
			break;
		case 10:
			CreateText();
			break;
		case 11:
			OpenText();
			break;
		case 12:
			ChangeFolderName();
			break;
		case 13:
			ChangeFilename();
			break;
		case 14:
			DeleteFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}
int Application::DisplayAll() {
	m_curFolder->DisplayAllFolderName();
	m_curFolder->DisplayAllFileName();
	return 1;
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	//DisplayAllFolders();
	int command;
	cout << endl << endl;
	cout << "\t-------- Command -------- " << endl;
	cout << "\t   1 : ���� ����" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� ����" << endl;
	cout << "\t   4 : �˻�" << endl;
	cout << "\t   5 : �ֱ� ��� ����" << endl;
	cout << "\t   6 : ���� ���� �Ӽ�" << endl;
	cout << "\t   7 : ���� ������ �̵�" << endl;
	cout << "\t   8 : �Ϻ� ��� ����" << endl;
	cout << "\t   9 : ���� ���� �˻�" << endl;
	cout << "\t  10 : �ؽ�Ʈ ���� �����" << endl;
	cout << "\t  11 : �ؽ�Ʈ ���� ����" << endl;
	cout << "\t  12 : ���� �̸� �ٲٱ�" << endl;
	cout << "\t  13 : ���� �̸� �ٲٱ�" << endl;
	cout << "\t  14 : ���� �����ϱ�" << endl;
	cout << "\t   0 : ����" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::NewFolder() 
{
	int result = m_curFolder->AddFolder();
	return result;
}
int Application:: RetrieveFolderByName() 
{
	m_curFolder->RetrieveFoldersByName();
	return 1;
}
//Delete����
int Application::DisplayProperty() 
{
	m_curFolder->DisplayRecordOnScreen();
	return 1;
}

int Application::DeleteFolder() {
	int result=m_curFolder->DeleteFolders();
	return result;
}

int Application::DeleteFile() {
	int result = m_curFolder->DeleteFile();
	return result;
}

//�Ϻ������� ���� �Լ�.

int Application::OpenFolder() {
	DisplayAll();
	FolderType* temp;
	temp = new FolderType;
	int index = m_curFolder->SearchFolder(temp);
	if ( index!= 0) {
		m_curFolder = temp;
		int result=AddFolderque(m_curFolder);
		if (result == 0) {
			Subque();
			AddFolderque(m_curFolder);
		}
		return 1;
	}
	else {
		cout << "�ش� �Ϻ� ������ �����ϴ�.\n";
		return 0;
	}
}

int Application::AddFolderque(FolderType* indata) {
	m_RecentlyRecord.enque(indata->GetName());
	UpperLower.push(indata);
	return 1;
}
int Application::AddFileque(string a) {
	m_RecentlyRecord.enque(a);
	return 1;
}

int Application::Subque() {
	FolderType temp;
	m_RecentlyRecord.deque();
	return 1;
}
int Application::RecentRecord() {
	cout << "\t=====�ֱ� ��� ����=====\n";
	m_RecentlyRecord.print();
	cout << "\t==========================\n";
	return 1;
}

int Application::MoveBack() {
	int index=UpperLower.Getindex()-1;
	m_curFolder = UpperLower.Get(index);
	AddFolderque(m_curFolder);
	UpperLower.DecreaseIndex();
	return 1;
}

int Application::CreateText() {
	m_curFolder->Addtextfile();
	return 1;
}

int Application::OpenText() {
	string Filename=m_curFolder->Opentext();//�ֱ� ��Ͽ� ��� ���� ����� ������.
	if (Filename != "-100") {
		AddFileque(Filename);
	}
	return 1;
}

int Application::ChangeFolderName() {
	m_curFolder->ChagneSubfolderName();
	m_curFolder->DisplayAllFolderName();
	return 1;
}
int Application::ChangeFilename() {
	m_curFolder->ChangeFileName();
	m_curFolder->DisplayAllFileName();
	return 1;
}
/*
int Application::ChangeName() {
	string temp;
	cout << "�ٲ� �̸� �Է�:  ";
	cin >> temp;
	m_curFolder->Setname(temp);
	m_curFolder->Setpath();
	//�˻��ϰ� ������ �� �߰� ������ �߰�.
	return 1;
}
*/
//id�� item�� ã�� ����Ѵ�.
/*
int Application::SearchFolderByName(FolderType& item)//���⸦ ��������.
{
	item.SetNameFromKB(); //id�Է¹޴´�.
	
	if(m_List.Get(item)) //0�� �ƴϸ�(ã����)
	{
		return 1;	//����(1)�� ����
	}
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//����(0)�� ����
}
*/
//�̸��� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
/*
int Application::RetriveRecordByMemberName()
{
	FolderType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if(SearchListByMemberName(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchListByMemberName( FolderType &inData )
{
	FolderType tmp;
	int result=0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while(m_List.GetNextItem(tmp)!=-1) //����Ʈ�� ���������� �ݺ�
	{
		if(tmp.GetName().find(inData.GetName())!=-1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if(result==0) //ó�� ã�� �����
				cout<<"<============I FOUND ITEM !==========>"<<endl;
			tmp.DisplayRecordOnScreen();
			result=1;	//����(1)
		}
	}
	if(result)	//�߰��� ���
		cout<<"<====================================>"<<endl;
	else	//�߰� ���ϴ� ���
		cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return result;
}
*/
/*
// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	FolderType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllFolders();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	FolderType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}
*/
int Application::BinarySearch()
{/*
	FolderType item;

	item.SetNameFromKB();	//id�� �Է¹޴´�
	if(m_curFolder.GetBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen();
		cout<<"<====================================>"<<endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	*/
	FolderType *temp;
	temp = new FolderType;
	m_curFolder->SearchFolderBinary(temp);

	return 0;	//����(0)�� ��ȯ
	
}
