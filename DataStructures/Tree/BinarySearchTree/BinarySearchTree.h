#pragma once	
#ifndef _BST_
#define _BST_
template<typename T>
struct node {
	T info;
	node* left;
	node* right;
};

template <typename T>
class BinarySearchTree {
private:
	node<T> *root;
public:
	/*
	constructor
	*/
	BinarySearchTree();

	/*
	destructor
	*/
	~BinarySearchTree();

	/*	@brief ����Ʈ�� �ʱ�ȭ
*	@pre	����
*	@post  length�� 0�� �ȴ�.
*	@param ����
*	@return	����.
*/
	void MakeEmpty();

	/*	@brief ����Ʈ�� ���ִ��� Ȯ��
*	@pre	����
*	@post  ����
*	@param ����
*	@return	�� �������� true, �ƴϸ� false
*/
	bool IsFull();

	/*	@brief ����Ʈ�� ����ִ��� Ȯ��
*	@pre	����
*	@post  ����
*	@param ����
*	@return	��������� true, �ƴϸ� false
*/
	bool IsEmpty();

	/*	@brief ����Ʈ�� ���� ������ ����
*	@pre	����
*	@post  ����
*	@param ����
*	@return	length�� ����
*/
	int GetLength() const;

	/*	@brief ����Ʈ���� ������ �˻�
*	@pre	����
*	@post  ����
*	@param �˻��� �������� �̸��� �޾Ƽ� input���� �޴´�.
*	@return	ã���� �ش� �������� ����, �ƴϸ� nullptr����
*/
	T Get(T item);

	/*	@brief ����Ʈ�� ������ �߰�
*	@pre	����
*	@post  ����Ʈ�� �������� �߰� �ȴ�.
*	@param �߰��� �������� �Է°����� �޴´�.
*	@return	�����ϸ� 1, �ƴϸ� 0�� ����
*/
	int Add(T item);

	/*	@brief  ����Ʈ���� ������ ����.
*	@pre	����
*	@post  ������ �������� ����Ʈ�� ������ �����ȴ�.
*	@param ������ �������� �̸��� ������ �Է°��� �Ķ���ͷ� ���´�.
*	@return	������ 1, �ƴϸ� 0�� ����.
*/
	int Delete(T item);

	/*	@brief  ����Ʈ���� ������ ��ü.
*	@pre	����
*	@post  ��ü�� �������� ����Ʈ�� ������ �ش� �������� ������ �����۰� �ٲ�.
*	@param ��ü�� �������� �̸��� ������ �Է°��� �Ķ���ͷ� ���´�.
*	@return	������ 1, �ƴϸ� 0�� ����.
*/
	int Replace(T item);

	/*	@brief  ����Ʈ�� ���Ҹ� �ϳ��� ȭ�鿡 ���
*	@pre	����
*	@post  ����
*	@param ����
*	@return	����.
*/
	void print();
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	MakeEmpty();
}

template<typename T>
void BinarySearchTree<T>::MakeEmpty() {
	//Erase(root);
}

template<typename T>
bool BinarySearchTree<T>::IsFull() {

	return  false;
}
template<typename T>
bool BinarySearchTree<T>::IsEmpty() {
	if (root->info == NULL)
		return true;
	return  false;
}
template<typename T>
int BinarySearchTree<T>::GetLength() const {
	int length=0;
	length = Counter(root);
	return length;
}

template<typename T>
T BinarySearchTree<T>::Get(T item) {
	bool found = false;
	search(root, item, found);
	if (found==true) {
		cout << "\tItem Found\n";
		cout <<"\t"<< item << endl;
		return item;
	}
	item = NULL;
	cout << "\tNo Such Item!\n";
	return item;
}

template<typename T>
int BinarySearchTree<T>::Add(T item) {
	insert(root, item);
	return 1;
}

template<typename T>
int BinarySearchTree<T>::Delete(T item) {
	
	return 1;
}

template<typename T>
int BinarySearchTree<T>::Replace(T item) {

	return 1;
}

template<typename T>
void BinarySearchTree<T>::print() {
	if (GetLength() != 0) {
		print_move_right(root);
	}
	else {
		cout << "\tTREE IS  EMPTY\n";
	}
}

/////////////////Global Function/////////////////
template<class T>
void insert(node<T>*&root, T Item) {
	if (root==nullptr) {
		root = new node<T>;
		root->left = nullptr;
		root->right = nullptr;
		root->info = Item;
		cout << "\titem inserted\n";
	}
	else if (root->info>Item) {
		insert(root->left, Item);
	}
	else if (root->info < Item) {
		insert(root->right, Item);
	}
}

template<class T>
void print_move_right(node<T>* root) {
	if (root->left != nullptr) {
		print_left(root->left);
	}
	cout << root->info << endl;
	if (root->right!=nullptr) {
		print_move_right(root->right);
	}
}

template<class T>
void print_left(node<T>*temp) {//inorder �������� ����ϱ� ���� �Ϻ� �Լ�
	//���� �Ʒ� �ﰢ���� ����Ѵ�, leftnode�� input���� ���� ����
	if (temp->left!=nullptr) {//�������� �� �� �� �ִ� ����
		print_left(temp->left);
		print_right(temp);
	}
	else if(temp->left ==nullptr){
		print_right(temp);
	}
	else{
		cout << "\t%%%%%Unexpected case error!%%%%%d\n";
	}
}

template<class T>
void print_right(const node<T>*temp) {//�ش� ������ ������ �Ʒ��� �� ���
	cout << temp->info << endl;
	if (temp->right != nullptr) {
		print_right(temp->right);
	}
}

template<class T>
void search(const node<T>* root, T& item, bool& found) {
	if (root->info == item) {
		found = true;
		item = root->info;
	}
	else if (root->info<item&&root->right!=nullptr) {
		search(root->right,item,found);
	}
	else if (root->info>item&&root->left!=nullptr) {
		search(root->right, item, found);
	}
}

template<class T>
int Counter(const node<T>*root) {
	if (root==nullptr) {
		return 0;
	}
	else {
		if (root->left==nullptr) {
			if (root->right == nullptr) { return 1; }
			else if (root->right != nullptr) { return 1 + Counter(root->right); }
		}
		else if (root->left != nullptr) {
			if (root->right == nullptr) { return 1+Counter(root->left); }
			else if (root->right != nullptr) { return 1 +Counter(root->left)+ Counter(root->right); }
		}
	}
}

template<class T>
void Erase(node<T>*root) {
	if (root->left==nullptr &&  root->right==nullptr) {
		cout <<"\t"<< root->info << " deleted!\n";
		root->info = NULL;
		delete root;
	}
	else if (root->left != nullptr &&  root->right == nullptr) {
		Erase(root->left);
		cout << "\t" << root->info << " deleted!\n";
		root->info = NULL;
		delete root;
	}
	else if (root->left == nullptr &&  root->right != nullptr) {
		Erase(root->right);
		cout << "\t" << root->info << " deleted!\n";
		root->info = NULL;
		delete root;
	}
	else if (root->left != nullptr &&  root->right != nullptr) {
		Erase(root->left);
		Erase(root->right);
		cout << "\t" << root->info << " deleted!\n";
		root->info = NULL;
		delete root;
	}
}
#endif