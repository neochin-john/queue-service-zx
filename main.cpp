#include <iostream>
#include <string>
#include <regex>
#include"user.h"
#include "window.h"

using namespace std;

std::string ltrim(const std::string& s) {
	return std::regex_replace(s, std::regex("^\\s + "), std::string(""));
}

std::string rtrim(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string replaceSpace(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+"), std::string(" "), std::regex_constants::match_any);
}

std::string trim(const std::string& s) {
	return replaceSpace(ltrim(rtrim(s)));
}

static void run()
{
	string a;
	std::cout << ">";
	while (std::getline(cin, a))
	{
		a = trim(a);
		size_t pos = a.find_first_of(' ', 0);
		//cout << pos << endl;
		string cmdStr = a.substr(0, pos);
		string argStr = a.substr(pos + 1, a.length() - pos - 1);
		cout << cmdStr << endl;
		cout << argStr << endl;
		cout << ">";
		break;
	}

}
int main()
{
	run();

	return 0;
}