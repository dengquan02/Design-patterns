#include <iostream>
#include <string.h>
#include <vector>
#include<sstream>
#include <stdio.h>
using namespace std;


// �����ࣨ�洢һЩȫ����Ϣ��
class Context
{
private:
	
public:
	void assign(string key, string value)
	{
		// ������������ֵ
	}
	string lookup(string key)
	{
		//��ȡ�洢�ڻ������е�ֵ
	}
};


// ������ʽ��
class AbstractExpression
{
public:
	virtual void interpret(Context ctx) = 0;
};

// �ս�����ʽ��
class TerminalExpression : public AbstractExpression
{
public:
	void interpret(Context ctx)
	{
		// �ս�����ʽ�Ľ��Ͳ���

	}
};

// ���ս�����ʽ��
class NonTerminalExpression : public AbstractExpression
{
private:
	AbstractExpression* left;
	AbstractExpression* right;

public:
	NonTerminalExpression(AbstractExpression* left, AbstractExpression* right)
	{
		this->left = left;
		this->right = right;
	}

	void interpret(Context ctx)
	{
		//�ݹ����ÿһ����ɲ��ֵ�interpret()����
		//�ڵݹ����ʱָ����ɲ��ֵ����ӷ�ʽ�������ս���Ĺ���

	}
};