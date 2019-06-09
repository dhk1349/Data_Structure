#pragma once
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include<ctime>
#include<iomanip>
#include <fstream>
#include <string>
#include<sstream>
#include <Windows.h>
#include"FileType.h"
#include "AllType.h"
#include"DoublyLinkedList.h"
#include"DoublyIterator.h"
#include"AVL.h"
using namespace std;

/*
*	item information class.
*/
class FolderType: public AllType
{
public:
	/**
	*	default constructor.
	*/
	FolderType()
	{
		//cout << "\t디폴트 생성자 사용\n";
		name = "";
		path = "";
		memory = 0;
		times=GenCreateTime();
		subfoldernum = 0;
		filenum = 0;
		size = 0;
		fdFolderList = new AVLTree<FolderType>;
		fdFileList = new AVLTree<FileType>;
	}
	/**
	*	destructor.
	*/
	~FolderType()	{}

	/*
	Copy Constructor
	*/
	FolderType(const FolderType& input) {
		//cout << "\t복사 생성자 사용\n";
		name = input.name;
		times=GenCreateTime();
		memory = input.memory;
		subfoldernum = input.subfoldernum;
		filenum = input.filenum;
		size = input.size;
		path = input.path;
		SetFileList(input.fdFileList);
		SetFolderList(input.fdFolderList);
	}
	/**
	*	@brief	ArrayList *list에 새로운 폴더를 추가
	*	@pre	사용자로부터 폴더 이름을 받는다.
	*	@post	폴더 이름, 메모리, 시간등이 initialize된다.
	*	@param	없음
	*	@return 1을 반환한다.
	*/
	int AddFolder();

	/**
	*	@brief	지정한 폴더를 삭제한다.
	*	@pre	사용자로부터 삭제할 폴더 이름을 받는다.
	*	@post	지정한 폴더가 삭제된다.
	*	@param	없음
	*	@return 1을 반환한다.
	*/
	int DeleteFolders();

	/**
*	@brief	지정한 폴더를 삭제한다.
*	@pre	사용자로부터 삭제할 폴더 이름을 받는다.
*	@post	지정한 폴더가 삭제된다.
*	@param	삭제할 폴더의 이름을 받는다.
*	@return 1을 반환한다.
*/
	int DeleteFolders2(FolderType temp);
	/**
*	@brief	지정한 파일을 삭제한다.
*	@pre	사용자로부터 삭제할 파일 이름을 받는다.
*	@post	지정한 파일이 삭제된다.
*	@param	없음
*	@return 1을 반환한다.
*/
	int DeleteFiles();

	/**
	*	@brief	폴더를 폴더명으로 검색한다.
	*	@pre	사용자로부터 검색할 검색어을 받는다.
	*	@post	검색어가 포함된 폴더들을 화면에 출력 한다.
	*	@param	없음
	*	@return 폴더를 1개 이상 발견하면 1을, 찾지 못했으면 0을 반환한다.
	*/
	int RetrieveFoldersByName();

	/**
	*	@brief	모든 폴더를 보인다.
	*	@pre	없음.
	*	@post	현재 폴더가 포함하는 모든 서브 폴더를 출력해준다.
	*	@param	없음.
	*	@return 없음.
	*/
	void DisplayAllFolderName();

	/**
	*	@brief	현재의 시간을 변수 time에 저장.
	*	@pre	없음
	*	@post	현재 시간이 time에 저장됨.
	*	@param	없음.
	*	@return 없음.
	*/
	string  GenCreateTime() 
	{
		// Declaring argument for time() 
		time_t tt;

		// Declaring variable to store return value of 
		// localtime() 
		struct tm * ti;

		// Applying time() 
		time(&tt);

		// Using localtime() 
		ti = localtime(&tt);

		// stream output
		stringstream ss;
		ss << setw(4) << ti->tm_year + 1900 << setfill('0') << setw(2)
			<< ti->tm_mon + 1 << setfill('0') << setw(2) << ti->tm_mday << setfill('0') << setw(2) << ti->tm_hour << setfill('0') << setw(2)
			<< ti->tm_min << setfill('0') << setw(2) << ti->tm_sec << "\0";
		string temp = ss.str();
		return temp;
	}

	/**
	*	@brief	폴더이름을 리턴
	*	@pre	폴더의 이름이 정의되어있다.
	*	@post	none.
	*	@return	name
	*/
	string GetName()
	{
		return name;
	}

	/**
		*	@brief 해당 폴더의 경로를 반환해줌. 
		*	@pre	폴더의 경로가 저장되어있다.
		*	@post	없음.
		*	@param	없음.
		*	@return 현재 폴거의 경로를 스트링으로 반환
		*/
	string GetPath()
	{
		return path;
	}

	/**
	*	@brief	폴더의 메모리 정보 제공.
	*	@pre	해당 폴더의 메모리 크기가 저장되어있다.
	*	@post	없음. 
	*	@return 메모리 크기 반환.
	*/
	int GetMemory()
	{
		return memory;
	}

	/**
*	@brief	폴더의 생성시간 제공.
*	@pre	폴더의 생성 시간이 정해져있다.
*	@post	없음.
*	@return 해당 폴더의 생성시간을 스트링으로 반환.
*/
	string Gettime()
	{
		return times;
	}

	/**
	*	@brief	폴더 이름을 지정.
	*	@pre	없음
	*	@post	폴더의 name이 설정된다.
	*	@param	inname이 name에 저장
	*/
	void Setname(string inname)
	{
		name=inname;
	}
	
	/**
	*	@brief	폴더의 경로를 지정.
	*	@pre	없음.
	*	@post	폴더의 경로가 지정된다.
	*	@param	inpath이 path에 저장
	*/
	void Setpath(string inpath)
	{
		path=inpath;
	}
	
	/**
	*	@brief	아직 메모리에 대한 안내가 없어서 메모리를 설장하는 함수를 만들었습니다.
	*	@pre	없음.
	*	@post	폴더의 메모리가 정해진다. 
	*	@param	m이 memory에 저장된다.
	*/
	void Setmemory(int m )
	{
		memory=m;
	}
	
	/**
*	@brief	생성시간을 설정한다.
*	@pre	없음.
*	@post	생성시간(time)이 설정된다.
*	@param	intime이 time에 저장된다.
*/
	void Settime(string intime)
	{
		times=intime;
	}

	/**
	*	@brief	Set student record.
	*	@pre	none.
	*	@post	name, path, memory가 설정된다.
	*	@param	inname->name   inpath->path   inmemory->memory
	*/
	void SetRecord(string inname,string inpath, int inmemory)
	{
		Setname(inname);
		Setpath(inpath);
		Setmemory(inmemory);
	}

	/**
	*	@brief	폴더 이름을 화면에 출력.
	*	@pre	폴더 이름이 정해져있다. 
	*	@post	폴더이름이 화면에 출력된다.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName   : " << name << endl; 
	};

	/**
	*	@brief	path를 화면에 출력한다.
	*	@pre	path가 설정되어있다.
	*	@post	path가 화면에 출력된다.
	*/
	void DisplayPathOnScreen() 
	{
		cout << "\tPath : " << path << endl; 
	};

	/**
	*	@brief	메모리를 화면에 출력한다.
	*	@pre	메모리의 크기가 지정되어 있다.
	*	@post	해당 폴더의 크리가 화면에 출련된다.
	*/
	void DisplayMemoryOnScreen() 
	{
		cout << "\tMemory : " << memory << endl; 
	};

	/**
*	@brief	생성시간(time)을 화면에 출력한다.
*	@pre	생성시간 변수가 저장되어있다.
*	@post	생성시간(time)이 화면에 출력된다.
*/
	void DisplayTimeOnScreen()
	{
		cout << "\tTime : " << times << endl;
	};

	
	/**
	*	@brief	폴더 정보를 화면에 출력한다.
	*	@pre	폴더 정보가 저장되어있다.
	*	@post	폴더 정보가 화면에 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayPathOnScreen();
		DisplayMemoryOnScreen();
		DisplayTimeOnScreen();
		cout << endl;
	};

	/**
	*	@brief	폴더 이름을 키보드로 저장한다.
	*	@pre	없음.
	*	@post	폴더 이름이 저장된다.
	*/
	void SetNameFromKB();

	/**
*	@brief	폴더  정보를 키보드로 저장한다.
*	@pre	없음.
*	@post	폴더 정보가 저장된다.
*/
	void SetRecordFromKB();

	/**
	*	@brief	파일로부터 폴더 정보를 가져온다.
	*	@pre	대상 파일이 열린다.
	*	@post	들여온 파일로부터 폴더 정보가 저장된다.
	*	@param	fin	file descriptor.
	*	@return	성공적으로 저장하면 1을 리턴, 실패하면 0을 리턴.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	폴더 정보를 파일로 만든다.
	*	@pre	대상 파일이 만들어져있고, 서브폴더리스트가 초기화되어있다. 
	*	@post	새로운 폴더 데이터가 파일에 저장된다.
	*	@param	fout	file descriptor.
	*	@return	함수가 제대로 작동하면 1을 반환하고, 작동하지 않으면 0을 반환한다.
	*/
	int WriteDataToFile(ofstream& fout);
	


	/**
*	@brief	하부폴더를 검색
*	@pre	서브폴더가 초기화되어있다.
*	@post	찾는 폴더가 있다면 temp해 해당 폴더가 복사된다.
*	@param	temp에 해당 서브폴더의 정보를 넣는다.
*	@return	찾으려고 했던 폴더가 리턴되며, 찾지 못하면 NULL이 리턴된다.
*/
	FolderType* SearchFolder(FolderType *temp);

	FolderType* SearchFolderWithInput(FolderType *temp);

	/**
*	@brief	하부파일을 검색
*	@pre	없음
*	@post	찾는 파일이 있다면 temp해 해당 파일이 복사된다.
*	@param	temp에 검색할 파일 정보를 넣는다.
*	@return	찾으려고 했던 파일이 리턴되며, 찾지 못하면 NULL이 리턴된다
*/
	FileType* SearchFile(FileType *temp);

	/**
*	@brief	하부파일을 검색
*	@pre	없음
*	@post	찾는 파일이 있다면 temp해 해당 파일이 복사된다.
*	@param	찾고자 하는 파일의 이름이 담긴 파일타입 변수
*	@return	찾으려고 했던 파일이 리턴되며, 찾지 못하면 NULL이 리턴된다
*/
	FileType* SearchFileWithInput(FileType *temp);
	/**
*	@brief	하부폴더를 이진 검색으로 검색
*	@pre	서브폴더가 초기화되어있다.
*	@post	찾는 폴더가 있다면 temp해 해당 폴더가 복사된다.
*	@param	temp에 해당 서브폴더의 정보를 넣는다.
*	@return	해당 서브 폴더의 인덱스가 리턴되며, 해당 서브폴더가 없으면 -1을 리턴
*/
	int SearchFolderBinary(FolderType *temp);

	/**
*	@brief	텍스트 파일을 설정한다.
*	@pre	없음
*	@post	해당 폴더 하부에 텍스트 파일이 형성된다.
*	@param	없음
*	@return 0을 반환한다.
*/
	int Addtextfile();

	/**
*	@brief	지정한 텍스트 파일을 연다.
*	@pre	없음
*	@post	지정한 텍스트 파일이 열린다.
*	@param	없음
*	@return 1을 반환한다.
*/
	int Opentext();

	/**
*	@brief	해당 폴더 하부의 모든 파일들의 이름이 화면에 출력된다.
*	@pre	없음
*	@post	해당 폴더 하부의 모든 파일들의 이름이 화면에 출력된다.
*	@return 없음
*/
	void DisplayAllFileName();


	/**
*	@brief	하부 폴더의 이름을 변경한다.
*	@pre	없음
*	@post	지정한 폴더의 이름이 변경된다.
*	@return 0을 리턴
*/
	int ChagneSubfolderName();

	/**
*	@brief	하부 파일의 이름을 변경한다.
*	@pre	없음
*	@post	지정한 파일의 이름이 변경된다.
*	@return 0을 리턴
*/
	int ChangeFileName();

	/**
*	@brief	하부 폴더에 indata로 입력 받은 폴더를 생성한다.
*	@pre	없음
*	@post	indata와 동일한 정보의 폴더가 하부 폴더에 생성된다.
*  @params indata를 하부 폴더에 생성한다.
*	@return 1을 리턴
*/
	int PaseteFolder(FolderType indata);

	/**
*	@brief	해당 폴더에 음악 추가
*	@pre	저장할 수 있는 노래의 목록이 지정되어있다.
*	@post	지정한 음악이 폴더 내부에 추가된다.
*  @params 없음.
*	@return 추가되면 1을 리턴, 그렇지 않으면 0을 리턴
*/
	int IncludeMusic();


	/*
	@brief ==연산자 오버로딩
*	@return	name변수가 같으면 true,아니면 false
	*/
	bool operator==(const FolderType& temp) {
		if (this->name == temp.name) {
			return true;
		}
		return false;
	}
	
/*
	@brief <연산자 오버로딩
*	@retur오른쪽 name변수가 왼쪽 name변수 보다 크면 true,아니면 false
	*/
	bool operator<(const FolderType& temp) {
		if (this->name < temp.name) {
			return true;
		}
		return false;
	}

	/*
	@brief >연산자 오버로딩
*	@return	왼쪽 name변수가 오른쪽 name 변수보다 크면 true,아니면 false
	*/
	bool operator>(const FolderType& temp) {
		if (this->name > temp.name) {
			return true;
		}
		return false;
	}

	/**
*	@brief	입력받은 리스트를 현재 리스트에 복사
*	@pre	없음
*	@post	입력받은 리스트를 현재 리스트에 복사
*	@param	복사하고자 하는 파일리스트
*	@return	없음
*/
	void SetFileList(AVLTree<FileType>*fdlist) {
		fdFileList = NULL;
		if (fdlist)
			fdFileList = new AVLTree<FileType>(*fdlist);
	}

	/**
*	@brief	입력받은 리스트를 현재 리스트에 복사
*	@pre	없음
*	@post	입력받은 리스트를 현재 리스트에 복사
*	@param	복사하고자 하는 폴더리스트
*	@return	없음
*/
	void SetFolderList(AVLTree<FolderType>* fdlist) {
		fdFolderList = NULL;
		if (fdlist)
			fdFolderList = new AVLTree<FolderType>(*fdlist);
	}
private:
	string name;		
	string path;	
	int memory;
	string times;
	int subfoldernum;
	int filenum;
	AVLTree<FolderType> *fdFolderList;
	AVLTree<FileType> *fdFileList;
	int size;
};

#endif	// _ITEMTYPE_H
