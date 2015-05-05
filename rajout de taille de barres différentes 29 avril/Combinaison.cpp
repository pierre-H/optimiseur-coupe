#include <iostream>
#include "Combinaison.h"
#include "List.h"
#include <cstdio>

using namespace std;

Combinaison::Combinaison() : m_rendement(0.0), m_barre (0.1)
{}

Combinaison::Combinaison(Paire& p) : m_rendement(0.0), m_barre (0.1)
{
    m_liste.push_back(p);
}

Combinaison::~Combinaison()
{}

void Combinaison::affiche()
{
    cout <<"[";
    for (list<Paire>::iterator it = m_liste.begin(); it != m_liste.end(); it++)
    {
        if (it != m_liste.begin())
            cout <<", ";
        it->affiche();
    }
    cout <<"]"<<endl;
    cout << "Rendement de "<< m_rendement <<"\% sur une barre de " << m_barre << endl;
}

void Combinaison::push (Paire p)
{
    m_liste.push_back(p);
}

void Combinaison::push (float e, int pos)
{
    Paire *p =new Paire(e, pos);
    push(*p);
    delete p;
}

float Combinaison::somme ()
{
	float sum = 0.;
	for (list<Paire>::iterator it = m_liste.begin() ; it != m_liste.end(); it++)
		sum += it->m_longueur;
	return sum;
}

float Combinaison::calculeRendement ()
{
    m_rendement = somme()/m_barre*100;
    return m_rendement;
}


// attacheBarre choisit dans la liste des barres la barre la plus proche de la somme
// des tronçons de la combinaison
// retourne -1.0 s'il n'y a pas de barre assez grande pour cette combinaison

float Combinaison::attacheBarre (List* barres)
{
	float barreChoisie, diff;
	List * pt;
	if (barres)
	{
		pt = barres->getProchain();
		diff =  pt->getPremier () - somme(); // différence
		barreChoisie = pt->getPremier();
	}
	else 
		cout <<"Liste des barres vide !"<<endl;
	while (pt)
	{
		if ((pt->getPremier() - somme()) < diff and (pt->getPremier() - somme() >= 0 ))
		{
			barreChoisie = pt->getPremier();
			diff = pt->getPremier () - somme();
		}
		pt = pt->getProchain ();
	}
	if (barreChoisie >= somme ())
	{
		m_barre = barreChoisie;
		return barreChoisie;
	}
	else
		return -1.;	// il n'y a pas de barre assez grande pour cette combinaison
}


float Combinaison::getRendement()
{return m_rendement;}

list<Paire> Combinaison::getPaires()
{return m_liste;}

float Combinaison::getBarre ()
{return m_barre;}

// retourne la position ds la liste, de la dernière paire
// de la liste des possibilités
int Combinaison::getPosDernier ()
{
    int a=0;
    list<Paire>::iterator it;
    for (it = m_liste.begin(); it != m_liste.end(); it++)
        a = it->getPos();
    return a;
}



list<Paire> Combinaison::getList()
{return m_liste;}
#if DEBUG_COMB
int main ()
{
	Paire p (56., 1); Paire q (120., 2); Paire r (130.5,3);
	Combinaison c (p);
	c.push (q); c.push (r);
	cout << "Somme = "<< c.somme() <<", rendement = " << c.calculeRendement ()<< endl;
	c.affiche ();
	return 0;
}
#endif
