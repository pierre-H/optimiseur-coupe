/*
 * \file ongletinfo.h
 * \brief Header de la classe OngletInfo
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */


#ifndef ONGLETINFO_H
#define ONGLETINFO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

// \class OngletInfo OngletInfo.h
// \brief Affiche des infos de base concernant le proramme

class OngletInfo : public QWidget
{
    Q_OBJECT
public:
    // \brief Constructeur de la classe OngletInfo
    explicit OngletInfo(QWidget *parent = 0);

signals:

public slots:
};

#endif // ONGLETINFO_H
