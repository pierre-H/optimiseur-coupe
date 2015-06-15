/* Paire.h
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#ifndef PAIRE_H
#define PAIRE_H

#include <iostream>
#include <list>
#include "../convertunit.h"
#include <iostream>

#if DEBUG
//Rien
#else
#include <QString>
#endif

// cette classe est juste un conteneur donc tout est public
class Paire
{
	public:
		Paire();
		Paire (double, int);
		virtual ~Paire();
#if DEBUG
        void affiche();
#else
        QString toStr() const;
#endif
		int getPos();
		double getLongueur();
		void setPosition (int);
		void setLongueur(double);


		double m_longueur;   // longueur du troncon
		int m_position;     // position dans le tableau d'où le tronçon a été pris
};


#endif // PAIRE_H
