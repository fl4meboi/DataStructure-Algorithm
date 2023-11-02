#include <iostream>
using namespace std;

struct Node {
	int Data;
	Node* Link;
};

Node* Top = NULL;

bool isEmpty() {
	if (Top == NULL)
		return true;
	else
		return false;
}

void Push(int Value) {
	Node* Temp = new Node();
	Temp->Data = Value;
	Temp->Link = Top;
	Top = Temp;
}

void Pop() {
	if (isEmpty())
		cout << "Stack is Empty";
	else {
		Node* Temp = Top;
		Top = Top->Link;
		delete(Temp);
	}
}

void Peek() {
	if (isEmpty())
		cout << "Stack is Empty";
	else
		cout << "Element at top is : " << Top->Data;
}

void main() {
	/*
	1x : Push int X
	2 : 
	3 : 
	4 : if(isEmpty)                                                                                                                                                                                                                            
	5 : 
	*/


}
