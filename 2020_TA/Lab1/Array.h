#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H
#define MAXSIZE 100

#include "_Library.h"

class UnsortedArray {
public:



private:
	ItemType box[MAXSIZE];
	int cur_pointer;
	int length;
};


#endif // !_ARRAY_H
