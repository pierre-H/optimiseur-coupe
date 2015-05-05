#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "Paire.h"
#include "List.h"
#include <list>

// liste de Paires
class Combinaison
{
    public:
        Combinaison();
        Combinaison(Paire&);
        virtual ~Combinaison();
        void affiche();
        void push (Paire);
        void push (float , int);
        float calculeRendement ();
        float getRendement();
        std::list<Paire> getList();
        std::list<Paire> getPaires();
		float getBarre ();
		float somme ();
		int getPosDernier ();
		float attacheBarre (List* barres);


	protected:
		float m_rendement; 	// rendement de la combinaison
		std::list<Paire> m_liste;
		float m_barre;		// barre à laquelle s'applique la combinaison
};


#endif // COMBINAISON_H
