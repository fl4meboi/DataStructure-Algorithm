#include <iostream>
#include "CircularQueue.h"

using namespace std;

void CircularQueue::CQ_CreateQueue(CircularQueue*& Queue, int Capacity)
{
	Queue = new CircularQueue; // 큐를 힙에 생성

	Queue->Nodes = new Node[Capacity + 1]; // Node 배열 동적 할당, Capacity+1 만큼 힙에 생성

	Queue->Capacity = Capacity;
	Queue->Front = 0;			// Front 초기화
	Queue->Rear = 0;			// Rear 초기화
}

void CircularQueue::CQ_DestroyQueue(CircularQueue* Queue)
{
	delete[] Queue->Nodes;
	delete[] Queue;
}

void CircularQueue::CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
	int Position = 0;					// Count 

	if (Queue->Rear == Queue->Capacity)	// Queue가 비어있을 때 
	{
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
		Position = Queue->Rear++;		// Data 새로 들어올 때마다 Count++

	Queue->Nodes[Position].Data = Data;	// Node 배열 안의 Position번째 데이터는 Data => 그러니까 넣은 자리에 넣은 Data가 있다는 뜻 
}

ElementType CircularQueue::CQ_Dequeue(CircularQueue* Queue)
{
	int Position = Queue->Front;			// Front에서만 Dequeue

	if (Queue->Front == Queue->Capacity)	// Queue가 비어있을 때 
		Queue->Front = 0;
	else
		Queue->Front++;						// Data 새로 들어올 때마다 Count++ => Front 앞으로 점점 옮기기

	return Queue->Nodes[Position].Data;		// 꺼낸 데이터 반환
}

int CircularQueue::CQ_GetSize(CircularQueue* Queue)
{
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;	// Front가 Rear보다 앞에 있을 때 
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