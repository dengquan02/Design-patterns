//#include <iostream>
//using namespace std;
//
//
////加法类：请求接收者Receiver
//class Adder {
//public:
//	//加法操作，每次将传入的值与num作加法运算，再将结果返回
//	int add(int value) {
//		num += value;
//		return num;
//	}
//
//private:
//	int num = 0; //定义初始值为0
//};
//
////抽象命令类
//class Command {
//public:
//	virtual int Execute(int value) = 0; //声明命令执行方法execute()
//	virtual int Undo() = 0; //声明撤销方法undo()
//};
//
////具体命令类
//class ConcreteCommand : public Command {
//public:
//	//实现抽象命令类中声明的execute()方法，调用加法类的加法操作
//	int Execute(int value) {
//		this->value = value;
//		return adder.add(value);
//	}
//
//public:
//	//实现抽象命令类中声明的undo()方法，通过加一个相反数来实现加法的逆向操作
//	int undo() {
//		return adder.add(-value);
//	}
//
//private:
//	Adder adder = new Adder();	// receiver
//	int value;	// 
//};
//
//
////计算器界面类：请求发送者
//class CalculatorForm {
//public:
//	void setCommand(AbstractCommand command) {
//		this.command = command;
//	}
//
//	//调用命令对象的execute()方法执行运算
//	void compute(int value) {
//		int i = command.execute(value);
//		cout << "执行运算，运算结果为：" << i;
//	}
//	//调用命令对象的undo()方法执行撤销
//	void undo() {
//		int i = command.undo();
//		cout << "执行撤销，运算结果为：" << i;
//	}
//
//private:
//	Command command;
//};
//
//
//
//int main()
//{
//	cout << "Hello World!";
//
//	return 0;
//}