#include <iostream>
#include <string>
using namespace std;

// �� Ǯ�̴� ���������� ������ ���� ���� ���� Ǯ���Դϴ�. �� �����մϴ� :)

int N;
string String;				// �Է¹��� ����ǥ���
double DataArray[26] = {};	// Operand ������ 26���� ����

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
		if ('A' <= Data && Data <= 'Z')				// �Էµ� Data�� A - Z �ȿ� �ִ��� => Operand���� 
		{
			return DataArray[Data - 'A'];			// Data �Է¹��� ������ �迭 �������ֱ�
		}
		else	// �Էµ� Data�� Operator�̸� 
		{
			Left = LeftChild->Calculation();		// 
			Right = RightChild->Calculation();
		}

		double Result = 0;
		switch (Data)								// Operator�� ��� �̸� 
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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	// print�� �ӵ� ����. �ڵ��׽�Ʈ�� �ʼ� ��� "��� ����"

	// �Ҽ��� 2��° �ڸ����� ����ϴ� �Լ�
	cout.setf(ios::fixed);
	cout.precision(2);

	cin >> N;			// 1�� �� : Operand ���� �Է�
	cin >> String;		// 2�� �� : ���� ǥ��� �Է� 
	for (int i = 0; i < N; ++i)
	{
		cin >> DataArray[i];		
	}
	
	Node* Root = nullptr;

	Node** Current = &Root;		// **�� ���� ���� : ���� �ð� ���������� ������ �迭�� ���� ����
	
	for (int i = String.size() - 1; i >= 0; --i)		// ���� �ڿ������� �б� 
	{
		// �켱 Node ����� 
		Node* NewNode = new Node(String[i]);	
		// ���� ���� nullptr�̸� Node�� �Է�
		if (*Current == nullptr)
		{
			*Current = NewNode; 
		}
		else
		{
			// ���� ���� �̹� �ٸ� Node�� �ִٸ�
			while (true)
			{
				// RightChild == nullptr�̸�
				if ((*Current)->RightChild == nullptr)
				{
					// ���� Node�� RightChild�� NewNode��
					NewNode->Parent = *Current;
					(*Current)->RightChild = NewNode;

					// ���� ���� ���� Operand�� �ƴ϶�� 
					if (!('A' <= String[i] && String[i] <= 'Z'))
					{
						Current = &(*Current)->RightChild;
					}
					break;
				}
				// RightChild�� �̹� �ְ� LeftChild�� nullptr���
				else if ((*Current)->LeftChild == nullptr)
				{
					// LeftChild�� NewNode�� ����
					NewNode->Parent = *Current;
					(*Current)->LeftChild = NewNode;

					// ���� ���� ���� Operand�� �ƴ϶�� 
					if (!('A' <= String[i] && String[i] <= 'Z'))
					{
						// ���� ��ġ�� LeftChild�� �ű�
						Current = &(*Current)->LeftChild;
					}
					break;
				}
				// ���� ��ġ�� �̹� Node�� �ְ�, ���� Child�� �̹� Node�� �ִ� ���
				else
				{
					// ���� ��ġ�� Parent�� �ö�
					Current = &(*Current)->Parent;
				}
			}
		}
	}

	if (Root != nullptr)
	{
		// Root�� �������� ������ȸ�ϸ鼭 ���
		cout << Root->Calculation() << '/n';
		Root->DeleteAll();
		delete Root;
	}

	return 0;
}
