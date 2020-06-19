#include "Customizer.h"
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

Customizer::Customizer() {}
void Customizer::my_menu() {
	cout << "***MY MENU***" << endl;
	//파일 연결
	ifstream fcustom("customized menu.txt", ios::in | ios::binary);

	while (!fcustom.eof()) {

		//파일에서 입력받음
		map<string, int>::iterator iter1;
		for (iter1 = bean.begin(); iter1 != bean.end(); iter1++)
			fcustom >> iter1->second;
		for (iter1 = extra.begin(); iter1 != extra.end(); iter1++)
			fcustom >> iter1->second;

		map<string, bool>::iterator iter2;
		for (iter2 = method.begin(); iter2 != method.end(); iter2++)
			fcustom >> iter2->second;

		//출력
		cout << "***" << endl;
		for (iter1 = bean.begin(); iter1 != bean.end(); iter1++)
			cout << iter1->first << " : " << iter1->second << endl;
		for (iter1 = extra.begin(); iter1 != extra.end(); iter1++)
			cout << iter1->first << " : " << iter1->second << endl;

		for (iter2 = method.begin(); iter2 != method.end(); iter2++)
			cout << iter2->first << " : " << iter2->second << endl;

		cout << "***" << endl;

	}
	fcustom.close();
}
void Customizer::bean_menu() throw(string){
	cout << "***KIND_OF_BEAN***" << endl;
	cout << "(unit: g)" << endl;
	cout << "columbia_supremo" << endl
		<< "ethiopia_yegachv" << endl
		<< "java" << endl
		<< "kenya_AA" << endl
		<< "brazil_santos" << endl
		<< "guatemala_antigua" << endl;
	cout << endl;
}
void Customizer::set_bean(int cnt) {
	cout << "set coffee_beans" << endl;

	for (int i = 0; i < cnt; i++) {
		string name = "";
		int amount = 0;
		cout << "bean name: "; cin >> name;
		cout << "how much: "; cin >> amount;
		if (bean.find(name) == bean.end())
			throw "!! ERROR: WORNG NAME of BEAN !!";

		bean[name] = amount;
		//재료양과 비교
		if (amount > ingredient[name])
			bean_check = false;
		else bean_check = true;
		cout << endl;
	}

}
void Customizer::method_menu() {
	cout << "***KIND_OF_METHOD***" << endl;
	cout << "(yes: 1 / no: 0)" << endl;
	cout << "drip_coffee" << endl
		<< "espresso" << endl
		<< "cold_brew" << endl;
	cout << endl;
}
void Customizer::set_method() {	//method는 하나만 선택 가능
	string name = "";
	cout << "method name: ";
	cin >> name;	
	if (method.find(name) == method.end())
		throw "!! ERROR: WORNG METHOD !!";

	if (possible_method[name] == false)
		method_check = false;
	else method_check = true;

	method[name] = true;
	cout << endl;
}
void Customizer::extra_menu() {
	cout << "***KIND_OF_EXTRA***" << endl;
	cout << "(drizzle & syrup unit: 1,2,3) (other unit: g)" << endl;
	cout << "water" << endl
		<< "ice" << endl
		<< "whipping_cream" << endl
		<< "steam_milk" << endl
		<< "milk_foam" << endl
		<< "choco_drizzle" << endl
		<< "caramel_drizzle" << endl
		<< "vanilla_syrup" << endl
		<< "hazelnut_syrup" << endl
		<< "caramel_syrup" << endl;
	cout << endl;
}
void Customizer::set_extra(int cnt) {
	for (int i = 0; i < cnt; i++) {
		string name = "";
		int amount = 0;
		cout << "extra name: "; cin >> name;
		cout << "how much: "; cin >> amount;
		if (extra.find(name) == extra.end())
			throw "!! ERROR: WORNG NAME of EXTRA !!";

		//재료양과 비교
		if (amount > ingredient[name])
			extra_check = false;
		else extra_check = true;
		extra[name] = amount;
		cout << endl;
	}
}
void Customizer::order() {
	if ((bean_check == true) && (method_check == true) && (extra_check == true)) {
		cout << "thank you for order!" << endl;
		ordered_coffee++;
	}
	else
		cout << "SORRY.. we do not have enough ingredient or method" << endl;
}
void Customizer::save() {
	string w = " ";
	ofstream fcustom("customized menu.txt", ios::out | ios::app | ios::binary);
	if (!fcustom.is_open())
		throw "!! ERROR: canoot open customized menu file !!";
	cout << endl;


	//파일에 입력
	map<string,int>::iterator iter1;
	for (iter1 = bean.begin(); iter1 != bean.end(); iter1++)
		fcustom << iter1->second << w;
	for (iter1 = extra.begin(); iter1 != extra.end(); iter1++)
		fcustom << iter1->second << w;

	map<string, bool>::iterator iter2;
	for (iter2 = method.begin(); iter2 != method.end(); iter2++)
		fcustom << iter2->second << w;

	fcustom.close();
}
Customizer::~Customizer() { }
