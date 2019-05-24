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
		return access;
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
*	@brief 해당 파일의 생성시간 설정한다.
*	@pre	없음
*	@post	해당 파일의 time변수가 설정된다.
*	@param stirng in이 time변수의 내용이 된다.
*	@return	없음
*/
	void Settime(string in) {
		time = in;
	}

	/**
*	@brief 해당 파일의 access 변수 값을 설정한다.
*	@pre	없음
*	@post	해당 파일의 path변수가 설정된다.
*	@param stirng in이 path변수의 내용이 된다.
*	@return	없음
*/
    virtual void Setaccess(string in){
		access = in;
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

	/**
*	@brief 해당 파일의 이름과 확장자를 화면에 충역.
*	@pre	없음
*	@post	해당 파일의 이름과 확장자가 화면에 출력
*	@param 없음
*	@return	없음
*/
	void DisplayRecordOnScreen() {
		cout << "\tName : "<<name<<endl;
		cout << "\tPath : " << path<<ext<<endl;
		cout << "\tEXT : "<<ext << endl;
		cout << "\tTime : " << time << endl << endl;;
	}





	
	/*
@brief ==연산자 오버로딩
*	@return	name변수가 같으면 true,아니면 false
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
	@brief <연산자 오버로딩
*	@retur오른쪽 name변수가 왼쪽 name변수 보다 크면 true,아니면 false
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
	@brief >연산자 오버로딩
*	@return	왼쪽 name변수가 오른쪽 name 변수보다 크면 true,아니면 false
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
