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
	cout << "\t   1 : 폴더 생성" << endl;
	cout << "\t   2 : 폴더 삭제" << endl;
	cout << "\t   3 : 폴더 열기" << endl;
	cout << "\t   4 : 검색" << endl;
	cout << "\t   5 : 최근 열어본 폴더" << endl;
	cout << "\t   6 : 현재 폴더 속성" << endl;
	cout << "\t   7 : 상위 폴더로 이동" << endl;
	cout << "\t   8 : 하부 목록 보기" << endl;
	cout << "\t   9 : 폴더 이진 검색" << endl;
	cout << "\t  10 : 텍스트 파일 만들기" << endl;
	cout << "\t  11 : 텍스트 파일 열기" << endl;
	cout << "\t  12 : 폴더 이름 바꾸기" << endl;
	cout << "\t  13 : 파일 이름 바꾸기" << endl;
	cout << "\t  14 : 파일 삭제하기" << endl;
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

int Application::DeleteFile() {
	int result = m_curFolder->DeleteFile();
	return result;
}

//하부폴더로 들어가는 함수.

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
		cout << "해당 하부 폴더가 없습니다.\n";
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
	cout << "\t=====최근 열어본 폴더=====\n";
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
	string Filename=m_curFolder->Opentext();//최근 기록에 어떻게 파일 기록을 남길지.
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
int Application::BinarySearch()
{/*
	FolderType item;

	item.SetNameFromKB();	//id를 입력받는다
	if(m_curFolder.GetBinarySearch(item))	//이진탐색에 성공했다면
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen();
		cout<<"<====================================>"<<endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	*/
	FolderType *temp;
	temp = new FolderType;
	m_curFolder->SearchFolderBinary(temp);

	return 0;	//실패(0)을 반환
	
}
