/* Paire.h
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#include "Paire.h"

using namespace std;  

Paire::Paire() : m_longueur(0), m_position (0)
{
	//ctor
}

Paire::~Paire()
{
	//dtor
}
//surcharge du constructeur
Paire::Paire (double valeur, int position) : m_longueur(valeur), m_position(position)
{

}

#if DEBUG
void Paire::affiche ()
{
	cout <<m_longueur ;
}
#else
QString Paire::toStr() const{
    return ConvertUnit::toStrSimplifie(m_longueur);
}
#endif

int Paire::getPos()
{return m_position;}

double Paire::getLongueur()
{return m_longueur;}

 void Paire::setPosition (int pos)
 {m_position = pos;}

 void Paire::setLongueur (double l)
 {m_longueur=l;}
