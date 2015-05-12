#include <iostream>
#include <stdarg.h>
#include <list>
#include "List.h"
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~ fonctions de construction et de destruction ~~~~~~~~~~~~~~~~~~~~~~~~~~

 //constructeur
List::List() : m_prochain (NULL)
{
}

// surcharge du constructeur
List::List(double premier)
{
    m_element = 0;
    m_prochain = new List ();
    m_prochain->m_element = premier;
    m_prochain->m_prochain = NULL;
}

// deuxième surcharge du constructeur
List::List (List * prochain)
{
    m_prochain = prochain;
}
//destructeur
List::~List()
{
        delete m_prochain;
}

// ajoute un element en première position de la liste
List& List::cons (double premier)
{
    List * l = new List ();
    l->m_element = premier;
    l->m_prochain = m_prochain;
    m_prochain = l;
    return *this;
}

// prend un nombre variable de parametres et les ajoute au debut de la liste
// le dernier argument doit être 0
List& List::append (double premier, ...)
{
    if (this != NULL) cons(premier);
    va_list ap;
    va_start (ap,premier);
    double parametre = va_arg(ap, double);
    while (parametre != (double) 0)
    {
            cons(parametre);
            parametre = va_arg (ap, double);
    }
    va_end(ap);
    this->supprime ();
    return *this;
}

// supprime le premier élément de la liste
int List::supprime ()
{
    if (this != NULL)
    {
		List * victime = m_prochain; 
		if (victime == NULL) return 0;
		m_prochain = victime->m_prochain; 
		victime = NULL;
		delete victime;
        return 0;
    }
    return 1;
}

// supprime le nième élément : n=1 => supprime le premier élément
// si dépasse la taille de la liste, ne se passe rien
int List::supprimeNieme (int n)
{
    if (n == 1 or n==0)
        return supprime();
    else if (m_prochain)
        return m_prochain->supprimeNieme(n-1);
    else 
    	return 0;
}

// supprime de la liste un élément connu.
// si cet élément n'existe pas, il ne se passe rien
void List::supprimeExplicite (double ASupprimer)
{
    int position = member(ASupprimer);
    if (position != 0) supprimeNieme(position);
}

// insere le nombre inserer à la position position de la liste
// l.insere (5., 1) ou (5., 0)insere 5 en première position
// si l'on dépasse la taille de la liste, ou que l'on rentre une
// position négative,la fonction ne fait rien
List& List::insere (double inserer, int position)
{
    if (position == 1 or position == 0) cons (inserer);
    else if (m_prochain) m_prochain->insere (inserer, position-1);
    return *this;
}

//insere un element à sa bonne place dans une liste en le triant par ordre croissant
void List::trie (double element)
{
    if (m_prochain == NULL)
        cons(element);
    // on récurse
    else if (element >= m_element && element >= m_prochain->m_element)
        return m_prochain->trie(element);
    //entre les 2 : on insere
    else if (element >= m_element)
        cons (element) ;
    else if (element < m_element)
        insere (element,1);
}

// crée et renvoie une liste comportant tous les arguments donnés en paramètres
// triés par ordre décroissant
// le dernier argument doit être un 0
List * createSortedList (List * l, ...)
{
    va_list ap;
    va_start (ap,l);
    double parametre = va_arg (ap, double);
    while (parametre != 0)
    {
        l->trie (parametre);
        parametre = va_arg (ap, double);
    }
    va_end(ap);
    return l;
}

// fonctions d'accès et d'information
// affiche ce que contient la Liste
void List::affiche (bool premier) const
{
    if (not premier) 
    {
		cout << m_element;
    	if (m_prochain != NULL)
    	{
			cout <<", ";
			m_prochain->affiche (false);
		}
		else 
			cout <<endl;	//fin de liste
	}
	else    // premier élément de la liste ou liste vide
	{
		if (m_prochain)
			m_prochain->affiche(false);
		else
			cout << endl;
	}
}

// copie une liste dans un vecteur et le renvoie pour travailler par index
void List::copie(vector<double> * v)
{
    List * pt = this;                // itérateur
    while (true)
    {
        if (pt != NULL)
        {
            v->push_back(pt->m_element) ;
            pt = pt->m_prochain;
        }
        else break;
    }
}

// member retourne la position de a_chercher s'il est ds la liste et 0 sinon
// index commençant à 1 et non 0
int List::member (double aChercher) const
{
    int i=0;
    if (m_element == aChercher) return i;
    List* ptr = m_prochain;
    while(ptr != NULL)
    {
        i++;
        if (ptr->m_element == aChercher) return i;
        ptr = ptr->m_prochain;
    }
    return false/*false*/;
}

double List::getPremier () const
{return m_element;}

List * List::getProchain () const
{return m_prochain;}

bool List::empty() const
{return not m_prochain;}


//renvoie la longueur de la liste
int List::length () const
{
    if (m_prochain != NULL)
        return 1 + m_prochain->length ();
    return 0 ;
}

// renvoie le plus grand élément de la liste
double List::max ()
{
    List * pt = this;
    double max = m_element;
    while (pt != NULL)
    {
        if (pt->m_element > max)
            max = pt->m_element;
        pt = pt->m_prochain;
    }
    return max;
}

// renvoie le plus petit élément de la liste
double List::min ()
{
    List * pt = this->m_prochain;
    double minimum;
    if (pt)
    	minimum = pt->m_element;
	else
		cout << "Erreur : Liste vide !" << endl;
    while (pt != NULL)
    {
        if (pt->m_element < minimum)
            minimum = pt->m_element;
        pt = pt->m_prochain;
    }
    return minimum;
}




#if DEBUG
int main ()
{
	List l = List (1.);	cout <<"Test du constructeur : "; l.affiche ();	// deuxième constructeur
	cout <<"Test de l.cons (2.) : ";l.cons (2.); l.affiche ();			// test de cons
	cout <<"Test de l.append (3.,4.,5., 6., 0) : ";l.append (3., 4., 5., 6. , 0);l.affiche ();
	cout <<"Test de length : "<< l.length() << endl;
    cout <<"Test de member Position de 1. : " << l.member (1.) <<" et de 6. : "<< l.member (6.) << " et de quelque chose qui n'est pas dans la liste : " << l.member (613.613) <<endl;
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
	cout << ", Max = " << li->max () << ", et min = " << li->min () << endl;
	return 0;
}
#endif
