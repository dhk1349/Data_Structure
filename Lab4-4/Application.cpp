#include "Application.h"


// Program driver.
void Application::Run2()
{
	while (1)
	{
		cout << "\n\t=====================\n";
		m_curFolder->DisplayPathOnScreen();
		cout << "\t=====================";
		m_Command = GetCommand2();
		switch (m_Command)
		{
		case 1:		
			DisplayAll(); 
			break;
		case 2:		
			FolderOption();
			break;
		case 3:
			FileOption();
			break;
		case 4:		
			SearchOption();
			break;
		case 5:
			RecentRecord();
			break;
		case 6:	
			MoveBack();
			break;
		case 7:		
			MoveForward();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::FolderOption() {
	int comm;
	cout << "\t========Folder Command========\n";
	cout << "\t   1. ���� ����\n";
	cout << "\t   2. ���� ����\n";
	cout << "\t   3. ���� ����\n";
	cout << "\t   4. ���� �Ӽ�\n";
	cout << "\t   5. ���� ����\n";
	cout << "\t   6. ���� �ٿ��ֱ�\n";
	cout << "\t   7. ���� �̸� �ٲٱ�\n";
	cout << "\t   8. ������\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> comm;
	switch (comm) {
		case 1	:
			NewFolder();
			break;
		case 2:
			DeleteFolder();
			break;
		case 3:
			OpenFolder();
			break;
		case 4:
			DisplayProperty();
			break;
		case 5:
			CopyFolder();
			break;
		case 6:
			PasteFolder();
			break;
		case 7:
			ChangeFolderName();
			break;
		case 8:
			break;
		default:
			cout << "\tIllegal Selection \n";
	}
}

void Application::FileOption() {
	int comm;
	cout << "\t========Folder Command========\n";
	cout << "\t   1. �ؽ�Ʈ ���� ����\n";
	cout << "\t   2. �ؽ�Ʈ ���� ����\n";
	cout << "\t   3. ���� �̸� �ٲٱ�\n";
	cout << "\t   4. ���� ����\n";
	cout << "\t   5. ���� �����ϱ�\n";
	cout << "\t   6. ���� ����ϱ�\n";
	cout << "\t   7. ������\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> comm;
	switch (comm) {
	case 1:
		CreateText();
		break;
	case 2:
		OpenText();
		break;
	case 3:
		ChangeFilename();
		break;
	case 4:
		Delete_File();
		break;
	case 5:
		ImportMusic();
		break;
	case 6:
		PlayMusic();
		break;
	case 7:
		break;
	default:
		cout << "\tIllegal Selection \n";
	}
}

void Application::SearchOption() {
	int comm;
	cout << "\t========Folder Command========\n";
	cout << "\t   1. �˻�\n";
	cout << "\t   2. ���� �˻�\n";
	cout << "\t   3. ������\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> comm;
	switch (comm) {
	case 1:
		RetrieveFolderByName();
		break;
	case 2:
		BinarySearch();
		break;
	case 3:
		break;
	default:
		cout << "\tIllegal Selection \n";
	}
}

int Application::DisplayAll() {
	m_curFolder->DisplayAllFolderName();
	m_curFolder->DisplayAllFileName();
	return 1;
}

int Application::GetCommand2() {
	//DisplayAllFolders();
	int command;
	cout << endl << endl;
	cout << "\t-------- Command -------- " << endl;
	cout << "\t   1 : �Ϻ� ��� ����" << endl;
	cout << "\t   2 : ���� �ɼ�" << endl;
	cout << "\t   3 : ���� �ɼ�" << endl;
	cout << "\t   4 : �˻� �ɼ�" << endl;
	cout << "\t   5 : �ֱ� ���" << endl;
	cout << "\t   6 : ���� ������ �̵�(������ �̵�)" << endl;
	cout << "\t   7 : ���� ������ �̵�" << endl;
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

int Application::Delete_File() {
	int result = m_curFolder->DeleteFiles();
	return result;
}

//�Ϻ������� ���� �Լ�.

int Application::OpenFolder() {
	DisplayAll();
	FolderType* temp;
	temp = new FolderType;
	//int index = m_curFolder->SearchFolder(temp);
	m_curFolder = m_curFolder->SearchFolder(temp);
	if(m_curFolder!= NULL) {
		//m_curFolder->Setname(temp->GetName());  �̷��� �ϸ� ������ ���������� �̸��� �ٲ�����..
		//m_curFolder=m_curFolder->SearchGivenFolder(temp);
		//m_curFolder = temp; //�̺κ��� �߸��Ǿ���.
		
		Addque(m_curFolder);
		UpperLower.EqualizeIndex();
		return 1;
	}
	
	else {
		m_curFolder = UpperLower.Get(UpperLower.Getindex());
		cout << "�ش� �Ϻ� ������ �����ϴ�.\n";
		return 0;
	}
}

int Application::Addque(FolderType* indata) {
	m_RecentlyFolder.enque(indata);
	UpperLower.push(indata);
	return 1;
}

int Application::Subque() {
	FolderType temp;
	m_RecentlyFolder.deque();
	return 1;
}
int Application::RecentRecord() {
	cout << "\t=====�ֱ� ��� ����=====\n";
	m_RecentlyFolder.print();
	cout << "\t==========================\n";
	return 1;
}

int Application::MoveBack() {
	int index=UpperLower.Getindex()-1;
	m_curFolder = UpperLower.Get(index);
	m_RecentlyFolder.enque(m_curFolder);
	UpperLower.DecreaseIndex();
	return 1;
}

int Application::MoveForward() {
	if (UpperLower.Getindex2() > UpperLower.Getindex()) {
		UpperLower.IncreaseIndex();
		m_curFolder = UpperLower.Get(UpperLower.Getindex());
	}
	else {
		cout << "\t�ڷ� �� �� �����ϴ�!!\n";
	}
	return 1;
}

int Application::CreateText() {
	m_curFolder->Addtextfile();
	return 1;
}

int Application::OpenText() {
	m_curFolder->Opentext();
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


void Application::CopyFolder() {
	DisplayAll();
	FolderType* temp;
	temp = new FolderType;
	copyspace = m_curFolder->SearchFolder(temp);
	//������ ������ temp���ٰ� �����صξ���.
}
void Application::PasteFolder() {
	if (copyspace!=NULL) {
		m_curFolder->PaseteFolder(copyspace);
	}
	else {
		cout << "\t����� ������ �����ϴ�!!\n";
	}
}

void Application::ImportMusic() {
	m_curFolder->IncludeMusic();
}

int Application::PlayMusic() {
	m_curFolder->DisplayAllFileName();
	cout << "\t����� ������ �����ϼ���(������ �ƴϸ� ������� ����)\n ";
	FileType* temp;
	temp = new FileType;
	temp = m_curFolder->SearchFile(temp);
	if (temp!=NULL) {
		if (temp->GetExt()=="wav") {
			//�������
			cout << "\t�ƹ� Ű�� ������ ����� ����˴ϴ�.\n";

			
			string inname = temp->GetName() + ".wav";

			char buffer[MAX_PATH];
			GetModuleFileNameA(NULL, buffer, MAX_PATH);
			string::size_type pos = string(buffer).find_last_of("\\/");
			inname = string(buffer).substr(0, pos) + "\\" + inname;
			LPCSTR song = inname.c_str();

			PlaySound(song, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			while (!_kbhit());
			PlaySound(NULL, 0, 0);
			return 1;
		}
		else {
			cout << "�ش� ������ ������: "<<temp->GetExt()<<"\n";
			cout << "\t������ ��ġ���� �ʽ��ϴ�.\n";
			return 1;
		}
	}
	else { cout << "\t�ش� ������ ã�� �� �����ϴ�.\n"; return 1; }
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
