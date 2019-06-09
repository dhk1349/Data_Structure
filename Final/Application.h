#ifndef _APPLICATION_H
#define _APPLICATION_H
#define MAX_PATH 260

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "FolderType.h"
#include  "FileType.h"
#include "Stack.h"
#include "AVL2.h"
#include "BaseHeap.h"
#include "MinHeap.h"
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
		FavFile = new AVLTree2<FileType*>;
		FavFol = new AVLTree2<FolderType*>;
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
*	@pre	RUN에서 즐겨찾기 옵션을 들어온다.
*	@post	폴더즐겨찾기 옵션으로 들어간다
*/
	void FavoriteFolOption();
	
	void PrintFavFol();

	void PrintFavFile();

	void EnterFavFol();

	void EnterFavFile();

	void AddFavFol();
	
	void AddFavFile();

	/**
*	@brief	Run함수 내부에서 검색 옵션을 작동시키는 함수
*	@pre	RUN에서 즐겨찾기 옵션을 들어온다.
*	@post	파일즐겨찾기 옵션으로 들어간다
*/
	void FavoriteFileOption();

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

	//input은 이미 존재한다는것이 가정
	int  PlayMusicWithInput(FileType*  temp) {
		if (temp != nullptr) {
			if (temp->GetExt() == ".wav") {
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
				cout << "해당 파일의 형식은: " << temp->GetExt() << "\n";
				cout << "\t형식이 일치하지 않습니다.\n";
				return 1;
			}
		}
		else { cout << "\t해당 파일을 찾을 수 없습니다.\n"; return 1; }
	}

	void EnterWithAddress() {
		string address;
		cout << "\t주소: ";
		cin >> address;
		EnterAddressWithInput(address);
	}
	void EnterAddressWithInput(string address) {
		CMinHeap<int> AddressIndex(100);
		int counter = 0;
		int validcounter = 0;//실제로 몇 번의 디렉토리를 거쳐야 하는지, 맨 앞은 루트여서 0으로 시작
		//AddressIndex->Add(-2);
		for (string::iterator it = address.begin(); it != address.end(); it++) {//해당 이터레이션을 마치면 주소 중 매 디렉토리의 시작 인텍스가 나온다.
			//AddressIndex에는 0,\전 인덱스들, 맨마지막 인덱스가 차례로 들어간다.
			if (*it == '\\') {
				//cout << "Adding " << counter + 1 << endl;
				AddressIndex.Add(counter + 1);
				validcounter += 1;
			}
			if (it == address.end() - 1) {
				//cout << "Adding " << counter + 2 << endl;
				AddressIndex.Add(counter+2);
			}
			counter += 1;
		}
		//openfolder할 때 실패 하면 0, 성공하면 1을 리턴한다.
		FolderType* temp = new FolderType;
		temp = &m_RootFolder;
		FolderType *temp2 = new FolderType;
		bool validaddress = false;
		int index1;
		int index2 = AddressIndex.Dequeue()-2;
		for (int i = 0;i<validcounter;i++) {
			index1 = index2+2;
			index2 = AddressIndex.Dequeue()-2;
			//cout << "Entering  " << address.substr(index1, index2 - index1 + 1) << endl;
			if (i != validcounter-1 ) {//계속 폴더로 들어가야함
				temp2->Setname(address.substr(index1,index2-index1+1));
				temp=temp->SearchFolderWithInput(temp2);
				if (temp == nullptr) {break;}
				//else {cout << "Entered!\n";}
			}
			else {//마지막에 들어가기
				string filename = address.substr(index1,index2-index1+1-4);
				//cout << "Filename: " << filename << endl;
				string ext = address.substr(address.length()-4);
				//cout << "EXT: " << ext << endl;
				if (ext == ".fol") {
					temp2->Setname(filename);
					temp = temp->SearchFolderWithInput(temp2);
					if (temp != nullptr) { validaddress = true; }
				}
				else {//파일 타입인경우
					FileType * temp3 = new FileType;
					temp3->Setname(filename);
					temp3 = temp->SearchFileWithInput(temp3);
					if (temp3 != nullptr) { validaddress = true; }
				}
			}
		}
		if (validaddress == false) {
			cout << "\tInvalid Address!\n";
		}
		else { cout << "\tValid Address!\n"; 
				//이제진짜 폴더로 들어가야함
			CMinHeap<int> R_AddressIndex(100);
			 counter = 0;
			 validcounter = 0;//실제로 몇 번의 디렉토리를 거쳐야 하는지, 맨 앞은 루트여서 0으로 시작
			for (string::iterator it = address.begin(); it != address.end(); it++) {//해당 이터레이션을 마치면 주소 중 매 디렉토리의 시작 인텍스가 나온다.
				if (*it == '\\') {
					R_AddressIndex.Add(counter + 1);
					validcounter += 1;
				}
				if (it == address.end() - 1) {
					R_AddressIndex.Add(counter + 2);
				}
				counter += 1;
			}
			m_curFolder = &m_RootFolder;
			UpperLower.Reset();
			int index1;
			int index2 = R_AddressIndex.Dequeue() - 2;
			for (int i = 0; i < validcounter; i++) {
				index1 = index2 + 2;
				index2 = R_AddressIndex.Dequeue() - 2;
				if (i != validcounter - 1) {//계속 폴더로 들어가야함
					temp2->Setname(address.substr(index1, index2 - index1 + 1));
					m_curFolder = m_curFolder->SearchFolderWithInput(temp2);
					Addque(m_curFolder);
					UpperLower.EqualizeIndex();
				}
				else {//마지막에 들어가기
					string filename = address.substr(index1, index2 - index1 + 1 - 4);
					string ext = address.substr(address.length() - 4);
					if (ext == ".fol") {
						temp2->Setname(filename);
						m_curFolder = m_curFolder->SearchFolderWithInput(temp2);
						Addque(m_curFolder);
						UpperLower.EqualizeIndex();
					}
					else {//파일 타입인경우
						FileType * temp3 = new FileType;
						temp3->Setname(filename);
						temp3 = m_curFolder->SearchFileWithInput(temp3);
						if (ext == ".txt") { 
							cout << "\t=====내용=====\n";
							temp3->OpenText(temp3); 
							cout << "==================\n";
						}
						else if (ext == ".wav") { PlayMusicWithInput(temp3); }
						else { cout << "\t지원하지 않는 형식입니다.\n"; }
					}
				}
			}

		}

	}

private:
	//ifstream m_InFile;		
	//ofstream m_OutFile;		
	int m_Command;			
	FolderType *m_curFolder;
	FolderType copyspace;
	FolderType m_RootFolder;
	Queue<FolderType> m_RecentlyFolder;
	Stack<FolderType> UpperLower;
	AVLTree2<FolderType*> *FavFol;
	AVLTree2<FileType*> *FavFile;
};

#endif	// _APPLICATION_H