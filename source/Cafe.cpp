#include "Cafe.h"
#include <iostream>
using namespace std;

map<string, int> Cafe::ingredient;
map<string, bool> Cafe::possible_method;

Cafe::Cafe() {
	set_bean();
	set_method();
	set_extra();
}
void Cafe::member_menu() {}
void Cafe::order() {}
void Cafe::my_menu() {}

void Cafe::basic_menu() {
	cout << "1) Customizing Coffee" << endl;
	cout << "2) Coupon and Level" << endl;
	cout << "3) My Menu" << endl;
	cout << "4) Member INFROMATION MODIFY" << endl;
	cout << "5) EXIT" << endl;
}
void Cafe::set_bean() {
	bean.insert(make_pair("columbia_supremo", 0));
	bean.insert(make_pair("ethiopia_yegachv", 0));
	bean.insert(make_pair("java", 0));
	bean.insert(make_pair("kenya_AA", 0));
	bean.insert(make_pair("brazil_santos", 0));
	bean.insert(make_pair("guatemala_antigua", 0));

}
void Cafe::set_method() {
	method.insert(make_pair("espresso", false));
	method.insert(make_pair("cold_brew", false));
	method.insert(make_pair("drip_coffee", false));
}
void Cafe::set_extra() {
	extra.insert(make_pair("water", 60));
	extra.insert(make_pair("ice", 0));
	extra.insert(make_pair("whipping_cream", 0));
	extra.insert(make_pair("steam_milk", 0));
	extra.insert(make_pair("milk_foam", 0));
	extra.insert(make_pair("choco_drizzle", 0));
	extra.insert(make_pair("caramel_drizzle", 0));
	extra.insert(make_pair("vanilla_syrup", 0));
	extra.insert(make_pair("hazelnut_syrup", 0));
	extra.insert(make_pair("caramel_syrup", 0));
}
void Cafe::set_ingredient() {
	ingredient.insert(make_pair("columbia_supremo", 500));
	ingredient.insert(make_pair("ethiopia_yegachv", 500));
	ingredient.insert(make_pair("java", 500));
	ingredient.insert(make_pair("kenya_AA", 500));
	ingredient.insert(make_pair("brazil_santos", 500));
	ingredient.insert(make_pair("guatemala_antigua", 500));
	ingredient.insert(make_pair("water", 1000));
	ingredient.insert(make_pair("ice", 1000));
	ingredient.insert(make_pair("whipping_cream", 1000));
	ingredient.insert(make_pair("steam_milk", 1000));
	ingredient.insert(make_pair("milk_foam", 1000));
	ingredient.insert(make_pair("choco_drizzle", 1000));
	ingredient.insert(make_pair("caramel_drizzle", 1000));
	ingredient.insert(make_pair("vanilla_syrup", 3));
	ingredient.insert(make_pair("hazelnut_syrup", 3));
	ingredient.insert(make_pair("caramel_syrup", 3));

	possible_method.insert(make_pair("espresso", true));
	possible_method.insert(make_pair("drip_coffee", true));
	possible_method.insert(make_pair("cold_brew", true));
}
Cafe::~Cafe() {}
