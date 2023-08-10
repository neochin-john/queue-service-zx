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
	case State::IDLE: return "����";
	case State::CLOSED: return "�ر�";
	case State::PROCESSING: return "������";
	default: return "δ֪";
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
	//��ǰû�д���
	if (count == 0)
	{
		cout << "��ǰû�з��񴰿�" << endl;
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
	string name = "����" + to_string(windows.size() + 1);
	Window win = { State::IDLE, name, ""};
	windows.push_back(win);
	cout << "��Ӵ��ڳɹ������Ϊ" << std::quoted(name) << endl;
}

void Window::closewindow()
{

	//service close 4���رմ��� 4��ֻ�п���״̬�Ĵ��ڲ��ܱ��رա��رճɹ�����״̬Ϊ�رա�
	switch (state)
	{
	case idle:
		cout << "�رմ���4�ɹ�" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case close:
		cout << "����4���ǹر�״̬" << endl;
		break;
	case processing:
		cout << "�رմ���4ʧ�ܣ��ô������ڴ���ҵ��" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case absent:
		cout << "�رմ���4ʧ�ܣ��ô��ڲ�����" << endl;
		break;
	}
}

void Window::idlewindow()
{
	//service idle 4�����ô��� 4 Ϊ���С�ֻ�д����еĿ���ֵ���С��ÿ��гɹ�����
		//״̬Ϊ���С�
	switch (state)
	{
	case idle:
		cout << "����4���ǿ���״̬" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case close:
		cout << "�ô���4����ʧ�ܣ��ô���Ϊ�ر�״̬" << endl;
		break;
	case absent:
		cout << "�ô���4����ʧ�ܣ��ô��ڲ�����" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case processing:
		cout << "�ô���4���гɹ�" << endl;
		break;
	}
}

void Window::callwindow()
{
	/*service callnext 4, ���� 4 ������һ���û�����ҵ���������������һ���û�����
��״̬Ϊ�����У��б���ʾΪ�û��ı�š����û�еȴ��û�������״̬Ϊ���С�
ֻ�д����кͿ���״̬���Ժ�����һ���û��������ǰ�������ڴ����У���ô������
һ���ͻ��Ĵ�����������һ������ǰΪ�����У�������һ��������ʾ����
C003������ϣ���C004�ŵ�����4����ҵ��*/
	switch (state)
	{
	case idle:
		cout << "��C004�ŵ�����4����ҵ��" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case 2://û����һ���û�
		cout << "��ǰû���û���Ҫ����ҵ��" << endl;
		break;
	case close:
		cout << "����4����ʧ�ܣ��ô���Ϊ�ر�״̬" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case absent:
		cout << "����4����ʧ�ܣ��ô��ڲ�����" << endl;
		break;
	}
}


void Window::openwindow()
{
	//service open 4���򿪴��� 4��ֻ�йر�״̬���ܱ��򿪡��򿪳ɹ�����״̬Ϊ���С�
	switch (state)
	{
	case idle://���У��������ڴ���ҵ��
		cout << "����4���Ǵ�״̬" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case processing://���У��������ڴ���ҵ��
		cout << "����4���Ǵ�״̬" << endl; // ��ӡ "1"
		break;       // Ȼ���˳� switch
	case close://�ر�
		cout << "�򿪴���4�ɹ�" << endl;
		break;
	case absent://������
		cout << "�򿪴���4ʧ�ܣ��ô��ڲ�����" << endl; // ��ӡ "1"
		break;
	}// Ȼ���˳� switch
}

