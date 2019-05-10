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
*	@pre	RUN���� �˻� �ɼ��� ���´�.
*	@post	�˻� �ɼ� ���ֿ� �ִ� ��� ����
*/
	void SearchOption();

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