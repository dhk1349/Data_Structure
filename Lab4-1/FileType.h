#pragma once
#ifndef _FileType_
#define _FileType_

#include<iostream>
#include<string>
using namespace std;

class FileType
{
private:
	string name = "";
	string path = "";
	string time = "";
	string access = "";
public:
	FileType() {
		name = "";
		path = "";
		time = "";
		 access= "";
	}
	~FileType() {}
	string GetName() {
		return name;
	}
	string Getpath() {
		return path;
	}
	string Getaccess() {
		return access;
	}
	void Setname(string in) {
		name = in;
	}
	void Setpath(string in) {
		path = in;
	}
	void Settime(string in) {
		time = in;
	}
	void Setaccess(string in) {
		access = in;
	}

	void SetNameFromKB() {
		string temp;
		cout << "\t파일 이름 입력: ";
		cin >> temp;
		name = temp;
	}
};


#endif