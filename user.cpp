#include <iostream>
#include <string>
#include <regex>
#include<vector>
#include"user.h"
#include <queue>
using namespace std;




void User::queueoperation(string cmdStr, string orgStr)
{
	auto ios(string a);
	if (cmdStr == "queue" && orgStr == "wait list")
	{

	}
	if (cmdStr == "queue" && orgStr == "history list")
	{

	}
	if (cmdStr == "queue" && orgStr == "processing list")
	{

	}
	if (cmdStr == "queue" && orgStr == "wait add normal")
	{

	}
	if (cmdStr == "queue" && orgStr == "wait add vip")
	{

	}
}



void User::waitqueue()
{
	std::list<int>waitqueuelist;
	//判断为空
	if (waitqueuelist.begin() == waitqueuelist.end())
	{
		cout << "该排队队列为空" << endl;
	}

	if (waitqueuelist.size() == 3)
	{

		auto iter = waitqueuelist.begin();
		//访问第3个元素
		for (int i = 0; i < 3; ++i) {
			++iter;
		}
		//获取第3个元素的值
		/*if (*iter != )
		{

		}*/

	}

	//输出排队队列
	for (std::list<int>::iterator it = waitqueuelist.begin(); it != waitqueuelist.end(); ++it) {
		std::cout << *it << endl;
	}
}



void User::processedqueue(int stateu, int nnumber)
{


}

void User::processingqueue()
{

}

void User::offernumber()
{
	std::list<int>waitqueuelist;

}
