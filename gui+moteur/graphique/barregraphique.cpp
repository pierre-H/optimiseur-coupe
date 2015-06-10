#include "barregraphique.h"

BarreGraphique::BarreGraphique(Combinaison * combinaison, QWidget *parent) :m_combinaison(combinaison), m_height(55), QWidget(parent)
{
    setMinimumHeight(m_height);
}


// Dessine la découpe d'une barre
void BarreGraphique::paintEvent(QPaintEvent *e)
{
    std::list<Paire> liste = m_combinaison->getPaires();
    int compteur = 0, longueur = 500;
    double carreLongueur;

    // Compte le nombre de coupe
    for (std::list<Paire>::iterator it = liste.begin(); it != liste.end(); it++){
        compteur++;
    }
    longueur -= compteur*15;

    // Painter
    QPainter painter(this);
    QPoint topLeft, bottomRight;
    QString text = "Sur une barre de " + ConvertUnit::toStrSimplifie(m_combinaison->getBarre()) + ".";
    painter.drawText(0,10, text);
    topLeft.setX(10);
    topLeft.setY(15);
    bottomRight.setY(m_height-10);
    for (std::list<Paire>::iterator it = liste.begin(); it != liste.end(); it++){
        carreLongueur = ( longueur * it->getLongueur() ) / m_combinaison->getBarre();
        bottomRight.setX(((int) carreLongueur) + topLeft.x());
        QRect rec(topLeft, bottomRight);
        painter.drawRect(rec);
        painter.drawText(rec, Qt::AlignCenter, it->toStr());
        topLeft.setX(bottomRight.x()+15);
    }
}
