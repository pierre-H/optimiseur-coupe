#include <iostream>
#include "List.h"
using namespace std;
#if DEBUG
int main ()
{
	List l = List (1.);	l.affiche ();	// deuxième constructeur
	cout <<"Test de l.cons (2.) : ";l.cons (2.); l.affiche ();			// test de cons
	cout <<"Test de l.append (3.,4.,5., 6., 0) : ";l.append (3., 4., 5., 6. , 0);l.affiche ();
	cout <<"Test de length : "<< l.length() << endl;
	cout << "Test de member Position de 1. : " << l.member (1.) <<" et de 6. : "<< l.member (6.) << " et de quelque chose qui n'est pas dans la liste : " << l.member (613.613) <<endl;
	cout <<"Test de supprime ";l.supprime (); l.affiche (); 
	cout <<"Test de supprimeNieme (premier élément) : "; l.supprimeNieme (1);  l.affiche ();
	cout <<"Test de supprimeNieme (dernier élément) : "; l.supprimeNieme (4); l.affiche ();
	cout <<"Test de supprimeNieme (si on dépasse la longueur de la liste) : "; l.supprimeNieme (25); l.affiche ();
	cout <<"Test de supprimeNieme (chiffre négatif) : "; l.supprimeNieme (-4); l.affiche ();
	cout <<"Test de supprimeExplicite (4.) : "; l.supprimeExplicite (4.); l.affiche ();
	cout <<"Test de supprimeExplicite (qq chose qui n'existe pas) : "; l.supprimeExplicite (613.613); l.affiche ();
	cout <<"Test de insere (54., 0) : "; l.insere (54.,0); l.affiche ();
	cout <<"Test de insere (54., dépasse index) : "; l.insere (54.,12); l.affiche ();
	cout <<"Test de insere (54., index négatif) : "; l.insere (5555.,-5); l.affiche ();
	cout << "Test de createSortedList (12.,18.2, 40.5, 95.,54., 546.,45., 0) : "; 
	List * li = new List(); createSortedList (li,12.,18.2, 40.5, 95.,54., 546.,45., 0);
	li->affiche ();
	
	
	
	return 0;
}
#endif
