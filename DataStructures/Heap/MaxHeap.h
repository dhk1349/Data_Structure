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
	//Ȧ���� ���ʳ����
	int parent = (bottom-1) / 2;
	if (root<=parent) {//�� �ö� �� �ִٴ� ��
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
	 //�ڽ� ��尡 ���� ���� ����.
	 if (right <= bottom) {//�ڽ� ��尡 �� �� �ȳ��� ���
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
	 else if (left<= bottom) {//�� �ʸ� �ִ� ���
		 if (Container[root]<Container[left]) {
			 T temp = Container[root];
			 Container[root] = Container[left];
			 Container[left] = temp;
			 ReHeapDown(left, bottom);
		 }
	 }
	 else if (left> bottom) {//�ڽĳ�尡 �� ���� ���
	 //�ƹ��͵� ����
	 }
 }

 template <typename T>
 void MaxHeap<T>::Delete(T item, bool &found, int parent) {
	 if (Container[parent] == item) {//ã��
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
	 if (Container[parent] == item) {//ã��
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