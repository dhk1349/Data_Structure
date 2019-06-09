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
		//cout << "\t����Ʈ ������ ���\n";
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
		//cout << "\t���� ������ ���\n";
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
	*	@brief	ArrayList *list�� ���ο� ������ �߰�
	*	@pre	����ڷκ��� ���� �̸��� �޴´�.
	*	@post	���� �̸�, �޸�, �ð����� initialize�ȴ�.
	*	@param	����
	*	@return 1�� ��ȯ�Ѵ�.
	*/
	int AddFolder();

	/**
	*	@brief	������ ������ �����Ѵ�.
	*	@pre	����ڷκ��� ������ ���� �̸��� �޴´�.
	*	@post	������ ������ �����ȴ�.
	*	@param	����
	*	@return 1�� ��ȯ�Ѵ�.
	*/
	int DeleteFolders();

	/**
*	@brief	������ ������ �����Ѵ�.
*	@pre	����ڷκ��� ������ ���� �̸��� �޴´�.
*	@post	������ ������ �����ȴ�.
*	@param	������ ������ �̸��� �޴´�.
*	@return 1�� ��ȯ�Ѵ�.
*/
	int DeleteFolders2(FolderType temp);
	/**
*	@brief	������ ������ �����Ѵ�.
*	@pre	����ڷκ��� ������ ���� �̸��� �޴´�.
*	@post	������ ������ �����ȴ�.
*	@param	����
*	@return 1�� ��ȯ�Ѵ�.
*/
	int DeleteFiles();

	/**
	*	@brief	������ ���������� �˻��Ѵ�.
	*	@pre	����ڷκ��� �˻��� �˻����� �޴´�.
	*	@post	�˻�� ���Ե� �������� ȭ�鿡 ��� �Ѵ�.
	*	@param	����
	*	@return ������ 1�� �̻� �߰��ϸ� 1��, ã�� �������� 0�� ��ȯ�Ѵ�.
	*/
	int RetrieveFoldersByName();

	/**
	*	@brief	��� ������ ���δ�.
	*	@pre	����.
	*	@post	���� ������ �����ϴ� ��� ���� ������ ������ش�.
	*	@param	����.
	*	@return ����.
	*/
	void DisplayAllFolderName();

	/**
	*	@brief	������ �ð��� ���� time�� ����.
	*	@pre	����
	*	@post	���� �ð��� time�� �����.
	*	@param	����.
	*	@return ����.
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
	*	@brief	�����̸��� ����
	*	@pre	������ �̸��� ���ǵǾ��ִ�.
	*	@post	none.
	*	@return	name
	*/
	string GetName()
	{
		return name;
	}

	/**
		*	@brief �ش� ������ ��θ� ��ȯ����. 
		*	@pre	������ ��ΰ� ����Ǿ��ִ�.
		*	@post	����.
		*	@param	����.
		*	@return ���� ������ ��θ� ��Ʈ������ ��ȯ
		*/
	string GetPath()
	{
		return path;
	}

	/**
	*	@brief	������ �޸� ���� ����.
	*	@pre	�ش� ������ �޸� ũ�Ⱑ ����Ǿ��ִ�.
	*	@post	����. 
	*	@return �޸� ũ�� ��ȯ.
	*/
	int GetMemory()
	{
		return memory;
	}

	/**
*	@brief	������ �����ð� ����.
*	@pre	������ ���� �ð��� �������ִ�.
*	@post	����.
*	@return �ش� ������ �����ð��� ��Ʈ������ ��ȯ.
*/
	string Gettime()
	{
		return times;
	}

	/**
	*	@brief	���� �̸��� ����.
	*	@pre	����
	*	@post	������ name�� �����ȴ�.
	*	@param	inname�� name�� ����
	*/
	void Setname(string inname)
	{
		name=inname;
	}
	
	/**
	*	@brief	������ ��θ� ����.
	*	@pre	����.
	*	@post	������ ��ΰ� �����ȴ�.
	*	@param	inpath�� path�� ����
	*/
	void Setpath(string inpath)
	{
		path=inpath;
	}
	
	/**
	*	@brief	���� �޸𸮿� ���� �ȳ��� ��� �޸𸮸� �����ϴ� �Լ��� ��������ϴ�.
	*	@pre	����.
	*	@post	������ �޸𸮰� ��������. 
	*	@param	m�� memory�� ����ȴ�.
	*/
	void Setmemory(int m )
	{
		memory=m;
	}
	
	/**
*	@brief	�����ð��� �����Ѵ�.
*	@pre	����.
*	@post	�����ð�(time)�� �����ȴ�.
*	@param	intime�� time�� ����ȴ�.
*/
	void Settime(string intime)
	{
		times=intime;
	}

	/**
	*	@brief	Set student record.
	*	@pre	none.
	*	@post	name, path, memory�� �����ȴ�.
	*	@param	inname->name   inpath->path   inmemory->memory
	*/
	void SetRecord(string inname,string inpath, int inmemory)
	{
		Setname(inname);
		Setpath(inpath);
		Setmemory(inmemory);
	}

	/**
	*	@brief	���� �̸��� ȭ�鿡 ���.
	*	@pre	���� �̸��� �������ִ�. 
	*	@post	�����̸��� ȭ�鿡 ��µȴ�.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName   : " << name << endl; 
	};

	/**
	*	@brief	path�� ȭ�鿡 ����Ѵ�.
	*	@pre	path�� �����Ǿ��ִ�.
	*	@post	path�� ȭ�鿡 ��µȴ�.
	*/
	void DisplayPathOnScreen() 
	{
		cout << "\tPath : " << path << endl; 
	};

	/**
	*	@brief	�޸𸮸� ȭ�鿡 ����Ѵ�.
	*	@pre	�޸��� ũ�Ⱑ �����Ǿ� �ִ�.
	*	@post	�ش� ������ ũ���� ȭ�鿡 ��õȴ�.
	*/
	void DisplayMemoryOnScreen() 
	{
		cout << "\tMemory : " << memory << endl; 
	};

	/**
*	@brief	�����ð�(time)�� ȭ�鿡 ����Ѵ�.
*	@pre	�����ð� ������ ����Ǿ��ִ�.
*	@post	�����ð�(time)�� ȭ�鿡 ��µȴ�.
*/
	void DisplayTimeOnScreen()
	{
		cout << "\tTime : " << times << endl;
	};

	
	/**
	*	@brief	���� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	���� ������ ����Ǿ��ִ�.
	*	@post	���� ������ ȭ�鿡 ��µȴ�.
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
	*	@brief	���� �̸��� Ű����� �����Ѵ�.
	*	@pre	����.
	*	@post	���� �̸��� ����ȴ�.
	*/
	void SetNameFromKB();

	/**
*	@brief	����  ������ Ű����� �����Ѵ�.
*	@pre	����.
*	@post	���� ������ ����ȴ�.
*/
	void SetRecordFromKB();

	/**
	*	@brief	���Ϸκ��� ���� ������ �����´�.
	*	@pre	��� ������ ������.
	*	@post	�鿩�� ���Ϸκ��� ���� ������ ����ȴ�.
	*	@param	fin	file descriptor.
	*	@return	���������� �����ϸ� 1�� ����, �����ϸ� 0�� ����.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���� ������ ���Ϸ� �����.
	*	@pre	��� ������ ��������ְ�, ������������Ʈ�� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	���ο� ���� �����Ͱ� ���Ͽ� ����ȴ�.
	*	@param	fout	file descriptor.
	*	@return	�Լ��� ����� �۵��ϸ� 1�� ��ȯ�ϰ�, �۵����� ������ 0�� ��ȯ�Ѵ�.
	*/
	int WriteDataToFile(ofstream& fout);
	


	/**
*	@brief	�Ϻ������� �˻�
*	@pre	���������� �ʱ�ȭ�Ǿ��ִ�.
*	@post	ã�� ������ �ִٸ� temp�� �ش� ������ ����ȴ�.
*	@param	temp�� �ش� ���������� ������ �ִ´�.
*	@return	ã������ �ߴ� ������ ���ϵǸ�, ã�� ���ϸ� NULL�� ���ϵȴ�.
*/
	FolderType* SearchFolder(FolderType *temp);

	FolderType* SearchFolderWithInput(FolderType *temp);

	/**
*	@brief	�Ϻ������� �˻�
*	@pre	����
*	@post	ã�� ������ �ִٸ� temp�� �ش� ������ ����ȴ�.
*	@param	temp�� �˻��� ���� ������ �ִ´�.
*	@return	ã������ �ߴ� ������ ���ϵǸ�, ã�� ���ϸ� NULL�� ���ϵȴ�
*/
	FileType* SearchFile(FileType *temp);

	/**
*	@brief	�Ϻ������� �˻�
*	@pre	����
*	@post	ã�� ������ �ִٸ� temp�� �ش� ������ ����ȴ�.
*	@param	ã���� �ϴ� ������ �̸��� ��� ����Ÿ�� ����
*	@return	ã������ �ߴ� ������ ���ϵǸ�, ã�� ���ϸ� NULL�� ���ϵȴ�
*/
	FileType* SearchFileWithInput(FileType *temp);
	/**
*	@brief	�Ϻ������� ���� �˻����� �˻�
*	@pre	���������� �ʱ�ȭ�Ǿ��ִ�.
*	@post	ã�� ������ �ִٸ� temp�� �ش� ������ ����ȴ�.
*	@param	temp�� �ش� ���������� ������ �ִ´�.
*	@return	�ش� ���� ������ �ε����� ���ϵǸ�, �ش� ���������� ������ -1�� ����
*/
	int SearchFolderBinary(FolderType *temp);

	/**
*	@brief	�ؽ�Ʈ ������ �����Ѵ�.
*	@pre	����
*	@post	�ش� ���� �Ϻο� �ؽ�Ʈ ������ �����ȴ�.
*	@param	����
*	@return 0�� ��ȯ�Ѵ�.
*/
	int Addtextfile();

	/**
*	@brief	������ �ؽ�Ʈ ������ ����.
*	@pre	����
*	@post	������ �ؽ�Ʈ ������ ������.
*	@param	����
*	@return 1�� ��ȯ�Ѵ�.
*/
	int Opentext();

	/**
*	@brief	�ش� ���� �Ϻ��� ��� ���ϵ��� �̸��� ȭ�鿡 ��µȴ�.
*	@pre	����
*	@post	�ش� ���� �Ϻ��� ��� ���ϵ��� �̸��� ȭ�鿡 ��µȴ�.
*	@return ����
*/
	void DisplayAllFileName();


	/**
*	@brief	�Ϻ� ������ �̸��� �����Ѵ�.
*	@pre	����
*	@post	������ ������ �̸��� ����ȴ�.
*	@return 0�� ����
*/
	int ChagneSubfolderName();

	/**
*	@brief	�Ϻ� ������ �̸��� �����Ѵ�.
*	@pre	����
*	@post	������ ������ �̸��� ����ȴ�.
*	@return 0�� ����
*/
	int ChangeFileName();

	/**
*	@brief	�Ϻ� ������ indata�� �Է� ���� ������ �����Ѵ�.
*	@pre	����
*	@post	indata�� ������ ������ ������ �Ϻ� ������ �����ȴ�.
*  @params indata�� �Ϻ� ������ �����Ѵ�.
*	@return 1�� ����
*/
	int PaseteFolder(FolderType indata);

	/**
*	@brief	�ش� ������ ���� �߰�
*	@pre	������ �� �ִ� �뷡�� ����� �����Ǿ��ִ�.
*	@post	������ ������ ���� ���ο� �߰��ȴ�.
*  @params ����.
*	@return �߰��Ǹ� 1�� ����, �׷��� ������ 0�� ����
*/
	int IncludeMusic();


	/*
	@brief ==������ �����ε�
*	@return	name������ ������ true,�ƴϸ� false
	*/
	bool operator==(const FolderType& temp) {
		if (this->name == temp.name) {
			return true;
		}
		return false;
	}
	
/*
	@brief <������ �����ε�
*	@retur������ name������ ���� name���� ���� ũ�� true,�ƴϸ� false
	*/
	bool operator<(const FolderType& temp) {
		if (this->name < temp.name) {
			return true;
		}
		return false;
	}

	/*
	@brief >������ �����ε�
*	@return	���� name������ ������ name �������� ũ�� true,�ƴϸ� false
	*/
	bool operator>(const FolderType& temp) {
		if (this->name > temp.name) {
			return true;
		}
		return false;
	}

	/**
*	@brief	�Է¹��� ����Ʈ�� ���� ����Ʈ�� ����
*	@pre	����
*	@post	�Է¹��� ����Ʈ�� ���� ����Ʈ�� ����
*	@param	�����ϰ��� �ϴ� ���ϸ���Ʈ
*	@return	����
*/
	void SetFileList(AVLTree<FileType>*fdlist) {
		fdFileList = NULL;
		if (fdlist)
			fdFileList = new AVLTree<FileType>(*fdlist);
	}

	/**
*	@brief	�Է¹��� ����Ʈ�� ���� ����Ʈ�� ����
*	@pre	����
*	@post	�Է¹��� ����Ʈ�� ���� ����Ʈ�� ����
*	@param	�����ϰ��� �ϴ� ��������Ʈ
*	@return	����
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
