//#include <iostream>
//#include <stack>
//#include <string>
//#include <vector>
//#include<sstream>
//using namespace std;
//
//// 判断字符串是否为数字
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
////以空格分隔指令字符串
//vector<string> split(string instruction) //instruction:待分割的字符串 
//{
//	//用于存放分割后的字符串 
//	vector<string> res;
//	//暂存从word中读取的字符串 
//	string result;
//	//将字符串读到input中 
//	stringstream input(instruction);
//	//依次输出到result中，并存入res中 
//	while (input >> result) {
//		res.push_back(result);
//	}
//	return res;
//}
//
//class StringTokenizer
//{
//private:
//	vector<string> res; //用于存放分割后的字符串 
//	int idx = 0; // 当前位置
//
//public:
//	StringTokenizer(string text)
//	{
//		this->res = split(text);
//	}
//	// 分隔符数量
//	int countTokens()
//	{
//		return res.size();
//	}
//	// 返回是否还有分隔符。同hasMoreElemenst
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
//	// 返回从当前位置到下一个分隔符（空格）的字符串
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
////环境类：用于存储和操作需要解释的语句，
////在本实例中每一个需要解释的单词可以称为一个动作标记(Action Token)或命令
//class Context
//{
//private:
//	StringTokenizer* tokenizer; //StringTokenizer类，用于将字符串分解为更小的字符串标记(Token)，默认情况下以空格作为分隔符
//	string* currentToken; //当前字符串标记
//
//public:
//	Context(string text)
//	{
//		tokenizer = new StringTokenizer(text);
//		nextToken(); //? 为currentToken赋值
//	}
//	//返回下一个标记
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
//	//返回当前的标记
//	string* currentToken() {
//		return this->currentToken;
//	}
//	//跳过一个标记
//	void skipToken(string token) {
//		if (token != *(this->currentToken)) {
//			cout << "错误提示 : " << this->currentToken << "解释错误！" << endl;
//		}
//		nextToken();
//	}
//	// 如果当前的标记是一个数字，则返回对应的数值
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
//// 抽象表达式类
//class Node
//{
//public:
//	virtual void interpret(Context context) = 0; //声明一个方法用于解释语句
//	virtual void execute() = 0; //声明一个方法用于执行标记对应的命令
//};
//
//
////表达式节点类：非终结符表达式
//class ExpressionNode : public Node
//{
//private:
//	vector<Node*> list; //定义一个集合用于存储多条命令
//public:
//	void interpret(Context context)
//	{
//		//循环处理Context中的标记
//		while (true)
//		{
//			//如果已经没有任何标记，则退出解释
//			if (context.currentToken() == NULL) {
//				break;
//			}
//			//不解释END并结束本次解释过程，继续之后的解释
//			else if (*(context.currentToken()) == "END") {
//				context.skipToken("END");
//				break;
//			}
//			//如果为其他标记，则解释标记并将其加入命令集合
//			else {
//				Node* commandNode = new CommandNode();
//				commandNode->interpret(context);
//				list.push_back(commandNode);
//			}
//		}
//	}
//
//	//循环执行命令集合中的每一条命令
//	void execute()
//	{
//		for (int i = 0; i < list.size(); i++) {
//			list[i]->execute();
//		}
//	}
//};
//
//
////语句命令节点类：非终结符表达式
//class CommandNode : public Node
//{
//private:
//	Node* node;
//public:
//	void interpret(Context context)
//	{
//		//处理LOOP循环命令
//		if (*(context.currentToken()) == "LOOP") {
//			node = new LoopCommandNode();
//			node->interpret(context);
//		}
//		//处理其他基本命令
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
////循环命令节点类：非终结符表达式
//class LoopCommandNode : public Node
//{
//private:
//	int number; //循环次数
//	Node* commandNode; //循环语句中的表达式
//public:
//	void interpret(Context context)
//	{
//		context.skipToken("LOOP");
//		number = context.currentNumber();
//		context.nextToken();
//		commandNode = new ExpressionNode(); //循环语句中的表达式
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
////基本命令节点类：终结符表达式
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
//			cout << "非法命令！" << endl;
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
//	string text = "LOOP 2 PRINT 杨过 SPACE SPACE PRINT 小龙女 BREAK END PRINT 郭靖 SPACE SPACE PRINT 黄蓉";
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
