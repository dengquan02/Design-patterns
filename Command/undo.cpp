//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//// ��������
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
////// ��������
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
////		//cout << "��ǰ�ȷ� : " << 
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
//// ������ SimpleCommand<Point>(...)
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
//		if (flag == 0) {	// ����
//			this->score[0] += point;
//			if (point > 0) {
//				cout << "���ӵ�" << point << "��" << endl;
//			}
//			cout << "��ǰ�ȷ�Ϊ : " << this->score[0] << ":" << this->score[1] << endl;
//		}
//		else if (flag == 1) {	// �Ͷ�
//			this->score[1] += point;
//			if (point > 0) {
//				cout << "�Ͷӵ�" << point << "��" << endl;
//			}
//			cout << "��ǰ�ȷ�Ϊ : " << this->score[0] << ":" << this->score[1] << endl;
//		}
//	}
//private:
//	int score[2];
//};
//
//// ���ӵ÷� SimpleCommand<HostPoint>(...)
//class HostPoint
//{
//public:
//	void Action(int score[2], int point)
//	{
//		score[0] += point;
//		cout << "���ӵ�" << point << "��" << endl;
//		cout << "��ǰ�ȷ�Ϊ : " << score[0] << ":" << score[1] << endl;
//	}
//};
//// �Ͷӵ÷� SimpleCommand<GuestPoint>(...)
//class GuestPoint
//{
//public:
//	void Action(int score[2], int point)
//	{
//		score[1] += point;
//		cout << "�Ͷӵ�" << point << "��" << endl;
//		cout << "��ǰ�ȷ�Ϊ : " << score[0] << ":" << score[1] << endl;
//	}
//};
//
//
//class Commander
//{
//public:
//	Commander(Command* pcmd)
//	{
//		//�������������
//		// ����ıȷ�
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
//			//�޷����˳���û������
//			printf("undo failed.\n");
//			return;
//		}
//		printf("undo:\n");
//
//		//��ǰ����
//		//auto pCmd = mUndo.top();
//		// ��ǰ����
//		int score[2] = { scoreA, scoreB };
//
//		//���浱ǰ����
//		//mRedo.push(pCmd);
//		// ���浱ǰ�ȷ�
//		mRedo.push(score);
//
//		//����
//		mUndo.pop();
//
//		//��ԭ���ϸ�����
//		//pCmd = mUndo.top();
//		// ��ԭ���ϸ��ȷ�
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
//			//�޷�ǰ������û������
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
////ģ�������ַ���,Ȼ���������ַ�������undo redo����
////����Դ���undo redo���ܵ��ı��༭��������Ƿ�������
////�����¼����������¼,��:������undo �� redo �������ַ������ݸı�
////Ҳ���¼,�������������undo ���� redo �������ַ���ʱ ��redo��ռ���
////����Ϊ����ʷ��¼���޸�ֵ����Ϊ�����µ�ֵ������Ҫ��redo
//int main()
//{
//	// for test
//
//
//
//	////Ĭ��û�������ַ��������ǿգ�����Ϊ����ʾ��ֵһ��������ַ���
//	//Commander* p = new Commander(new InputCommand("[empty]"));
//
//	////����1234
//	//p->ExecuteCommand(new InputCommand("1234"));
//	////����567
//	//p->ExecuteCommand(new InputCommand("567"));
//	////����xxx
//	//p->ExecuteCommand(new InputCommand("xxx"));
//
//	////ִ��һ��undo ������ 567
//	//p->Undo();
//	////ִ��һ��undo ������ 1234
//	//p->Undo();
//
//	////undo���м��������ַ��� insert ���� 1234
//	//p->ExecuteCommand(new InputCommand("insert"));
//
//	////ִ��һ��undo ������ 1234
//	//p->Undo();
//
//	////ִ��һ��undo ������������ [empty]
//	//p->Undo();
//
//	////ִ��ʧ���Ѿ�undo ����ԭʼ���
//	//p->Undo();
//
//	////ִ��һ��redo ������ 1234
//	//p->Redo();
//	////ִ��һ��redo ������ insert
//	//p->Redo();
//	////ִ��һ��redo ������ 567
//	//p->Redo();
//
//	////redo���м��������ַ��� insert again ���� 567
//	//p->ExecuteCommand(new InputCommand("insert again"));
//
//	////ִ��һ��undo ������567
//	//p->Undo();
//
//	////ִ��һ��redo ������ insert again
//	//p->Redo();
//
//	////ִ��һ��redo ������ xxx
//	//p->Redo();
//
//	////ִ��ʧ���Ѿ�redo ���������
//	//p->Redo();
//	//delete p;
//	return 0;
//}