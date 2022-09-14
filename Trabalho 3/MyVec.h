#ifndef MYVEC_H
#define MYVEC_H

#include <iostream>
#include <string>
#include <ostream>
#include <cassert>

template<class T>
class MyVec {
public:
	typedef T * iterator;

	// Construtores
	MyVec();
	MyVec(int n, const T&init=T());

	// Construtor de copia, operador de atribuição e destrutor
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);
	~MyVec() { destroy(); };

	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}

	void push_back(const T&);
	void pop_back() { assert(dataSize!=0); dataSize--; }
	
	void resize(int new_size);
	void clear();

	bool empty() const {return size() == 0;};
	int size() const {return dataSize;};

	iterator begin() {return data;}
	iterator end() {return data+dataSize;}

	const iterator begin() const {return data;}
	const iterator end() const {return data+dataSize;}
	
private:
	T *data;
	int dataSize;
	int capacity;

	void create();
	void destroy();
	void resizeCapacity(int new_capacity);
};

template<class T>
void MyVec<T>::push_back(const T&elem) {
	if(dataSize + 1 >= capacity) {
		if(capacity ==0) resizeCapacity(1);
		else resizeCapacity(capacity*2);
	}
	
	data[dataSize] = elem;
	dataSize++;
}

template<class T>
void MyVec<T>::clear() {
	destroy();
	create();
}

// SECTION Funções de redimensionamento
template<class T>
void MyVec<T>::resize(int new_size) {
	if(new_size >= capacity) resizeCapacity(new_size);
	for(int i=dataSize;i<new_size;i++) data[i] = T();
	dataSize = new_size;
}

template<class T>
void MyVec<T>::resizeCapacity(int new_capacity) {
	if(new_capacity <= capacity) return;

	T* oldData = data;
	data = new T[new_capacity];

	for(int i=0;i<dataSize;i++)
		data[i] = oldData[i];

	delete []oldData;

	capacity = new_capacity;
}

// SECTION Funções auxiliares
template<class T>
void MyVec<T>::create() {
	data = NULL;
	dataSize = capacity = 0;
}

template<class T>
void MyVec<T>::destroy() {
	delete []data;
	dataSize = capacity = 0;
}

// SECTION Construtores
template<class T>
MyVec<T>::MyVec() {
	create();
}

template<class T>
MyVec<T>::MyVec(int n, const T&init) {
	dataSize = capacity = n;
	data = new T[n];
	for(int i=0;i<n;i++) data[i] = init;
}

// SECTION Construtor de cópia
template<class T>
MyVec<T>::MyVec(const MyVec &other) {
	create(); //Crie um vetor vazio
	*this = other; 
}

// SECTION Operador de atribuição
template<class T>
MyVec<T> & MyVec<T>::operator=(const MyVec &other) {
	if(this==&other) return *this; 
	destroy();
	capacity = other.capacity;
	dataSize = other.dataSize;
	data = new T[capacity];
	for(int i=0; i<dataSize; i++) data[i] = other.data[i];
	return *this;
}

#endif