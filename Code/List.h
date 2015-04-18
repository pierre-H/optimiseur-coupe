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
        List();
        List(float);
        List (List* m_prochain);

        virtual ~List();

        void affiche (bool premier = true) const ;
        List& cons (float);
        int length ();
        List& append (float , ...);
        int member (float);
        int supprime ();
        int supprimeNieme (int);
        void supprimeExplicite (float ASupprimer);
        List& insere (float, int);
        float car ();
        List* cdr();
        void trie (float element);
        // définies ds moteur
        int ordreCombinaison (float tailleBarres);
        void copie (std::vector<float> * v);
        List * getProchain ();
        float getPremier ();

        bool empty();

    protected:
        float m_element;
        List * m_prochain;
};

//prototype
List * createSortedList (List * l= new List(), ...);

#endif // List_H
