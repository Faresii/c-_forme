#include"header.h"
Country::Country() : area(0.0), name("неизвестно"), polity("неизвестна") {};
Country::Country(const std::string name, const std::string polity, const float area) : name(name), polity(polity), area(area) {};
Country::Country(const Country & otherObject) : name(otherObject.name), polity(otherObject.polity), area(otherObject.area) {};
std::string Country::SetName(const std::string name) {
	this->name = name;
	return name;
}
std::string Country::SetPolity(const std::string polity) {
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
std::string Country::GetName() {
	return this->name;
}
std::string Country::GetPolity() {
	return this->polity;
}
void Country::Print() {
	std::cout << "Название страны: " << GetName() << std::endl << "Государственный строй: " << GetPolity() << std::endl << "Площадь: " << GetArea() << std::endl;
}
Republic::Republic() : Country() {
	polity = "Республика";
	party = "Не известна";
}
Republic::Republic(const std::string name, const float area, const std::string party ="") : Country(name, "Республика", area) , party("party") {};
Republic::Republic(const Republic& otherObject) : Country(otherObject) {
	this->party = otherObject.party;
};
void Republic::Print() {
	Country::Print();
	std::cout <<"Партия: "<< party << std::endl;
}
Monarchy::Monarchy() : Country() {
	polity = "Монархия";
}
Monarchy::Monarchy(const std::string name, const float area, const std::string dynasty) : Country(name, "Монархия", area), dynasty(dynasty) {}

Monarchy::Monarchy(const Monarchy& otherObject) : Country(otherObject) {}
void Monarchy::Print() {
	Country::Print();
	std::cout << "Династия: " << dynasty << std::endl;
}
std::string Monarchy::SetDynasty(const std::string dynasty) {
	this->dynasty = dynasty;
	return dynasty;
};

Kingdom::Kingdom() : Country() {};

Kingdom::Kingdom(const std::string name, const float area, const std::string leader) : Country(name, "Королевство", area ), leader(leader){}

Kingdom::Kingdom(const Kingdom& otherObject) : Country(otherObject) {}
std::string Kingdom::SetLeader(const std::string leader) {
	this->leader = leader;
	return leader;
};
void Kingdom::Print() {
	Country::Print();
	std::cout << "Глава государства: " << leader << std::endl;
};
