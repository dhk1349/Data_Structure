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
	root->info = NULL;
	//Erase(root);
	root->left = nullptr;
	root->right = nullptr;
}

template<typename T>
bool BinarySearchTree<T>::IsFull() {
	cout << "함수 구현하세요: isfull\n";
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
	int length = 0;
	length = Counter(root);
	return length;
}

template<typename T>
T BinarySearchTree<T>::Get(T item) {
	bool found = false;
	search(root, item, found);
	if (found == true) {
		cout << "\tItem Found\n";
		cout << "\t" << item << endl;
		return item;
	}
	item = NULL;
	cout << "\tNo Such Item!\n";
	return item;
}

template<typename T>
int BinarySearchTree<T>::Add(T item) {
	int result=insert(root, item);
	return result;
}

template<typename T>
int BinarySearchTree<T>::Delete(T item) {
	int result=G_Delete(root, item);
	return result;
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

/*	@brief root 안에 Item을 삽입하는 재귀적  함수
*	@pre	없음
*	@post  트리에 아이템이 추가 된다.
*	@param 추가 당할 트리를 입력 받는다. 추가할 아이템을 입력값으로 받는다.
*	@return	없음
*/
template<class T>
int insert(node<T>*&root, T Item) {
	if (root == nullptr) {
		root = new node<T>;
		root->left = nullptr;
		root->right = nullptr;
		root->info = Item;
		cout << "\titem inserted\n";
		return 1;
	}
	else if (root->info->GetName() > Item->GetName()) {
		insert(root->left, Item);
	}
	else if (root->info->GetName() < Item->GetName()) {
		insert(root->right, Item);
	}
	else if (root->info->GetName() == Item->GetName()) {
			cout << "\tSame Item Already Exist!\n";
			return 0;
	}
}

/*	@brief root 안에 Item을 프린트하는 함수
*	@pre	root가 초기화 되어있다. 
*	@post  트리에 아이템이 추가 된다.
*	@param 추가 당할 트리를 입력 받는다. 추가할 아이템을 입력값으로 받는다.
*	@return	없음
*/
template<class T>
void print_move_right(node<T>* root) {
	if (root->left != nullptr) {
		print_left(root->left);
	}
	root->info->DisplayRecordOnScreen();
	//cout << root->info << endl;
	if (root->right != nullptr) {
		print_move_right(root->right);
	}
}

/*	@brief root 안에 Item을 Inorder순서로 화면에 출력한다.
*	@pre	없음
*	@post  트리에 아이템이 출력된다.
*	@param 추가 당할 트리를 입력 받는다. 추가할 아이템을 입력값으로 받는다.
*	@return	없음
*/
template<class T>
void print_left(node<T>*temp) {//inorder 형식으로 출력하기 위한 하부 함수
	//왼쪽 아래 삼각형을 출력한다, leftnode를 input으로 받은 상태
	if (temp->left != nullptr) {//왼쪽으로 더 갈 수 있는 상태
		print_left(temp->left);
		print_right(temp);
	}
	else if (temp->left == nullptr) {
		print_right(temp);
	}
	else {
		cout << "\t%%%%%Unexpected case error!%%%%%d\n";
	}
}

/*	@brief root 안에 Item을 Inorder순서로 화면에 출력한다.
*	@pre	없음
*	@post  트리에 아이템이 출력된다.
*	@param 추가 당할 트리를 입력 받는다. 추가할 아이템을 입력값으로 받는다.
*	@return	없음
*/
template<class T>
void print_right(const node<T>*temp) {//해당 노드부터 오른쪽 아래로 쭉 출력
	//cout << temp->info << endl;
	temp->info->DisplayRecordOnScreen();
	if (temp->right != nullptr) {
		print_right(temp->right);
	}
}

/*	@brief root 안에 Item을 이진 검색한다.
*	@pre	없음
*	@post  트리에 찾던 아이템이 있으면 item값에 넣어주고, found가 true로 바뀐다.
*	@param 검색할 트리는 root, 검색하고자 하는 아이템은 item, 검색 결과를 알기 위해 found변수는 false 상태로 입력
*	@return	없음
*/
template<class T>
void search(const node<T>* root, T& item, bool& found) {
	if (root->info == item) {
		found = true;
		item = root->info;
	}
	else if (root->info < item&&root->right != nullptr) {
		search(root->right, item, found);
	}
	else if (root->info > item&&root->left != nullptr) {
		search(root->right, item, found);
	}
}

/*	@brief root 안에 Item의  갯수를 세는 함수
*	@pre	없음
*	@post  없음
*	@param 원소 갯수를 알고 싶은 트리 root의 주소값
*	@return	Item의 갯수
*/
template<class T>
int Counter(const node<T>*root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		if (root->left == nullptr) {
			if (root->right == nullptr) { return 1; }
			else if (root->right != nullptr) { return 1 + Counter(root->right); }
		}
		else if (root->left != nullptr) {
			if (root->right == nullptr) { return 1 + Counter(root->left); }
			else if (root->right != nullptr) { return 1 + Counter(root->left) + Counter(root->right); }
		}
	}
}

/*	@brief root의 오른 쪽 노드 값을 root에 오게 하는 함수
*	@pre	없음
*	@post  root의 오른 쪽 노드 값이 root에 오게된다.
*	@param 트리형태인 root와 그 결과를 복사할  item
*	@return	없음
*/
template<class T>
void GetPredecessor(node<T> *root, T& item)
{
	while (root->right != NULL)			// root의 오른쪽이 존재할 경우
		root = root->right;				// root의 오른쪽 노드값이 root에 오도록 한다
	item = root->info;					// root 노드의 값을 item에 복사한다.
}

/*	@brief root의 뿌리 노드를 삭제
*	@pre	없음
*	@post  뿌리 노드가 삭제되고 재정렬된다.
*	@param root
*	@return	없음
*/
template<class T>
void DeleteNode(node<T> *&root)
{
	T item;
	node<T>* tempPtr;			// 임시 노드를 생성하고 root 노드를 임시 노드에 복사
	tempPtr = root;

	if (root->left == NULL)				// 왼쪽노드가 없을 때
	{
		root = root->right;				// 오른쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else if (root->right == NULL)		// 오른쪽노드가 없을 때
	{
		root = root->left;				// 왼쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// 중간에 있는 노드를 지우고 싶을 때 (left, right, child 노드 있을 경우)
		root->info = item;					// 지우려는 노드보다 작은 노드들 중에 가장 큰 노드를 찾음
		G_Delete(root->left, item);			// 그 값을 지울 노드에 복사를 해서 지운 것처럼 눈속임
	}
}

/*	@brief root 안에 Item을 삭제
*	@pre	없음
*	@post  삭제하고자하는 아이템이 있으면 트레에서 삭제된다.
*	@param 찾고자 하는 Item, 찾아지고자 하는 트리 root
*	@return	없음
*/
template<class T>
int G_Delete(node<T> *&root, T item)
{
	if (item->GetName() < root->info->GetName()&&root->left!=nullptr)				// root노드값보다 item노드가 작을 때
		G_Delete(root->left, item);		// 왼쪽노드로 가서 delete함수 호출
	else if (item->GetName() > root->info->GetName()&&root->right!=nullptr)			// root노드값보다 item노드가 클 때
		G_Delete(root->right, item);		// 오른쪽노드로 가서 delete함수 호출
	else if (item->GetName() == root->info->GetName()) {
		DeleteNode(root);				// 찾고자 하는 값이 일치하는 경우 deletenode 함수 호출
		return 1;
	}
	else {
		return 0;
	}
}

/*	@brief root 안에 Item을 Inorder순서로 화면에 출력한다.
*	@pre	없음
*	@post  트리에 아이템이 출력된다.
*	@param 추가 당할 트리를 입력 받는다. 추가할 아이템을 입력값으로 받는다.
*	@return	없음
*/
template<class T>
T Bring_left_right(node<T>*root) {//해당 루트 노드를 기준으로  왼쪽 가장 아래노드를 삭제하고 리턴해줌

}
template<class T>
T Bring_move_right(node<T>*root) {//해당 루트 노드를 기준으로  가장 오른쪽 노드로 이동
	///근데 변수를 포인터로 할거면 이렇게 하면 안될 듯.
	if (root->right != nullptr) {

	}
	else if (root->right == nullptr) {
		T temp = root->info;

		return temp;
	}
}
#endif