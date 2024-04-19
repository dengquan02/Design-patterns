//#include <iostream>
//using namespace std;
//
//
////�ӷ��ࣺ���������Receiver
//class Adder {
//public:
//	//�ӷ�������ÿ�ν������ֵ��num���ӷ����㣬�ٽ��������
//	int add(int value) {
//		num += value;
//		return num;
//	}
//
//private:
//	int num = 0; //�����ʼֵΪ0
//};
//
////����������
//class Command {
//public:
//	virtual int Execute(int value) = 0; //��������ִ�з���execute()
//	virtual int Undo() = 0; //������������undo()
//};
//
////����������
//class ConcreteCommand : public Command {
//public:
//	//ʵ�ֳ�����������������execute()���������üӷ���ļӷ�����
//	int Execute(int value) {
//		this->value = value;
//		return adder.add(value);
//	}
//
//public:
//	//ʵ�ֳ�����������������undo()������ͨ����һ���෴����ʵ�ּӷ����������
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
////�����������ࣺ��������
//class CalculatorForm {
//public:
//	void setCommand(AbstractCommand command) {
//		this.command = command;
//	}
//
//	//������������execute()����ִ������
//	void compute(int value) {
//		int i = command.execute(value);
//		cout << "ִ�����㣬������Ϊ��" << i;
//	}
//	//������������undo()����ִ�г���
//	void undo() {
//		int i = command.undo();
//		cout << "ִ�г�����������Ϊ��" << i;
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