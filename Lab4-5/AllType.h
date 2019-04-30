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

};


#endif
