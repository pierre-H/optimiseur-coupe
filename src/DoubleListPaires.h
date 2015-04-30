#ifndef DOUBLELISTPAIRES_H
#define DOUBLELISTPAIRES_H

#include <list>
#include "ListPaires.h"
#include "List.h"
#include <iostream>

using namespace std;
// liste de listes de paires
class DoubleListPaires
{
        public:
            DoubleListPaires(List* troncons, float tailleBarres, int);
            virtual ~DoubleListPaires();
            int push (ListPaires *);

            int moteurCombinaisons (ListPaires&);
            ListPaires& maxi (ListPaires * lp=NULL);
            bool rentreCombinaisonFinale ();
            void pilote();
            float calculeRendementFinal ();
/*====================access=====================*/
            List *getTroncons () const;

/*====================affichage=====================*/
            void affiche() ;
            void afficheResultats ();



        protected:
            List * m_troncons;
            int m_nbTroncons;
            float m_tailleBarres;
            int m_nbBarres;
            std::list<ListPaires> m_possibilites;
            std::list<ListPaires> m_resultatFinal;
            std::vector<float>  m_copieTroncons;
            int m_exigence; // prend en compte à partir d'un certain pourcentage
};

#endif // DOUBLELISTPAIRES_H
