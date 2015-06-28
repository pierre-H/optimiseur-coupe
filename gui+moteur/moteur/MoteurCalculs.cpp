/* MoteurCalculs.cpp
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#include "MoteurCalculs.h"

using namespace std;
int limite = 0;
int * lim = &limite;
//============================= MoteurCalculs ===============================

// obligatoirement initialisé avec tous les membres, sauf la liste des
//possibilités qui sera calculée au fur et à mesure

MoteurCalculs::MoteurCalculs(List* troncons, List *barres, double perte)
{
    m_perteCoupe = perte;
    m_troncons = troncons;
    ajoutePerte ();
    m_barres = barres;
    m_troncons->copie(&m_copieTroncons);
    m_exigence = 100;
    *lim = 0;
}


MoteurCalculs::~MoteurCalculs()
{
    m_possibilites.clear();
    m_resultatFinal.clear();
   //dtor
}

// ajoutePerte ajoute la longueur de perte à la coupe de
// chacun des tronçons de la liste de tronçons
// utilisée dans pilote avant toute opération
void MoteurCalculs::ajoutePerte ()
{
    List * it = m_troncons; // itérateur
    while (it)
    {
        it->setPremier (it->getPremier () + m_perteCoupe);
        it = it->getProchain ();
    }
}

// calcule le rendement moyen final quand tous les calculs ont été finis
// exprimé en pourcentage
double MoteurCalculs::calculeRendementFinal ()
{
    double sum = 0., sumBarres=0.;
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
int MoteurCalculs::pilote ()
{
    Combinaison *liste = new Combinaison ();
    while ((not getTroncons()->empty()) and (not getBarres()->empty()) and (m_exigence >= 0))
    {
        if (moteurCombinaisons(*liste) == -1) return (-1);
        rentreCombinaisonFinale();
    }
    return 0;
    #if DEBUG
    affiche ();
    #endif
}


// fonction récursive
// à partir d'une Combinaison, calcule toutes les combinaisons possibles
// et les rentre dans la liste des possibilités
// renvoie le nombre de possibilités dans la liste
int MoteurCalculs::moteurCombinaisons (Combinaison& l)
{
    int cpt = 0, t;
    Paire * p = new Paire ();
    Combinaison * lp = new Combinaison();
    for (int i= l.getPosDernier()+1; i <= m_troncons->length(); i++)
    {
        if (limite > 2000000) return(-1);
        if (doublons (m_copieTroncons[i], i))
            break;
        *lim=*lim + 1;
        *lp = l; 				// copie de la liste donnée en argument
        p->setLongueur(m_copieTroncons[i]);
        p->setPosition(i); 		// création d'1 nvelle paire
        lp->push (*p);          // rajout à la liste de paires
        switch (t = push (lp))
        {
            case 0 :
                cpt++;   // nouvelle possibilité créé rajoutée à la liste
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

// renvoie 1 s'il on a déjà effectué des combinaisons commençant par un tronçon différent, mais de même taille
// c'est à dire un doublon. Renvoie 0 sinon
int MoteurCalculs::doublons (double longueur, int position)
{
    list<Combinaison>::iterator itComb;
    list<Paire>::iterator itPair;
    for (itComb = m_possibilites.begin(); itComb != m_possibilites.end(); itComb++)
    {
        itPair = itComb->getPaires().begin();
        if (itPair->getLongueur() == longueur && itPair->getPos() != position)
            return 1;
    }
    return 0;
}


// ajoute une combinaison à la liste des possibilités
// si cette combinaison ne dépasse pas la longueur des barres
// et qu'elle est au dessus du niveau d'exigence de rendement.
// Retourne 0 si on a ajouté à la liste de possibilités
// 1 si c'était plus grand que la taille de la plus grande barre,
// et 2 si < que exigence sur la plus petite barre
int MoteurCalculs::push (Combinaison * l)
{
    double result = l->attacheBarre (m_barres, m_perteCoupe);
    if (result == -1.)	//si dépasse la taille de la plus grande barre
        return 1;
    if (l->calculeRendement(m_perteCoupe) < m_exigence)	// trop mauvais rendement pour le retenir
        return 2;
    m_possibilites.push_back(*l);						// encore avec la perte à la coupe
    return 0;
}

// rentre la meilleure combinaison dans la Combinaison resultatFinal
// supprime les tronçons correspondants dans la liste des tronçons
// supprime la barre correspondante dans la liste des barres
// recopie le vecteur m_copieTroncons avec les nouvelles valeurs de la liste de tronçons
// fait le ménage ds la liste des possibilités
// vérifie s'il n'y a pas trop de tronçons pour le nombre de barres.
bool MoteurCalculs::rentreCombinaisonFinale ()
{
    Combinaison * lp= new Combinaison ();
    if (m_possibilites.empty())
    {
        m_exigence -= 10;
        return false;
    }
    lp = &maxi(lp);
    list<Paire>::iterator it;
    list<Paire> p = lp->getPaires();
    for (it = p.begin(); it != p.end(); it++)
        m_troncons->supprimeExplicite (it->getLongueur());
    lp->retranchePerte (m_perteCoupe);
    m_resultatFinal.push_front (*lp); // rajouter ds combinaisons finales
    m_barres->supprimeExplicite (lp->getBarre());
    m_copieTroncons.clear();
    m_troncons->copie (&m_copieTroncons);
    m_possibilites.clear();
    return true;
}

// renvoie la liste de Paires qui a le plus haut rendement
// de la liste des possibilités déjà calculées
// Modifie les tronçons qui prennent en compte la perte en leur longueur sans coupe
Combinaison&  MoteurCalculs::maxi(Combinaison *lp)
{
    if (m_possibilites.empty())
    {
        cout <<"Liste des possibilités vide..."<<endl;
        return *lp;
    }
    double rendement=0;
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
/*===================access=====================*/

List* MoteurCalculs::getTroncons () const
{
    return m_troncons;
}

List* MoteurCalculs::getBarres () const
{
    return m_barres;
}

double MoteurCalculs::getPerte () const
{
    return m_perteCoupe;
}

std::list<Combinaison> MoteurCalculs::getResultatFinal() const
{
    return m_resultatFinal;
}

std::list<Combinaison> *MoteurCalculs::getPointResultatFinal()
{
    return & m_resultatFinal;
}

int MoteurCalculs::getExigence() const
{
    return m_exigence;
}


#if DEBUG
/*===================affichage=====================*/


void MoteurCalculs::affiche()
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

#endif
