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

	/*	@brief 리스트를 초기화
*	@pre	없음
*	@post  length가 0이 된다.
*	@param 없음
*	@return	없음.
*/
	void MakeEmpty();

	/*	@brief 리스트가 차있는지 확인
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	꽉 차있으면 true, 아니면 false
*/
	bool IsFull();

	/*	@brief 리스트가 비어있는지 확인
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	비어있으면 true, 아니면 false
*/
	bool IsEmpty();

	/*	@brief 리스트의 길이 정보를 제공
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	length를 리턴
*/
	int GetLength() const;

	/*	@brief 리스트에서 아이템 검색
*	@pre	없음
*	@post  없음
*	@param 검색할 아이템의 이름을 받아서 input으로 받는다.
*	@return	찾으면 해당 아이템을 리턴, 아니면 nullptr리턴
*/
	T Get(T item);

	/*	@brief 리스트에 아이템 추가
*	@pre	없음
*	@post  리스트에 아이템이 추가 된다.
*	@param 추가할 아이템을 입력값으로 받는다.
*	@return	성공하면 1, 아니면 0을 리턴
*/
	int Add(T item);

	/*	@brief  리스트에서 아이템 삭제.
*	@pre	없음
*	@post  삭제할 아이템이 리스트에 있으면 삭제된다.
*	@param 삭제할 아이템의 이름을 가지는 입력값을 파라미터로 갖는다.
*	@return	성공시 1, 아니면 0을 리턴.
*/
	int Delete(T item);

	/*	@brief  리스트에서 아이템 대체.
*	@pre	없음
*	@post  대체할 아이템이 리스트에 있으면 해당 아이템이 지정한 아이템과 바뀜.
*	@param 대체할 아이템의 이름을 가지는 입력값을 파라미터로 갖는다.
*	@return	성공시 1, 아니면 0을 리턴.
*/
	int Replace(T item);

	/*	@brief  리스트의 원소를 하나씩 화면에 출력
*	@pre	없음
*	@post  없음
*	@param 없음
*	@return	없음.
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
void print_left(node<T>*temp) {//inorder 형식으로 출력하기 위한 하부 함수
	//왼쪽 아래 삼각형을 출력한다, leftnode를 input으로 받은 상태
	if (temp->left!=nullptr) {//왼쪽으로 더 갈 수 있는 상태
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
void print_right(const node<T>*temp) {//해당 노드부터 오른쪽 아래로 쭉 출력
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