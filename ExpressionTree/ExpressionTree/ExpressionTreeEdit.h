/*
#pragma once

#include <iostream>
using namespace std;

class ExpressionTree : public BinaryTree<String>
{
public:
	void BuildExpressionTree(const String& strPostFix);

	bool isOperator(char c)
	{
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}

	void PreOrderTraverse(Node* pNode = 0);
	void PostOrderTraverse(Node* pNode = 0);
	void InOrderTraverse(Node* pNode = 0);
	void Visit(Node* pNode = 0);
};

*/