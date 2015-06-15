/* Combinaison.h
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#ifndef COMBINAISON_H
#define COMBINAISON_H

#include "Paire.h"
#include "List.h"
#include <list>
#include <iostream>
#include <cstdio>
#include "../convertunit.h"

#if DEBUG
//rien
#else
#include <QObject>
#include <QString>
#endif

// liste de Paires
class Combinaison
{
	public:
		Combinaison();
		Combinaison(Paire&);
		virtual ~Combinaison();
#if DEBUG
		void affiche();
#else
        QString toStr();
#endif
		void push (Paire);
		void push (double , int);
		double calculeRendement (double perte);
		double getRendement() const;
        std::list<Paire> getPaires() const;
		double getBarre () const;
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
