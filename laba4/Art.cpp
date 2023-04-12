#include <iostream>
#include <string>
#include"Art.h"

using namespace std;

Art::Art() : cost(0.0), name("неизвестно"), art("неизвестно")
{};
Art::Art(const string name, const string art, const float cost) : name(name), art(art), cost(cost)
{};
Art::Art(const Art& otherObject) : name(otherObject.name), art(otherObject.art), cost(otherObject.cost)
{};
string Art::SetName(const string name) {
	this->name = name;
	return name;
}

string Art::SetArt(const string art) {
	this->art = art;
	return art;
}

float Art::SetCost(const float cost) {
	this->cost = cost;
	return cost;
}

float Art::GetCost() {
	return this->cost;
}

string Art::GetName() {
	return this->name;
}

string Art::GetArt() {
	return this->art;
}

void Art::Print() {
	cout << "Расположение : " << GetName() << endl;
	cout << "Искусство : " << GetArt() << endl;
	cout << "Цена : " << GetCost() << endl;
}

Theater::Theater() : Art() {
	art = "Театр";
}

Theater::Theater(const string name, const float cost, const int amount_places) : Art(name, "Театр", cost), amount_places(amount_places)
{};
Theater::Theater(const Theater& otherObject) : Art(otherObject)
{
	this->amount_places = otherObject.amount_places;
}

int Theater::SetTheater(const int _amount_places)
{
	this->amount_places = _amount_places;
	return _amount_places;
}

void Theater::Print()
{
	Art::Print();
	cout << "Количество мест : " << amount_places << endl;
}

Music::Music() : Art() {
	art = "Музыка";
}

Music::Music(const string name, const float cost, const int amount_music) : Art(name, "Музыка", cost), amount_music(amount_music)
{}

Music::Music(const Music& otherObject) : Art(otherObject)
{
	this->amount_music = otherObject.amount_music;
}

int Music::SetMusic(const int _amount_music) {
	this->amount_music = _amount_music;
	return _amount_music;
}

void Music::Print()
{
	Art::Print();
	cout << "Количество произведений : " << amount_music << endl;
}

Painting::Painting() : Art()
{}

Painting::Painting(const string name, const float cost, const int kol_vo) : Art(name, "Живопись", cost), kol_vo(kol_vo)
{}

Painting::Painting(const Painting& otherObject) : Art(otherObject)
{
	this->kol_vo = otherObject.kol_vo;
}

int Painting::SetPainting(const int kol_vo)
{
	this->kol_vo = kol_vo;
	return kol_vo;
}

void Painting::Print()
{
	Art::Print();
	cout << "Количество картин : " << kol_vo << endl;
}




