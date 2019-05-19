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
*	@brief 해당 파일의 이름 정보를 받는다.
*	@pre	없음
*	@post	해당 파일의 name이 리턴된다.
*	@return	name
*/
	 string GetName() {
		return name;
	}
	/**
*	@brief 해당 파일의 확장자 정보를 받는다.
*	@pre	없음
*	@post	해당 파일의 ext이 리턴된다.
*	@return	ext
*/
	string GetExt() {
		return ext;
	}
	/**
	*	@brief 해당 파일의 경로 정보를 받는다.
	*	@pre	없음
	*	@post	해당 파일의 path가 리턴된다.
	*	@return	path
	*/
	string Getpath() {
		return path;
	}

	/**
*	@brief ofstream으로 저장된 해당 텍스트 파일의 이름이 리턴된다.
*	@pre	없음
*	@post	ofstream으로 저장된 해당 txt파일이름을 반환해준다.
*	@return	access
*/
	virtual string Getaccess() {
		return "Getaccess의 잘못된 호출\n";
	}
	/**
*	@brief 해당 파일의 이름을 설정한다.
*	@pre	없음
*	@post	해당 파일의 name변수가 설정된다.
*	@param stirng in이 name변수의 내용이 된다.
*	@return	없음
*/
	void Setname(string in) {
		name = in;
	}

	virtual void Setaccess(string in) { cout << "\t이게 불리면 안된다.\n"; };
	/**
*	@brief 해당 파일의 경로를 설정한다.
*	@pre	없음
*	@post	해당 파일의 path변수가 설정된다.
*	@param stirng in이 path변수의 내용이 된다.
*	@return	없음
*/
	void Setpath(string in) {
		path = in;
	}


	/**
*	@brief 해당 파일의 ext 변수 값을 설정한다.
*	@pre	없음
*	@post	해당 파일의 ext변수가 설정된다.
*	@param stirng in이 ext변수의 내용이 된다.
*	@return	없음
*/
	void Setext(string in) {
		ext = in;
	}

	/*	@brief 해당 파일의 생성시간 설정한다.
*	@pre	없음
*	@post	해당 파일의 time변수가 설정된다.
*	@param stirng in이 time변수의 내용이 된다.
*	@return	없음
*/
	virtual void Settime(string in) {
		cout << "불리면 안되는 함수\n";
	}
	virtual void DisplayPathOnScreen() {}
	virtual void DisplayRecordOnScreen() {
		cout << "불리면 안되는 함수 display record on screen\n";
	}
	virtual void DisplayAll() { cout << "불리면 안되는 함수 displayallfoldername\n"; }
	virtual int AddFolder() { cout << "불리면 안되는 add folder"; return -1; }
	virtual int RetrieveFoldersByName() { cout << "불리면 안되는 retrievefoldersbyname"; return -1; }
	virtual int DeleteFiles() { cout << "불리면 안되는deletefiles"; return -1; }
	virtual int DeleteFolders() { cout << "불리면 안되는 deletefolders"; return -1; }
	virtual AllType* SearchFolder(AllType* temp) { cout << "불리면 안되는 search folder"; return temp; }
	virtual int Addtextfile() { cout << "불리면 안되는 addtextfile\n"; return -1; }
	virtual int Opentext() { cout << "불리면 안되는 opentext"; return -1; }
	virtual int ChangeSubfolderName() { cout << "불리면 안되는 changesubfoldername\n"; return -1; }
	virtual int ChangeFileName() { cout << "불리면 안되는 changefilename"; return -1; }
	virtual int DeleteFolders2(AllType *temp) { cout << "불리면 안되는 deletefoldets2"; return-2; }
	virtual int PasteFolder(AllType* indata) { "불리면 안되는 pastefolder"; return -1; }
	virtual int IncludeMusic() { cout << "불리면 안되는 includemusic"; return -1; }
	virtual AllType* SearchFile(AllType* temp) { cout << "불리면안되는 searchfile"; return temp; }
	virtual UnsortedList<AllType*> Getsublist() { cout << "불리면 안되는 getsublist";  
		UnsortedList<AllType*>temp;
		return temp;
	}
	/**
*	@brief 해당 파일의 이름을 키보드로 설정한다.
*	@pre	없음
*	@post	해당 파일의 name변수가 설정된다.
*	@param 없음
*	@return	없음
*/
	void SetNameFromKB() {
		string temp;
		cout << "\t파일 이름 입력: ";
		cin >> temp;
		name = temp;
	}

	/*
	@brief ==연산자 오버로딩
*	@return	name변수가 같으면 true,아니면 false
	*/
	virtual  bool operator==(AllType* temp) {
		if (this->name == temp->GetName()) {
			return true;
		}
		return false;
	}

	/*
	@brief <연산자 오버로딩
*	@retur오른쪽 name변수가 왼쪽 name변수 보다 크면 true,아니면 false
	*/
	virtual bool operator<(AllType* temp) {
		if (this->name < temp->GetName()) {
			return true;
		}
		return false;
	}
	/*
	@brief >연산자 오버로딩
*	@return	왼쪽 name변수가 오른쪽 name 변수보다 크면 true,아니면 false
	*/
	virtual bool operator>( AllType* temp) {
		if (this->name > temp->GetName()) {
			return true;
		}
		return false;
	}
};


#endif
