#ifndef ListPaires_H
#define ListPaires_H
#include "Paire.h"
#include <list>

// liste de Paires
class ListPaires
{
        public:
                ListPaires();
                ListPaires(Paire&);
                virtual ~ListPaires();
                void affiche();
                void push (Paire);
                void push (float , int);
                float calculeRendement (float longueurBarres);
                float getRendement();
                std::list<Paire> getList();
                std::list<Paire> getPaires();
                int getPosDernier ();


        protected:
                float m_rendement; // rendement de la combinaison
                std::list<Paire> m_liste;
};

#endif // ListPaires_H
