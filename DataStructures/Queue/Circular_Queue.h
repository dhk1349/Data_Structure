#pragma once
#ifndef _CIRCULARQUEUE_
#define _CIRCULARQUEUE_
#define CIRCULAR 8
#include<iostream>
using namespace std;

template<typename T>
class CircularQue {
public:
	CircularQue() {//circular queue�� ũ�⸦ 8�� ������ ������ ���� �� �ִ� ���� ������ 7�� �̴�.
		length = 0;
		head = 7;
		tail = 7;
	}
	~CircularQue() {
		EmptyQue();
	}
	void EmptyQue();
	int EnQue(T data);
	int DeQue(T& data);
	int next(int input);//�Է��� ���ڸ� ���� ĭ�� ���ڷ� ��ȯ���ش�.
	void print();
	
private:
	int head;
	int tail;
	int length;
	T circle[CIRCULAR];
};

template<typename  T>
void CircularQue<T>::EmptyQue() {
	head = tail;
	print();
}
	

template<typename  T>
int CircularQue<T>::EnQue(T data) {
	int temp = next(tail);
	if (temp==head) {
		cout << "\t@@@@@Full Queue@@@@@\n";
		print();
		return 0;
	}
	tail = temp;
	circle[tail] = data;
	//cout << "Head : " << head << " Tail : " << tail << endl;
	print();
	return 1;
}

template<typename  T>
int CircularQue<T>::DeQue(T& data) {
	if (head == tail) {
		cout << "\t@@@@@Empty Queue@@@@@\n";
		return 0;
	}
	head = next(head);
	data = circle[head];
	//cout << "Head : " << head << " Tail : " << tail << endl;
	print();
	return 1;
}

template<typename  T>
int CircularQue<T>::next(int input) {
	int csize = CIRCULAR;
	int result = input;
	result++;
	result %= csize;
	return result;
}

template<typename T>
void CircularQue<T>::print() { 
	int iter = head; //7
	int end = next(tail);//0
	iter = next(iter);
	cout << "\t=====Circular Queue====\n";
	//cout << iter << " ����" << end << "������ ����� �� " << endl;
	if (head==tail) {
		cout << "\tStack  IS Empty\n";
	}
	else {
		while (true) {
			cout << "\t" << iter << " ������ : ";
			cout << circle[iter] << endl;
			iter = next(iter);
			if (iter == end) {
				break;
			}
		}
	}
	cout << "\t======================\n";
}
#endif