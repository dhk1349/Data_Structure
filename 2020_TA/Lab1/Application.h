#pragma once
#ifndef _APP_H
#define _APP_H

#include "_Library.h"

class Application {
public:

	Application(){}

	~Application(){}

	int GetCommand();

	void Run();

	void AddMusic();

	void DeleteMusic();

	void RetrieveMusic();

	void ReplaceMusic();

	void DisplayAllMusic();

	void MakeEmpty();

	void ReadDataFromFile();

	void WriteDataToFile();

private:
	UnsortedArray Container;

};

#endif // !_APP_
