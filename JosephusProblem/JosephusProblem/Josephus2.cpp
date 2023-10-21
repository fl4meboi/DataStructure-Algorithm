/*
int N
1���� N���� N���� ������ �ɾ����� 

int K 
K��° ����� ����

Circular Linked List 

1. �Է� 
	��� �� N��
	���ŵ� ���� K��°

2. ��� 
	K��°���� RemoveNode 

	ǳ�� �Ͷ߸���ó�� head�� �����ϰ� FindNode�� temp�� �־ �ϳ��� cout

*/

#include <iostream>
#include <vector>
using namespace std;

class CDLL_Node					
{
private: 
	int Data;
	int Num;
	CDLL_Node* NextNode;
	// CDLL_Node* PrevNode;

public:
	CDLL_Node(int NewData, int NewNum)		// Node ������
	{
		Data = NewData;
		Num = NewNum;
		NextNode = nullptr;
		// PrevNode = nullptr;
	}

	~CDLL_Node()							// Node �Ҹ���
	{
	}

	int GetData() 
	{
		return Data;
	}

	int GetNum()
	{
		return Num;
	}
	
	CDLL_Node* GetNextNode()
	{
		return NextNode;
	}

	void SetData(int NewData)
	{
		Data = NewData;
	}

	void SetNextNode(CDLL_Node* NewNextNode)
	{
		NextNode = NewNextNode;
	}
};

class CircularLinkedList
{
private:
	CDLL_Node* Head;
	int Count;

public:
	CircularLinkedList()
	{
		Head = nullptr;
		Count = 0;
	}

	~CircularLinkedList()
	{
	}

	CDLL_Node* CreateNode(int NewData, int NewNum)
	{
		return new CDLL_Node(NewData, NewNum);
	}


};

void Josephus()
{
	int N;
	int K;

	cin >> N >> K;



}
