#include <iostream>
using namespace std;

// 백준 10773 제로 문제풀이 

class ArrayStack {
private: 
	int Capacity;
	int Top;
	int* Arr;
	int Sum;
public:
	ArrayStack(int _Size) {
		Top = -1;
		Capacity = _Size;
		Arr = new int[Capacity];
		Sum = 0;
	}
	~ArrayStack() {
		delete[] Arr;
	}
	bool isEmpty() {
		return (Top == -1);
	}
	bool isFull() {
		return (Top + 1 == Capacity);
	}
	void Push(int Value) {
		if (isFull()) {
			cout << "Stack Overflow!";
		}
		// cout << "Push : " << Value << endl;
		Arr[++Top] = Value;
	}
	int Peek() {
		if (isEmpty()) {
			cout << "Stack Underflow";
		}
		return Arr[Top];
	}
	int Pop() {
		if (isEmpty()) {
			cout << "Stack Underflow";
		}
		// cout << "Pop : " << Peek() << endl;
		return Arr[Top--];
	}
	int GetSize() {
		return Top + 1;
	}

	int PrintStackRemainingSum() {
		for (int i = 0; i < GetSize(); i++) {
			Sum += Arr[i];
			return Sum;
		}
	}
};

void main(int K, int Input) {
	cin >> K;
	ArrayStack St(K);
	for (int i = 0; i < K; i++) {
		cin >> Input;
		if (Input == 0)
			St.Pop();
		else
			St.Push(Input);
	}
	cout << St.PrintStackRemainingSum();
}