/* main.cpp
 * Optimiseur de Coupe
 * 2015 - Pierre-Emmanuel PIRNAY 11296315
 */

#include <QApplication>
#include <QTranslator>
#include "fenetreprincipale.h"
#include <QMessageBox>

using namespace std;

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QFont police("Ubuntu", 10);
    police.setStyleHint(QFont::SansSerif);
    app.setFont(police);

    // Chargement de la traduction
    QString locale = QLocale::system().name().section('_', 0, 0);
    //locale = "en";
    QTranslator translator;
    translator.load("optimiseurdecoupe_"+locale);
    app.installTranslator(&translator);

    FenetrePrincipale mafenetre;

    mafenetre.show();
    return app.exec();
}
