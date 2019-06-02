#pragma once
#ifndef _MINHEAP_
#define _MINHEAP_
#include"BaseHeap.h"
#include<iostream>
using namespace std;

template<typename T>
class MinHeap:public BaseHeap<T> {
	using BaseHeap<T>::Container;
	using BaseHeap<T>::Length;

public:
	MinHeap() { BaseHeap<T>::Container = new T[10]; }
	~MinHeap() {}
	virtual void ReHeapUp(int root, int bottom);
	virtual void ReHeapDown(int root, int bottom);
	virtual void Delete(T item, bool &found, int parent);
	virtual void Retrieve(T& item, bool& found, int parent);
};

template<typename T>
void MinHeap<T>::ReHeapUp(int root, int bottom) {//Non-Recursively 
	int added = bottom;
	
	while (root<=(added-1)/2) {
		if (Container[(added - 1) / 2]>Container[added]) {
			T temp = Container[(added - 1) / 2];
			Container[(added - 1) / 2] = Container[added];
			Container[added] = temp;
			added = (added - 1) / 2;
		}
		else { break; }
	}
}

template<typename T>
void MinHeap<T>::ReHeapDown(int root, int bottom) {
	int left=root*2+1;
	int right=root*2+2;
	int smallchild;
	int added=root;
	while (left<=bottom) {// left<=bottom means it al least has space to look down
		//finding smaller leaf
		if (right<=bottom) {
			if (Container[left]>Container[right]) {
				smallchild = right;
			}
			else { smallchild = left; }
		}
		else { smallchild = left; }
		if (Container[smallchild]>Container[added]) {
			T temp = Container[smallchild];
			Container[smallchild] = Container[added];
			Container[added] = temp;
			added = smallchild;
			left = added * 2 + 1;
			right = added * 2 + 2;
		}
		else {break;}
	}
}

template<typename T>
void MinHeap<T>::Delete(T item, bool &found, int parent) {
	int location = parent;
	if (Container[location] == item) {//found item
		found = true;
		Container[location] = Container[Length - 1];
		ReHeapDown(location,Length-2);
	}
	else if (location*2+2<=Length-1) {//can  go down to  left and right node
		if (Container[location * 2 + 1] <= item) {
			Delete(item, found, location * 2 + 1);
		}
		if (Container[location * 2 + 2] <= item) {
			Delete(item, found, location *2+2);
		}
	}
	else if (location * 2 + 2 <= Length - 1) {//can only go down to left node
		if (Container[location * 2 + 1] <= item) {
			Delete(item, found, location * 2 + 1);
		}
	}
}

template<typename T>
void MinHeap<T>::Retrieve(T& item, bool& found, int parent) {
	int location = parent;
	if (Container[location] == item) {//found item
		found = true;
		item = Container[location];
		cout << "\t=====Item Found=====\n";
	}
	else if (parent * 2 + 2 < Length - 1) {//can  go down to  left and right node
		if (Container[parent * 2 + 1] <= item) {
			Retrieve(item, found, parent * 2 + 1);
		}
		if (Container[parent * 2 + 2] <= item) {
			Retrieve(item, found, parent * 2 + 2);
		}
	}
	else if (parent * 2 + 2 < Length - 1) {//can only go down to left node
		if (Container[parent * 2 + 1] <= item) {
			Retrieve(item, found, parent * 2 + 1);
		}
	}
}
#endif