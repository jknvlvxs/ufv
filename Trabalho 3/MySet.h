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
		Node<T> *parent;
};

template  <class T>
class MySet {
public:
	typedef MySetIterator<T> iterator;

	MySet() : root(NULL) {}
	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	~MySet();

	pair<iterator,bool> insert(const T&elem, const char&code);
	iterator merge(const MySet &treeA, const MySet &treeB);

	iterator end() {return iterator(NULL);}; 
	iterator begin() ;

	bool operator>(const MySet &other);

	void createCodification(); // TODO
	string getCodification(const char&caractere) const { return codification[caractere]; };
	void getCharacter(MyVec<char> &out, const MyVec<bool> &in) const; // TODO

private:
	Node<T> *root;
	string codification[256];

	pair<iterator,bool> insert(const T&elem, const char&code, Node<T> *&root, Node<T> *parent); 

	void deleteNodes(Node<T> *root);
	Node<T> * copyNodes(const Node<T> *root, Node<T> *parent) const;

	void createCodification(const Node<T> *root); // TODO
	void getCharacter(MyVec<char> &out, const MyVec<bool> &in, const Node<T> *root) const; // TODO

};

template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(Node<T> *ptr_): ptr(ptr_) { }
	pair<T, char> operator*() {return make_pair(ptr->elem, ptr->code);}

	bool operator==(const MySetIterator &other) const {return ptr==other.ptr;}
	bool operator!=(const MySetIterator &other) const {return ptr!=other.ptr;}
private:
	Node<T> *ptr;
};

// SECTION Construtor de cópia, operador de atribuição e destrutor
template  <class T>
MySet<T>::MySet(const MySet &other) {
	root= NULL;
	*this = other;
}

template  <class T>
MySet<T> & MySet<T>::operator=(const MySet &other) {
	if(this==&other) return *this;
	deleteNodes(root);
	root = copyNodes(other.root, NULL);
	return *this;
}

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

// SECTION operador de ordenação
template  <class T>
bool MySet<T>::operator>(const MySet &other) {
	if(root->elem > other.root->elem) return false;
	else if(root->elem <  other.root->elem) return true;

	if(root->code > other.root->code) return false;
	else if(root->code <  other.root->code) return true;

	return false;
}

// SECTION begin
template  <class T>
typename MySet<T>::iterator MySet<T>::begin() {
	if(!root) return end();
	Node<T> *ptr = root;
	return iterator(ptr);
}

// SECTION função que cria uma cópia dos nodos
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
	root = new Node<T>(elem, code);
	root->parent = parent;
	return make_pair(iterator(root),true);
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, const char&code) {
	return insert(elem, code, root, NULL);
}

// SECTION merge
template  <class T>
typename MySet<T>::iterator MySet<T>::merge(const MySet &treeA, const MySet &treeB) {
	root = new Node<T>((treeA.root->elem + treeB.root->elem), '\0');
	root->left = copyNodes(treeA.root, root);
	root->right = copyNodes(treeB.root, root);
	return iterator(root);
}

// SECTION Gerar codificação variável
template <class T>
void MySet<T>::createCodification() {
	createCodification(root);
}

template <class T>
void MySet<T>::createCodification(const Node<T> *p) {
	if(!p) return;

	if(p->left) createCodification(p->left);
	if(p->right) createCodification(p->right);
	
	if(p->code != '\0') {
		char pos = p->code;
		string code;

		/* para caso de arquivo com 1 caractere */
		if(p == root) code.push_back('0'); 

		while(p != root){
			// caso seja o filho da esquerda, adiciona 0 na codificação
			if(p->parent && p->parent->left == p){
				code.push_back('0');
				p = p->parent;
			}
			// caso seja o filho da direita, adiciona 1 na codificação
			if(p->parent && p->parent->right == p){
				code.push_back('1');
				p = p->parent;
			}
		}

		/* inverte a codificação */
		int n = code.length();
		for (int i = 0; i < n / 2; i++)
			swap(code[i], code[n - i - 1]);

		/* adiciona a codificação na posicao referente ao byte */
		codification[pos] = code;
	}
}

// SECTION Buscar caracter
template <class T>
void MySet<T>::getCharacter(MyVec<char> &out, const MyVec<bool> &in) const {
	return getCharacter(out, in, root);
}

template <class T>
void MySet<T>::getCharacter(MyVec<char> &out, const MyVec<bool> &in, const Node<T> *root) const {
	for(MyVec<bool>::iterator it = in.begin(); it != in.end(); it++){
		/* caso o bit seja 1, anda para a direita */
		if(*it == 1 && root->right) root = root->right;
		/* caso o bit seja 0, anda para a esquerda */
		if(*it == 0 && root->left) root = root->left;

		/* ao chegar em um caractere, adiciona na saída e retorna a posição inicial */
		if(root->code != '\0') {
			out.push_back(root->code);
			while(root->parent) root = root->parent;
		};
	}
};

#endif