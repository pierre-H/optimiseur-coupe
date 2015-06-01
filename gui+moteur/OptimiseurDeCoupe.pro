SOURCES += \
    main.cpp \
    saisie.cpp \
    groupesaisie.cpp \
    convertunit.cpp \
    formulaireSaisie.cpp \
    fenetreprincipale.cpp \
    widgetresultats.cpp \
    moteur/Combinaison.cpp \
    moteur/List.cpp \
    moteur/MoteurCalculs.cpp \
    moteur/Paire.cpp

DISTFILES += \
    readme.md

HEADERS += \
    saisie.h \
    groupesaisie.h \
    convertunit.h \
    formulaireSaisie.h \
    fenetreprincipale.h \
    widgetresultats.h \
    moteur/Combinaison.h \
    moteur/List.h \
    moteur/MoteurCalculs.h \
    moteur/Paire.h

QT += widgets
QT += core

TRANSLATIONS = optimiseurdecoupe_en.ts
