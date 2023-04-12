#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

#ifndef Viewer_H
#define Viewer_H
class Viewer // абстрактный класс
{
public:
	virtual void Print() = 0; // чисто виртуальная функция 

};
#endif

#ifndef Art_H
#define Art_H

class Art : public Viewer
{
protected:
	string name;
	string art;
	float cost;
public:
	Art();
	Art(const string name, const string art, const float cost);
	Art(const Art& otherObject);
	//сеттеры

	string SetName(const string name);
	string SetArt(const string art);
	float SetCost(const float cost);

	//геттеры

	string GetName();
	string GetArt();
	float GetCost();

	//методы

	void Print() override; // хотим в будущем переопределить эту функцию
};
#endif

#ifndef Theater_H
#define Theater_H

class Theater : public Art {
protected:
	int amount_places;

public:
	Theater();
	Theater(const string name, const float cost, int amount_places);
	Theater(const Theater& otherObject);

	int SetTheater(const int _amount_places);

	void Print() override; // override, компилятор помогает понять что мы переопределяем эту функцию
};
#endif

#ifndef Music_H
#define Music_H
class Music : public Art {
private:
	int amount_music;

public:
	Music();
	Music(const string name, const float cost, const int amount_music);
	Music(const Music& otherObject);

	int SetMusic(const int _amount_music);

	void Print();
};
#endif

#ifndef Painting_H
#define Painting_H

class Painting : public Art {
private:
	int kol_vo;

public:
	Painting();
	Painting(const string name, const float cost, const int kol_vo);
	Painting(const Painting& otherObject);

	int SetPainting(const int kol_vo);

	void Print() override;
	
};
#endif

