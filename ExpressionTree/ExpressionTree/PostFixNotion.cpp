#include <iostream>
#include <string>
using namespace std;

// 본 풀이는 석현이형의 도움을 아주 많이 받은 풀이입니다. 형 감사합니다 :)

int N;
string String;				// 입력받을 후위표기식
double DataArray[26] = {};	// Operand 개수는 26개로 제한

typedef struct Node
{
	char Data;

	Node* Parent;
	Node* LeftChild;
	Node* RightChild;

	double Calculation()
	{
		double Left;
		double Right;
		if ('A' <= Data && Data <= 'Z')				// 입력된 Data가 A - Z 안에 있는지 => Operand인지 
		{
			return DataArray[Data - 'A'];			// Data 입력받을 포인터 배열 세팅해주기
		}
		else	// 입력된 Data가 Operator이면 
		{
			Left = LeftChild->Calculation();		// 
			Right = RightChild->Calculation();
		}

		double Result = 0;
		switch (Data)								// Operator별 계산 미리 
		{
		case '+' :	Result = Left + Right;	break;
		case '-':	Result = Left - Right;	break;
		case '*':	Result = Left * Right;	break;
		case '/':	Result = Left / Right;	break;
		}

		return Result;
	}

	void DeleteAll()
	{
		if (LeftChild != nullptr)
			LeftChild->DeleteAll();
		if (RightChild != nullptr)
			RightChild->DeleteAll();

		delete this;
	}

	Node(char NewData) : Data(NewData), Parent(nullptr), LeftChild(nullptr), RightChild(nullptr) {}

} Node;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	// print시 속도 보완. 코딩테스트시 필수 요소 "라면 스프"

	// 소수점 2번째 자리까지 출력하는 함수
	cout.setf(ios::fixed);
	cout.precision(2);

	cin >> N;			// 1번 줄 : Operand 개수 입력
	cin >> String;		// 2번 줄 : 후위 표기식 입력 
	for (int i = 0; i < N; ++i)
	{
		cin >> DataArray[i];		
	}
	
	Node* Root = nullptr;

	Node** Current = &Root;		// **를 쓰는 이유 : 저번 시간 세연누나가 구현한 배열과 같은 원리
	
	for (int i = String.size() - 1; i >= 0; --i)		// 식을 뒤에서부터 읽기 
	{
		// 우선 Node 만들고 
		Node* NewNode = new Node(String[i]);	
		// 현재 값이 nullptr이면 Node를 입력
		if (*Current == nullptr)
		{
			*Current = NewNode; 
		}
		else
		{
			// 현재 값에 이미 다른 Node가 있다면
			while (true)
			{
				// RightChild == nullptr이면
				if ((*Current)->RightChild == nullptr)
				{
					// 현재 Node의 RightChild를 NewNode로
					NewNode->Parent = *Current;
					(*Current)->RightChild = NewNode;

					// 만약 현재 식이 Operand가 아니라면 
					if (!('A' <= String[i] && String[i] <= 'Z'))
					{
						Current = &(*Current)->RightChild;
					}
					break;
				}
				// RightChild가 이미 있고 LeftChild가 nullptr라면
				else if ((*Current)->LeftChild == nullptr)
				{
					// LeftChild를 NewNode로 만듦
					NewNode->Parent = *Current;
					(*Current)->LeftChild = NewNode;

					// 만약 현재 식이 Operand가 아니라면 
					if (!('A' <= String[i] && String[i] <= 'Z'))
					{
						// 현재 위치를 LeftChild로 옮김
						Current = &(*Current)->LeftChild;
					}
					break;
				}
				// 현재 위치도 이미 Node가 있고, 양쪽 Child도 이미 Node가 있는 경우
				else
				{
					// 현재 위치를 Parent로 올라감
					Current = &(*Current)->Parent;
				}
			}
		}
	}

	if (Root != nullptr)
	{
		// Root를 기준으로 후위순회하면서 계산
		cout << Root->Calculation() << '/n';
		Root->DeleteAll();
		delete Root;
	}

	return 0;
}
