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
    List * l = new List();
    List * barres =  new List ();
    createSortedList(l,45.,23.,12.,54.,97.,45.6,87.,52.,41., 78.,1., 6., 7., 87., 25.,0.);
    createSortedList (barres, 60., 100., 200.,100., 70., 120.,0.);
    DoubleListPaires * d = new DoubleListPaires(l,barres);
    d->pilote ();
    //d->affiche();
    return 0;
}
