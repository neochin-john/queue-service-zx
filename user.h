#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <list>
using namespace std;
typedef enum stateu { wait, processe, processi, } stateu;
class User
{
private:



public:
	void queueoperation(string cmdStr, string orgStr);

	void  waitqueue();
	void processedqueue(int stateu, int nnumber);
	void  processingqueue();
	void  offernumber();
};
class NormalUser :public User
{
private:
	char nc = 'C';
	int nnumber = 1;


public:
	void GenerateNumber(char nc, int nnumber = 1);
	void autoarrange();
};
class VipUser :public User
{
private:
	char vc = 'A';
	int vnumber = 1;

public:
	void GeneratevNumber(char vc, int vnumber = 1);
	void autoarrange();
};
