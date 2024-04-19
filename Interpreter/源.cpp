#include <iostream>
#include <string.h>
#include <vector>
#include<sstream>
#include <stdio.h>
using namespace std;


// 环境类（存储一些全局信息）
class Context
{
private:
	
public:
	void assign(string key, string value)
	{
		// 往环境类中设值
	}
	string lookup(string key)
	{
		//获取存储在环境类中的值
	}
};


// 抽象表达式类
class AbstractExpression
{
public:
	virtual void interpret(Context ctx) = 0;
};

// 终结符表达式类
class TerminalExpression : public AbstractExpression
{
public:
	void interpret(Context ctx)
	{
		// 终结符表达式的解释操作

	}
};

// 非终结符表达式类
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
		//递归调用每一个组成部分的interpret()方法
		//在递归调用时指定组成部分的连接方式，即非终结符的功能

	}
};