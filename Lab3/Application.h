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
*	@brief 
*	@pre	
*	@post	
*	@return	
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
*	@brief ���������� ������ ��� ���
*	@pre	����
*	@post	��� ���� ������ ������ ��µȴ�.
*	@return	1�� ��ȯ�Ѵ�.
*/
	int DisplayAllFolders();

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
*	@brief �ֱ� ���� ������ ȭ�鿡 ����Ѵ�.
*	@pre	����
*	@post	�ֱ� ������ ���� ������ ȭ�鿡 ���.
*	@return	1�� ��ȯ�Ѵ�.
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
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	//int SearchFolderByName(FolderType& item);

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� item�� ã�� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	//int RetriveRecordByMemberName();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� ItemType�� �̸��� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	�̸��� �Էµ� �ִ� ItemType��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	//int SearchListByMemberName( FolderType &inData );

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	//int OpenInFile(char *fileName);

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ����Ž���� �̿��� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ȭ�鿡 ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
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