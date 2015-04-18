#include <iostream>
#include <stdarg.h>
#include "List.h"
using namespace std;

 //constructeur
List::List() : m_prochain (NULL)
{
}

// surcharge du constructeur
List::List(float premier)
{
    m_element = 0;
    m_prochain = new List ();
    m_prochain->m_element = premier;
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

// affiche ce que contient la Liste
void List::affiche (bool premier) const
{
    if (not premier) cout << m_element <<", ";
    if (m_prochain != 0)
           {m_prochain->affiche(false);}
    else cout <<endl;
}

// ajoute un element en première position de la liste

List& List::cons (float premier)
{
    List * l = new List ();
    l->m_element = premier;
    l->m_prochain = m_prochain;
    m_prochain = l;
    return *this;
}

//prend un nombre variable de parametres et les ajoute au debut de la liste
// le dernier argument doit être 0
List& List::append (float premier, ...)
{
    if (this != NULL) cons(premier);
    va_list ap;
    va_start (ap,premier);
    double parametre = va_arg(ap, double);
    while (parametre != (float) 0)
    {
            cons(parametre);
            parametre = va_arg (ap, double);
    }
    va_end(ap);
    return *this;
}
//renvoie la longueur de la liste
int List::length ()
{
    if (m_prochain != NULL)
        return 1 + m_prochain->length ();
    return 0 ;
}

// member retourne la position de a_chercher s'il est ds la liste et 0 sinon
// (si aChercher est premier, retourne 1 et non 0)
int List::member (float aChercher)
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
    }
    return 1;
}

// supprime le nième élément : n=1 => supprime le premier élément
// si dépasse la taille de la liste, ne se passe rien
int List::supprimeNieme (int n)
{
    if (n == 1 or n==0)
    {
        return supprime();
    }
    else if (m_prochain)
        return m_prochain->supprimeNieme(n-1);
}
// supprime de la liste un élément connu.
// si cet élément n'existe pas, il ne se passe rien
void List::supprimeExplicite (float ASupprimer)
{
    int position = member(ASupprimer);
    if (position != 0) supprimeNieme(position);
}
// insere le nombre inserer à la position position de la liste
// l.insere (5., 1) ou (5., 0)insere 5 en première position
// si l'on dépasse la taille de la liste, ou que l'on rentre une
// position négative,la fonction ne fait rien
List& List::insere (float inserer, int position)
{
    if (position == 1 or position == 0) cons (inserer);
    else if (m_prochain) m_prochain->insere (inserer, position-1);
    return *this;}

// car renvoie le premier element de la liste
float List::car ()
{return m_element;}

List* List::cdr()
{return m_prochain;}

//insere un element à sa bonne place dans une liste en le triant par ordre croissant
void List::trie (float element)
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

List * List::getProchain ()
{return m_prochain;}

float List::getPremier ()
{return m_element;}

bool List::empty()
{return not m_prochain;}
