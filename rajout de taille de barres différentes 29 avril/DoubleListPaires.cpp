#include "DoubleListPaires.h"
#include <list>
#include "Paire.h"
#include "List.h"
#include <iostream>


using namespace std;
//============================= DoubleListPaires ===============================

// obligatoirement initialisé avec tous les membres, sauf la liste des
//possibilités qui sera calculée au fur et à mesure

DoubleListPaires::DoubleListPaires(List* troncons, List *barres)
{
    m_troncons = troncons;
    m_barres = barres;
    m_troncons->copie(&m_copieTroncons);
    m_exigence = 80;
}


DoubleListPaires::~DoubleListPaires()
{
    m_possibilites.clear();
    m_resultatFinal.clear();
   //dtor
}

// ajoute une combinaison à la liste des possibilités
// si cette combinaison ne dépasse pas la longueur des barres
// et qu'elle est au dessus du niveau d'exigence de rendement.
// Retourne 0 si on a ajouté à la liste de possibilités
// 1 si c'était plus grand que la taille de la plus grande barre,
// et 2 si < que exigence sur la plus petite barre
int DoubleListPaires::push (Combinaison * l)
{
	float result = l->attacheBarre (m_barres);
    if (result == -1.)	//si dépasse la taille de la plus grande barre
    	return 1;
	if (l->calculeRendement() < m_exigence)	// trop mauvais rendement pour le retenir
		return 2;
    m_possibilites.push_back(*l);
    return 0;
}

// fonction récursive
// à partir d'une Combinaison, calcule toutes les combinaisons possibles
// et les rentre dans la liste des possibilités
// renvoie le nombre de possibilités dans la liste
int DoubleListPaires::moteurCombinaisons (Combinaison& l)
{
    int cpt = 0, t;
    Paire * p = new Paire ();
    Combinaison * lp = new Combinaison();
    for (int i= l.getPosDernier()+1; i <= m_troncons->length(); i++)
    {
        *lp = l; 				// copie de la liste donnée en argument
        p->setLongueur(m_copieTroncons[i]);
        p->setPosition(i); 		// création d'1 nvelle paire
        lp->push (*p);             // rajout à la liste de paires
        switch (t = push (lp))
        {
			case 0 :
				cpt++;    // nouvelle possibilité créé rajoutée à la liste
				cpt += moteurCombinaisons(*lp);
				break;
			case 1 :	// tailler la branche qui dépasse la longueur de la barre
				break;	
			default :	// pas rajouter mais continuer de mouliner
				cpt += moteurCombinaisons(*lp);
				break;
		}
   }
   return cpt;
}

// renvoie la liste de Paires qui a le plus haut rendement
// de la liste des possibilités déjà calculées

Combinaison&  DoubleListPaires::maxi(Combinaison *lp)
{
    if (m_possibilites.empty())
    {
        cout <<"Liste des possibilités vide..."<<endl;
        return *lp;
    }
    float rendement=0;
    list<Combinaison>::iterator it = m_possibilites.begin();
    lp = &(*it);
    for (it = m_possibilites.begin(); it != m_possibilites.end(); it++)
    {
        if (it->getRendement() > rendement)
        {
            rendement = it->getRendement();
            lp = &(*it);
        }
    }
    return *lp;
}

// rentre la meilleure combinaison dans la Combinaison resultatFinal
// supprime les tronçons correspondants dans la liste des tronçons
// supprime la barre correspondante dans la liste des barres
// recopie le vecteur m_copieTroncons avec les nouvelles valeurs de la liste de tronçons
// fait le ménage ds la liste des possibilités
// vérifie s'il n'y a pas trop de tronçons pour le nombre de barres.
bool DoubleListPaires::rentreCombinaisonFinale ()
{
    Combinaison * lp= new Combinaison ();
    if (m_possibilites.empty())
    {
        m_exigence -= 10;
        return false;
    }
    lp = &maxi(lp);
    m_resultatFinal.push_front (*lp); // rajouter ds combinaisons finales
    list<Paire>::iterator it;
    list<Paire> p = lp->getList();
    for (it = p.begin(); it != p.end(); it++)
        m_troncons->supprimeExplicite (it->getLongueur());
    m_barres->supprimeExplicite (lp->getBarre());
    m_copieTroncons.clear();
    m_troncons->copie (&m_copieTroncons);
    m_possibilites.clear();
    return true;
}
// calcule le rendement moyen final quand tous les calculs ont été finis
// exprimé en pourcentage
float DoubleListPaires::calculeRendementFinal ()
{
    float sum = 0., sumBarres=0.;
    list <Combinaison>::iterator it;
    for (it = m_resultatFinal.begin(); it != m_resultatFinal.end(); it++)
    {
        sum += it->somme();
        sumBarres += it->getBarre ();
    }
    return sum / sumBarres *100;
}

// dirige tous les calculs en appelant les fonctions nécessaires
// se charge de l'affichage

void DoubleListPaires::pilote ()
{
   Combinaison *liste = new Combinaison ();
    while ((not getTroncons()->empty()) and (not getBarres()->empty()))
    {
		moteurCombinaisons(*liste);
		rentreCombinaisonFinale();
	}
	affiche ();
}
/*===================access=====================*/
List* DoubleListPaires::getTroncons () const
{
    return m_troncons;
}

List* DoubleListPaires::getBarres () const
{
    return m_barres;
}

/*===================affichage=====================*/



void DoubleListPaires::affiche()
{
	if (m_troncons->empty ())
		cout <<"Vous avez réussi à couper tous les tronçons que vous désiriez." << endl;
	else
	{
    	cout <<"Vous n'avez pas eu assez de matière première pour couper tous les tronçons que vous désiriez... Liste de troncons restants: ";
    	m_troncons->affiche();
    }
    if (m_barres->empty ())
		cout <<"Vous avez utilisé toutes vos barres." << endl;
	else
	{
    	cout <<"Il vous reste des barres entières que vous n'avez pas utilisées : Liste des barres restantes: ";
    	m_barres->affiche();
    }
    cout << "Voici la liste des coupes que vous devez effectuer : " << endl;
    for(list<Combinaison>::iterator it=m_resultatFinal.begin(); it!= m_resultatFinal.end(); ++it)
    {
        it->affiche();
        cout <<endl;
    }
    cout << "Exigence : "<<m_exigence<<endl;
	cout << "Vous avez un rendement moyen de " << calculeRendementFinal ()<<"%"<<endl;
}
