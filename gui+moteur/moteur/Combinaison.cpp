/* Combinaison.cpp
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#include "Combinaison.h"

using namespace std;

Combinaison::Combinaison() : m_rendement(0.0), m_barre (0.1)
{}

Combinaison::Combinaison(Paire& p) : m_rendement(0.0), m_barre (0.1)
{
    m_liste.push_back(p);
}

Combinaison::~Combinaison()
{}

#if DEBUG
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
#else
QString Combinaison::toStr(){
    QString text = QObject::tr("<li>Sur une barre de ") + ConvertUnit::toStrSimplifie(m_barre) + " :<br>";
    for (list<Paire>::iterator it = m_liste.begin(); it != m_liste.end(); it++)
    {
        if (it != m_liste.begin())
            text+= ", ";
        text+=it->toStr();
    }
    text+= "<br>";
    text+= QObject::tr("Le rendement est de ") + QString::number(m_rendement,'g', 4) + "\%.<br></li>";
    return text;
}
#endif


void Combinaison::push (Paire p)
{
    m_liste.push_back(p);
}

void Combinaison::push (double e, int pos)
{
    Paire *p =new Paire(e, pos);
    push(*p);
    delete p;
}

// retourne la somme des longueurs des troncons de la combinaison
double Combinaison::somme ()
{
    double sum = 0.;
    for (list<Paire>::iterator it = m_liste.begin() ; it != m_liste.end(); it++)
        sum += it->m_longueur;
    return sum;
}

// calcule le rendement de la combinaison
// tient compte de la perte à la coupe
// c'est à dire que l'enlève avant de calculer
double Combinaison::calculeRendement (double perte)
{
    m_rendement = (somme() - perte * m_liste.size())/m_barre*100;
    return m_rendement;
}



// attacheBarre choisit dans la liste des barres la barre la plus proche de la somme
// des tronçons de la combinaison
// retourne -1.0 s'il n'y a pas de barre assez grande pour cette combinaison
// vérifie la cas d'une combinaison de 100% où il faut compter une coupe en moins
double Combinaison::attacheBarre (List* barres, double perte)
{
    double barreChoisie, diff;
    List * pt;
    if (barres)
    {
        pt = barres->getProchain();
        diff =  pt->getPremier () - somme(); // différence entre barre et somme des tronçons
        barreChoisie = pt->getPremier();
    }
    else
        cout <<"Liste des barres vide !"<<endl;
    while (pt)
    {
        if (diff <= perte-2*perte)
        {
            barreChoisie = pt->getPremier();
            diff =  pt->getPremier () - somme();
            pt = pt->getProchain ();
            continue;
        }
        if ((pt->getPremier() - somme() >= perte-2*perte) and (pt->getPremier() - somme() <= diff))
        {
            barreChoisie = pt->getPremier();
            diff = pt->getPremier () - somme();
        }
        pt = pt->getProchain ();
    }
    if (barreChoisie - somme () >= perte-2*perte )
    {
        m_barre = barreChoisie;
        return barreChoisie;
    }
    else
        return -1.;	// il n'y a pas de barre assez grande pour cette combinaison
}

// Dans chacun des tronçons d'une combinaison, retranche la perte due
// à la coupe
// utilisé dans rentreCombinaisonFinale
void Combinaison::retranchePerte (double perte)
{
    list<Paire>::iterator it;
    for (it = m_liste.begin(); it != m_liste.end() ; it++)
        if (it->getLongueur() -perte >=0) it->setLongueur(it->getLongueur() - perte);
}

double Combinaison::getRendement() const
{return m_rendement;}

list<Paire> Combinaison::getPaires() const
{return m_liste;}

double Combinaison::getBarre () const
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
