//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//// 抽象命令
//class Command
//{
//public:
//    virtual ~Command() 
//    {
//        cout << "Command dtor" << endl;
//    }
//    virtual void Execute(int[2], int) = 0;
//
//protected:
//    Command() 
//    {
//        cout << "Command ctor" << endl;
//    }
//};
//
////// 输入命令
////class InputCommand : public Command
////{
////public:
////	InputCommand(const string& input)
////	{
////		mInput = input;
////	}
////	~InputCommand() {}
////	void Execute()
////	{
////		printf("current string: %s\n", mInput.c_str());
////		//cout << "当前比分 : " << 
////	}
////private:
////	string mInput;	// receiver
////};
//
//template <class Receiver>
//class SimpleCommand : public Command
//{
//public:
//	typedef void (Receiver::* Action)(int flag, int point);
//	SimpleCommand(Receiver* r, Action a) : _receiver(r), _action(a) {}
//	virtual void Execute(int, int);
//private:
//	Action _action;
//	Receiver* _receiver;
//};
//
//template <class Receiver>
//void SimpleCommand<Receiver>::Execute(int flag, int point)
//{
//	(_receiver->*_action)(point);
//}
//
//// 分数类 SimpleCommand<Point>(...)
//class Point
//{
//public:
//	Point()
//	{
//		this->score[0] = 0;
//		this->score[1] = 0;
//	}
//	void Action(int flag, int point)	
//	{
//		if (flag == 0) {	// 主队
//			this->score[0] += point;
//			if (point > 0) {
//				cout << "主队得" << point << "分" << endl;
//			}
//			cout << "当前比分为 : " << this->score[0] << ":" << this->score[1] << endl;
//		}
//		else if (flag == 1) {	// 客队
//			this->score[1] += point;
//			if (point > 0) {
//				cout << "客队得" << point << "分" << endl;
//			}
//			cout << "当前比分为 : " << this->score[0] << ":" << this->score[1] << endl;
//		}
//	}
//private:
//	int score[2];
//};
//
//// 主队得分 SimpleCommand<HostPoint>(...)
//class HostPoint
//{
//public:
//	void Action(int score[2], int point)
//	{
//		score[0] += point;
//		cout << "主队得" << point << "分" << endl;
//		cout << "当前比分为 : " << score[0] << ":" << score[1] << endl;
//	}
//};
//// 客队得分 SimpleCommand<GuestPoint>(...)
//class GuestPoint
//{
//public:
//	void Action(int score[2], int point)
//	{
//		score[1] += point;
//		cout << "客队得" << point << "分" << endl;
//		cout << "当前比分为 : " << score[0] << ":" << score[1] << endl;
//	}
//};
//
//
//class Commander
//{
//public:
//	Commander(Command* pcmd)
//	{
//		//最初的命令数据
//		// 最初的比分
//		mUndo.push(pcmd);
//	}
//	~Commander()
//	{
//		while (false == mUndo.empty())
//		{
//			delete mUndo.top();
//			mUndo.pop();
//		}
//		while (false == mRedo.empty())
//		{
//			delete mRedo.top();
//			mRedo.pop();
//		}
//	}
//
//	void ExecuteCommand(Command* pCmd, int point)
//	{
//		pCmd->Execute(point);
//		mUndo.push(score);
//	}
//
//	void Undo()
//	{
//		if (mUndo.size() < 2)
//		{
//			//无法后退撤销没有数据
//			printf("undo failed.\n");
//			return;
//		}
//		printf("undo:\n");
//
//		//当前命令
//		//auto pCmd = mUndo.top();
//		// 当前分数
//		int score[2] = { scoreA, scoreB };
//
//		//保存当前命令
//		//mRedo.push(pCmd);
//		// 保存当前比分
//		mRedo.push(score);
//
//		//弹出
//		mUndo.pop();
//
//		//还原到上个命令
//		//pCmd = mUndo.top();
//		// 还原到上个比分
//		scoreA = mUndo.top()[0];
//		scoreB = mUndo.top()[1];
//
//		pCmd->Execute();
//	}
//
//	void Redo()
//	{
//		if (mRedo.empty())
//		{
//			//无法前进重做没有数据
//			printf("redo failed.\n");
//			return;
//		}
//
//		printf("redo:\n");
//
//		auto pCmd = mRedo.top();
//
//		pCmd->Execute();
//
//		mRedo.pop();
//
//		mUndo.push(pCmd);
//	}
//
//private:
//	stack< Command* > mUndo;
//	stack< Command* > mRedo;
//};
//
//
////模拟输入字符串,然后对输入的字符串进行undo redo操作
////你可以打开有undo redo功能的文本编辑程序测试是否是这样
////这里记录的是完整记录,即:即便在undo 或 redo 过程中又发生数据改变
////也会记录,如果不想这样在undo 或者 redo 输入新字符串时 将redo清空即可
////即认为在历史记录中修改值被认为是最新的值，不需要再redo
//int main()
//{
//	// for test
//
//
//
//	////默认没有输入字符串可以是空，这里为了演示赋值一个特殊的字符串
//	//Commander* p = new Commander(new InputCommand("[empty]"));
//
//	////输入1234
//	//p->ExecuteCommand(new InputCommand("1234"));
//	////输入567
//	//p->ExecuteCommand(new InputCommand("567"));
//	////输入xxx
//	//p->ExecuteCommand(new InputCommand("xxx"));
//
//	////执行一次undo 撤销到 567
//	//p->Undo();
//	////执行一次undo 撤销到 1234
//	//p->Undo();
//
//	////undo后中间输入新字符串 insert 覆盖 1234
//	//p->ExecuteCommand(new InputCommand("insert"));
//
//	////执行一次undo 撤销到 1234
//	//p->Undo();
//
//	////执行一次undo 撤销到最初情况 [empty]
//	//p->Undo();
//
//	////执行失败已经undo 到最原始情况
//	//p->Undo();
//
//	////执行一次redo 重做到 1234
//	//p->Redo();
//	////执行一次redo 重做到 insert
//	//p->Redo();
//	////执行一次redo 重做到 567
//	//p->Redo();
//
//	////redo后中间输入新字符串 insert again 覆盖 567
//	//p->ExecuteCommand(new InputCommand("insert again"));
//
//	////执行一次undo 撤销到567
//	//p->Undo();
//
//	////执行一次redo 重做到 insert again
//	//p->Redo();
//
//	////执行一次redo 重做到 xxx
//	//p->Redo();
//
//	////执行失败已经redo 到最新情况
//	//p->Redo();
//	//delete p;
//	return 0;
//}