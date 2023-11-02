#include<iostream>
using namespace std;

#define MAX_QUEUE_SIZE 20		// �ִ� �뷮 ���ϰ� ���� 

int main() {

	class CircularQueue {
	private:
		int Data[MAX_QUEUE_SIZE]; // ����� �迭
		int Front; //ù��° ��� ���� ��ĭ ���� ��ġ
		int Rear; //������ ��� ��ġ

	public:
		CircularQueue() {
			Front = Rear = 0;
		}
		~CircularQueue() {
		}
		void EnQueue(int Val) {
			if (isFull()) {//ť�� ��ȭ�̸� �����÷ο�
				cout << "Queue Overflow!";
				exit(EXIT_FAILURE);
			}
			else {//�ƴϸ� Rear�� 1�����ϰ� ������ ����
				Rear = (Rear + 1) % MAX_QUEUE_SIZE; //ť �����ŭ ������ ���� ; �� ���� �������� �ٽ� ù��° �ڸ����� 
				Data[Rear] = Val;
			}
		}
		int DeQueue() {
			if (isEmpty()) {//ť�� ��������� ����÷ο�
				cout << "Queue Underflow!";
				exit(1);
			}
			else {//�ƴϸ� Front�� 1�����ϰ� ������ ����
				Front = (Front + 1) % MAX_QUEUE_SIZE;
				return Data[Front]; //����Ʈĭ�� ����ֱ� ����
			}
		}
		int Peek() {
			if (isEmpty()) {
				cout << "Queue Underflow!";
				exit(1);
			}
			else {
				return Data[Front + 1]; //����Ʈĭ�� ����ֱ⶧��
			}
		}
		bool isFull() {
			if (Front == (Rear + 1) % MAX_QUEUE_SIZE) {
				return true;
			}
			else {
				return false;
			}
			//return (Front == (Rear+1) % MAX_QUEUE_SIZE;
		}
		bool isEmpty() {
			if (Front == Rear) {
				return true;
			}
			else {
				return false;
			}
			//return (Front == Rear);
		}
		int Size() {
			return Rear - Front + 1;
		}
	};

	CircularQueue CQ;
	CQ.EnQueue(0);
	CQ.EnQueue(1);
	CQ.EnQueue(2);
	cout << CQ.DeQueue();
	cout << CQ.DeQueue();


	return 0;
}