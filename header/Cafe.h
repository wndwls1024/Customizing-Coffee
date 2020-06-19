#pragma once
#include <map>
#include <string>
using namespace std;
//#include "_Coffee.h"
//#include "_Ingredient.h"

class Cafe
{
protected:
	//static _Coffee ingredient;
	map<string,int> bean;
	map<string,bool> method;
	map<string,int> extra;
	void set_bean();
	void set_method();
	void set_extra();
	static int ordered_coffee;	//주문한 커피 수
public:
	Cafe();
	static std::map<string, int> ingredient;	//재료의 양
	static std::map<string, bool> possible_method;	//가능한 추출 방법
	void basic_menu();
	static void set_ingredient();
	virtual void order();		//주문 기능 (Custermizer에서 구현)
	virtual void my_menu();
	virtual void member_menu();	//회원가입 및 로그인에서 사용할 메뉴
	~Cafe();
};
