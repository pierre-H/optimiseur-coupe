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
	double tronconsTab [] = {45.,5., 40., 1., 2., 3.,5., 0.};
	double barresTab [] = {100.,200.,0.};
	createSortedList(tronconsList, tronconsTab);
	createSortedList (barresList, barresTab);
	barresList->affiche();
	MoteurCalculs * d = new MoteurCalculs(tronconsList,barresList, 0.7);
	d->pilote ();
	return 0;
}
