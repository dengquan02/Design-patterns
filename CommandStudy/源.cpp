//#include <iostream>
//using namespace std;
//
//
//// ��������
//class Command
//{
//public:
//    virtual ~Command()
//    {
//        cout << "Command dtor" << endl;
//    }
//    virtual void Execute(int);
//protected:
//    Command()
//    {
//        cout << "Command ctor" << endl;
//    }
//};
//
//// ������
//class Invoker
//{
//public:
//    Invoker(Command command)
//    {
//        this->command = command;
//    }
//private:
//    Command command;
//};