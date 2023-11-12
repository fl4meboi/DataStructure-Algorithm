#include<iostream>

using namespace std;

// 명훈형님 코드 보고 공부했습니다 

class Node
{
public:
	char Data;
	Node* LeftChild;
	Node* RightChild;

	Node(char NewData) : Data(NewData), LeftChild(nullptr), RightChild(nullptr) {}		// Node 클래스의 NewData, LeftChild, RightChild 선언과 초기화 동시에
};

class Tree
{
public:
	Node* Root;
	int NodeCount;		// 여기서는 필요없음 

	Tree() : Root(nullptr), NodeCount(0) {}		// Tree 클래스의 Root와 NodeCount 선언과 초기화 동시에 
	
	void AddNodeAt(char Parent, char Left, char Right)
	{
		if (Root == nullptr)
		{
			Node* NewParent = new Node(Parent);		// Root가 nullptr이면 Node의 Parent 자리는 NewParent로 선언
			Root = NewParent;		// Root 자리에 NewParent 선언

			if (Left != '.')		// Left, Right 새로운 애들로 배치 
				NewParent->LeftChild = new Node(Left);
			if (Right != '.')
				NewParent->RightChild = new Node(Right);
		}
		else
		{
			Node* Current = FindParent(Root, Parent);	// Root가 nullptr가 아니면 현재 Node의 Root와 ...

			if (Left != '.')
				Current->LeftChild = new Node(Left);
			if (Right != '.')
				Current->RightChild = new Node(Right);
		}
	}

	Node* FindParent(Node* Target, char FindNode)
	{
		if (Target->Data == FindNode)
		{
			return Target;
		}
		else
		{
			if (Target->LeftChild != nullptr)
				return FindParent(Target->LeftChild, FindNode);
			if (Target->RightChild != nullptr)
				return FindParent(Target->RightChild, FindNode);
		}
		return nullptr;
	}

	void PrintPreOrder(Node* Node)
	{
		if (Node == nullptr)
			return;

		cout << Node->Data;					// Root 출력. 여기서 Node는 Root 기준이다 
		PrintPreOrder(Node->LeftChild);		// LeftChild 출력 
		PrintPreOrder(Node->RightChild);	// RightChild 출력 
	}

	void PrintInOrder(Node* Node)
	{
		if (Node == nullptr)
			return;

		PrintPreOrder(Node->LeftChild);
		cout << Node->Data;
		PrintPreOrder(Node->RightChild);
	}

	void PrintPostOrder(Node* Node)
	{
		if (Node == nullptr)
			return;

		PrintPostOrder(Node->LeftChild);
		PrintPostOrder(Node->RightChild);
		cout << Node->Data;
	}
};

int main()
{
	int N = 0;
	cin >> N;

	Tree* NewTree = new Tree;		// Tree 동적할당

	for (int i = 0; i < N; ++i)
	{
		char Parent, LeftChild, RightChild;
		cin >> Parent >> LeftChild >> RightChild;
		NewTree->AddNodeAt(Parent, LeftChild, RightChild);
	}

	NewTree->PrintPreOrder(NewTree->Root);
	cout << '/n';
	NewTree->PrintInOrder(NewTree->Root);
	cout << '/n';
	NewTree->PrintPostOrder(NewTree->Root);
	
	return 0;
}