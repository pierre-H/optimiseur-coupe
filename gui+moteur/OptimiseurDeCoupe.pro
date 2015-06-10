HEADERS += \
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
    wigetgraphique.h \
    graphique/barregraphique.h \
    graphique/wigetgraphique.h

SOURCES += \
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
    graphique/barregraphique.cpp \
    graphique/wigetgraphique.cpp

QT += widgets
QT += core

TRANSLATIONS = optimiseurdecoupe_en.ts

RC_ICONS = mainIcon.ico
