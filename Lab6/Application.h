#ifndef _APPLICATION_H
#define _APPLICATION_H
#define MAX_PATH 260

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "FolderType.h"
#include "Stack.h"
#include <Windows.h>
#include <MMsystem.h>
#include <conio.h>
using namespace std;
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
	void Run2();

	/**
*	@brief	Run함수 내부에서 폴더 옵션을 작동시키는 함수
*	@pre	RUN에서 폴더 옵션을 들어온다.
*	@post	폴더 옵션 범주에 있는 명령 동작
*/
	void FolderOption();

	/**
*	@brief	Run함수 내부에서 파일 옵션을 작동시키는 함수
*	@pre	RUN에서 파일 옵션을 들어온다.
*	@post	파일 옵션 범주에 있는 명령 동작
*/
	void FileOption();

	/**
*	@brief	Run함수 내부에서 검색 옵션을 작동시키는 함수
*	@pre	RUN에서 검색 옵션을 들어온다.
*	@post	검색 옵션 범주에 있는 명령 동작
*/
	void SearchOption();

	/**
*	@brief	커맨드들을 모니터에 띄우고 커맨드를 사용자로부터 받는다
*	@pre	none.
*	@post	none.
*	@return	사용자가 입력한 명령을 반환
*/
	int GetCommand2();

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


	/**
*	@brief 파일 삭제하는 함수
*	@pre	삭제할 파일의 이름을 입력받는다.
*	@post	주어진 이름의 파일가 삭제된다.
*	@return	삭제된 파일 없으면 0을, 삭제된 파일이 있으면 1을 반환.
*/
	int Delete_File();
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
*	@brief 폴더 기록을 통해서 이전에 들어갔던 하부 폴더로 들어간다..
*	@pre	이동했던 하위 폴더가 존재한다.
*	@post	하위폴더로 이동한다.
*	@return	1을 반환한다.
*/
	int MoveForward();

	/**
*	@brief 최근 폴더 정보를 화면에 출력한다.
*	@pre	없음
*	@post	최근 열었던 폴더 정보가 화면에 출력.
*	@return	1을 반환한다.
*/
	int RecentRecord();


	/**
*	@brief 현재 속한 폴더에 텍스트 파일을 생성한다.
*	@pre	현재 폴더에 동일한 이름의 텍스트 파일이 존재하지 않는다.
*	@post	텍스트 파일 형성
*	@return	1을 반환한다.
*/
	int CreateText();

	/**
*	@brief 텍스트 파일을 연다.
*	@pre	해당 폴더에 지정한 텍스트 파일이 존재한다.
*	@post	텍스트 파일이 열린다.
*	@return	1을 반환한다.
*/
	int OpenText();

	/**
*	@brief 폴더 이름을 변경한다.
*	@pre	해당 폴더에 동일한 이름의 폴더가 존재하지 않는다.
*	@post	해당 폴더의 이름이 변경된다.
*	@return	1을 반환한다.
*/
	int ChangeFolderName();

	/**
*	@brief 파일 이름을 변경한다.
*	@pre	동일한 이름의 파일이 존재하지 않는다.
*	@post	해당 파일의 이름이 변경된다.
*	@return	1을 반환한다.
*/
	int ChangeFilename();

	/**
*	@brief 지정한 폴더를 copyspace라는 폴더에 저장한다. (복사)
*	@pre	지정할 폴더가 존재한다.
*	@post	지정한 폴더가 copyspace라는 공간에 저장된다.
*	@return	없음
*/
	void CopyFolder();
	/**
*	@brief m_curFolder에 특정 폴더를 잘라내기한다.
*	@pre 없음
*	@post	현재 폴더에 특정 폴더가 잘린다.
*	@return	없음
*/
	void CutFolder();
	/**
*	@brief m_curFolder에 복사해놓은 폴더를 붙여넣는다.
*	@pre 없음
*	@post	현재 폴더에 복사해 놓은 폴더가 붙어넣어진다.
*	@return	없음
*/
	void PasteFolder();

	/**
*	@brief 들여올 수 있는 음악을 해당폴더에 가져와서 저장한다.
*	@pre 없음
*	@post	현재 폴더에 지정한 음악이 저장된다.
*	@return	없음
*/
	void ImportMusic();

	/**
*	@brief 해당 폴더 내부에 있는 음악을 재생한다.
*	@pre 재생할 음악이 폴더 내부에 존재한다.
*	@post	현재 폴더에 지정한 음악이 재생된다.
*	@return	
*/
	int PlayMusic();

private:
	//ifstream m_InFile;		
	//ofstream m_OutFile;		
	int m_Command;			
	FolderType *m_curFolder;
	FolderType copyspace;
	FolderType m_RootFolder;
	Queue<FolderType> m_RecentlyFolder;
	Stack<FolderType> UpperLower;
	DoublySortedLinkedList<AllType> Freq;
};

#endif	// _APPLICATION_H