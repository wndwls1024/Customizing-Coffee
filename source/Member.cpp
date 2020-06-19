#include "Member.h"
#include "_Member.h"
#include <iostream>
#include <fstream>
using namespace std;

Member::Member() {}
void Member::member_menu() {
	cout << "***Cafe Customizer***" << endl
		<< "Hello! This is A SPECIAL Cafe ORDER PROGRAM" << endl
		<< "You can make and order YOUR OWN Cafe MENU" << endl
		<< "enjoy our service :)" << endl;
	cout << endl;
	cout << "1) (NEW)JOIN" << '\t'
		<< "2) LOGIN" << endl;
}

void Member::join() {	//회원가입
	cout << "***JOIN***" << endl;

	_Member mem;
	cout << "!! NO BLANK !!" << endl;
	cin.clear();
	cout << "name: "; cin >> mem.name;
	cout << "gender: "; cin >> mem.gender;
	cout << "phone number: "; cin >> mem.phone;
	cout << "ID: "; cin >> mem.member_id;
	cout << "nickname: "; cin >> mem.nickname;

	//파일에 입력
	ofstream info;
	string w = " ";
	info.open("Info.txt", ios_base::out | ios_base::binary);
	if (!info.is_open())
		cout << "Error: cannot open information file" << endl;
	info << mem.name << w << mem.gender << w << mem.phone << w << mem.member_id << w << mem.nickname << w << mem.coupon << w << mem.level;
	info.close();
}

bool Member::login() {
	cout << "***LOGIN***" << endl;
	ifstream info;
	info.open("info.txt", ios_base::in | ios_base::binary);
	if (!info.is_open())
		cout << "Error: cannot open information file" << endl;

	//info파일에서 이름과 id 받아오기
	_Member fmem;
	info >> fmem.name >> fmem.gender >> fmem.phone >> fmem.member_id >> fmem.nickname >> fmem.coupon >> fmem.level;

	//사용자가 이름과 아이디 입력
	string input_name = "";
	string input_id = "";
	cout << "name: "; 
	cin >> input_name;
	//getline(cin,input_name);
	cout << "member_id: "; cin >> input_id;
	cin.ignore();


	//비교
	if ((fmem.name != input_name) || (fmem.member_id != input_id)) {
		return false;
	}

	cout << "**login success**" << endl << endl;
	this->name = fmem.name;
	this->gender = fmem.gender;
	this->phone = fmem.phone;
	this->member_id = fmem.member_id;
	this->nickname = fmem.nickname;

	info.close();

	return true;
}

void Member::modify() {	//정보 수정 함수
	_Member mem;

	//객체에 저장된 현재 개인정보 표시
	cout << "1) name: " << this->name << endl;
	cout << "2) gender: " << this->gender << endl;
	cout << "3) phone: " << this->phone << endl;
	cout << "4) ID: " << this->member_id << endl;
	cout << "5) nickname: " << this->nickname << endl;

	//수정할 정보 입력
	int num;
	cout << "What information do you change? (1~5): "; cin >> num;
	if ((num != 1) && (num != 2) && (num != 3) && (num != 4) && (num != 5)) 	//예외처리
		throw "!! ERROR: WRONG NUMBER !!";
	switch (num) {
	case 1:
		cout << "new name: ";
		cin >> mem.name;
		this->name = mem.name;
		break;
	case 2:
		cout << "new gender: "; cin >> mem.gender;
		this->gender = mem.gender;
		break;
	case 3:
		cout << "new phone: "; cin >> mem.phone;
		this->phone = mem.phone;
		break;
	case 4:
		cout << "new ID: "; cin >> mem.member_id;
		this->member_id = mem.member_id;
		break;
	case 5:
		cout << "new nickname: "; cin >> mem.nickname;
		this->nickname = mem.nickname;
		break;
	default:
		cout << "error: worng number" << endl;
		return;
	}

	//파일 값 수정
	ofstream info;
	string w = " ";
	info.open("info.txt", ios_base::out | ios_base::trunc);
	if (!info.is_open())
		throw "Error: cannot open information file";
	info << this->name << w << this->gender << w << this->phone << w << this->member_id << w << this->nickname << w << this->coupon << w << this->level;
	info.close();
}

Member::~Member() {}
