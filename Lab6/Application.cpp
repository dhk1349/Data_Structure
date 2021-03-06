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
	cout << "\t   1. 폴더 생성\n";
	cout << "\t   2. 폴더 삭제\n";
	cout << "\t   3. 폴더 열기\n";
	cout << "\t   4. 폴더 속성\n";
	cout << "\t   5. 폴더 복사\n";
	cout << "\t   6. 폴더 잘라내기\n";
	cout << "\t   7. 폴더 붙여넣기\n";
	cout << "\t   8. 폴더 이름 바꾸기\n";
	cout << "\t   9. 나가기\n";
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
	cout << "\t   1. 텍스트 파일 생성\n";
	cout << "\t   2. 텍스트 파일 열기\n";
	cout << "\t   3. 파일 이름 바꾸기\n";
	cout << "\t   4. 파일 삭제\n";
	cout << "\t   5. 음악 저장하기\n";
	cout << "\t   6. 음악 재생하기\n";
	cout << "\t   7. 나가기\n";
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
	cout << "\t   1. 검색\n";
	cout << "\t   2. 나가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> comm;
	switch (comm) {
	case 1:
		RetrieveFolderByName();
		break;
	case 2:
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
	cout << "\t   1 : 하부 목록 보기" << endl;
	cout << "\t   2 : 폴더 옵션" << endl;
	cout << "\t   3 : 파일 옵션" << endl;
	cout << "\t   4 : 검색 옵션" << endl;
	cout << "\t   5 : 최근 기록" << endl;
	cout << "\t   6 : 상위 폴더로 이동(앞으로 이동)" << endl;
	cout << "\t   7 : 하위 폴더로 이동" << endl;
	cout << "\t   0 : 종료" << endl;

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
//Delete있음
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

//하부폴더로 들어가는 함수.

int Application::OpenFolder() {
	DisplayAll();
	FolderType* temp;
	temp = new FolderType;
	//int index = m_curFolder->SearchFolder(temp);
	m_curFolder = m_curFolder->SearchFolder(temp);
	if(m_curFolder!= NULL) {
		//m_curFolder->Setname(temp->GetName());  이렇게 하면 원래의 상위폴더의 이름이 바뀌어버림..
		//m_curFolder=m_curFolder->SearchGivenFolder(temp);
		//m_curFolder = temp; //이부분이 잘못되었다.
		
		Addque(m_curFolder);
		UpperLower.EqualizeIndex();
		return 1;
	}
	
	else {
		m_curFolder = UpperLower.Get(UpperLower.Getindex());
		cout << "해당 하부 폴더가 없습니다.\n";
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
	cout << "\t=====최근 열어본 폴더=====\n";
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
		cout << "\t더 이상 이동할 수 없습니다.\n";
	}
	return 1;
}

int Application::MoveForward() {
	if (UpperLower.Getindex2() > UpperLower.Getindex()) {
		UpperLower.IncreaseIndex();
		m_curFolder = UpperLower.Get(UpperLower.Getindex());
	}
	else {
		cout << "\t뒤로 갈 수 없습니다!!\n";
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
	//지정한 폴더를 temp에다가 복사해두었다.
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
		cout << "\t복사된 내용이 없습니다!!\n";
	}
}

void Application::ImportMusic() {
	m_curFolder->IncludeMusic();
}

int Application::PlayMusic() {
	m_curFolder->DisplayAllFileName();
	cout << "\t재생할 음악을 선택하세요(음악이 아니면 재생되지 않음)\n ";
	FileType* temp;
	temp = new FileType;
	temp = m_curFolder->SearchFile(temp);
	if (temp!=NULL) {
		if (temp->GetExt()=="wav") {
			//음악재생
			cout << "\t아무 키나 누르면 재생이 종료됩니다.\n";

			
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
			cout << "해당 파일의 형식은: "<<temp->GetExt()<<"\n";
			cout << "\t형식이 일치하지 않습니다.\n";
			return 1;
		}
	}
	else { cout << "\t해당 파일을 찾을 수 없습니다.\n"; return 1; }
}
/*
int Application::ChangeName() {
	string temp;
	cout << "바꿀 이름 입력:  ";
	cin >> temp;
	m_curFolder->Setname(temp);
	m_curFolder->Setpath();
	//검색하고 있으면 못 추가 없으면 추가.
	return 1;
}
*/
//id로 item을 찾아 출력한다.
/*
int Application::SearchFolderByName(FolderType& item)//여기를 수정하자.
{
	item.SetNameFromKB(); //id입력받는다.
	
	if(m_List.Get(item)) //0이 아니면(찾으면)
	{
		return 1;	//성공(1)을 리턴
	}
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//실패(0)을 리턴
}
*/
//이름을 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
/*
int Application::RetriveRecordByMemberName()
{
	FolderType item;
	item.SetNameFromKB(); //name을 입력받는다.

	if(SearchListByMemberName(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//이름으로 item을 찾아서 출력한다.
int Application::SearchListByMemberName( FolderType &inData )
{
	FolderType tmp;
	int result=0;

	m_List.ResetList();//iterator 초기화
	while(m_List.GetNextItem(tmp)!=-1) //리스트의 마지막까지 반복
	{
		if(tmp.GetName().find(inData.GetName())!=-1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if(result==0) //처음 찾는 경우라면
				cout<<"<============I FOUND ITEM !==========>"<<endl;
			tmp.DisplayRecordOnScreen();
			result=1;	//성공(1)
		}
	}
	if(result)	//발견한 경우
		cout<<"<====================================>"<<endl;
	else	//발견 못하는 경우
		cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return result;
}
*/
/*
// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	FolderType data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllFolders();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	FolderType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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