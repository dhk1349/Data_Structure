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
	root->info = NULL;
	//Erase(root);
	root->left = nullptr;
	root->right = nullptr;
}

template<typename T>
bool BinarySearchTree<T>::IsFull() {
	cout << "�Լ� �����ϼ���: isfull\n";
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

/*	@brief root �ȿ� Item�� �����ϴ� �����  �Լ�
*	@pre	����
*	@post  Ʈ���� �������� �߰� �ȴ�.
*	@param �߰� ���� Ʈ���� �Է� �޴´�. �߰��� �������� �Է°����� �޴´�.
*	@return	����
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

/*	@brief root �ȿ� Item�� ����Ʈ�ϴ� �Լ�
*	@pre	root�� �ʱ�ȭ �Ǿ��ִ�. 
*	@post  Ʈ���� �������� �߰� �ȴ�.
*	@param �߰� ���� Ʈ���� �Է� �޴´�. �߰��� �������� �Է°����� �޴´�.
*	@return	����
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

/*	@brief root �ȿ� Item�� Inorder������ ȭ�鿡 ����Ѵ�.
*	@pre	����
*	@post  Ʈ���� �������� ��µȴ�.
*	@param �߰� ���� Ʈ���� �Է� �޴´�. �߰��� �������� �Է°����� �޴´�.
*	@return	����
*/
template<class T>
void print_left(node<T>*temp) {//inorder �������� ����ϱ� ���� �Ϻ� �Լ�
	//���� �Ʒ� �ﰢ���� ����Ѵ�, leftnode�� input���� ���� ����
	if (temp->left != nullptr) {//�������� �� �� �� �ִ� ����
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

/*	@brief root �ȿ� Item�� Inorder������ ȭ�鿡 ����Ѵ�.
*	@pre	����
*	@post  Ʈ���� �������� ��µȴ�.
*	@param �߰� ���� Ʈ���� �Է� �޴´�. �߰��� �������� �Է°����� �޴´�.
*	@return	����
*/
template<class T>
void print_right(const node<T>*temp) {//�ش� ������ ������ �Ʒ��� �� ���
	//cout << temp->info << endl;
	temp->info->DisplayRecordOnScreen();
	if (temp->right != nullptr) {
		print_right(temp->right);
	}
}

/*	@brief root �ȿ� Item�� ���� �˻��Ѵ�.
*	@pre	����
*	@post  Ʈ���� ã�� �������� ������ item���� �־��ְ�, found�� true�� �ٲ��.
*	@param �˻��� Ʈ���� root, �˻��ϰ��� �ϴ� �������� item, �˻� ����� �˱� ���� found������ false ���·� �Է�
*	@return	����
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

/*	@brief root �ȿ� Item��  ������ ���� �Լ�
*	@pre	����
*	@post  ����
*	@param ���� ������ �˰� ���� Ʈ�� root�� �ּҰ�
*	@return	Item�� ����
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

/*	@brief root�� ���� �� ��� ���� root�� ���� �ϴ� �Լ�
*	@pre	����
*	@post  root�� ���� �� ��� ���� root�� ���Եȴ�.
*	@param Ʈ�������� root�� �� ����� ������  item
*	@return	����
*/
template<class T>
void GetPredecessor(node<T> *root, T& item)
{
	while (root->right != NULL)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->info;					// root ����� ���� item�� �����Ѵ�.
}

/*	@brief root�� �Ѹ� ��带 ����
*	@pre	����
*	@post  �Ѹ� ��尡 �����ǰ� �����ĵȴ�.
*	@param root
*	@return	����
*/
template<class T>
void DeleteNode(node<T> *&root)
{
	T item;
	node<T>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == NULL)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == NULL)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->info = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		G_Delete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

/*	@brief root �ȿ� Item�� ����
*	@pre	����
*	@post  �����ϰ����ϴ� �������� ������ Ʈ������ �����ȴ�.
*	@param ã���� �ϴ� Item, ã�������� �ϴ� Ʈ�� root
*	@return	����
*/
template<class T>
int G_Delete(node<T> *&root, T item)
{
	if (item->GetName() < root->info->GetName()&&root->left!=nullptr)				// root��尪���� item��尡 ���� ��
		G_Delete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item->GetName() > root->info->GetName()&&root->right!=nullptr)			// root��尪���� item��尡 Ŭ ��
		G_Delete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else if (item->GetName() == root->info->GetName()) {
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
		return 1;
	}
	else {
		return 0;
	}
}

/*	@brief root �ȿ� Item�� Inorder������ ȭ�鿡 ����Ѵ�.
*	@pre	����
*	@post  Ʈ���� �������� ��µȴ�.
*	@param �߰� ���� Ʈ���� �Է� �޴´�. �߰��� �������� �Է°����� �޴´�.
*	@return	����
*/
template<class T>
T Bring_left_right(node<T>*root) {//�ش� ��Ʈ ��带 ��������  ���� ���� �Ʒ���带 �����ϰ� ��������

}
template<class T>
T Bring_move_right(node<T>*root) {//�ش� ��Ʈ ��带 ��������  ���� ������ ���� �̵�
	///�ٵ� ������ �����ͷ� �ҰŸ� �̷��� �ϸ� �ȵ� ��.
	if (root->right != nullptr) {

	}
	else if (root->right == nullptr) {
		T temp = root->info;

		return temp;
	}
}
#endif