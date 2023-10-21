/*
int N
1부터 N까지 N명이 원으로 앉아있음 

int K 
K번째 사람을 제거

Circular Linked List 

1. 입력 
	사람 수 N명
	제거될 패턴 K번째

2. 출력 
	K번째에서 RemoveNode 

	풍선 터뜨리기처럼 head를 고정하고 FindNode를 temp에 넣어서 하나씩 cout

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
	CDLL_Node(int NewData, int NewNum)		// Node 생성자
	{
		Data = NewData;
		Num = NewNum;
		NextNode = nullptr;
		// PrevNode = nullptr;
	}

	~CDLL_Node()							// Node 소멸자
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
