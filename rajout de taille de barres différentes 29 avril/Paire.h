#ifndef PAIRE_H
#define PAIRE_H

// cette classe est juste un conteneur donc tout est public
class Paire
{
    public:
        Paire();
        Paire (double, int);
        virtual ~Paire();
        void affiche();
        int getPos();
        double getLongueur();
        void setPosition (int);
        void setLongueur(double);


        double m_longueur;   // longueur du troncon
        int m_position;     // position dans le tableau d'où le tronçon a été pris
};


#endif // PAIRE_H
