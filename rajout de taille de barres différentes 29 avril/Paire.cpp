#include "Paire.h"
#include <iostream>
#include <list>

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
Paire::Paire (float valeur, int position) : m_longueur(valeur), m_position(position)
{

}

void Paire::affiche ()
{
    cout <<"(" <<m_longueur << ", " << m_position << ")";
}

int Paire::getPos()
{return m_position;}

float Paire::getLongueur()
{return m_longueur;}

 void Paire::setPosition (int pos)
 {m_position = pos;}

 void Paire::setLongueur (float l)
 {m_longueur=l;}
