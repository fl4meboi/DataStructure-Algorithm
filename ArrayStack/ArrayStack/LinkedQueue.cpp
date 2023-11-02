#include "ioStream"
using namespace std;

class Node {
public:
	int Data;
	Node* pNextNode;
	Node() : Data(0), pNextNode(nullptr){}
};

class LinkedQueue {
	Node* Front;
	Node* Rear;
	int Count;
public:
	LinkedQueue() : Front(nullptr), Rear(nullptr), Count(0){}
	~LinkedQueue(){}
	
	bool isEmpty() {
		return(Front == nullptr);
	}

	void Enqueue(int _Data) {
		Node* pNewNode = new Node;
		pNewNode->Data = _Data;
		pNewNode->pNextNode = nullptr;

		if (isEmpty()) {
			Front = pNewNode;
			Rear = pNewNode;				// Front�� Rear ��� NewNode
		}
		else {
			Rear->pNextNode = pNewNode;		// Rear ������ NewNode
			Rear = pNewNode;				// Rear�� NewNode�� ����Ű��
		}
		Count++;							// ���� 1 �߰�
	}

	int Dequeue() {
		Node* pRemoveNode;
		int Data;
		
		if (isEmpty()) {
			cout << "IsEmpty" << "\n";
		}
	}

	// �������� ���� 
	

	// Dequeue Ƚ�� ++ 

};
