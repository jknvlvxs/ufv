#ifndef MYSET_H
#define MYSET_H

#include <algorithm>
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class Node {
	public:
		Node(const T &elem_, const char &code_) : elem(elem_), code(code_), left(NULL), right(NULL) {}
		Node<T> *left, *right;
		T elem;
		char code;
		Node<T> *parent; // NOTE verificar necessidade
};

template  <class T>
class MySet {
public:
	typedef MySetIterator<T> iterator;

	int size() const { return size_; }
	MySet() : size_(0), root(NULL) {}

	pair<iterator,bool> insert(const T&elem, const char&code);
	pair<iterator,bool> merge(const MySet &treeA, const MySet &treeB);
	iterator find(const T&elem); // NOTE verificar necessidade

	iterator end() {return iterator(NULL);}; 
	iterator begin() ;

	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	~MySet();

	bool operator>(const MySet &other);

	void imprimeBFS() const; // FIXME
	void imprimeDFS_pre() const; // FIXME
	void imprimeDFS_in() const; // FIXME
	void imprimeDFS_pos() const; // FIXME
private:
	Node<T> *root;
	int size_;

	pair<iterator,bool> insert(const T&elem, const char&code, Node<T> *&root, Node<T> *parent); 
	pair<iterator,bool> merge(const MySet &treeA, const MySet &treeB, Node<T> *&root);
	iterator find(const T&elem, Node<T> *root); // NOTE verificar necessidade

	void deleteNodes(Node<T> *root);
	Node<T> * copyNodes(const Node<T> *root, Node<T> *parent) const;

	void imprimeDFS_pre(const Node<T> *root) const; // FIXME
	void imprimeDFS_in(const Node<T> *root) const; // FIXME
	void imprimeDFS_pos(const Node<T> *root) const; // FIXME
};

template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(Node<T> *ptr_): ptr(ptr_) { }
	pair<T, char> operator*() {return make_pair(ptr->elem, ptr->code);}

	bool operator==(const MySetIterator &other) const {return ptr==other.ptr;}
	bool operator!=(const MySetIterator &other) const {return ptr!=other.ptr;}

	MySetIterator operator++();
	MySetIterator operator++(int);

	MySetIterator operator--();
	MySetIterator operator--(int);
private:
	Node<T> *ptr;
};


// SECTION Operadores de pré-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++() {
	if(ptr->right){
		ptr = ptr->right;
		while(ptr->left) ptr = ptr->left;
	} else {
		while(ptr->parent && ptr->parent->right==ptr) ptr = ptr->parent;
		ptr = ptr->parent; 
	}

	return *this;
}

template<class T>
MySetIterator<T>  MySetIterator<T>::operator--() {
	if(ptr->left) { 
		ptr = ptr->left;
		while(ptr->right) ptr=ptr->right;
	} else { 
		while(ptr->parent && ptr->parent->left==ptr) ptr = ptr->parent;  
		ptr = ptr->parent;	
	}
	return *this;
}

// SECTION Operadores de pós-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++(int) {
	MySetIterator<T> old(*this);
	++(*this);
	return old;
}

template<class T>
MySetIterator<T>  MySetIterator<T>::operator--(int) {
	MySetIterator<T> old(*this);
	--(*this);
	return old;
}

// SECTION Construtor de cópia
template  <class T>
MySet<T>::MySet(const MySet &other) {
	size_=0;
	root= NULL;
	*this = other;
}

// SECTION Operador de atribuição
template  <class T>
MySet<T> & MySet<T>::operator=(const MySet &other) {
	if(this==&other) return *this;
	deleteNodes(root);
	root = copyNodes(other.root,NULL);
	size_ = other.size_;
	return *this;
}

// SECTION Destrutor
template  <class T>
MySet<T>::~MySet() {
	deleteNodes(root);
}

template  <class T>
void MySet<T>::deleteNodes(Node<T> *root) {
	if(!root) return;
	deleteNodes(root->left);
	deleteNodes(root->right);
	delete root;
}

// SECTION Operador>
template  <class T>
bool MySet<T>::operator>(const MySet &other) {
	if(root->elem > other.root->elem) return false;
	else if(root->elem <  other.root->elem) return true;

	if(root->code > other.root->code) return false;
	else if(root->code <  other.root->code) return true;

	// if(!root->left) return false;

	return false;
}

// SECTION begin
template  <class T>
typename MySet<T>::iterator MySet<T>::begin() {
	if(!root) return end();
	Node<T> *ptr = root;
	// while(ptr->left) ptr = ptr->left;
	return iterator(ptr);
}

// SECTION copyNodes
template  <class T>
Node<T> * MySet<T>::copyNodes(const Node<T> *root,  Node<T> *parent) const {
	if(root==NULL) return NULL;

	Node<T> * ans = new Node<T>(root->elem, root->code);
	ans->parent = parent;
	ans->left = copyNodes(root->left,ans);
	ans->right = copyNodes(root->right,ans);
	return ans;
}

// SECTION insert
template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, const char&code, Node<T> * &root, Node<T> *parent) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	cout << "Insere: " << elem << " " << code << endl;
	if(!root) {
		root = new Node<T>(elem, code);
		root->parent = parent;
		size_++;
		return make_pair(iterator(root),true);
	} else {
		if(!root->left) return insert(elem, code, root->left, root);
		else if (!root->right) return insert(elem, code, root->right, root);
		else return make_pair(iterator(root),true);//igual..
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, const char&code) {
	return insert(elem, code, root, NULL);
}

// SECTION merge
template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::merge(const MySet &treeA, const MySet &treeB, Node<T> * &root) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if(!root) {
		int elem = treeA.root->elem + treeB.root->elem;
		root = new Node<T>(elem, '\0');
		// root->parent = parent;
		root->left = copyNodes(treeA.root, root);
		root->right = copyNodes(treeB.root, root);
		size_++;
		return make_pair(iterator(root),true);
	} else {
			// if(!root->left) return insert(elem, code, root->left, root);
			// else if (!root->right) return insert(elem, code, root->right, root);
		
		return make_pair(iterator(root),true);//igual..
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::merge(const MySet &treeA, const MySet &treeB) {
	return merge(treeA, treeB, root);
}

// SECTION find
template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem, Node<T> *root) {
	if(!root) {		
		return iterator(NULL);
	} else {
		if(root->elem > elem) return find(elem, root->left);
		else if (root->elem < elem) return find(elem, root->right);
		else return iterator(root);
	}
}

template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem) {
	return find(elem,root);
}

// SECTION Impressões
#include "MyQueue.h"

template  <class T>
void MySet<T>::imprimeBFS() const {
	MyQueue<Node<T>*> q;
	if(!root) return;
	q.push(root);

	while(q.size() != 0) {
		Node<T> * p = q.top();
		q.pop();
		cout << p->elem << p->code << " ";
		if(p->left) q.push(p->left);  
		if(p->right) q.push(p->right);
	}
}

template  <class T>
void MySet<T>::imprimeDFS_pre(const Node<T> *p) const {
	if(!p) return;
	cout << p->elem << p->code << " ";
	imprimeDFS_pre(p->left);
	imprimeDFS_pre(p->right);
} 

template  <class T>
void MySet<T>::imprimeDFS_in(const Node<T> *p) const {
	if(!p) return;	
	imprimeDFS_in(p->left);
	cout << p->elem << " ";
	imprimeDFS_in(p->right);
} 

template  <class T>
void MySet<T>::imprimeDFS_pos(const Node<T> *p) const {
	if(!p) return;
	imprimeDFS_pos(p->left);
	imprimeDFS_pos(p->right);
	cout << p->elem << " ";
} 

template  <class T>
void MySet<T>::imprimeDFS_pre() const {
	imprimeDFS_pre(root);
}

template  <class T>
void MySet<T>::imprimeDFS_in() const {
	imprimeDFS_in(root);
}

template  <class T>
void MySet<T>::imprimeDFS_pos() const {
	imprimeDFS_pos(root);
}

#endif