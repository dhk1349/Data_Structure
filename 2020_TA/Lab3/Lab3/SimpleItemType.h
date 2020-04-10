#pragma once
#pragma once
#ifndef _SIMPLE_H
#include "_Library.h"
class SimpleItemType {
public:
	SimpleItemType() {}
	~SimpleItemType(){}
	SimpleItemType(string input){
		this->SetPkey(input);
	}
	int SetPkey(string input);
	string GetPkey();
private:
	string p_key;
};

#endif // !_SIMPLE_H
