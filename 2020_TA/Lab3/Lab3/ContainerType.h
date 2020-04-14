#pragma once
#ifndef _CONTAINER_H
#define _CONTAINER_H
#include "_Library.h"

class ContainerType {
public:
	ContainerType() {}
	ContainerType(int id, string location) {
		
	}
	~ContainerType(){}

	void SetId(int id) { this->Id = id; }
	void SetLocation(string location) { this->Location = location; }
private:
	int Id;
	string Location;
	UnsortedList<string> Photolist;
	Stack<SimpleItemType*> SimpleItemList;

};

#endif
