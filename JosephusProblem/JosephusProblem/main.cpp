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

	ptr = new Node(2);		// ���2 -> ���3
	ptr->setNext(next);
	next = ptr;				// next�� ���2�� 

	ptr = new Node(1);		// ���1 -> ���2
	ptr->setNext(next);
	next = ptr;				// next�� ���1��		�ݺ��Ǵ� ����

	last->setNext(next);	// ���3 -> ���1		����Ŭ ����
	*/

	// ���� �ݺ������� ǥ���ϸ�
	for (int i = N - 1; i >= 1; i--)
	{
		ptr = new Node(i);
		ptr->setNext(next);	// ���i -> ���(i+1)
		next = ptr;
	}

	last->setNext(next);	// ���N -> ���1
	
	Node* list = next;		// ���� ��带 list�� ����Ŵ

	int count = N;			// ���� �����ִ� ����� ��

	while (count > 1)
	{
		list->setNext(list->getNext()->getNext());	// kill�� ��� ���� ��带 get
		
		list = list->getNext();
		count--;
	}

	cout << list->getName() << endl;

	return 0;
}