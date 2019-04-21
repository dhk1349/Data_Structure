#pragma once
#ifndef _ALLTYPE_H
#define _ALLTYPE_H
#include<iostream>
#include <string>
using namespace std;

class AllType {
private:
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

};


#endif
