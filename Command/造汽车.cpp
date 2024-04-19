//#include <iostream>
//#include <vector>
//using namespace std;
//
//// ������
//class Receiver
//{
//public:
//	void makeElectricCar()
//	{
//		cout << "An electric car is made." << endl;
//	}
//	void makeOilCar()
//	{
//		cout << "An oil car is made." << endl;
//	}
//};
//
//// ����������
//class Command
//{
//protected:
//	Receiver* receiver;
//public:
//	virtual void executeCMD() = 0;
//};
//
//// �糵������
//class ElectricCarCMD : public Command
//{
//public:
//	ElectricCarCMD(Receiver* receiver)
//	{
//		this->receiver = receiver;
//	}
//	void executeCMD()
//	{
//		this->receiver->makeElectricCar();
//	}
//};
//
//// ����������
//class OilCarCMD : public Command
//{
//public:
//	OilCarCMD(Receiver* receiver)
//	{
//		this->receiver = receiver;
//	}
//	void executeCMD()
//	{
//		this->receiver->makeOilCar();
//	}
//};
//
//// ������
//class Invoker
//{
//private:
//	vector<Command*> commands_vec; // ��������
//public:
//	//Add, remove, notify
//	void add(Command* cmd)
//	{
//		this->commands_vec.push_back(cmd);
//	}
//	void remove(Command* cmd)
//	{
//		vector<Command*>::iterator it;
//		for (it = this->commands_vec.begin(); it != this->commands_vec.end();)
//		{
//			if (*it == cmd)
//			{
//				it = this->commands_vec.erase(it);
//			}
//			else
//			{
//				it++;
//			}
//		}
//	}
//	void notify()
//	{
//		vector<Command*>::iterator it;
//		for (it = this->commands_vec.begin(); it != this->commands_vec.end(); it++)
//		{
//			(*it)->executeCMD();
//		}
//	}
//};
//
//
//
//// �����ͻ���
//int main()
//{
//	Receiver* receiver = new Receiver();
//	Command* electricCar = new ElectricCarCMD(receiver);
//	Command* oilCar = new OilCarCMD(receiver);
//	Invoker* invoker = new Invoker();
//	cout << "******************************************" << endl;
//	invoker->add(electricCar);
//	invoker->add(oilCar);
//	invoker->notify();
//	cout << "******************************************" << endl;
//	invoker->remove(electricCar);
//	invoker->notify();
//}
