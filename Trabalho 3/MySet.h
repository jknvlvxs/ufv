#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H

#include <algorithm> //classe pair esta aqui...
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_, const char &code_) : elem(elem_), code(code_), left(NULL), right(NULL) {}
		Node<T> *left, *right;
		T elem;
		char code;
		Node<T> *parent; //agora cada nodo armazena seu pai // FIXME não é necessário parent
};

template  <class T>
class MySet {
public:
	typedef MySetIterator<T> iterator;

	int size() const;
	MySet() : size_(0), root(NULL) {}

	pair<iterator,bool> insert(const T&elem, const char&code); //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	pair<iterator,bool> merge(const MySet &treeA, const MySet &treeB);
	iterator find(const T&elem); //por simplicidade, nao vamos deixar implementar um find constante...

	iterator end() {return iterator(NULL);}; 
	iterator begin() ;

	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	bool operator>(const MySet &other);
	~MySet();

	void imprimeBFS() const;
	void imprimeDFS_pre() const;
	void imprimeDFS_in() const;
	void imprimeDFS_pos() const;
private:
	Node<T> *root;
	int size_;

	//funcoes auxiliares...
	pair<iterator,bool> insert(const T&elem, const char&code, Node<T> *&root, Node<T> *parent); 
	pair<iterator,bool> merge(const MySet &treeA, const MySet &treeB, Node<T> *&root);
	iterator find(const T&elem, Node<T> *root);

	void deleteNodes(Node<T> *root);
	Node<T> * copyNodes(const Node<T> *root, Node<T> *parent) const;

	void imprimeDFS_pre(const Node<T> *root) const;
	void imprimeDFS_in(const Node<T> *root) const;
	void imprimeDFS_pos(const Node<T> *root) const;
};

//por enquanto vamos desconsiderar os operadores ++ e -- em conjuntos...
//tais operadores serao "escondidos"
template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(Node<T> *ptr_): ptr(ptr_) { }
	T &operator*() {return ptr->elem;}
	char getCode() {return ptr->code;}

	bool operator==(const MySetIterator &other) const {return ptr==other.ptr;}
	bool operator!=(const MySetIterator &other) const {return ptr!=other.ptr;}

	MySetIterator operator++();
	MySetIterator operator++(int);

	MySetIterator operator--();
	MySetIterator operator--(int);
private:
	Node<T> *ptr;
};


//operador de pre-incremento
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

//operador de pre-decremento
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

//operador de pos-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++(int) {
	MySetIterator<T> old(*this);
	++(*this);
	return old;
}

//operador de pos-decremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator--(int) {
	MySetIterator<T> old(*this);
	--(*this);
	return old;
}

template  <class T>
typename MySet<T>::iterator MySet<T>::begin() {
	if(!root) return end();
	Node<T> *ptr = root;
	// while(ptr->left) ptr = ptr->left;
	return iterator(ptr);
}

template  <class T>
MySet<T>::MySet(const MySet &other) {
	size_=0;
	root= NULL;
	*this = other; //vamos usar o operador de atribuicao..
}

template  <class T>
void MySet<T>::deleteNodes(Node<T> *root) {
	if(!root) return;
	deleteNodes(root->left);
	deleteNodes(root->right);
	delete root;
}

template  <class T>
MySet<T>::~MySet() {
	deleteNodes(root);
}

template  <class T>
Node<T> * MySet<T>::copyNodes(const Node<T> *root,  Node<T> *parent) const {
	if(root==NULL) { //caso base
		return NULL;
	}
	Node<T> * ans = new Node<T>(root->elem, root->code);
	ans->parent = parent;
	ans->left = copyNodes(root->left,ans);
	ans->right = copyNodes(root->right,ans);
	return ans;
}

template  <class T>
MySet<T> & MySet<T>::operator=(const MySet &other) {
	if(this==&other) return *this; //testa auto-atribuicao...
	deleteNodes(root);
	root = copyNodes(other.root,NULL);
	size_ = other.size_;
	return *this;
}

template  <class T>
bool MySet<T>::operator>(const MySet &other) {
	if(root->elem > other.root->elem) return false;
	else if(root->elem <  other.root->elem) return true;

	// cout << root->code << ">" << other.root->code << ":" << (root->code > other.root->code) << endl;

	if(root->code > other.root->code) return false;
	else if(root->code <  other.root->code) return true;

	if(!root->left) return false;

	return false;
}

template  <class T>
int MySet<T>::size() const {
	return size_; //exercicio: como calcular o tamanho de forma dinamica? (i.e., sem armazenar o inteiro "size" na classe)
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