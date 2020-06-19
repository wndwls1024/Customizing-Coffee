#pragma once
#include "Member.h"

class Customizer
	:public Member
{
private:
	bool bean_check = true;
	bool extra_check = true;
	bool method_check = true;
public:
	Customizer();
	void bean_menu();
	void method_menu();
	void extra_menu();
	void set_bean(int cnt);	//커피 원두 선택 함수
	void set_method();	//커피 추출 방법을 선택할 함수
	void set_extra(int cnt);		//extra 요소들을 추가할 함수
	~Customizer();
	void save();
	virtual void order();
	virtual void my_menu();
};
