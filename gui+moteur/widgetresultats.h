/*
 * \file widgetresultats.h
 * \brief Header de la classe WidgetResultats
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 *
 */

#ifndef WIDGETRESULTATS_H
#define WIDGETRESULTATS_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QScrollArea>
#include <QPalette>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>

/*
 * \class WidgetResultats widgetresultats.h
 * \brief Classe Affiche (uniquement, aucun calcul fait) les résultats sous forme texte
 */

class WidgetResultats : public QWidget
{
    Q_OBJECT
public:
    // \brief Constructeur de la classe
    // \param fontTitre Police du titre principal
    explicit WidgetResultats(QFont & fontTitre, QWidget *parent = 0);

    // \brief Mets à jour le texte des résultats
    // \param text Le texte à afficher
    void updateResultats(QString & text);
private:
    QTextEdit * m_labelResultat;
signals:

public slots:
    // \brief Slot lançant l'affichage de l'aire
    void afficheAide();
};

#endif // WIDGETRESULTATS_H
