//#include <iostream>
//#include <stack>
//#include <string>
//#include <vector>
//#include<sstream>
//using namespace std;
//
//// �ж��ַ����Ƿ�Ϊ����
//bool isNumber(string str)
//{
//	int i = 0;
//	char ch;
//	for (; i < str.length(); i++) {
//		ch = str[++i];
//		if (!isdigit(ch)) {
//			break;
//		}
//	}
//	if (i == str.length()) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
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
//	while (input >> result) {
//		res.push_back(result);
//	}
//	return res;
//}
//
//class StringTokenizer
//{
//private:
//	vector<string> res; //���ڴ�ŷָ����ַ��� 
//	int idx = 0; // ��ǰλ��
//
//public:
//	StringTokenizer(string text)
//	{
//		this->res = split(text);
//	}
//	// �ָ�������
//	int countTokens()
//	{
//		return res.size();
//	}
//	// �����Ƿ��зָ�����ͬhasMoreElemenst
//	bool hasMoreTokens()
//	{
//		int len = countTokens();
//		if (idx < len) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	// ���شӵ�ǰλ�õ���һ���ָ������ո񣩵��ַ���
//	string nextToken()
//	{
//		if (hasMoreTokens()) {
//			return res[idx++];
//		}
//		else {
//			return "";
//		}
//	}
//};
//
//
////�����ࣺ���ڴ洢�Ͳ�����Ҫ���͵���䣬
////�ڱ�ʵ����ÿһ����Ҫ���͵ĵ��ʿ��Գ�Ϊһ���������(Action Token)������
//class Context
//{
//private:
//	StringTokenizer* tokenizer; //StringTokenizer�࣬���ڽ��ַ����ֽ�Ϊ��С���ַ������(Token)��Ĭ��������Կո���Ϊ�ָ���
//	string* currentToken; //��ǰ�ַ������
//
//public:
//	Context(string text)
//	{
//		tokenizer = new StringTokenizer(text);
//		nextToken(); //? ΪcurrentToken��ֵ
//	}
//	//������һ�����
//	string* nextToken()
//	{
//		if (tokenizer->hasMoreTokens()) {
//			this->currentToken = &(tokenizer->nextToken());
//		}
//		else {
//			/*currentToken = "";*/
//			this->currentToken = NULL;
//		}
//		return this->currentToken;
//	}
//	//���ص�ǰ�ı��
//	string* currentToken() {
//		return this->currentToken;
//	}
//	//����һ�����
//	void skipToken(string token) {
//		if (token != *(this->currentToken)) {
//			cout << "������ʾ : " << this->currentToken << "���ʹ���" << endl;
//		}
//		nextToken();
//	}
//	// �����ǰ�ı����һ�����֣��򷵻ض�Ӧ����ֵ
//	int currentNumber()
//	{
//		int num = 0;
//		if (isNumber(*currentToken)) {
//			return stoi(*currentToken);
//		}
//		else {
//			return -1;
//		}
//	}
//};
//
//
//// ������ʽ��
//class Node
//{
//public:
//	virtual void interpret(Context context) = 0; //����һ���������ڽ������
//	virtual void execute() = 0; //����һ����������ִ�б�Ƕ�Ӧ������
//};
//
//
////���ʽ�ڵ��ࣺ���ս�����ʽ
//class ExpressionNode : public Node
//{
//private:
//	vector<Node*> list; //����һ���������ڴ洢��������
//public:
//	void interpret(Context context)
//	{
//		//ѭ������Context�еı��
//		while (true)
//		{
//			//����Ѿ�û���κα�ǣ����˳�����
//			if (context.currentToken() == NULL) {
//				break;
//			}
//			//������END���������ν��͹��̣�����֮��Ľ���
//			else if (*(context.currentToken()) == "END") {
//				context.skipToken("END");
//				break;
//			}
//			//���Ϊ������ǣ�����ͱ�ǲ�������������
//			else {
//				Node* commandNode = new CommandNode();
//				commandNode->interpret(context);
//				list.push_back(commandNode);
//			}
//		}
//	}
//
//	//ѭ��ִ��������е�ÿһ������
//	void execute()
//	{
//		for (int i = 0; i < list.size(); i++) {
//			list[i]->execute();
//		}
//	}
//};
//
//
////�������ڵ��ࣺ���ս�����ʽ
//class CommandNode : public Node
//{
//private:
//	Node* node;
//public:
//	void interpret(Context context)
//	{
//		//����LOOPѭ������
//		if (*(context.currentToken()) == "LOOP") {
//			node = new LoopCommandNode();
//			node->interpret(context);
//		}
//		//����������������
//		else {
//			node = new PrimitiveCommandNode();
//			node->interpret(context);
//		}
//	}
//
//	void execute()
//	{
//		node->execute();
//	}
//};
//
//
////ѭ������ڵ��ࣺ���ս�����ʽ
//class LoopCommandNode : public Node
//{
//private:
//	int number; //ѭ������
//	Node* commandNode; //ѭ������еı��ʽ
//public:
//	void interpret(Context context)
//	{
//		context.skipToken("LOOP");
//		number = context.currentNumber();
//		context.nextToken();
//		commandNode = new ExpressionNode(); //ѭ������еı��ʽ
//		commandNode->interpret(context);
//	}
//
//	void execute()
//	{
//		for (int i = 0; i < number; i++) {
//			commandNode->execute();
//		}
//	}
//};
//
////��������ڵ��ࣺ�ս�����ʽ
//class PrimitiveCommandNode : public Node
//{
//private:
//	string name;
//	string text;
//public:
//	void interpret(Context context)
//	{
//		name = *(context.currentToken());
//		context.skipToken(name);
//		if (name != "PRINT" && name != "BREAK" && name != "SPACE") {
//			cout << "�Ƿ����" << endl;
//		}
//		if (name == "PRINT") {
//			text = *(context.currentToken());
//			context.nextToken();
//		}
//	}
//
//	void execute()
//	{
//		if (name != "PRINT") {
//			cout << text;
//		}
//		else if (name == "SPACE") {
//			cout << " ";
//		}
//		else if (name == "BREAK") {
//			cout << endl;
//		}
//	}
//};
//
//
//int main()
//{
//	string text = "LOOP 2 PRINT ��� SPACE SPACE PRINT С��Ů BREAK END PRINT ���� SPACE SPACE PRINT ����";
//	Context context(text);
//	Node* node = new ExpressionNode();
//	node->interpret(context);
//	node->execute();
//
//	return 0;
//}
//		
//
//		
//		
