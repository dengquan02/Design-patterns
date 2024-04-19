//#include <iostream>
//#include <stack>
//#include <string>
//#include <vector>
//#include<sstream>
//using namespace std;
//
//// ������ʽ��
//class AbstractNode
//{
//public:
//	virtual string interpret() = 0;
//};
//
//// And���ͣ����ս�����ʽ
//class AndNode : public AbstractNode
//{
//private:
//	AbstractNode* left;//And������ʽ
//	AbstractNode* right;//And���ұ��ʽ
//
//public:
//	AndNode(AbstractNode* left, AbstractNode* right)
//	{
//		this->left = left;
//		this->right = right;
//	}
//	//And���ʽ���Ͳ���
//	string interpret()
//	{
//		//�ݹ����ÿһ����ɲ��ֵ�interpret()����
//		//�ڵݹ����ʱָ����ɲ��ֵ����ӷ�ʽ�������ս���Ĺ���
//		return this->left->interpret() + "��" + this->right->interpret();
//	}
//};
//
//// �򵥾��ӽ��ͣ����ս�����ʽ
//class SentenceNode : public AbstractNode
//{
//private:
//	AbstractNode* direction;
//	AbstractNode* action;
//	AbstractNode* distance;
//
//public:
//	SentenceNode(AbstractNode* direction, AbstractNode* action, AbstractNode* distance)
//	{
//		this->direction = direction;
//		this->action = action;
//		this->distance = distance;
//	}
//	//�򵥾��ӵĽ��Ͳ���
//	string interpret()
//	{
//		return direction->interpret() + action->interpret() + distance->interpret();
//	}
//};
//
//
//// ������ͣ��ս�����ʽ
//class DirectionNode : public AbstractNode
//{
//private:
//	string direction;
//public:
//	DirectionNode(string direction)
//	{
//		this->direction = direction;
//	}
//	//������ʽ�Ľ��Ͳ���
//	string interpret()
//	{
//		if (this->direction == "up") {
//			return "����";
//		}
//		else if (this->direction == "down") {
//			return "����";
//		}
//		else if (this->direction == "left") {
//			return "����";
//		}
//		else if (this->direction == "right") {
//			return "����";
//		}
//		else {
//			return "��Чָ��";
//		}
//	}
//};
//
//// �������ͣ��ս�����ʽ
//class ActionNode : public AbstractNode
//{
//private:
//	string action;
//public:
//	ActionNode(string action)
//	{
//		this->action = action;
//	}
//	//������ʽ�Ľ��Ͳ���
//	string interpret()
//	{
//		if (this->action == "move") {
//			return "�ƶ�";
//		}
//		else if (this->action == "run") {
//			return "�����ƶ�";
//		}
//		else {
//			return "��Чָ��";
//		}
//	}
//};
//
//// ������ͣ��ս�����ʽ
//class DistanceNode : public AbstractNode
//{
//private:
//	string distance;
//public:
//	DistanceNode(string distance)
//	{
//		this->distance = distance;
//	}
//	//������ʽ�Ľ��Ͳ���
//	string interpret()
//	{
//		return this->distance;
//	}
//};
//
//
////�Կո�ָ�ָ���ַ���
//vector<string> split(string instruction) //instruction:���ָ���ַ��� 
//{
//	//���ڴ�ŷָ����ַ��� 
//	vector<string> res;
//	//�ݴ��word�ж�ȡ���ַ��� 
//	string result;
//	//���ַ�������input�� 
//	stringstream input(instruction);
//	//���������result�У�������res�� 
//	while (input >> result)
//		res.push_back(result);
//	return res;
//}
//
//// ָ����ࣺ������
//class InstructionHandler
//{
//private:
//	string instruction;
//	AbstractNode* node;
//
//public:
//	void handle(string instruction)
//	{
//		AbstractNode* left = NULL, * right = NULL;
//		AbstractNode* direction = NULL, * action = NULL, * distance = NULL;
//		stack<AbstractNode*> s;//����һ��ջ�������ڴ洢�����﷨��
//		//�Կո�ָ�ָ���ַ���
//		vector<string> words = split(instruction);
//		//��ʵ������ջ�ķ�ʽ������ָ��
//		for (int idx = 0; idx < words.size(); idx++) {
//			//������and���������3��������Ϊ3���ս������һ��SentenceNode��Ϊ��and�����ұ��ʽ��������ջ�������ı��ʽ��Ϊ��and��������ʽ������µġ�and�����ʽѹ��ջ�С�
//			if (words[idx] == "and") {
//				left = s.top();
//				s.pop();
//				string word1 = words[++idx];
//				direction = new DirectionNode(word1);
//				string word2 = words[++idx];
//				action = new ActionNode(word2);
//				string word3 = words[++idx];
//				distance = new DistanceNode(word3);
//				right = new SentenceNode(direction, action, distance);
//				s.push(new AndNode(left, right));
//			}
//			//�����ͷ��ʼ���ͣ���ǰ3����������һ��SentenceNode����ѹ��ջ��
//			else {
//				string word1 = words[idx];
//				direction = new DirectionNode(word1);
//				string word2 = words[++idx];
//				action = new ActionNode(word2);
//				string word3 = words[++idx];
//				distance = new DistanceNode(word3);
//				left = new SentenceNode(direction, action, distance);
//				s.push(left);
//			}
//		}
//		this->node = s.top();
//		s.pop();
//	}
//	string output()
//	{
//		string result = this->node->interpret();
//		return result;
//	}
//};
//
//
////int main()
////{
////	string instruction = "up move 5 and down run 10 and left move 5";
////	InstructionHandler hander;
////	hander.handle(instruction);
////	string outString;
////	outString = hander.output();
////	cout << outString << endl;
////
////	return 0;
////}