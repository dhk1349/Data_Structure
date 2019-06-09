#pragma once
#include <iostream>
#include <fstream>
using namespace std;
/**
*	AVL트리노드
*/
template <typename T>
struct TreeNode
{
	T data;
	TreeNode* left;
	TreeNode* right;
};
/**
*	AVL트리
*/
template<typename T>
class AVLTree
{
public:
	/**
	*	생성자,변수 초기화
	*/
	AVLTree();
	/**
	*	소멸자,메모리 제거
	*/
	~AVLTree();
	/**
	*	@bried 현재 노드의 길이(갯수를 반환)
	*	@pre 없음
	*	@post 없음
	*	@param 없음
	*	@return 현재 노드의 길이(갯수를 반환)
	*/
	int GetLength();
	/**
	*	@brief 비어있는지 확인
	*	@pre 없음
	*	@post 없음
	*	@param 없음
	*	@return 비어있으면 true아니면 false
	*/
	bool IsEmpty();
	/**
	*	@brief 전체 트리삭제
	*	@pre 없음
	*	@post 전체 트리삭제
	*	@param 없음
	*	@return 없음
	*/
	void MakeEmpty(TreeNode<T>*& Node);
	/**
	*	@brief 파라미터로 받은 데이터를 트리에 추가
	*	@pre 없음
	*	@post 파라미터로 받은 데이터를 트리에 추가
	*	@param 추가하고자 하는 데이터
	*	@return 성공하면 1
	*/
	int Add(T data);
	/**
	*	@brief 파라미터로 받은 데이터를 트리에서 삭제
	*	@pre 없음
	*	@post 파라미터로 받은 데이터를 트리에서 삭제
	*	@param 삭제하고자 하는 데이터
	*	@return 성공하면 1
	*/
	int Delete(T data);
	/**
	*	@brief 데이터를 파라미터로 받아 일치하는 데이터가 있는지 확인 후 데이터를 복사해줌
	*	@pre 없음
	*	@post 찾으면 파라미터에 정보 복사
	*	@param 찾고자하는 데이터
	*	@return 성공하면 true
	*/
	bool Find(T data);
	/**
	*	@brief 데이터를 파라미터로 받아 일치하는 데이터가 있는지  장르 이름 비교를 통해 확인 후 데이터의 주소값을 리턴해줌
	*	@pre 없음
	*	@post 없음
	*	@param 추가하고자 하는 데이터의 포인터
	*	@return 성공하면 찾고자하는 데이터의 포인터가 리턴
	*/
	T* Get(T* data);

	/**
	*	데이터를 파라미터로 받아 일치하는 데이터가 있는지  장르 이름 비교를 통해 확인 후 데이터의 주소값을 리턴해줌
	*/
	T GetByPoint(T data);
	/**
	*	데이터를 파라미터로 받아 일치하는 데이터가 있는지 ID 비교를 통해 확인 후 데이터의 주소값을 리턴해줌
	*/
	T* GetByID(T& data);
	/**
	*	데이터를 파라미터로 받아 일치하는 데이터가 있는지 확인 후 데이터를 수정해줌
	*/
	void Replace(T data);
	/**
	*	루트를 리턴
	*/
	TreeNode<T>* getroot();
	/**
	*	@brief	Tree의 node를 스크린에 출력한다.
	*	@pre	none
	*	@post	스크린에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	void print();

	/**
	*	@brief	Tree의 node를 스크린에 출력한다.(변수가 포인터 형식인 경우)
	*	@pre	none
	*	@post	스크린에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	//void pointprint();
	/**
	*	@brief	Tree의 node를 파일에 저장한다.
	*	@pre	none
	*	@post	파일에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	void SaveTree(ofstream& fout);

private:
	/**
	*	맥스함수 두 파라미터중 큰것을 리턴함
	*/
	int Max(int i, int j);
	/**
	*	노드의 높이를 얻음, 파라미터로 받은 노드의 최대 높이 (제일 깊숙히 있는 리프노드와 의 높이)
	*/
	int getHeight(TreeNode<T>* Node);
	/**
	*	균형이 맞춰져있는지 확인함, 파라미터로 받은 노드의 왼쪽 트리와 오른쪽트리의 높이 차이를 반환함
	*/
	int getBalance(TreeNode<T>* Node);

	/**
	*	트리 전부 출력
	*/
	void PrintInOrderTraversal(TreeNode<T>* root);
	/**
	*	트리 전부 출력(데이터가 포인터인 경우)
	*/
	//void PointPrintInOrderTraversal(TreeNode<T>* root);

	/**
	*	트리 전부 저장
	*/
	void SaveInOrderTraversal(TreeNode<T>* root, ofstream& out);
	/**
	*	오른쪽으로 싱글 로테이션을 함
	*/
	TreeNode<T>* Rotate_LL(TreeNode<T>* parent);
	/**
	*	왼쪽으로 싱글 로테이션을 함
	*/
	TreeNode<T>* Rotate_RR(TreeNode<T>* parent);
	/**
	*	왼쪽 오른쪽으로 더블로테이션을 함
	*/
	TreeNode<T>* Rotate_LR(TreeNode<T>* parent);
	/**
	*	오른쪽 왼쪽으로 더블 로테이션을 함
	*/
	TreeNode<T>* Rotate_RL(TreeNode<T>* parent);

	/**
	*	에드함수를 위한 재귀함수
	*/
	TreeNode<T>* RecursiveInsert(TreeNode<T>* Node, T data);
	/**
	*	딜리트를 위한 재귀함수
	*/
	TreeNode<T>* Recursivedelete(TreeNode<T>* Node, T data);
	/**
	*	노드기준 오른쪽과 왼쪽의 균형을 맞춰짐
	*/
	TreeNode<T>* MakeBalance(TreeNode<T>* Node);

	TreeNode<T>* root; // 진짜루트
	int length; // 길이 (갯수)
};
template<typename T>
AVLTree<T>::AVLTree()
{
	root = nullptr; //처음에 루트는 눌로 초기화함
	this->length = 0; // 길이(갯수) 0으로 초기화
}
template<typename T>
AVLTree<T>::~AVLTree()
{
	MakeEmpty(root); // 파라미터에 루트를 주어서 트리를 다 삭제함
}
template<typename T>
int AVLTree<T>::GetLength()
{
	return this->length;
}
template<typename T>
bool AVLTree<T>::IsEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}
template<typename T>
void AVLTree<T>::MakeEmpty(TreeNode<T>*& Node)
{
	if (Node == nullptr) // 비어있다면
		return;
	else
	{
		MakeEmpty(Node->left); // 왼쪽으로 재귀함수실행
		MakeEmpty(Node->right); // 오른쪽으로 재귀함수실행
		delete Node; // 노드를 지워줌 재귀함수이므로 리프노드부터 지워진다.
		Node = nullptr; // 포인터의 래퍼런스를 눌로 만듬
	}
}
template<typename T>
int AVLTree<T>::Add(T data)
{
	if (root == nullptr) // 트리가 비어있다면
	{
		// 노드생성
		TreeNode<T>* temp = new TreeNode<T>;
		temp->data = data;
		temp->left = nullptr;
		temp->right = nullptr;
		root = temp; // 루트로 연결
		length++; // 길이추가
	}
	else
	{
		// 트리가 비어있지않다면 RecursiveInsert에 루트와 데이터를 넣어주고 반환값을 루트로 바꿔줌
		root = RecursiveInsert(root, data);
	}
	return 1;
}
template<typename T>
int AVLTree<T>::Delete(T data)
{
	// 루트와 데이터를 파라미터로 넣어주고 결과값을 루트로 연결
	root = Recursivedelete(root, data);
	length--; // 길이감소
	return 1;
}
template<typename T>
bool AVLTree<T>::Find(T data)
{
	TreeNode<T>* temp;// 임시변수
	temp = root;
	while (temp != nullptr)
	{
		if (temp->data > data) // 현재 노드의 데이터가 찾을 데이터보다 클 경우
		{
			temp = temp->left; // 왼쪽으로감
		}
		else if (temp->data < data) // 현재 노드의 데이터가 찾을 데이터보다 작을 경우
		{
			temp = temp->right; // 오른쪽으로감
		}
		else // 찾았다면
		{
			//data = temp->data; // 노드의 데이터를 복사
			return true; // 결과값참
		}
	}
	return false; // 못찾았을경우 펄스
}
template<typename T>
T* AVLTree<T>::Get(T* data)
{
	TreeNode<T>* temp;// 임시변수
	temp = root;
	while (temp != nullptr)
	{
		if (temp->data > *data) // 현재 노드의 데이터가 찾을 데이터보다 클 경우
		{
			temp = temp->left; // 왼쪽으로감
		}
		else if (temp->data < *data) // 현재 노드의 데이터가 찾을 데이터보다 작을 경우
		{
			temp = temp->right; // 오른쪽으로감
		}
		else // 찾았다면
		{
			data = &temp->data; // 노드의 데이터를 복사
			return data; // 결과값참
		}
	}
	return nullptr; // 못찾았을경우 펄스
}

template<typename T>
T AVLTree<T>::GetByPoint(T data)
{
	TreeNode<T>* temp;// 임시변수
	temp = root;
	while (temp != nullptr)
	{
		if (*temp->data > * data) // 현재 노드의 데이터가 찾을 데이터보다 클 경우
		{
			temp = temp->left; // 왼쪽으로감
		}
		else if (*temp->data < *data) // 현재 노드의 데이터가 찾을 데이터보다 작을 경우
		{
			temp = temp->right; // 오른쪽으로감
		}
		else // 찾았다면
		{
			data = temp->data; // 노드의 데이터를 복사
			return data; // 결과값참
		}
	}
	return nullptr; // 못찾았을경우 펄스
}

template<typename T>
T* AVLTree<T>::GetByID(T& data)
{
	TreeNode<T>* temp;// 임시변수
	temp = root;
	while (temp != nullptr)
	{
		if (temp->data >= data) // 현재 노드의 데이터가 찾을 데이터보다 클 경우
		{
			temp = temp->left; // 왼쪽으로감
		}
		else if (temp->data <= data) // 현재 노드의 데이터가 찾을 데이터보다 작을 경우
		{
			temp = temp->right; // 오른쪽으로감
		}
		else // 찾았다면
		{
			data = temp->data; // 노드의 데이터를 복사
			return &temp->data; // 결과값참
		}
	}
	return false; // 못찾았을경우 펄스
}

template<typename T>
void AVLTree<T>::Replace(T data)
{
	TreeNode<T>* temp;// 임시변수
	temp = root;
	temp->data = data; // 노드에 데이터를 복사
}

// Tree의 node를 각각의 방법대로 출력함
template<class T>
void AVLTree<T>::print()
{
	//ostream &out;
	PrintInOrderTraversal(root);			// InOrder 방법으로 출력
}
/*
template<typename T>
void AVLTree<T>::pointprint()
{
	//ostream &out;
	PointPrintInOrderTraversal(root);			// InOrder 방법으로 출력
}
*/
// Tree의 node를 각각의 방법대로 출력함
template<class T>
void AVLTree<T>::SaveTree(ofstream& fout)
{
	SaveInOrderTraversal(root, fout);			// InOrder 방법으로 출력
}

template<typename T>
int AVLTree<T>::Max(int i, int j)
{
	return i > j ? i : j;
}
template<typename T>
int AVLTree<T>::getHeight(TreeNode<T>* Node)
{
	// 가장 밑 에있는 리프노드로부터 1씩더해져서 올라옴
	int height = 0; //높이
	if (Node != nullptr)
	{
		int i = getHeight(Node->left); // 노드의 왼쪽으로 재귀
		int j = getHeight(Node->right); // 노드의 오른쪽으로 재귀
		height = Max(i, j); // 큰거를 높이에 넣고
	}
	return 1 + height; // 하이트 +1 리턴
}
template<typename T>
int AVLTree<T>::getBalance(TreeNode<T>* Node)
{
	return getHeight(Node->left) - getHeight(Node->right); // 왼쪽 높이 - 오른쪽높이
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_LL(TreeNode<T>* parent)
{
	// 왼쪽 왼쪽으로 연결되있는경우 오른쪽으로 회전하고 패런트가 차일드의 오른쪽이되고 차일드가 부모가됨
	TreeNode<T>* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_RR(TreeNode<T>* parent)
{
	// 오른쪽 오른쪽으로 연결되있는경우 왼쪽으로 회전하고 패런트가 차일드의 왼쪽이되고 차일드가 부모가됨
	TreeNode<T>* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_LR(TreeNode<T>* parent)
{
	// 왼쪽 오른쪽으로 연결되있는 경우 차일드의 차일드가 왼쪽으로 로테이션하고 차일드가 오른쪽으로 로테이션함
	TreeNode<T>* child = parent->left;
	parent->left = Rotate_RR(child);
	return Rotate_LL(parent);
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_RL(TreeNode<T>* parent)
{
	// 오른쪽 왼쪽으로 연결되있는 경우 차일드의 차일드가 오른쪽으로 로테이션하고 차일드가 왼쪽으로 로테이션함
	TreeNode<T>* child = parent->right;
	parent->right = Rotate_LL(child);
	return Rotate_RR(parent);
}
template<typename T>
TreeNode<T>* AVLTree<T>::MakeBalance(TreeNode<T>* Node)
{
	int hight_different = getBalance(Node); // 높이차이

	if (hight_different > 1) // 1초과일경우 즉 왼쪽 부분트리의 높이가 더 큰 경우
	{
		if (getBalance(Node->left) > 0) // 노드의 왼쪽의 균형인수가 0보다 큰경우 즉 노드의 왼쪽이 더 긴경우 
			Node = Rotate_LL(Node);
		else // 반대경우
			Node = Rotate_LR(Node);
	}
	else if (hight_different < -1) // -1미만일경우 즉 오른쪽 부분트리의 높이가 더 큰 경우
	{
		if (getBalance(Node->right) < 0) // 노드의 오른쪽 균형인수가 0보다 작은 경우 즉 노드의 오른쪽이 더 긴경우
			Node = Rotate_RR(Node);
		else // 반대경우
			Node = Rotate_RL(Node);
	}
	return Node; // 노드리턴 즉 차일드를 리턴하게됨
}
template<typename T>
TreeNode<T>* AVLTree<T>::RecursiveInsert(TreeNode<T>* Node, T data)
{
	if (Node->data > data) // 데이터가 노드의 데이터보다 작을때 왼쪽으로 갈때
	{
		if (Node->left == nullptr) // 노드의 왼쪽이 비었다면
		{
			// 추가
			TreeNode<T>* temp = new TreeNode<T>;
			temp->data = data;
			temp->left = nullptr;
			temp->right = nullptr;
			Node->left = temp;
			length++;
		}
		else //안 비었다면
			Node->left = RecursiveInsert(Node->left, data); // 노드를 노드의 왼쪽으로 옮겨서 다시 돌림
		Node = MakeBalance(Node); // 재귀를 빠져나오면서 추가된 노드의 부모부터 루트까지 균형을 맞춤 , 혹은 추가 되고 그 부모노드부터 균형을맞춤
	}
	else // 데이터가 노드의 데이터보다 클때 오른쪽으로 갈 때
	{
		if (Node->right == nullptr) // 노드의 오른쪽이 비었다면
		{
			// 추가
			TreeNode<T>* temp = new TreeNode<T>;
			temp->data = data;
			temp->left = nullptr;
			temp->right = nullptr;
			Node->right = temp;
			length++;
		}
		else
			Node->right = RecursiveInsert(Node->right, data); // 노드를 노드의 오른쪽으로 옮겨서 다시 돌림
		Node = MakeBalance(Node); // 재귀를 빠져나오면서 추가된 노드의 부모부터 루트까지 균형을 맞춤
	}
	return Node; //노드를 리턴함으로써 재귀함수가 빠져나오면서 연결을 해줌
}
template<typename T>
TreeNode<T>* AVLTree<T>::Recursivedelete(TreeNode<T>* Node, T data)
{
	if (Node == nullptr) // 노드가 눌이라면 
	{
		return nullptr;
	}
	else // 눌이 아니라면
	{
		if (Node->data > data) // 왼쪽으로 감
		{
			Node->left = Recursivedelete(Node->left, data); // 노드를 노드의 왼쪽으로 맞추어 재귀를 돌림
			Node = MakeBalance(Node); // 재귀를 빠져나오면서 삭제된 노드의 부모부터 균형을 맞춤
		}
		else if (Node->data < data) // 오른쪽으로 감
		{
			Node->right = Recursivedelete(Node->right, data); // 노드를 노드의 오른쪽으로 맞추어 재귀를 돌림
			Node = MakeBalance(Node); // 재귀를 빠져나오면서 삭제된 노드의 부모부터 균형을 맞춤
		}
		else // 찾았다면
		{
			if (Node->left == nullptr && Node->right == nullptr) // 노드의 왼쪽과 오른쪽이 다 비었다면
			{
				delete Node;
				Node = nullptr;
				return Node;
			}
			else if (Node->left == nullptr && Node->right != nullptr) // 오른쪽만 있다면
			{
				TreeNode<T>* temp = Node->right; // 노드의 오른쪽 저장
				delete Node;
				return temp; // 노드의 오른쪽 리턴
			}
			else if (Node->right == nullptr && Node->left != nullptr) // 왼쪽만 있다면
			{
				TreeNode<T>* temp = Node->left; // 노드의 왼쪽을 저장
				delete Node;
				return temp; // 노드의 왼쪽 리턴
			}
			else // 양쪽다 있다면
			{
				// 삭제할 노드의 왼쪽으로 이동하여 오른쪽으로 계속이동하여 트리내 가장 가까운 작은값을 찾음
				TreeNode<T>* dummy = Node->left;
				while (dummy->right != nullptr)
				{
					dummy = dummy->right;
				}
				Node->data = dummy->data; // 찾은 값을 노드에 추가해줌
				Node->left = Recursivedelete(Node->left, Node->data); // 노드의 왼쪽을 기준으로 그 아래 트리에서 찾은 값을 삭제함
				Node = MakeBalance(Node); // 삭제한 노드의 부모부터 균형을 맞추어주면서 올라감
				return Node; // 노드리턴
			}
		}
	}
	return Node;
}
template<typename T>
TreeNode<T>* AVLTree<T>::getroot()
{
	return this->root;
}

// InOrder 방법으로 출력하는 함수 
template<typename T>
void AVLTree<T>::PrintInOrderTraversal(TreeNode<T>* root)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintInOrderTraversal(root->left);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		root->data.DisplayRecordOnScreen();
		PrintInOrderTraversal(root->right);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}
/*
template<typename T>
void AVLTree<T>::PointPrintInOrderTraversal(TreeNode<T>* root)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintInOrderTraversal(root->left);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		root->data->DisplayRecordOnScreen();							// root 출력
		PrintInOrderTraversal(root->right);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}
*/
// InOrder 방법으로 저장하는 함수 
template<typename T>
void AVLTree<T>::SaveInOrderTraversal(TreeNode<T>* root, ofstream& out)
{
	MasterType temp;
	if (root != NULL)								// root가 존재하는 경우
	{
		SaveInOrderTraversal(root->left, out);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		temp = root->data;
		//temp = data;
		temp.WriteDataToFile(out);
		//out << root->data;
		SaveInOrderTraversal(root->right, out);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}