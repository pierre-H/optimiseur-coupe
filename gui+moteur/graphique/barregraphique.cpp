#include "barregraphique.h"

BarreGraphique::BarreGraphique(Combinaison * combinaison, QWidget *parent) :QWidget(parent), m_combinaison(combinaison)
{
    setMinimumHeight(65);
    setMinimumWidth(500);
    m_liste = m_combinaison->getPaires();
    m_barre = m_combinaison->getBarre();
}


// Dessine la découpe d'une barre
void BarreGraphique::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    // Affiche "Sur une barre de ...
    painter.drawText(QPoint(0,10), tr("Sur une barre de ") + ConvertUnit::toStrSimplifie(m_barre) + " :");

    // Calcul le nb de pixels dispos
    int longueur = 0, i, typeAffichage;
    double longueurUtilisee = 0;
    std::list<Paire>::iterator it;
    for (it = m_liste.begin(); it != m_liste.end(); it++)
        longueur++;
    longueur = 500 - ((longueur-1)*5); // 5 px d'espace entre les carrés

    // Calcul la façon dont sera affiché le graphique
    it = m_liste.begin();
    if((longueur * (int) it->getLongueur() / m_barre) < 45){
        for (it = m_liste.begin(); it != m_liste.end(); it++)
            longueurUtilisee += it->getLongueur();
        typeAffichage = 0;
    }
    else
        typeAffichage = 1;

    // QPoints
    QPoint a(0,20), b;
    b.setY(55);

    QRect rec;

    // Affichage des rectangles
    for (it = m_liste.begin(); it != m_liste.end(); it++){
        if(typeAffichage == 1)
            i = (longueur * (int) it->getLongueur()) / m_barre;
        else
            i = (longueur * (int) it->getLongueur()) / (int) longueurUtilisee;
        b.setX(a.x() + i);
        rec.setTopLeft(a);
        rec.setBottomRight(b);
        painter.drawRect(rec);
        painter.drawText(rec, Qt::AlignCenter, it->toStr());
        a.setX(b.x() + 5);
    }
}
