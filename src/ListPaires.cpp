#include <iostream>
#include "ListPaires.h"

using namespace std;

ListPaires::ListPaires() : m_rendement(0.0)
{}

ListPaires::ListPaires(Paire& p) : m_rendement(0.0)
{
    m_liste.push_back(p);
}

ListPaires::~ListPaires()
{}

void ListPaires::affiche()
{
    cout <<"[";
    for (list<Paire>::iterator it = m_liste.begin(); it != m_liste.end(); it++)
    {
        if (it != m_liste.begin())
            cout <<", ";
        it->affiche();
    }
    cout <<"]"<<endl;
    cout << "Rendement : " << m_rendement <<" %" << endl <<endl;

}

void ListPaires::push (Paire p)
{
    m_liste.push_back(p);
}

void ListPaires::push (float e, int pos)
{
    Paire *p =new Paire(e, pos);
    push(*p);
    delete p;
}

float ListPaires::calculeRendement (float longueurBarres)
{
    float somme = 0;
    for (list<Paire>::iterator it = m_liste.begin(); it != m_liste.end(); it++)
        somme += it->m_longueur;
    m_rendement = somme/longueurBarres*100;
    return m_rendement;
}

float ListPaires::getRendement()
{return m_rendement;}

list<Paire> ListPaires::getPaires()
{return m_liste;}

// retourne la position ds la liste, de la dernière paire
// de la liste des possibilités
int ListPaires::getPosDernier ()
{
    int a=0;
    list<Paire>::iterator it;
    for (it = m_liste.begin(); it != m_liste.end(); it++)
        a = it->getPos();
    return a;
}

list<Paire> ListPaires::getList()
{return m_liste;}
