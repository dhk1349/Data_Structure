#pragma once
#ifndef _CONTAINER_H
#define _CONTAINER_H
#include "_Library.h"

class ContainerType {
public:
	ContainerType() {}
	~ContainerType(){}




private:
	int Id;
	string Location;
	UnsortedList<string> Photolist;
	Stack<SimpleItemType> SimpleList;

};

#endif
