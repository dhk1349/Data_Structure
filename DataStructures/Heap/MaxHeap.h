#pragma once
#ifndef _MAXHEAP_
#define _MAXHEAP_
#include"BaseHeap.h"
#include<iostream>
using namespace std;

template<typename T>
class MaxHeap :public BaseHeap<T> {
	using BaseHeap<T>::Length;
	using BaseHeap<T>::Container;

public:
	MaxHeap() { BaseHeap<T>::Container = new T[10]; }
	virtual void ReHeapUp(int root, int bottom);
	virtual void ReHeapDown(int root, int bottom);
	virtual void Delete(T item, bool &found, int parent);
	virtual void Retrieve(T& item, bool& found, int parent);
};

template <typename T>
void MaxHeap<T>::ReHeapUp(int root, int bottom) {
	//홀수면 왼쪽노드임
	int parent = (bottom-1) / 2;
	if (root<=parent) {//더 올라갈 수 있다는 뜻
		if (Container[parent] < Container[bottom]) {
			T temp = Container[parent];
			Container[parent] = Container[bottom];
			Container[bottom] = temp;

			ReHeapUp(root, parent);
		}

	}
}

 template <typename T>
 void MaxHeap<T>::ReHeapDown(int root, int bottom) {
	 int left = root * 2 + 1;
	 int right = root * 2 + 2;
	 int Bigchild;
	 //자식 노드가 없을 수도 있음.
	 if (right <= bottom) {//자식 노드가 둘 다 안녕한 경우
		 if (Container[left] < Container[right]) 
			 Bigchild = right;
		 else
			 Bigchild = left;
		 if (Container[Bigchild] > Container[root]) {
			 T temp = Container[root];
			 Container[root] = Container[Bigchild];
			 BaseHeap<T>::Container[Bigchild] = temp;

			 ReHeapDown(Bigchild, bottom);
		 }
	 }
	 else if (left<= bottom) {//왼 쪽만 있는 경우
		 if (Container[root]<Container[left]) {
			 T temp = Container[root];
			 Container[root] = Container[left];
			 Container[left] = temp;
			 ReHeapDown(left, bottom);
		 }
	 }
	 else if (left> bottom) {//자식노드가 더 없는 경우
	 //아무것도 안함
	 }
 }

 template <typename T>
 void MaxHeap<T>::Delete(T item, bool &found, int parent) {
	 if (Container[parent] == item) {//찾음
		 found = true;
		 Container[parent] = Container[Length - 1];
		 ReHeapDown(parent, Length - 1);
	 }
	 if (Container[parent*2+1]>=item) {
		 Delete(item, found, parent * 2 + 1);
	 }
	 if (Container[parent * 2 + 1] >= item) {
		 Delete(item, found, parent);
	 }
 }

 template <typename T>
 void MaxHeap<T>::Retrieve(T& item, bool& found, int parent) {
	 if (Container[parent] == item) {//찾음
		 found = true;
		 item = Container[parent];
	 }
	 if (Container[parent * 2 + 1] >= item) {
		 Delete(item, found, parent * 2 + 1);
	 }
	 if (Container[parent * 2 + 1] >= item) {
		 Delete(item, found, parent);
	 }
 }
#endif