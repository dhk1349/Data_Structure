#pragma once
#ifndef _ALLTYPE_H
#define _ALLTYPE_H
#include<iostream>
#include <string>
#include"Unsorted.h"
using namespace std;

class AllType {
protected:
	string name;
	string path;
	string ext;
public:
	/**
*	@brief �ش� ������ �̸� ������ �޴´�.
*	@pre	����
*	@post	�ش� ������ name�� ���ϵȴ�.
*	@return	name
*/
	 string GetName() {
		return name;
	}
	/**
*	@brief �ش� ������ Ȯ���� ������ �޴´�.
*	@pre	����
*	@post	�ش� ������ ext�� ���ϵȴ�.
*	@return	ext
*/
	string GetExt() {
		return ext;
	}
	/**
	*	@brief �ش� ������ ��� ������ �޴´�.
	*	@pre	����
	*	@post	�ش� ������ path�� ���ϵȴ�.
	*	@return	path
	*/
	string Getpath() {
		return path;
	}

	/**
*	@brief ofstream���� ����� �ش� �ؽ�Ʈ ������ �̸��� ���ϵȴ�.
*	@pre	����
*	@post	ofstream���� ����� �ش� txt�����̸��� ��ȯ���ش�.
*	@return	access
*/
	virtual string Getaccess() {
		return "Getaccess�� �߸��� ȣ��\n";
	}
	/**
*	@brief �ش� ������ �̸��� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ name������ �����ȴ�.
*	@param stirng in�� name������ ������ �ȴ�.
*	@return	����
*/
	void Setname(string in) {
		name = in;
	}

	virtual void Setaccess(string in) { cout << "\t�̰� �Ҹ��� �ȵȴ�.\n"; };
	/**
*	@brief �ش� ������ ��θ� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ path������ �����ȴ�.
*	@param stirng in�� path������ ������ �ȴ�.
*	@return	����
*/
	void Setpath(string in) {
		path = in;
	}


	/**
*	@brief �ش� ������ ext ���� ���� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ ext������ �����ȴ�.
*	@param stirng in�� ext������ ������ �ȴ�.
*	@return	����
*/
	void Setext(string in) {
		ext = in;
	}

	/*	@brief �ش� ������ �����ð� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ time������ �����ȴ�.
*	@param stirng in�� time������ ������ �ȴ�.
*	@return	����
*/
	virtual void Settime(string in) {
		cout << "�Ҹ��� �ȵǴ� �Լ�\n";
	}
	virtual void DisplayPathOnScreen() {}
	virtual void DisplayRecordOnScreen() {
		cout << "�Ҹ��� �ȵǴ� �Լ� display record on screen\n";
	}
	virtual void DisplayAll() { cout << "�Ҹ��� �ȵǴ� �Լ� displayallfoldername\n"; }
	virtual int AddFolder() { cout << "�Ҹ��� �ȵǴ� add folder"; return -1; }
	virtual int RetrieveFoldersByName() { cout << "�Ҹ��� �ȵǴ� retrievefoldersbyname"; return -1; }
	virtual int DeleteFiles() { cout << "�Ҹ��� �ȵǴ�deletefiles"; return -1; }
	virtual int DeleteFolders() { cout << "�Ҹ��� �ȵǴ� deletefolders"; return -1; }
	virtual AllType* SearchFolder(AllType* temp) { cout << "�Ҹ��� �ȵǴ� search folder"; return temp; }
	virtual int Addtextfile() { cout << "�Ҹ��� �ȵǴ� addtextfile\n"; return -1; }
	virtual int Opentext() { cout << "�Ҹ��� �ȵǴ� opentext"; return -1; }
	virtual int ChangeSubfolderName() { cout << "�Ҹ��� �ȵǴ� changesubfoldername\n"; return -1; }
	virtual int ChangeFileName() { cout << "�Ҹ��� �ȵǴ� changefilename"; return -1; }
	virtual int DeleteFolders2(AllType *temp) { cout << "�Ҹ��� �ȵǴ� deletefoldets2"; return-2; }
	virtual int PasteFolder(AllType* indata) { "�Ҹ��� �ȵǴ� pastefolder"; return -1; }
	virtual int IncludeMusic() { cout << "�Ҹ��� �ȵǴ� includemusic"; return -1; }
	virtual AllType* SearchFile(AllType* temp) { cout << "�Ҹ���ȵǴ� searchfile"; return temp; }
	virtual UnsortedList<AllType*> Getsublist() { cout << "�Ҹ��� �ȵǴ� getsublist";  
		UnsortedList<AllType*>temp;
		return temp;
	}
	/**
*	@brief �ش� ������ �̸��� Ű����� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ name������ �����ȴ�.
*	@param ����
*	@return	����
*/
	void SetNameFromKB() {
		string temp;
		cout << "\t���� �̸� �Է�: ";
		cin >> temp;
		name = temp;
	}

	/*
	@brief ==������ �����ε�
*	@return	name������ ������ true,�ƴϸ� false
	*/
	virtual  bool operator==(AllType* temp) {
		if (this->name == temp->GetName()) {
			return true;
		}
		return false;
	}

	/*
	@brief <������ �����ε�
*	@retur������ name������ ���� name���� ���� ũ�� true,�ƴϸ� false
	*/
	virtual bool operator<(AllType* temp) {
		if (this->name < temp->GetName()) {
			return true;
		}
		return false;
	}
	/*
	@brief >������ �����ε�
*	@return	���� name������ ������ name �������� ũ�� true,�ƴϸ� false
	*/
	virtual bool operator>( AllType* temp) {
		if (this->name > temp->GetName()) {
			return true;
		}
		return false;
	}
};


#endif
