#pragma once
#ifndef _UNSORTED_
#define _UNSORTED_
#define MAX 10
template <typename T>
class UnsortedList {
private:
	int length;
	T info[10];
	int current_pos;
public:
	UnsortedList();
	~UnsortedList();
	void MakeEmpty();
	bool IsFull();
	int LengthIs() const;
	void RetrieveItem(T& item, bool & found);
	void InsertItem(T item);
	void DeleteItem(T item);
	void ResetList();
	void GetNextItem(T& item);
};

template<typename T>
UnsortedList<T>::UnsortedList() {
	length = 0;
	current_pos = -1;
}

template<typename T>
UnsortedList<T>::~UnsortedList() {
	MakeEmpty();
}

template<typename T>
void UnsortedList<T>::MakeEmpty() {
	length = 0;
}

template<typename T>
bool UnsortedList<T>::IsFull() {
	if (length >= MAX)
		return true;
	return  false;
}

template<typename T>
int UnsortedList<T>::LengthIs() const {
	return length;
}

template<typename T>
void UnsortedList<T>::RetrieveItem(T& item, bool & found) {
	found = false;
	bool moretofind = true;
	ResetList();
	while (!found&&moretofind) {
		if (item.name == info[current_pos].name) {
			found = true;
			item = info[current_pos];
		}
		if (current_pos+1>=length)
		{
			moretofind = false;
		}
		current_pos++;
	}
}

template<typename T>
void UnsortedList<T>::InsertItem(T item) {
	if (!IsFull) {//list is not full
		info[length] = item;
		length++;
	}
	else {//list is full
		cout << "\t =====list is full=====\n";
	}
}

template<typename T>
void UnsortedList<T>::DeleteItem(T item) {
	T temp;
	ResetList();
	while (true) {
		GetNextItem(temp);
		if (temp.name == item.name) {//deleting
			info[current_pos] = info[length - 1];
			length--;
			continue;
		}
		if (temp == NULL)
			break;
	}
}

template<typename T>
void UnsortedList<T>::ResetList() {
	current_pos = -1;
}

template<typename T>
void UnsortedList<T>::GetNextItem(T& item) {//current_pos를 하나 이동하고 그 아이템을 준다.
	if(current_pos+1<length){//
		current_pos++;
		item = info[current_pos];
	}
	else {
		item = NULL;
		cout << "Iterator at last element.";
	}
}

#endif // !_UNSORTED_
