#include "ItemType.h"

int ItemType::GetType() { return this->type; }
string ItemType::GetDate() { return this->date; }
string ItemType::GetName() { return this->name; }
int ItemType::GetNum() { return this->num; }
string ItemType::GetPkey() { return this->pkey; }
string ItemType::GetData() { return this->pkey; }

int ItemType::SetRecordFromKB() {

	return 1;
}