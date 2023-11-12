#include<iostream>

using namespace std;

// �������� �ڵ� ���� �����߽��ϴ� 

class Node
{
public:
	char Data;
	Node* LeftChild;
	Node* RightChild;

	Node(char NewData) : Data(NewData), LeftChild(nullptr), RightChild(nullptr) {}		// Node Ŭ������ NewData, LeftChild, RightChild ����� �ʱ�ȭ ���ÿ�
};

class Tree
{
public:
	Node* Root;
	int NodeCount;		// ���⼭�� �ʿ���� 

	Tree() : Root(nullptr), NodeCount(0) {}		// Tree Ŭ������ Root�� NodeCount ����� �ʱ�ȭ ���ÿ� 
	
	void AddNodeAt(char Parent, char Left, char Right)
	{
		if (Root == nullptr)
		{
			Node* NewParent = new Node(Parent);		// Root�� nullptr�̸� Node�� Parent �ڸ��� NewParent�� ����
			Root = NewParent;		// Root �ڸ��� NewParent ����

			if (Left != '.')		// Left, Right ���ο� �ֵ�� ��ġ 
				NewParent->LeftChild = new Node(Left);
			if (Right != '.')
				NewParent->RightChild = new Node(Right);
		}
		else
		{
			Node* Current = FindParent(Root, Parent);	// Root�� nullptr�� �ƴϸ� ���� Node�� Root�� ...

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

		cout << Node->Data;					// Root ���. ���⼭ Node�� Root �����̴� 
		PrintPreOrder(Node->LeftChild);		// LeftChild ��� 
		PrintPreOrder(Node->RightChild);	// RightChild ��� 
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

	Tree* NewTree = new Tree;		// Tree �����Ҵ�

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