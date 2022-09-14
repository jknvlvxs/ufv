#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "MyVec.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue {
public:
	void push(const T&el);
	void pop();

	const T & top() const { return heap[ 0 ]; }
	int size() const { return heap.size(); }
private:
	void moveUp(int pos);
	void moveDown(int pos);

	MyVec<T> heap;
};

template<class T>
void MyQueue<T>::moveDown(int pos) {
	while(2*pos+1 < heap.size()) {
		int maiorFilho = 2*pos+1;
		if(2*pos+2 < heap.size() && heap[2*pos+2] > heap[maiorFilho]) maiorFilho = 2*pos+2;
		if(heap[pos] > heap[maiorFilho]) return; 
		else {
			swap(heap[pos],heap[maiorFilho]);
			pos = maiorFilho;
		}
	}
}

template<class T>
void MyQueue<T>::moveUp(int pos) { 
	while(pos>=0) {
		int pai = (pos-1)/2;
		if(heap[pos] > heap[pai]) {
			swap(heap[pos],heap[pai]);
			pos = pai;
		}
		else break;
	}	
}

template<class T>
void MyQueue<T>::push(const T&elem) {
	heap.push_back(elem);
	moveUp(heap.size()-1);
}

template<class T>
void MyQueue<T>::pop() {
	swap(heap[heap.size()-1],heap[0]);
	heap.resize(heap.size()-1);
	moveDown(0);
}

#endif