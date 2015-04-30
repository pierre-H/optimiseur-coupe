#include <iostream>
#include <map>
#include "List.h"
#include "Paire.h"
#include "ListPaires.h"
#include "DoubleListPaires.h"
#include <list>

using namespace std;

int main()
{
    List * l = new List();
    createSortedList(l,45.,23.,12.,54.,97.,45.6,87.,52.,41., 78.,1., 6., 7., 87., 25.,0.);
    l->affiche();
    DoubleListPaires * d = new DoubleListPaires(l,(float)100.,15);
    d->affiche();
    d->pilote ();
    return 0;
}
