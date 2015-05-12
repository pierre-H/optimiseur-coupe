#ifndef LIST_H
#define LIST_H

#define Car(List) ((List).car())
#define Cdr(List) ((List).cdr())
#define Cadr(List) (List.cdr()->car())
#define Cddr(List) (List.cdr()->cdr)
#define Caddr(List) (List.cdr()->cdr()->car())
#include <vector>

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
        void copie (std::vector<double> * v);
        
        // fonctions d'accès et d'information
        void affiche (bool premier = true) const ;
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
List * createSortedList (List * l= new List(), ...);

#endif // List_H
