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
	*	@brief	��ü ���α׷��� �۵���Ű�� �Լ�
	*	@pre	���α׷� ����
	*	@post	���α׷� ��
	*/
	void Run();

	/**
	*	@brief	Ŀ�ǵ���� ����Ϳ� ���� Ŀ�ǵ带 ����ڷκ��� �޴´�
	*	@pre	none.
	*	@post	none.
	*	@return	����ڰ� �Է��� ����� ��ȯ
	*/
	int GetCommand();

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

	int DeleteFile();
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
	int AddFolderque(FolderType* indata);
	
	int AddFileque(string a);
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
*	@brief �ֱ� ���� ������ ȭ�鿡 ����Ѵ�.
*	@pre	����
*	@post	�ֱ� ������ ���� ������ ȭ�鿡 ���.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int RecentRecord();


	//int ChangeName();

	/**
*	@brief ������ ���� �˻��Ѵ�.
*	@pre	����
*	@post	�˻��� ���� ������ ���
*	@return	1�� ��ȯ�Ѵ�.
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