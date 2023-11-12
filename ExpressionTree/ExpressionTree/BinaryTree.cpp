#include<iostream>

using namespace std;

/*
class BinaryNode
{
	friend class BinaryTree;
private:
	int Data;
	BinaryNode* Left;
	BinaryNode* Right; 

public:
	BinaryNode(int Val) 
	{
		Data = Val;
		Left = nullptr;
		Right = nullptr;
	}
	~BinaryNode()
	{
	}
	bool isLeaf() 
	{
		return (Left == nullptr && Right == nullptr);
	}
	int GetData()
	{
		return Data;
	}
	void SetData(int Val)
	{
		Data = Val;
	}
	BinaryNode* GetLeft()
	{
		return Left;
	}
	BinaryNode* GetRight()
	{
		return Right;
	}
	void SetLeft(BinaryNode* L)
	{
		Left = L;
	}
	void SetRight(BinaryNode* R)
	{
		Right = R;
	}
};

class BinaryTree
{
	BinaryNode* Root; 
public:
	BinaryTree() 
	{
		Root = nullptr;
	}
	~BinaryTree()
	{

	}
	void SetRoot(BinaryNode* Node)
	{
		Root = Node;
	}
	BinaryNode* GetRoot()
	{
		return Root;
	}
	bool IsEmpty()
	{
		return (Root == nullptr);
	}
	void PreOrder(BinaryNode* Node) 
	{
		if (Node != nullptr)
		{
			cout << " [" << (char)Node->GetData() << "] "; 

			if (Node->GetLeft() != nullptr)
				PreOrder(Node->GetLeft()); 

			if (Node->GetRight() != nullptr)
				PreOrder(Node->GetRight()); 
		}
	}

	void InOrder(BinaryNode* Node) 
	{
		if (Node != nullptr)
		{
			if (Node->GetLeft() != nullptr)
				InOrder(Node->GetLeft());

			cout << " [" << (char)Node->GetData() << "] "; 

			if (Node->GetRight() != nullptr)
				InOrder(Node->GetRight()); 
		}

	}

	void PostOrder(BinaryNode* Node) 
	{
		if (Node != nullptr)
		{
			if (Node->GetLeft() != nullptr)
				InOrder(Node->GetLeft());

			if (Node->GetRight() != nullptr)
				InOrder(Node->GetRight()); 

			cout << " [" << (char)Node->GetData() << "] ";
		}
	}
};


int main()
{



}
*/