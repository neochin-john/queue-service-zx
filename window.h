#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <queue>
#include <list>
#include <vector>

enum class State {
	IDLE, CLOSED, PROCESSING
};

struct Window {
	State state;
	std::string name;
	std::string userNo;

	std::string StateStr();
};

class WindowMgr
{
private:
	std::vector<Window> windows;

public:
	void DoCmd(std::string cmd, std::string args);
	void ListWindow();
	void AddWindow();
	void CloseWindow(int windowId);
	void OpenWindow(int windowId);
	void IdleWindow(int windowId);
	void CallWindow(int windowId);
};