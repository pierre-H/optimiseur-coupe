/* MoteurCalculs.h
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#ifndef MOTEURCALCULS_H
#define MOTEURCALCULS_H

#include <list>
#include "Combinaison.h"
#include "List.h"
#include <iostream>
#include "Paire.h"
#include <cstdlib>

// pour détecter les boucles infinies
extern int limite;
extern int * lim;

using namespace std;
// liste de listes de paires
class MoteurCalculs
{
        public:
            MoteurCalculs(List* troncons, List * barres, double perte);
            virtual ~MoteurCalculs();
            int push (Combinaison *);
            void ajoutePerte ();
            int moteurCombinaisons (Combinaison&);
            int doublons (double longueur, int position);
            Combinaison& maxi (Combinaison * lp=NULL);
            bool rentreCombinaisonFinale ();
            int pilote();
            double calculeRendementFinal ();
/*====================access=====================*/
            List *getTroncons () const;
            List * getBarres () const;
            double getPerte () const;
            std::list<Combinaison> getResultatFinal() const;
            std::list<Combinaison> * getPointResultatFinal();
            int getExigence() const;

#if DEBUG
/*====================affichage=====================*/
            void affiche() ;
#endif

        protected:
            List * m_troncons;	// liste des tronçons qu'on veut
            List * m_barres;    // liste des barres dont on dispose
            std::list<Combinaison> m_possibilites;
            std::list<Combinaison> m_resultatFinal;
            QVector<double>  m_copieTroncons;
            int m_exigence; 		// prend en compte à partir d'un certain pourcentage
            double m_perteCoupe;	// perte occasionnée à chaque coupe
};

#endif // MoteurCalculs_H
