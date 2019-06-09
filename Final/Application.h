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
*	@brief	��ü ���α׷��� �۵���Ű�� �Լ�
*	@pre	���α׷� ����
*	@post	���α׷� ��
*/
	void Run2();

	/**
*	@brief	Run�Լ� ���ο��� ���� �ɼ��� �۵���Ű�� �Լ�
*	@pre	RUN���� ���� �ɼ��� ���´�.
*	@post	���� �ɼ� ���ֿ� �ִ� ��� ����
*/
	void FolderOption();

	/**
*	@brief	Run�Լ� ���ο��� ���� �ɼ��� �۵���Ű�� �Լ�
*	@pre	RUN���� ���� �ɼ��� ���´�.
*	@post	���� �ɼ� ���ֿ� �ִ� ��� ����
*/
	void FileOption();

	/**
*	@brief	Run�Լ� ���ο��� �˻� �ɼ��� �۵���Ű�� �Լ�
*	@pre	RUN���� ���ã�� �ɼ��� ���´�.
*	@post	�������ã�� �ɼ����� ����
*/
	void FavoriteFolOption();
	
	void PrintFavFol();

	void PrintFavFile();

	void EnterFavFol();

	void EnterFavFile();

	void AddFavFol();
	
	void AddFavFile();

	/**
*	@brief	Run�Լ� ���ο��� �˻� �ɼ��� �۵���Ű�� �Լ�
*	@pre	RUN���� ���ã�� �ɼ��� ���´�.
*	@post	�������ã�� �ɼ����� ����
*/
	void FavoriteFileOption();

	/**
*	@brief	Ŀ�ǵ���� ����Ϳ� ���� Ŀ�ǵ带 ����ڷκ��� �޴´�
*	@pre	none.
*	@post	none.
*	@return	����ڰ� �Է��� ����� ��ȯ
*/
	int GetCommand2();

	/**
	*	@brief ���ο� ���������� ���� ������ �߰��Ѵ�.
	*	@pre	����
	*	@post	���ο� ���� ������ �߰��ȴ�.
	*	@return	1�� ��ȯ��
	*/
	int NewFolder();

	/**
*	@brief �Է� ���� ���� �����ϴ� ��� ���������� ����Ϳ� ���
*	@pre	����
*	@post	���ǿ� �´� ���� ������ ���.
*	@return	1�� ��ȯ��.
*/
	int RetrieveFolderByName();

	/**
*	@brief ���� ������ �Ӽ��� ����Ϳ� ����Ѵ�.
*	@pre	����
*	@post	���� ������ �Ӽ��� ��µ�.
*	@return	1�� ��ȯ��.
*/
	int DisplayProperty();


	/**
*	@brief ������ �Ϻ� ������ �̵�
*	@pre	����.
*	@post	������ �Ϻ� ������ �����ϸ� �Ϻ� ������ �̵�.
*	@return	�Ϻ������� �̵��ϸ� 1�� ����, �̵����� ���ϸ� 0�� ����.
*/
	int OpenFolder();
	/**
*	@brief ������ �����ϴ� �Լ�
*	@pre	������ ������ �̸��� �Է¹޴´�.
*	@post	�־��� �̸��� ������ �����ȴ�.
*	@return	������ ������ ������ 0��, ������ ������ ������ 1�� ��ȯ.
*/
	int DeleteFolder();


	/**
*	@brief ���� �����ϴ� �Լ�
*	@pre	������ ������ �̸��� �Է¹޴´�.
*	@post	�־��� �̸��� ���ϰ� �����ȴ�.
*	@return	������ ���� ������ 0��, ������ ������ ������ 1�� ��ȯ.
*/
	int Delete_File();
	/**
*	@brief ���������� ������ ��� ���
*	@pre	����
*	@post	��� ���� ������ ������ ��µȴ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int DisplayAll();

	/**
*	@brief m_RecentlyFolder�� ����� �߰��Ѵ�.
*	@pre	������ �� �� �۵��ȴ�.
*	@post	������ ���� ����� m_RecentlyFolder�� ����ȴ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int Addque(FolderType* indata);

	/**
*	@brief m_RecentlyFolder�� ����� �߰��Ѵ�.
*	@pre	����
*	@post	������ ���� ����� m_RecentlyFolder���� �� �տ� �ִ� ����� �������.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int Subque();

	/**
*	@brief ���������� �̵�.
*	@pre	�̵��� ���������� �����Ѵ�.
*	@post	���������� �̵��Ѵ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int MoveBack();

	/**
*	@brief ���� ����� ���ؼ� ������ ���� �Ϻ� ������ ����..
*	@pre	�̵��ߴ� ���� ������ �����Ѵ�.
*	@post	���������� �̵��Ѵ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int MoveForward();

	/**
*	@brief �ֱ� ���� ������ ȭ�鿡 ����Ѵ�.
*	@pre	����
*	@post	�ֱ� ������ ���� ������ ȭ�鿡 ���.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int RecentRecord();


	/**
*	@brief ���� ���� ������ �ؽ�Ʈ ������ �����Ѵ�.
*	@pre	���� ������ ������ �̸��� �ؽ�Ʈ ������ �������� �ʴ´�.
*	@post	�ؽ�Ʈ ���� ����
*	@return	1�� ��ȯ�Ѵ�.
*/
	int CreateText();

	/**
*	@brief �ؽ�Ʈ ������ ����.
*	@pre	�ش� ������ ������ �ؽ�Ʈ ������ �����Ѵ�.
*	@post	�ؽ�Ʈ ������ ������.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int OpenText();

	/**
*	@brief ���� �̸��� �����Ѵ�.
*	@pre	�ش� ������ ������ �̸��� ������ �������� �ʴ´�.
*	@post	�ش� ������ �̸��� ����ȴ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int ChangeFolderName();

	/**
*	@brief ���� �̸��� �����Ѵ�.
*	@pre	������ �̸��� ������ �������� �ʴ´�.
*	@post	�ش� ������ �̸��� ����ȴ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int ChangeFilename();

	/**
*	@brief ������ ������ copyspace��� ������ �����Ѵ�. (����)
*	@pre	������ ������ �����Ѵ�.
*	@post	������ ������ copyspace��� ������ ����ȴ�.
*	@return	����
*/
	void CopyFolder();
	/**
*	@brief m_curFolder�� Ư�� ������ �߶󳻱��Ѵ�.
*	@pre ����
*	@post	���� ������ Ư�� ������ �߸���.
*	@return	����
*/
	void CutFolder();
	/**
*	@brief m_curFolder�� �����س��� ������ �ٿ��ִ´�.
*	@pre ����
*	@post	���� ������ ������ ���� ������ �پ�־�����.
*	@return	����
*/
	void PasteFolder();

	/**
*	@brief �鿩�� �� �ִ� ������ �ش������� �����ͼ� �����Ѵ�.
*	@pre ����
*	@post	���� ������ ������ ������ ����ȴ�.
*	@return	����
*/
	void ImportMusic();

	/**
*	@brief �ش� ���� ���ο� �ִ� ������ ����Ѵ�.
*	@pre ����� ������ ���� ���ο� �����Ѵ�.
*	@post	���� ������ ������ ������ ����ȴ�.
*	@return	
*/
	int PlayMusic();

	//input�� �̹� �����Ѵٴ°��� ����
	int  PlayMusicWithInput(FileType*  temp) {
		if (temp != nullptr) {
			if (temp->GetExt() == ".wav") {
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
				cout << "�ش� ������ ������: " << temp->GetExt() << "\n";
				cout << "\t������ ��ġ���� �ʽ��ϴ�.\n";
				return 1;
			}
		}
		else { cout << "\t�ش� ������ ã�� �� �����ϴ�.\n"; return 1; }
	}

	void EnterWithAddress() {
		string address;
		cout << "\t�ּ�: ";
		cin >> address;
		EnterAddressWithInput(address);
	}
	void EnterAddressWithInput(string address) {
		CMinHeap<int> AddressIndex(100);
		int counter = 0;
		int validcounter = 0;//������ �� ���� ���丮�� ���ľ� �ϴ���, �� ���� ��Ʈ���� 0���� ����
		//AddressIndex->Add(-2);
		for (string::iterator it = address.begin(); it != address.end(); it++) {//�ش� ���ͷ��̼��� ��ġ�� �ּ� �� �� ���丮�� ���� ���ؽ��� ���´�.
			//AddressIndex���� 0,\�� �ε�����, �Ǹ����� �ε����� ���ʷ� ����.
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
		//openfolder�� �� ���� �ϸ� 0, �����ϸ� 1�� �����Ѵ�.
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
			if (i != validcounter-1 ) {//��� ������ ������
				temp2->Setname(address.substr(index1,index2-index1+1));
				temp=temp->SearchFolderWithInput(temp2);
				if (temp == nullptr) {break;}
				//else {cout << "Entered!\n";}
			}
			else {//�������� ����
				string filename = address.substr(index1,index2-index1+1-4);
				//cout << "Filename: " << filename << endl;
				string ext = address.substr(address.length()-4);
				//cout << "EXT: " << ext << endl;
				if (ext == ".fol") {
					temp2->Setname(filename);
					temp = temp->SearchFolderWithInput(temp2);
					if (temp != nullptr) { validaddress = true; }
				}
				else {//���� Ÿ���ΰ��
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
				//������¥ ������ ������
			CMinHeap<int> R_AddressIndex(100);
			 counter = 0;
			 validcounter = 0;//������ �� ���� ���丮�� ���ľ� �ϴ���, �� ���� ��Ʈ���� 0���� ����
			for (string::iterator it = address.begin(); it != address.end(); it++) {//�ش� ���ͷ��̼��� ��ġ�� �ּ� �� �� ���丮�� ���� ���ؽ��� ���´�.
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
				if (i != validcounter - 1) {//��� ������ ������
					temp2->Setname(address.substr(index1, index2 - index1 + 1));
					m_curFolder = m_curFolder->SearchFolderWithInput(temp2);
					Addque(m_curFolder);
					UpperLower.EqualizeIndex();
				}
				else {//�������� ����
					string filename = address.substr(index1, index2 - index1 + 1 - 4);
					string ext = address.substr(address.length() - 4);
					if (ext == ".fol") {
						temp2->Setname(filename);
						m_curFolder = m_curFolder->SearchFolderWithInput(temp2);
						Addque(m_curFolder);
						UpperLower.EqualizeIndex();
					}
					else {//���� Ÿ���ΰ��
						FileType * temp3 = new FileType;
						temp3->Setname(filename);
						temp3 = m_curFolder->SearchFileWithInput(temp3);
						if (ext == ".txt") { 
							cout << "\t=====����=====\n";
							temp3->OpenText(temp3); 
							cout << "==================\n";
						}
						else if (ext == ".wav") { PlayMusicWithInput(temp3); }
						else { cout << "\t�������� �ʴ� �����Դϴ�.\n"; }
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