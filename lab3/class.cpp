#include <iostream>
#include <string>
#include"header.h"

using namespace std;


Country::Country() : area(0.0), name("неизвестно"), polity("неизвестна") 
{};
Country::Country(const string name, const string polity, const float area) : name(name), polity(polity), area(area)
{};
Country::Country(const Country & otherObject) : name(otherObject.name), polity(otherObject.polity), area(otherObject.area)
{};
string Country::SetName(const string name) {
	this->name = name;
	return name;
}

string Country::SetPolity(const string polity) {
	this->polity = polity;
	return polity;
}

float Country::SetArea(const float area) {
	this->area = area;
	return area;
}

float Country::GetArea() {
	return this->area;
}

string Country::GetName() {
	return this->name;
}

string Country::GetPolity() {
	return this->polity;
}

void Country::Print() {
	cout << "Название страны : " << GetName() << endl;
	cout << "Государственный строй : " << GetPolity() << endl;
	cout << "Площадь : " << GetArea() << endl;
}

Republic::Republic() : Country() {
	polity = "Республика";
	party = "Неизвестна";
}

Republic::Republic(const string name, const float area) : Country(name, "Республика", area) {};


Monarchy::Monarchy() : Country() {
	polity = "Монархия";
}

Monarchy::Monarchy(const string name, const float area) : Country(name, "Монархия", area)
{}

Monarchy::Monarchy(const Monarchy& otherObject) : Country(otherObject) 
{}

Kingdom::Kingdom() : Country() 
{}

Kingdom::Kingdom(const string name, const float area) : Country(name, "Королевство", area )
{}

Kingdom::Kingdom(const Kingdom& otherObject) : Country(otherObject) {}
string Kingdom::SetLeader(const string leader) {
	cin >> this->leader;
	return this->leader;
};
