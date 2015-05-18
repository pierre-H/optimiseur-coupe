// Optimiseur de coupe

#include <QApplication>
#include <QTranslator>
#include "fenetreprincipale.h"

using namespace std;

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    // Chargement de la traduction
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load("optimiseurdecoupe_en"+locale);
    app.installTranslator(&translator);

    FenetrePrincipale mafenetre;

    mafenetre.show();
    return app.exec();
}
