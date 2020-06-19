#include <iostream>
#include <cctype>
#include "Customizer.h"
using std::cin;
using std::cout;

int Cafe::ordered_coffee = 0;
int input();

int main() {
	try {
		Cafe::set_ingredient();
		Customizer custom;

		int choice;
		//회원가입 or 로그인
		while (1) {
			custom.member_menu();
			bool log = false;
			choice = input();
			if ((choice != 1) && (choice != 2)) {	//예외처리
				throw "!! ERROR: WRONG MENU !!";
			}
			switch (choice) {
			case 1:
				custom.join();	//회원가입 후 로그인
				cout << endl;
				break;
			case 2:
				while (log != true) {
					log = custom.login();
					if (log == false)
						cout << "!! ERROR: LOGIN FAILURE !!" << endl;	//로그인 실패 -> 다시 로그인 페이지로 돌아감
				}
				break;
			default:
				throw "!! ERROR: WRONG MENU !!";
			}
			if (log == true)
				break;
		}

		while (1) {
			custom.basic_menu();
			choice = input();
			if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5)) 	//예외처리
				throw "!! ERROR: WRONG MENU !!";
			switch (choice) {
			case 1: 
			{	//customizing
				custom.bean_menu();		//1) 원두세팅

				cout << "how many beans do you set? (NUMBER): ";
				int cnt = input();
				if (!isdigit(cnt))
					throw "!! ERROR: WRONG INPUT !!";
				cout << endl;
				custom.set_bean(cnt);

				custom.method_menu();	//2) 추출방법 세팅
				custom.set_method();

				custom.extra_menu();	//3) extra 세팅
				cout << "how many extra do you set?: ";
				cnt = input();
				if (!isdigit(cnt))
					throw "!! ERROR: WRONG INPUT !!";
				custom.set_extra(cnt);
				cout << endl;

				cout << "customizing success" << endl;
				cout << "save(1) or order(2)" << endl;
				cnt = input();
				if (!isdigit(cnt))
					throw "!! ERROR: WRONG INPUT !!";
				if (cnt == 1)
					custom.save();
				else if (cnt == 2) {
					custom.order();
					cout << endl;
					custom.set_coupon();
					custom.set_level();
				}
				else throw "!! ERROR: WRONG INPUT !!";
				
				break;
			}
			case 2: { //coupon & level
				custom.print_Level();
				break; }
			case 3:
				custom.my_menu();
				break;
			case 4:
				custom.modify();
				break;
			case 5:
				cout << "THANK YOU FOR VISTING US! BYE!" << endl;
				break;
			default:
				cout << "wrong menu" << endl;
				break;
			}
			if (choice == 5)
				break;
			}
		}
	catch(string s){
		cout << s << endl;
		return 0;
	}
	return 0;
}

int input() {
	int input;
	cin >> input;
	cin.ignore();
	return input;
}
