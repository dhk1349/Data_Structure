#pragma once
#ifndef cmd_h
#define cmd_h
#include "ul.h"
#include "ItemType.h"
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;	
class Cmd
{
public:
	Cmd();
	~Cmd();

	void run();
	//void addItem();
	//void printAll();
	//void makeEmptyList();
	//void getFromFile();
	//void putToFile();
	//bool quit();

private:
	ArrayList AL;
	ItemType elem;
};


#endif