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
			FavoriteFolOption();
			break;
		case 5:
			FavoriteFileOption();
			break;
		case 6:
			RecentRecord();
			break;
		case 7:	
			MoveBack();
			break;
		case 8:		
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
	cout << "\t   6. ���� �߶󳻱�\n";
	cout << "\t   7. ���� �ٿ��ֱ�\n";
	cout << "\t   8. ���� �̸� �ٲٱ�\n";
	cout << "\t   9. ������\n";
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
			CutFolder();
			break;
		case 7:
			PasteFolder();
			break;
		case 8:
			ChangeFolderName();
			break;
		case 9:
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

void Application::FavoriteFolOption() {
	int comm;
	cout << "\t========Folder Command========\n";
	cout << "\t   1. ���ã�� ���� ����\n";
	cout << "\t   2. ����\n";
	cout << "\t   3. ������\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> comm;
	switch (comm) {
	case 1:
		PrintFavFol();
		break;
	case 2:
		EnterFavFol();
		break;
	case 3:
		break;
	default:
		cout << "\tIllegal Selection \n";
	}
}

void Application::FavoriteFileOption() {
	int comm;
	cout << "\t========Folder Command========\n";
	cout << "\t   1. ���ã�� ���� ����\n";
	cout << "\t   2. ����\n";
	cout << "\t   3. ������\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> comm;
	switch (comm) {
	case 1:
		PrintFavFile();
		break;
	case 2:
		EnterFavFile();
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
	cout << "\t   4 : ���� ���ã��" << endl;
	cout << "\t   5 : ���� ���ã��" << endl;
	cout << "\t   6 : �ֱ� ���" << endl;
	cout << "\t   7 : ���� ������ �̵�(������ �̵�)" << endl;
	cout << "\t   8 : ���� ������ �̵�" << endl;
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
	if (UpperLower.Getindex()>0) {
		int index = UpperLower.Getindex() - 1;
		m_curFolder = UpperLower.Get(index);
		m_RecentlyFolder.enque(m_curFolder);
		UpperLower.DecreaseIndex();
	}
	else {
		cout << "\t�� �̻� �̵��� �� �����ϴ�.\n";
	}
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
	FolderType copy(*m_curFolder->SearchFolder(temp));
	copyspace = copy;
	//������ ������ temp���ٰ� �����صξ���.
}

void Application::CutFolder() {
	DisplayAll();
	FolderType* temp;
	temp = new FolderType;
	copyspace = *m_curFolder->SearchFolder(temp);
	FolderType temp2;
	temp2 = *temp;
	m_curFolder->DeleteFolders2(temp2);
}

void Application::PasteFolder() {
	if (copyspace.GetName()!="") {
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

void Application::AddFavFol() {}
void Application::AddFavFile() {}

void Application::PrintFavFile() {
	cout << "\t=====���ã�� ����=====\n"; 
	//FavFile->pointprint();
	cout << "\t=======================\n";
}

void Application::PrintFavFol() {
	cout << "\t=====���ã�� ����=====\n";
	//FavFol->pointprint();
	cout << "\t=======================\n";
}

void Application::EnterFavFile() {
	FileType* temp = new FileType;
	temp->SetNameFromKB();
	if (FavFile->GetByPoint(temp) != nullptr) {
		temp->OpenText(temp);
	}
	else
	{
		cout << "\tNo such File\n";
	}
}

void Application::EnterFavFol() {}
