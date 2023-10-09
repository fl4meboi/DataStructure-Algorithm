#include <iostream>
#include "Josephus.h"
using namespace std;

int main() 
{
	int N = 0;
	cin >> N;

	Node* next = new Node(N);
	Node* last = next;

	Node* ptr;

	/*
	N = 3;

	ptr = new Node(2);		// 노드2 -> 노드3
	ptr->setNext(next);
	next = ptr;				// next를 노드2로 

	ptr = new Node(1);		// 노드1 -> 노드2
	ptr->setNext(next);
	next = ptr;				// next를 노드1로		반복되는 형식

	last->setNext(next);	// 노드3 -> 노드1		사이클 형성
	*/

	// 위를 반복문으로 표현하면
	for (int i = N - 1; i >= 1; i--)
	{
		ptr = new Node(i);
		ptr->setNext(next);	// 노드i -> 노드(i+1)
		next = ptr;
	}

	last->setNext(next);	// 노드N -> 노드1
	
	Node* list = next;		// 기준 노드를 list가 가리킴

	int count = N;			// 현재 남아있는 노드의 수

	while (count > 1)
	{
		list->setNext(list->getNext()->getNext());	// kill한 노드 다음 노드를 get
		
		list = list->getNext();
		count--;
	}

	cout << list->getName() << endl;

	return 0;
}