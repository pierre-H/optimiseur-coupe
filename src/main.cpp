#include <iostream>
#include <map>
#include "List.h"
#include "Paire.h"
#include "Combinaison.h"
#include "DoubleListPaires.h"
#include <list>

using namespace std;

int main()
{
    List * tronconsList = new List();
    List * barresList =  new List ();
    double tronconsTab [] = {45.,23.,12.,54.,97.,45.6,87.,52.,41., 78.,1., 6., 7., 87., 25.,0.};
    double barresTab [] = {60., 100., 200.,100., 70., 120.,0.};
    createSortedList(tronconsList, tronconsTab);
    createSortedList (barresList, barresTab);
    DoubleListPaires * d = new DoubleListPaires(tronconsList,barresList);
    d->pilote ();
    return 0;
}
