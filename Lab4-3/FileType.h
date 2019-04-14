#pragma once
#ifndef _FileType_
#define _FileType_

#include<iostream>
#include<string>
using namespace std;

class FileType 
{
private:
	string name ;
	string path ;
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
	}

	/**
	*	destructor.
	*/
	~FileType() {}
	string GetName() {
		return name;
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
	string Getaccess() {
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
	void Setaccess(string in) {
		access = in;
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
};


#endif