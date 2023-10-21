#include <iostream>
using namespace std;
/*
class ArrayStack {

private:
	int Capacity;
	int Top; //������ �� ����� ��������� -1
	int* Arr; //���� �Ҵ��� �迭
public:
	ArrayStack(int _Size) {
		Top = -1;
		Capacity = _Size;
		Arr = new int[Capacity];
	}
	~ArrayStack() {
		delete[] Arr; // �迭�� �����Ҵ� �߱� ������ delete[]
	}
	bool IsEmpty() { // ������ ����ֳ� Ȯ��
		return (Top == -1);
	}
	bool IsFull() { // ������ �� ���ֳ� Ȯ��
		return (Top + 1 == Capacity);
	}
	void Push(int Value) {//���ÿ� �� �߰�
		if (IsFull()) {
			cout << "Stack Overflow!";
			exit(EXIT_FAILURE); //����
		}
		cout << "�߰��� �� : " << Value << endl;
		Arr[++Top] = Value; // ���ǿ�����, ���ǿ����� ���� 
							// Arr[-1] ��ü�� �ȵ� 
	}
	int Peek() {//������ ������ ���� ��ȯ
		if (IsEmpty()) {
			exit(EXIT_FAILURE);
		}
		else {
			return Arr[Top];
		}
	}
	int Pop() {//������ ������ ���� ��ȯ(���� ��ȯ�ϱ� ������ int������ ����)�ϰ� ����
		if (IsEmpty()) {
			cout << "Stack Underflow!";
			exit(EXIT_FAILURE); //����
		}
		cout << "������ �� : " << Peek() << endl;

		return Arr[Top--]; // ��ȯ�ϰ� ���� 
	}

	int GetSize() { //���� ���� ũ�⸦ ��ȯ
		return Top + 1;
	}

	void PrintStack() {
		cout << "ArrayStack : [ ";
		for (int i = 0; i < GetSize(); i++) {
			if (i == 0) {
				cout << Arr[i];
			}
			else {
				cout << ", " << Arr[i];
			}
		}
		cout << " ]" << endl;
	}
};

int main() {
	ArrayStack St(5);

	St.Push(0);
	St.Push(1);
	St.Push(2);
	St.Push(3);
	St.PrintStack();
	St.Pop();
	St.Push(4);
	St.Pop();
	St.Pop();
	St.PrintStack();
	return 0;
}
*/