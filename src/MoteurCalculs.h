#ifndef MOTEURCALCULS_H
#define MOTEURCALCULS_H

#include <list>
#include "Combinaison.h"
#include "List.h"
#include <iostream>

using namespace std;
// liste de listes de paires
class MoteurCalculs
{
        public:
            MoteurCalculs(List* troncons, List * barres);
            virtual ~MoteurCalculs();
            int push (Combinaison *);

            int moteurCombinaisons (Combinaison&);
            Combinaison& maxi (Combinaison * lp=NULL);
            bool rentreCombinaisonFinale ();
            void pilote();
            double calculeRendementFinal ();
/*====================access=====================*/
            List *getTroncons () const;
            List * getBarres () const;

/*====================affichage=====================*/
            void affiche() ;



        protected:
            List * m_troncons;	// liste des tronçons qu'on veut
            List * m_barres;    // liste des barres dont on dispose   
            std::list<Combinaison> m_possibilites;
            std::list<Combinaison> m_resultatFinal;
            std::vector<double>  m_copieTroncons;
            int m_exigence; // prend en compte à partir d'un certain pourcentage
};

#endif // MoteurCalculs_H
