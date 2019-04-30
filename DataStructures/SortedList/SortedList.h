#pragma once
#ifndef _SORTED_
#define _SORTED_
#define MAX 10

//Operator overloading for T is needed(>,<,==)
template <typename T>
class SortedList {
private:
	int length;
	T info[MAX];
	int current_pos;
public:
	SortedList();
	~SortedList();
	void MakeEmpty();
	bool IsFull();
	int LengthIs() const;
	void RetrieveItem(T& item, bool & found);
	void InsertItem(T item);
	void DeleteItem(T item);
	void ResetList();
	void GetNextItem(T& item);
	void print() {
		for (int i = 0; i < length; i++) {
			cout << i + 1 << " th data\n";
			info[i].printdata();
		}
	}
};

template<typename T>
SortedList<T>::SortedList() {
	length = 0;
	current_pos = -1;
}

template<typename T>
SortedList<T>::~SortedList() {
	MakeEmpty();
}

template<typename T>
void SortedList<T>::MakeEmpty() {
	length = 0;
}

template<typename T>
bool SortedList<T>::IsFull() {
	if (length >= MAX)
		return true;
	return  false;
}

template<typename T>
int SortedList<T>::LengthIs() const {
	return length;
}

template<typename T>
void SortedList<T>::RetrieveItem(T& item, bool & found) {
	//BinarySearch
	found = false;

}

template<typename T>
void SortedList<T>::InsertItem(T item) {
	int location;
	if (!IsFull()) {
		ResetList();
		T temp;
		while (true) {
			GetNextItem(temp);
			if (temp > item) {
				location = current_pos;
				break;
			}
			else if (temp == NULL) {
				location = current_pos;
				break;
			}
		}
	}
	if (length>=1) {
		for (int i = length; i > location; i--) {
			info[i] = info[i - 1];
		}
	}
	length++;
	info[location] = item;
	cout << "현재 길이는 " << length<<endl;
}

template<typename T>
void SortedList<T>::DeleteItem(T item) {
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
void SortedList<T>::ResetList() {
	current_pos = -1;
}

template<typename T>
void SortedList<T>::GetNextItem(T& item) {//current_pos를 하나 이동하고 그 아이템을 준다.
	if (current_pos + 1 <= length) {//
		current_pos++;
		item = info[current_pos];
	}
	else {
		item = NULL;
	}
}

#endif // !_SORTED_
