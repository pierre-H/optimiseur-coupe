/* List.h
 * Optimiseur de Coupe
 * 2015 - Rebecca Charbit
 */

#ifndef MYLIST_H
#define MYLIST_H

#define Car(List) ((List).car())
#define Cdr(List) ((List).cdr())
#define Cadr(List) (List.cdr()->car())
#define Cddr(List) (List.cdr()->cdr)
#define Caddr(List) (List.cdr()->cdr()->car())

#include <iostream>
#include <stdarg.h>
#include <list>
#include <QVector>
#include "../saisies/saisie.h"
#include "../convertunit.h"

#if DEBUG
//rien
#else
#include <QString>
#endif

class List
{
	public:
		// fonctions de construction et de destruction
		List();
		List(double);
		List (List* m_prochain);
		virtual ~List();
		
		List& cons (double);
		List& append (double , ...);
		int supprime ();
		int supprimeNieme (int);
		void supprimeExplicite (double ASupprimer);
		List& insere (double, int);
		void trie (double element);
        void copie (QVector<double> * v);
		void setPremier (double e);
		
		// fonctions d'accès et d'information
#if DEBUG
		void affiche (bool premier = true) const ;
#else
        QString toStr(bool premier = true) const;
#endif
		int member (double)const;
		double getPremier ()const;
		List * getProchain ()const;
		bool empty()const;
		int length ()const;
		double max () ;
		double min ();


	protected:
		double m_element;
		List * m_prochain;
};

//ex
List * createSortedList (List * l, double tab []);
List * createSortedList (List * l, QVector<Saisie *> vecteur);

#endif // MYList_H
