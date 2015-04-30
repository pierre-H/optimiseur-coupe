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
        List(float);
        List (List* m_prochain);
        virtual ~List();
        
        List& cons (float);
        List& append (float , ...);
        int supprime ();
        int supprimeNieme (int);
        void supprimeExplicite (float ASupprimer);
        List& insere (float, int);
        void trie (float element);
        void copie (std::vector<float> * v);
        
        // fonctions d'accès et d'information
        void affiche (bool premier = true) const ;
        int member (float);
        float getPremier ();
        List * getProchain ();
        bool empty();
        int length ();

    protected:
        float m_element;
        List * m_prochain;
};

//ex
List * createSortedList (List * l= new List(), ...);

#endif // List_H
