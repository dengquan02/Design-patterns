//#include <iostream>
//using namespace std;
//
//
//// ³éÏóÃüÁî
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
//// ÇëÇóÕß
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