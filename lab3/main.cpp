#include "header.h"


int main() {
	setlocale(LC_ALL, "rus");
	Republic r1("Россия", 17098246, "какая-то партия");
	r1.Print();
	Kingdom k1("UK", 242495, "Charlse III");
	k1.Print();
	Monarchy* m1 = new Monarchy;
	m1->SetArea(3500000);
	m1->SetName("Византийсакя Империя");
	m1->SetDynasty("Палеологи");
	m1->Print();
	delete m1;
	return 0;
}
