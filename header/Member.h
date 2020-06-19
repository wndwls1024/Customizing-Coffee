#pragma once
#include <string>
#include "Level.h"
using namespace std;

class Member
	:public Level
{
private:
	string name = "";
	string gender = "";
	string phone = "";
public:
	Member();
	string member_id = "";
	string nickname = "";
	virtual void member_menu();
	void join();
	bool login();
	void modify();
	~Member();
};
