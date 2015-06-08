#include <iostream>
#include <map>
#include "List.h"
#include "Paire.h"
#include "Combinaison.h"
#include "MoteurCalculs.h"
#include <list>

using namespace std;

int main()
{
	List * tronconsList = new List();
	List * barresList =  new List ();
	double barresTab [] = {15.,6., 6., 0.};
	double tronconsTab [] = {9., 3., 3., 0.};
	createSortedList(tronconsList, tronconsTab);
	createSortedList (barresList, barresTab);
	barresList->affiche();
	MoteurCalculs * d = new MoteurCalculs(tronconsList,barresList, 0.);
	d->pilote ();
	return 0;
}
