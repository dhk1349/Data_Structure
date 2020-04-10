#include "SimpleItemType.h"

string SimpleItemType::GetPkey() { return this->p_key; }

int SimpleItemType::SetPkey(string input) { this->p_key = input; return 1; }
