#pragma once
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include<ctime>
#include<iomanip>
#include <fstream>
#include <string>
#include<sstream>
#include"FileType.h"
#include "AllType.h"
//#include"Unsorted.h"
#include "Stack.h"
#include"DoublyLinkedList.h"
#include"DoublyIterator.h"
#include"BST.h"
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
		ext = ".fol";
		//fdFolderList = new DoublySortedLinkedList<FolderType>;
		//fdFileList = new DoublySortedLinkedList<FileType>;
		m_list = new  BinarySearchTree<AllType*>;
	}
	/**
	*	destructor.
	*/
	~FolderType()	{}

	/*
	Copy Constructor
	*/
	/*
	FolderType(const FolderType& input) {
		//cout << "\t���� ������ ���\n";
		name = input.name;
		GenCreateTime();
		memory = input.memory;
		subfoldernum = input.subfoldernum;
		filenum = input.filenum;
		size = input.size;
		path = input.path;
		fdFolderList = input.fdFolderList;
		fdFileList = input.fdFileList;
	}
	*/
	/**
	*	@brief	ArrayList *list�� ���ο� ������ �߰�
	*	@pre	����ڷκ��� ���� �̸��� �޴´�.
	*	@post	���� �̸�, �޸�, �ð����� initialize�ȴ�.
	*	@param	����
	*	@return 1�� ��ȯ�Ѵ�.
	*/
	virtual int AddFolder();

	/**
	*	@brief	������ ������ �����Ѵ�.
	*	@pre	����ڷκ��� ������ ���� �̸��� �޴´�.
	*	@post	������ ������ �����ȴ�.
	*	@param	����
	*	@return 1�� ��ȯ�Ѵ�.
	*/
	virtual int DeleteFolders();

	/**
*	@brief	������ ������ �����Ѵ�.
*	@pre	����ڷκ��� ������ ���� �̸��� �޴´�.
*	@post	������ ������ �����ȴ�.
*	@param	������ ������ �̸��� �޴´�.
*	@return 1�� ��ȯ�Ѵ�.
*/
	virtual int DeleteFolders2(AllType* temp);
	/**
*	@brief	������ ������ �����Ѵ�.
*	@pre	����ڷκ��� ������ ���� �̸��� �޴´�.
*	@post	������ ������ �����ȴ�.
*	@param	����
*	@return 1�� ��ȯ�Ѵ�.
*/
	virtual int DeleteFiles();

	/**
	*	@brief	������ ���������� �˻��Ѵ�.
	*	@pre	����ڷκ��� �˻��� �˻����� �޴´�.
	*	@post	�˻�� ���Ե� �������� ȭ�鿡 ��� �Ѵ�.
	*	@param	����
	*	@return ������ 1�� �̻� �߰��ϸ� 1��, ã�� �������� 0�� ��ȯ�Ѵ�.
	*/
	virtual int RetrieveFoldersByName();

	/**
	*	@brief	��� ������ ���δ�.
	*	@pre	����.
	*	@post	���� ������ �����ϴ� ��� ���� ������ ������ش�.
	*	@param	����.
	*	@return ����.
	*/
	virtual void DisplayAll();

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
		return ss.str();  // copy the stream buffer to name 
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
		cout << "\tName  : " << name << endl; 
	};

	/**
	*	@brief	path�� ȭ�鿡 ����Ѵ�.
	*	@pre	path�� �����Ǿ��ִ�.
	*	@post	path�� ȭ�鿡 ��µȴ�.
	*/
	virtual void DisplayPathOnScreen() 
	{
		cout << "\tPath : " << path<<ext << endl; 
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
		cout << "\tTime : " << time << endl;
	};

	/**
*	@brief	Display student address on screen.
*	@pre	student address is set.
*	@post	student address is on screen.
*/
	//���������� �����ִ� �Լ�!! �߰� ������ �ʿ��� �Լ���.
	void DisplayListOnScreen()
	{
		//�Ƹ��� ArrayList���� ������ �Լ��� ������ ���� ���� ���� �� �ϴ�.
		//cout << "\tTime : " << time << endl;
	};

	/**
	*	@brief	���� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	���� ������ ����Ǿ��ִ�.
	*	@post	���� ������ ȭ�鿡 ��µȴ�.
	*/
	virtual void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayPathOnScreen();
		//DisplayMemoryOnScreen();
		cout << "\tEXT : " << ext << endl;
		DisplayTimeOnScreen();
		cout << endl;
		//	DisplayListOnScreen();
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
	virtual AllType* SearchAllType(AllType *temp) ;

	/**
*	@brief	�ؽ�Ʈ ������ �����Ѵ�.
*	@pre	����
*	@post	�ش� ���� �Ϻο� �ؽ�Ʈ ������ �����ȴ�.
*	@param	����
*	@return 0�� ��ȯ�Ѵ�.
*/
	virtual int Addtextfile();

	/**
*	@brief	������ �ؽ�Ʈ ������ ����.
*	@pre	����
*	@post	������ �ؽ�Ʈ ������ ������.
*	@param	����
*	@return 1�� ��ȯ�Ѵ�.
*/
	virtual int Opentext();


	/**
*	@brief	�Ϻ� ������ �̸��� �����Ѵ�.
*	@pre	����
*	@post	������ ������ �̸��� ����ȴ�.
*	@return 0�� ����
*/
	virtual int ChangeSubfolderName();

	/**
*	@brief	�Ϻ� ������ �̸��� �����Ѵ�.
*	@pre	����
*	@post	������ ������ �̸��� ����ȴ�.
*	@return 0�� ����
*/
	virtual int ChangeFileName();

	/**
*	@brief	�Ϻ� ������ indata�� �Է� ���� ������ �����Ѵ�.
*	@pre	����
*	@post	indata�� ������ ������ ������ �Ϻ� ������ �����ȴ�.
*  @params indata�� �Ϻ� ������ �����Ѵ�.
*	@return 1�� ����
*/
	virtual int PasteFolder(AllType* indata);

	/**
*	@brief	�ش� ������ ���� �߰�
*	@pre	������ �� �ִ� �뷡�� ����� �����Ǿ��ִ�.
*	@post	������ ������ ���� ���ο� �߰��ȴ�.
*  @params ����.
*	@return �߰��Ǹ� 1�� ����, �׷��� ������ 0�� ����
*/
	virtual int IncludeMusic();

	/*	@brief �ش� ������ ���긮��Ʈ�� �����ϴ� �Լ�.
*	@pre	����
*	@post  ����.
*	@param ����
*	@return	m_list�� ����.
*/
	virtual BinarySearchTree<AllType*> Getsublist() {
		return *m_list;
	}

	 void PushAllFolder(Stack<FolderType>* box) {
		m_list->PushAllFolders(box);
	}
private:
	int memory;
	string times;
	int subfoldernum;
	int filenum;
	BinarySearchTree<AllType*> *m_list;
	int size;
};

#endif	// _ITEMTYPE_H
