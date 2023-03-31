#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#ifndef COUNTRY_H
#define COUNTRY_H
class Country {
protected:
	std::string name;
	std::string polity;
	float area;
public:
	Country();
	Country(const std::string name, const std::string polity, const float area);
	Country(const Country& otherObject);

	//сеттеры

	std::string SetName(const std::string name);
	std::string SetPolity(const std::string polity);
	float SetArea(const float area);

	//геттеры

	std::string GetName();
	std::string GetPolity();
	float GetArea();

	//методы

	void Print();
};
#endif
#ifndef REPUBLIC_H
#define REPUBLIC_H
class Republic : public Country {
private:
	std::string party;
public:
	Republic();
	Republic(const std::string name, const float area, const std::string party);
	Republic(const Republic& otherObject);
	void Print();
};
#endif
#ifndef MONARCHY_H
#define MONARCHY_H
class Monarchy : public Country {
private:
	std::string dynasty;
public:
	Monarchy();
	Monarchy(const std::string name, const float area, const std::string dynasty);
	Monarchy(const Monarchy& otherObject);
	std::string SetDynasty(const std::string dynasty);
	void Print();

};
#endif
#ifndef KINGDOM_H
#define KINGDOM_H
class Kingdom : public Country {
private:
	std::string leader;
public:
	Kingdom();
	Kingdom(const std::string name, const float area, const std::string leader);
	Kingdom(const Kingdom& otherObject);
	std::string SetLeader(const std::string leader);
	void Print();

};
#endif
