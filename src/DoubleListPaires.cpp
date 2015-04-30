#include "DoubleListPaires.h"
#include <list>
#include "Paire.h"
#include "List.h"
#include <iostream>

using namespace std;
//============================= DoubleListPaires ===============================

// obligatoirement initialisé avec tous les membres, sauf la liste des
//possibilités qui sera calculée au fur et à mesure

DoubleListPaires::DoubleListPaires(List* troncons, float tailleBarres, int nbBarres)
{
    m_troncons = troncons;
    m_tailleBarres =tailleBarres;
    m_nbBarres = nbBarres;
    m_nbTroncons = m_troncons->length();
    m_troncons->copie(&m_tab);
    m_exigence = 80;
    m_flag = 0;
}


DoubleListPaires::~DoubleListPaires()
{
    m_possibilites.clear();
    m_resultatFinal.clear();
   //dtor
}

// ajoute une combinaison à la liste des possibilités
// si cette combinaison ne dépasse pas la longueur des barres
// et qu'elle est au dessus du niveau d'exigence de rendement
// retourne 0 si on a ajouté à la liste de possibilités
// 1 si c'était plus grand que la taille des barres, et 2 si < que exigence
int DoubleListPaires::push (ListPaires * l)
{
    if ((l->calculeRendement(m_tailleBarres) > 100))
    	return 1;
	if (l->getRendement() < m_exigence)
		return 2;
    m_possibilites.push_back(*l);
    return 0;
}

// fonction récursive
// à partir d'une ListPaires, calcule toutes les combinaisons possibles
// et les rentre dans la liste des possibilités
// renvoie le nombre de possibilités dans la liste
int DoubleListPaires::moteurCombinaisons (ListPaires& l)
{
    int cpt = 0, t;
    Paire * p = new Paire ();
    ListPaires * lp = new ListPaires();
    for (int i= l.getPosDernier()+1; i <= m_troncons->length(); i++)
    {
        *lp = l; 				// copie de la liste donnée en argument
        p->setLongueur(m_tab[i]);
        p->setPosition(i); 		// création d'1 nvelle paire
        lp->push (*p);             // rajout à la liste de paires
        //lp->affiche();
        switch (t = push (lp))
        {
			case 0 :
				cpt++;    // nouvelle possibilité créé rajoutée à la liste
				cpt += moteurCombinaisons(*lp);
				break;
			case 1 :
				break;	// tailler la branche qui dépasse la longueur de la barre
			default :
				cpt += moteurCombinaisons(*lp);
				break;
		}
   }
   return cpt;
}


// renvoie la liste de Paires qui a le plus haut rendement
// de la liste des possibilités déjà calculées

ListPaires&  DoubleListPaires::maxi(ListPaires *lp)
{
    if (m_possibilites.empty())
    {
        cout <<"Liste des possibilités vide..."<<endl;
        return *lp;
    }
    float rendement=0;
    list<ListPaires>::iterator it = m_possibilites.begin();
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

// rentre la meilleure combinaison dans la ListPaires resultatFinal
// supprime les tronçons correspondants dans la liste des tronçons
// recopie le vecteur m_tab avec les nouvelles valeurs de la liste de tronçons
// fait le ménage ds la liste des possibilités
// vérifie s'il n'y a pas trop de tronçons pour le nombre de barres.
bool DoubleListPaires::rentreCombinaisonFinale ()
{
    ListPaires * lp= new ListPaires ();

    if (m_possibilites.empty())
    {
        m_exigence -= 10;
        m_flag = 1;
        return false;
    }
    lp = &maxi(lp);
    m_resultatFinal.push_front (*lp); // rajouter ds combinaisons finales
    list<Paire>::iterator it;
    list<Paire> p = lp->getList();
    for (it = p.begin(); it != p.end(); it++)
        m_troncons->supprimeExplicite (it->getLongueur());
    m_tab.clear();
    m_troncons->copie (&m_tab);
    m_possibilites.clear();
    if (m_resultatFinal.size() > m_nbBarres)
        m_flag = 2;
    return true;
}
// calcule le rendement moyen final quand tous les calculs ont été finis
// exprimé en pourcentage
float DoubleListPaires::calculeRendementFinal ()
{
    float rendement = 0.;
    int cpt = 0;
    list <ListPaires>::iterator it;
    for (it = m_resultatFinal.begin(); it != m_resultatFinal.end(); it++)
    {
        cpt++;
        rendement += it->getRendement();
    }

    return rendement / cpt;
}

// dirige tous les calculs en appelant les fonctions nécessaires
// se charge de l'affichage

void DoubleListPaires::pilote ()
 {
   ListPaires *liste = new ListPaires ();
    while (not getTroncons()->empty())
    {
		moteurCombinaisons(*liste);
		rentreCombinaisonFinale();
		//getTroncons ()->affiche();
	}
	affiche();
	cout << "Vous aurez besoin de "<<m_resultatFinal.size()<<" barres de "<< m_tailleBarres<< "cm" <<endl;
	cout << "Vous avez un rendement moyen de " << calculeRendementFinal ()<<endl;
}
/*===================access=====================*/
List* DoubleListPaires::getTroncons () const
{
    return m_troncons;
}

/*===================affichage=====================*/

void DoubleListPaires::afficheResultats ()
{
    list<ListPaires>::iterator it;
    for (it=m_resultatFinal.begin(); it != m_resultatFinal.end(); it++)
    {
        it->affiche();
    }
}


void DoubleListPaires::affiche()
{
    cout <<"Liste de troncons : ";
    m_troncons->affiche();
    cout << "Liste des possibilites :" <<endl;
    for(list<ListPaires>::iterator it=m_possibilites.begin(); it!= m_possibilites.end(); ++it)
    {
        it->affiche();
    }
    cout << "Exigence : "<<m_exigence<<endl;
    cout <<endl<<"Liste des combinaisons finales : "<<endl;
    afficheResultats();
}
