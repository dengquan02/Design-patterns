#include <iostream>
#include <string.h>
#include <vector>
#include<sstream>
#include <stdio.h>
using namespace std;


vector<string> split(string word) //word:待分割的字符串 
{
	//用于存放分割后的字符串 
	vector<string> res;
	//暂存从word中读取的字符串 
	string result;
	//将字符串读到input中 
	stringstream input(word);
	//依次输出到result中，并存入res中 
	while (input >> result)
		res.push_back(result);
	return res;
}

//int x = 0;
////以空格分隔指令字符串
//string* split(string instruction) //instruction:待分割的字符串 
//{
//	//用于存放分割后的字符串 
//	string* res = new string[30];
//	//暂存从word中读取的字符串 
//	string result;
//	//将字符串读到input中 
//	stringstream input(instruction);
//	//依次输出到result中，并存入res中
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
	//输出res 
	for (int idx = 0; idx < res.size(); idx++) {
		cout << res[idx] << endl;
	}

	return 0;
}