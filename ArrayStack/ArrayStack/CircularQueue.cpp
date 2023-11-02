#include <iostream>
#include "CircularQueue.h"

using namespace std;

void CircularQueue::CQ_CreateQueue(CircularQueue*& Queue, int Capacity)
{
	Queue = new CircularQueue; // ť�� ���� ����

	Queue->Nodes = new Node[Capacity + 1]; // Node �迭 ���� �Ҵ�, Capacity+1 ��ŭ ���� ����

	Queue->Capacity = Capacity;
	Queue->Front = 0;			// Front �ʱ�ȭ
	Queue->Rear = 0;			// Rear �ʱ�ȭ
}

void CircularQueue::CQ_DestroyQueue(CircularQueue* Queue)
{
	delete[] Queue->Nodes;
	delete[] Queue;
}

void CircularQueue::CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
	int Position = 0;					// Count 

	if (Queue->Rear == Queue->Capacity)	// Queue�� ������� �� 
	{
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
		Position = Queue->Rear++;		// Data ���� ���� ������ Count++

	Queue->Nodes[Position].Data = Data;	// Node �迭 ���� Position��° �����ʹ� Data => �׷��ϱ� ���� �ڸ��� ���� Data�� �ִٴ� �� 
}

ElementType CircularQueue::CQ_Dequeue(CircularQueue* Queue)
{
	int Position = Queue->Front;			// Front������ Dequeue

	if (Queue->Front == Queue->Capacity)	// Queue�� ������� �� 
		Queue->Front = 0;
	else
		Queue->Front++;						// Data ���� ���� ������ Count++ => Front ������ ���� �ű��

	return Queue->Nodes[Position].Data;		// ���� ������ ��ȯ
}

int CircularQueue::CQ_GetSize(CircularQueue* Queue)
{
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;	// Front�� Rear���� �տ� ���� �� 
}

bool CircularQueue::CQ_IsEmpty(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}

bool CircularQueue::CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	else
		return (Queue->Rear + 1) == Queue->Front;
}

int main()
{
	int i = 0; 
	CircularQueue* Queue;

	CircularQueue::CQ_CreateQueue(Queue, 10);

	CircularQueue::CQ_Enqueue(Queue, 1);
	CircularQueue::CQ_Enqueue(Queue, 2);
	CircularQueue::CQ_Enqueue(Queue, 3);
	CircularQueue::CQ_Enqueue(Queue, 4);

	for (int i = 0; i < 3; ++i)
	{
		cout << 
	}
}