#pragma once
#include "_Library.h"

class Application
{
private:
	int							m_Command;		///< current command number.

	SortedList<ItemType*> MasterList;	
	SortedList<ContainerType*> ContainerList;
	TempType TempList;

public:
	/**
	*	constructor.
	*/
	Application();

	/**
	*	destructor.
	*/
	~Application();

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*/
	void GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchById_SequenS();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� item�� ã�� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByName();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� ItemType�� �̸��� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	�̸��� �Էµ� �ִ� ItemType��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchAllItmeByName(ItemType& inData);

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteItem();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceItem();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ����Ž���� �̿��� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ȭ�鿡 ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByID_BinaryS();

	void AddPlayItem();
	void DeletePlayItem();
	void PrintAllPlayItem();
};