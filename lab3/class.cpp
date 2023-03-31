#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
#ifndef COUNTRY_H
#define COUNTRY_H
class Country {
protected:
	string name;
	string polity;
	float area;
public:
	Country();
	Country(const string name, const string polity, const float area);
	Country(const Country& otherObject);

	//сеттеры

	string SetName(const string name);
	string SetPolity(const string polity);
	float SetArea(const float area);

	//геттеры

	string GetName();
	string GetPolity();
	float GetArea();

	//методы

	void Print();
};

class Republic : public Country {
private:
	string party;
public:
	Republic();
	Republic(const string name, const float area);

};

class Monarchy : public Country {
private:
	string dynasty;
public:
	Monarchy();
	Monarchy(const string name, const float area);
	Monarchy(const Monarchy& otherObject);
};

class Kingdom : public Country {
private:
	string leader;
public:
	Kingdom();
	Kingdom(const string name, const float area);
	Kingdom(const Kingdom& otherObject);
	string SetLeader(const string leader);


};
#endif
