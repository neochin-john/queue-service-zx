#include "window.h"
#include "user.h"
#include <iostream>
#include <string>
#include <regex>
#include <queue>
#include <list>
#include <iomanip>
using namespace std;

string Window::StateStr() {
	switch (state) {
	case State::IDLE: return "空闲";
	case State::CLOSED: return "关闭";
	case State::PROCESSING: return "处理中";
	default: return "未知";
	}
}


void Window::windowoperation(string cmdStr, string orgStr)
{
	auto ios(string a);
	if (cmdStr == "service" && orgStr == "list")
	{
		viewwindow(state, nowwindowcount);
	}
	if (cmdStr == "service" && orgStr == "add")
	{
		addwindow(state, nowwindowcount);
	}
	if (cmdStr == "service" && orgStr == "close 1")
	{
		closewindow();
	}
	if (cmdStr == "service" && orgStr == "open 1")
	{
		openwindow();
	}
	if (cmdStr == "service" && orgStr == "idle 4")
	{
		idlewindow();
	}
	if (cmdStr == "service" && orgStr == "callnext 4")
	{
		callwindow();
	}
}

void WindowMgr::ListWindow()
{
	size_t count = windows.size();
	//当前没有窗口
	if (count == 0)
	{
		cout << "当前没有服务窗口" << endl;
		return;
	}

	for (auto &window : windows)
	{
		if (window.state == State::PROCESSING) {
			cout << window.name << "\t" << window.userNo << endl;
		}
		else {
			cout << window.name << "\t" << window.StateStr() << endl;
		}
	}
}

void WindowMgr::AddWindow()
{
	string name = "窗口" + to_string(windows.size() + 1);
	Window win = { State::IDLE, name, ""};
	windows.push_back(win);
	cout << "添加窗口成功，编号为" << std::quoted(name) << endl;
}

void Window::closewindow()
{

	//service close 4，关闭窗口 4。只有空闲状态的窗口才能被关闭。关闭成功后置状态为关闭。
	switch (state)
	{
	case idle:
		cout << "关闭窗口4成功" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case close:
		cout << "窗口4已是关闭状态" << endl;
		break;
	case processing:
		cout << "关闭窗口4失败，该窗口正在处理业务" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case absent:
		cout << "关闭窗口4失败，该窗口不存在" << endl;
		break;
	}
}

void Window::idlewindow()
{
	//service idle 4，设置窗口 4 为空闲。只有处理中的可以值空闲。置空闲成功后，置
		//状态为空闲。
	switch (state)
	{
	case idle:
		cout << "窗口4已是空闲状态" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case close:
		cout << "置窗口4空闲失败，该窗口为关闭状态" << endl;
		break;
	case absent:
		cout << "置窗口4空闲失败，该窗口不存在" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case processing:
		cout << "置窗口4空闲成功" << endl;
		break;
	}
}

void Window::callwindow()
{
	/*service callnext 4, 窗口 4 呼叫下一个用户处理业务。如果队列中有下一个用户，则
置状态为处理中，列表显示为用户的编号。如果没有等待用户，则置状态为空闲。
只有处理中和空闲状态可以呼叫下一个用户。如果当前窗口正在处理中，那么结束上
一个客户的处理，并呼叫下一个。当前为处理中，呼叫下一个，返回示例：
C003处理完毕，请C004号到窗口4办理业务*/
	switch (state)
	{
	case idle:
		cout << "请C004号到窗口4办理业务" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case 2://没有下一个用户
		cout << "当前没有用户需要办理业务" << endl;
		break;
	case close:
		cout << "窗口4呼叫失败，该窗口为关闭状态" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case absent:
		cout << "窗口4呼叫失败，该窗口不存在" << endl;
		break;
	}
}


void Window::openwindow()
{
	//service open 4，打开窗口 4。只有关闭状态才能被打开。打开成功后置状态为空闲。
	switch (state)
	{
	case idle://空闲，或者正在处理业务
		cout << "窗口4已是打开状态" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case processing://空闲，或者正在处理业务
		cout << "窗口4已是打开状态" << endl; // 打印 "1"
		break;       // 然后退出 switch
	case close://关闭
		cout << "打开窗口4成功" << endl;
		break;
	case absent://不存在
		cout << "打开窗口4失败，该窗口不存在" << endl; // 打印 "1"
		break;
	}// 然后退出 switch
}

