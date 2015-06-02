HEADERS += \
    graphique/widgetgraphique.h \
    moteur/Combinaison.h \
    moteur/List.h \
    moteur/MoteurCalculs.h \
    moteur/Paire.h \
    saisies/groupesaisie.h \
    saisies/saisie.h \
    convertunit.h \
    fenetreprincipale.h \
    formulaireSaisie.h \
    widgetresultats.h \
    graphique/barregraphique.h

SOURCES += \
    graphique/widgetgraphique.cpp \
    moteur/Combinaison.cpp \
    moteur/List.cpp \
    moteur/MoteurCalculs.cpp \
    moteur/Paire.cpp \
    saisies/groupesaisie.cpp \
    saisies/saisie.cpp \
    convertunit.cpp \
    fenetreprincipale.cpp \
    formulaireSaisie.cpp \
    main.cpp \
    widgetresultats.cpp \
    graphique/barregraphique.cpp

QT += widgets
QT += core

TRANSLATIONS = optimiseurdecoupe_en.ts

RC_ICONS = mainIcon.ico
