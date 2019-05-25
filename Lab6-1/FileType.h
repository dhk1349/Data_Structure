#pragma once
#ifndef _FileType_
#define _FileType_

#include<iostream>
#include<string>
#include "AllType.h"
using namespace std;

class FileType : public AllType{	
private:
	string time ;
	string access ;
public:
	/**
	*	default constructor.
	*/
	FileType() {
		name = "";
		path = "";
		time = "";
		 access= "";
		 ext = "";
	}

	/**
	*	destructor.
	*/
	~FileType() {}
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
		return access;
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
*	@brief �ش� ������ �����ð� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ time������ �����ȴ�.
*	@param stirng in�� time������ ������ �ȴ�.
*	@return	����
*/
	void Settime(string in) {
		time = in;
	}

	/**
*	@brief �ش� ������ access ���� ���� �����Ѵ�.
*	@pre	����
*	@post	�ش� ������ path������ �����ȴ�.
*	@param stirng in�� path������ ������ �ȴ�.
*	@return	����
*/
    virtual void Setaccess(string in){
		access = in;
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

	/**
*	@brief �ش� ������ �̸��� Ȯ���ڸ� ȭ�鿡 �濪.
*	@pre	����
*	@post	�ش� ������ �̸��� Ȯ���ڰ� ȭ�鿡 ���
*	@param ����
*	@return	����
*/
	void DisplayRecordOnScreen() {
		cout << "\tName : "<<name<<endl;
		cout << "\tPath : " << path<<ext<<endl;
		cout << "\tEXT : "<<ext << endl;
		cout << "\tTime : " << time << endl << endl;;
	}





	
	/*
@brief ==������ �����ε�
*	@return	name������ ������ true,�ƴϸ� false
	*/
	/*
	bool operator==(AllType* temp) {
		if (this->name == temp->GetName()) {
			return true;
		}
		return false;
	}
	*/
	/*
	@brief <������ �����ε�
*	@retur������ name������ ���� name���� ���� ũ�� true,�ƴϸ� false
	*/

	/*
	bool operator<(AllType* temp) {
		if (this->name < temp->GetName()) {
			return true;
		}
		return false;
	}
	*/
	/*
	@brief >������ �����ε�
*	@return	���� name������ ������ name �������� ũ�� true,�ƴϸ� false
	*/
	/*
	bool operator>(AllType* temp) {
		if (this->name > temp->GetName()) {
			return true;
		}
		return false;
	}
	*/
};


#endif
