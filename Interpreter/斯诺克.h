#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include<sstream>
using namespace std;

// ������ʽ��
class AbstractNode
{
public:
	virtual string interpret() = 0;
};

// And���ͣ����ս�����ʽ
class AndNode : public AbstractNode
{
private:
	AbstractNode* left;//And������ʽ
	AbstractNode* right;//And���ұ��ʽ

public:
	AndNode(AbstractNode* left, AbstractNode* right)
	{
		this->left = left;
		this->right = right;
	}
	//And���ʽ���Ͳ���
	string interpret()
	{
		//�ݹ����ÿһ����ɲ��ֵ�interpret()����
		//�ڵݹ����ʱָ����ɲ��ֵ����ӷ�ʽ�������ս���Ĺ���
		return this->left->interpret() + "��" + this->right->interpret();
	}
};

// �򵥾��ӽ��ͣ����ս�����ʽ
class SentenceNode : public AbstractNode
{
private:
	AbstractNode* action;
	AbstractNode* position;
	AbstractNode* tactics;

public:
	SentenceNode(AbstractNode* action, AbstractNode* position, AbstractNode* tactics)
	{
		this->action = action;
		this->position = position;
		this->tactics = tactics;
	}
	//�򵥾��ӵĽ��Ͳ���
	string interpret()
	{
		return action->interpret() + " " + position->interpret() + " " + tactics->interpret();
	}
};



// ���������򷽷�������˦���̡��ף����ͣ��ս�����ʽ
class ActionNode : public AbstractNode
{
private:
	string action;
public:
	ActionNode(string action)
	{
		this->action = action;
	}
	//������ʽ�Ľ��Ͳ���
	string interpret()
	{
		if (this->action == "1") { 
			return "flip";
		}
		else if (this->action == "2") {
			return "toss";
		}
		else if (this->action == "3") {
			return "stab";
		}
		else if (this->action == "4") {
			return "throw";
		}
		else {
			return "Invalid instructions";
		}
	}
};

// ����Ŀ����ͣ��ս�����ʽ
class PositionNode : public AbstractNode
{
private:
	string position;
public:
	PositionNode(string position)
	{
		this->position = position;
	}
	//������ʽ�Ľ��Ͳ���
	string interpret()
	{
		return "the No." + position + " ball";
	}
};


// ������ͣ��ս�����ʽ
// �����귨����λ��x��
class TacticsNode : public AbstractNode
{
private:
	string tactics;
public:
	TacticsNode(string tactics)
	{
		this->tactics = to_string(atoi(tactics.c_str()) % 360);
	}
	//������ʽ�Ľ��Ͳ���
	string interpret()
	{
		return "at " + this->tactics + " azimuth";
	}
};


//�Կո�ָ�ָ���ַ���
vector<string> split(string instruction) //instruction:���ָ���ַ��� 
{
	//���ڴ�ŷָ����ַ��� 
	vector<string> res;
	//�ݴ��word�ж�ȡ���ַ��� 
	string result;
	//���ַ�������input�� 
	stringstream input(instruction);
	//���������result�У�������res�� 
	while (input >> result)
		res.push_back(result);
	return res;
}

// ָ����ࣺ������
class InstructionHandler
{
private:
	string instruction;
	AbstractNode* node;

public:
	void handle(string instruction)
	{
		AbstractNode* left = NULL, * right = NULL;
		AbstractNode* tactics = NULL, * action = NULL, * position = NULL;
		stack<AbstractNode*> s;//����һ��ջ�������ڴ洢�����﷨��
		//�Կո�ָ�ָ���ַ���
		vector<string> words = split(instruction);
		//��ʵ������ջ�ķ�ʽ������ָ��
		for (int idx = 0; idx < words.size(); idx += 3) {
			//������and���������3��������Ϊ3���ս������һ��SentenceNode��Ϊ��and�����ұ��ʽ��������ջ�������ı��ʽ��Ϊ��and��������ʽ������µġ�and�����ʽѹ��ջ�С�
			if (words[idx] == "and") {
				idx++;
				left = s.top();
				s.pop();
				string word1 = words[idx];
				action = new ActionNode(word1);
				string word2 = words[idx + 1];
				position = new PositionNode(word2);
				string word3 = words[idx + 2];
				tactics = new TacticsNode(word3);
				right = new SentenceNode(action, position, tactics);
				s.push(new AndNode(left, right));
			}
			//�����ͷ��ʼ���ͣ���ǰ3����������һ��SentenceNode����ѹ��ջ��
			else {
				string word1 = words[idx];
				action = new ActionNode(word1);
				string word2 = words[idx + 1];
				position = new PositionNode(word2);
				string word3 = words[idx + 2];
				tactics = new TacticsNode(word3);
				left = new SentenceNode(action, position, tactics);
				s.push(left);
			}
		}
		this->node = s.top();
		s.pop();
	}
	string output()
	{
		string result = this->node->interpret();
		return result;
	}
};