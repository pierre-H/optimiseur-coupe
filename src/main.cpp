#include <iostream>
#include <map>
#include "List.h"
#include "Moteur.h"
#include "Paire.h"
#include "ListPaires.h"
#include "DoubleListPaires.h"
#include <list>

using namespace std;

int main()
{
    List * l = new List();
    createSortedList(l,45.,23.,12.,54.,97.,45.6,87.,52.,41., 78.,1., 6., 7., 87., 25.,0.);
    DoubleListPaires * d = new DoubleListPaires(l,(float)100.,10);
	d->pilote ();
    return 0;
}
