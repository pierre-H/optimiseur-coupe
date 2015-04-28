#include "List.h"
#include "Moteur.h"
#include <iostream>
#include <vector>

using namespace std;

// calcule l'ordre de la combinaison.
// quel est le nombre maximal de tronçons qui peuvent exister
// dans une combinaison en sachant la taille des barres ?

int List::ordreCombinaison (float tailleBarres)
{
    float somme = 0, cpt=0;
    List * pt = this;
    while (somme <= tailleBarres)
    {
        somme += pt->m_element;
        if (pt == NULL) break;
        pt = pt->m_prochain;
        if (somme <= tailleBarres) cpt ++;
    }
    return cpt;
}

// copie une liste dans un vecteur et le renvoie pour travailler par index
void List::copie(vector<float> * v)
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
