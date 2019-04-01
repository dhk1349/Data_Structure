#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Queue.h"
#include "ArrayList.h"
#include "FolderType.h"
#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_RootFolder.SetRecord("Root", "Root", 0);
		m_curFolder = new FolderType;
		m_curFolder = &m_RootFolder;
		Addque(m_curFolder);
		m_Command = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	전체 프로그램을 작동시키는 함수
	*	@pre	프로그램 시작
	*	@post	프로그램 끝
	*/
	void Run();

	/**
	*	@brief	커맨드들을 모니터에 띄우고 커맨드를 사용자로부터 받는다
	*	@pre	none.
	*	@post	none.
	*	@return	사용자가 입력한 명령을 반환
	*/
	int GetCommand();

	/**
	*	@brief 새로운 서브폴더를 현재 폴더에 추가한다.
	*	@pre	없음
	*	@post	새로운 서브 폴더가 추가된다.
	*	@return	1을 반환함
	*/
	int NewFolder();

	/**
*	@brief 입력 받은 값을 포함하는 모든 서브폴더를 모니터에 출력
*	@pre	없음
*	@post	조건에 맞는 서브 폴더들 출력.
*	@return	1을 반환함.
*/
	int RetrieveFolderByName();

	/**
*	@brief 현재 폴더의 속성을 모니터에 출력한다.
*	@pre	없음
*	@post	현재 폴더의 속성이 출력됨.
*	@return	1을 반환함.
*/
	int DisplayProperty();


	/**
*	@brief 
*	@pre	
*	@post	
*	@return	
*/
	int OpenFolder();
	/**
*	@brief 폴더를 삭제하는 함수
*	@pre	삭제할 폴더의 이름을 입력받는다.
*	@post	주어진 이름의 폴더가 삭제된다.
*	@return	삭제된 폴더가 없으면 0을, 삭제된 폴더가 있으면 1을 반환.
*/
	int DeleteFolder();

	/**
*	@brief 서브폴더의 정보를 모두 출력
*	@pre	없음
*	@post	모든 서브 폴더의 정보가 출력된다.
*	@return	1을 반환한다.
*/
	int DisplayAllFolders();

	/**
*	@brief m_RecentlyFolder에 기록을 추가한다.
*	@pre	폴더를 열 때 작동된다.
*	@post	열었던 폴더 기록이 m_RecentlyFolder에 저장된다.
*	@return	1을 반환한다.
*/
	int Addque(FolderType* indata);

	/**
*	@brief m_RecentlyFolder에 기록을 추가한다.
*	@pre	없음
*	@post	열었던 폴더 기록이 m_RecentlyFolder에서 맨 앞에 있는 기록이 사라진다.
*	@return	1을 반환한다.
*/
	int Subque();

	/**
*	@brief 상위폴더로 이동.
*	@pre	이동할 상위폴더가 존재한다.
*	@post	상위폴더로 이동한다.
*	@return	1을 반환한다.
*/
	int MoveBack();
	/**
*	@brief 최근 폴더 정보를 화면에 출력한다.
*	@pre	없음
*	@post	최근 열었던 폴더 정보가 화면에 출력.
*	@return	1을 반환한다.
*/
	int RecentRecord();

	//int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	//int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	//int WriteDataToFile();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	//int SearchFolderByName(FolderType& item);

	/**
	*	@brief	리스트에서 해당 이름을 가진 item을 찾아 출력한다.
	*	@pre	없음.
	*	@post	찾은 item이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	//int RetriveRecordByMemberName();

	/**
	*	@brief	리스트에서 해당 이름을 가진 item을 찾아 반환한다.
	*	@pre	인자로 받는 ItemType에 이름이 입력되어 있어야 한다.
	*	@post	찾은 item이 인자로 들어온다.
	*	@param	inData	이름이 입력되 있는 ItemType값.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	//int SearchListByMemberName( FolderType &inData );

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	//int OpenInFile(char *fileName);

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 이진탐색을 이용해 찾는다.
	*	@pre	없음.
	*	@post	찾은 item이 화면에 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	//int SearchItemByBinarySearch();

private:
	//ifstream m_InFile;		
	//ofstream m_OutFile;		
	int m_Command;			
	FolderType *m_curFolder;
	FolderType m_RootFolder;
	Queue<FolderType> m_RecentlyFolder;
	Queue<FolderType> UpperLower;
};

#endif	// _APPLICATION_H