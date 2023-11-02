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
			Rear = pNewNode;				// Front와 Rear 모두 NewNode
		}
		else {
			Rear->pNextNode = pNewNode;		// Rear 다음이 NewNode
			Rear = pNewNode;				// Rear를 NewNode를 가리키게
		}
		Count++;							// 개수 1 추가
	}

	int Dequeue() {
		Node* pRemoveNode;
		int Data;
		
		if (isEmpty()) {
			cout << "IsEmpty" << "\n";
		}
	}

	// 내림차순 구현 
	

	// Dequeue 횟수 ++ 

};
