#include "Level.h"
#include <iostream>
#include <fstream>
#include "_Member.h"
using namespace std;

Level::Level() {}
void Level::set_coupon() {
	if (ordered_coffee % 10 == 0)		//만약 커피 주문량이 10의 배수일때 쿠폰 1개 지급
		coupon++;

	//파일에 저장된 쿠폰의 수 수정
	_Member mem;
	//파일에 저장된 값을 읽어옴
	ifstream fin("info.txt", ios_base::in);
	if (!fin.is_open())
		throw "!! Error: cannot open information file !!";
	fin >> mem.name >> mem.gender >> mem.phone >> mem.member_id >> mem.nickname >> mem.coupon >> mem.level;
	mem.coupon = coupon;
	fin.close();

	//coupon 값을 수정 후 다시 파일로 출력
	ofstream fout;
	string w = " ";
	fout.open("info.txt", ios_base::out | ios_base::trunc);
	if (!fout.is_open())
		throw "!! Error: cannot open information file !!";
	fout << mem.name << w << mem.gender << w << mem.phone << w << mem.member_id << w << mem.nickname << w << mem.coupon << w << mem.level;
	fout.close();
}

void Level::set_level() {
	if (ordered_coffee >= 10)
		level = "GREEN";

	if (ordered_coffee >= 20)
		level = "SILVER";

	if (ordered_coffee >= 30)
		level = "GOLD";

	//파일에 저장된 레벨 수정
	_Member mem;
	ifstream fin("info.txt", ios_base::in);
	if (!fin.is_open())
		throw "!! Error: cannot open information file !!";
	fin >> mem.name >> mem.gender >> mem.phone >> mem.member_id >> mem.nickname >> mem.coupon >> mem.level;
	mem.level = level;
	fin.close();

	//coupon 값을 수정 후 다시 파일로 출력
	ofstream fout;
	string w = " ";
	fout.open("info.txt", ios_base::out | ios_base::trunc);
	if (!fout.is_open())
		throw "!! Error: cannot open information file !!";
	fout << mem.name << w << mem.gender << w << mem.phone << w << mem.member_id << w << mem.nickname << w << mem.coupon << w << mem.level;
	fout.close();

}

void Level::print_Level() {
	cout << "***COUPON & LEVEL***" << endl;
	cout << "Level: " << level << endl;
	cout << "Coupon: " << coupon << endl;
	cout << "***" << endl;
}
Level::~Level() {}
