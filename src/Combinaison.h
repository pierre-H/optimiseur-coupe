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
		void push (double , int);
		double calculeRendement (double perte);
		double getRendement();
		std::list<Paire> getList();
		std::list<Paire> getPaires();
		double getBarre ();
		double somme ();
		int getPosDernier ();
		double attacheBarre (List* barres, double perte);
		void retranchePerte (double perte);


	protected:
		double m_rendement; 		// rendement de la combinaison
		std::list<Paire> m_liste;	// liste des tronçons de la combinaison
		double m_barre;				// barre à laquelle s'applique la combinaison
};


#endif // COMBINAISON_H
