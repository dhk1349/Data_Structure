#pragma once
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include<ctime>
#include<iomanip>
#include <fstream>
#include <string>
#include<sstream>
#include"ArrayList.h"
using namespace std;
class ArrayList;
/**
*	Relation between two items.
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	item information class.
*/
class ItemType
{
public:
	/**
	*	default constructor.
	*/
	ItemType()
	{
		name = "";
		path = "";
		memory = 0;
		GenCreateTime();
		subfoldernum = 0;
		size = 0;
	}

	/**
	*	destructor.
	*/
	~ItemType()	{}

	int AddFolder();

	int DeleteFolders();

	int RetrieveFoldersByName();

	void DisplayAllFolderName();

	void  GenCreateTime() 
	{
		// Declaring argument for time() 
		time_t tt;

		// Declaring variable to store return value of 
		// localtime() 
		struct tm * ti;

		// Applying time() 
		time(&tt);

		// Using localtime() 
		ti = localtime(&tt);

		// stream output
		stringstream ss;
		ss << setw(4) << ti->tm_year + 1900 << setfill('0') << setw(2)
			<< ti->tm_mon + 1 << setfill('0') << setw(2) << ti->tm_mday << setfill('0') << setw(2) << ti->tm_hour << setfill('0') << setw(2)
			<< ti->tm_min << setfill('0') << setw(2) << ti->tm_sec << "\0";
		times=ss.str();  // copy the stream buffer to name 

	}

	/**
	*	@brief	Get student id.
	*	@pre	student id is set.
	*	@post	none.
	*	@return	student id.
	*/
	string GetName()
	{
		return name;
	}

	/**
	*	@brief	Get student name.
	*	@pre	student name is set.
	*	@post	none.
	*	@return	student name.
	*/
	string GetPath()
	{
		return path;
	}

	/**
	*	@brief	Get student address
	*	@pre	student address is set.
	*	@post	none.
	*	@return	student address.
	*/
	int GetMemory()
	{
		return memory;
	}

	/**
*	@brief	Get student address
*	@pre	student address is set.
*	@post	none.
*	@return	student address.
*/
	string Gettime()
	{
		return times;
	}

	/**
	*	@brief	Set student id.
	*	@pre	none.
	*	@post	student id is set.
	*	@param	inId	student id.
	*/
	void Setname(string inname)
	{
		name=inname;
	}
	
	/**
	*	@brief	Set student name.
	*	@pre	none.
	*	@post	student name is set.
	*	@param	inName	student name.
	*/
	void Setpath(string inpath)
	{
		path=inpath;
	}
	
	/**
	*	@brief	Set student address.
	*	@pre	none.
	*	@post	student address is set.
	*	@param	inAddress	student address.
	*/
	void Setmemory(int m )
	{
		memory=m;
	}
	
	/**
*	@brief	Set student address.
*	@pre	none.
*	@post	student address is set.
*	@param	inAddress	student address.
*/
	void Settime(string intime)
	{
		times=intime;
	}

	/**
	*	@brief	Set student record.
	*	@pre	none.
	*	@post	student record is set.
	*	@param	inId	student id.
	*	@param	inName	student name.
	*	@param	inAddress	student address.
	*/
	void SetRecord(string inname,string inpath, int inmemory)
	{
		Setname(inname);
		Setpath(inpath);
		Setmemory(inmemory);
	}

	/**
	*	@brief	Display student id on screen.
	*	@pre	student id is set.
	*	@post	student id is on screen.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName   : " << name << endl; 
	};

	/**
	*	@brief	Display student name on screen.
	*	@pre	student name is set.
	*	@post	student name is on screen.
	*/
	void DisplayPathOnScreen() 
	{
		cout << "\tPath : " << path << endl; 
	};

	/**
	*	@brief	Display student address on screen.
	*	@pre	student address is set.
	*	@post	student address is on screen.
	*/
	void DisplayMemoryOnScreen() 
	{
		cout << "\tMemory : " << memory << endl; 
	};

	/**
*	@brief	Display student address on screen.
*	@pre	student address is set.
*	@post	student address is on screen.
*/
	void DisplayTimeOnScreen()
	{
		cout << "\tTime : " << time << endl;
	};

	/**
*	@brief	Display student address on screen.
*	@pre	student address is set.
*	@post	student address is on screen.
*/
	//서브폴더를 보여주는 함수!! 추가 수정이 필요한 함수임.
	void DisplayListOnScreen()
	{
		//아마도 ArrayList에서 구현한 함수를 가지고 오는 것이 좋을 듯 하다.
		//cout << "\tTime : " << time << endl;
	};

	/**
	*	@brief	Display an student record on screen.
	*	@pre	student record is set.
	*	@post	student record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayPathOnScreen();
		DisplayMemoryOnScreen();
		DisplayTimeOnScreen();
		cout << endl;
		//	DisplayListOnScreen();
	};

	/**
	*	@brief	Set student id from keyboard.
	*	@pre	none.
	*	@post	student id is set.
	*/
	void SetNameFromKB();

	void SetRecordFromKB();
	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id, 
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const ItemType &data);

protected:
	string name;		
	string path;	
	int memory;
	string times;
	int subfoldernum;
	ArrayList *list;
	int size;
};

#endif	// _ITEMTYPE_H
