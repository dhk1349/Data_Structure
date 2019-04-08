#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Queue.h"
#include "LinkedList.h"
#include "FolderType.h"
#include "Stack.h"
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
		AddFolderque(m_curFolder);
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
*	@brief 선택한 하부 폴더로 이동
*	@pre	없음.
*	@post	지정한 하부 폴더가 존재하면 하부 폴더로 이동.
*	@return	하부폴더로 이동하면 1을 리턴, 이동하지 못하면 0을 리턴.
*/
	int OpenFolder();
	/**
*	@brief 폴더를 삭제하는 함수
*	@pre	삭제할 폴더의 이름을 입력받는다.
*	@post	주어진 이름의 폴더가 삭제된다.
*	@return	삭제된 폴더가 없으면 0을, 삭제된 폴더가 있으면 1을 반환.
*/
	int DeleteFolder();

	int DeleteFile();
	/**
*	@brief 서브폴더의 정보를 모두 출력
*	@pre	없음
*	@post	모든 서브 폴더의 정보가 출력된다.
*	@return	1을 반환한다.
*/
	int DisplayAll();

	/**
*	@brief m_RecentlyFolder에 기록을 추가한다.
*	@pre	폴더를 열 때 작동된다.
*	@post	열었던 폴더 기록이 m_RecentlyFolder에 저장된다.
*	@return	1을 반환한다.
*/
	int AddFolderque(FolderType* indata);
	
	int AddFileque(string a);
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


	//int ChangeName();

	/**
*	@brief 폴더를 이진 검색한다.
*	@pre	없음
*	@post	검색한 폴더 정보가 출력
*	@return	1을 반환한다.
*/
	int BinarySearch();

	int CreateText();

	int OpenText();

	int ChangeFolderName();

	int ChangeFilename();
private:
	//ifstream m_InFile;		
	//ofstream m_OutFile;		
	int m_Command;			
	FolderType *m_curFolder;
	FolderType m_RootFolder;
	Queue<string> m_RecentlyRecord;
	Stack<FolderType> UpperLower;
};

#endif	// _APPLICATION_H