#include <iostream>
#include <string.h>
#include <vector>
#include<sstream>
#include <stdio.h>
using namespace std;


vector<string> split(string word) //word:���ָ���ַ��� 
{
	//���ڴ�ŷָ����ַ��� 
	vector<string> res;
	//�ݴ��word�ж�ȡ���ַ��� 
	string result;
	//���ַ�������input�� 
	stringstream input(word);
	//���������result�У�������res�� 
	while (input >> result)
		res.push_back(result);
	return res;
}

//int x = 0;
////�Կո�ָ�ָ���ַ���
//string* split(string instruction) //instruction:���ָ���ַ��� 
//{
//	//���ڴ�ŷָ����ַ��� 
//	string* res = new string[30];
//	//�ݴ��word�ж�ȡ���ַ��� 
//	string result;
//	//���ַ�������input�� 
//	stringstream input(instruction);
//	//���������result�У�������res��
//	for (; input >> result; x++) {
//		res[x] = result;
//	}
//	return res;
//}


int main()
{
	string word = "   Hello, I want   to learn C++!   ";
	vector<string> res = split(word);
	//string* res = split(word);
	//���res 
	for (int idx = 0; idx < res.size(); idx++) {
		cout << res[idx] << endl;
	}

	return 0;
}