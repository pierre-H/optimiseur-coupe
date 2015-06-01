#include "formulaireSaisie.h"

FormulaireSaisie::FormulaireSaisie(QWidget *parent) : QWidget(parent)
{
    // Layout principal
    QVBoxLayout * layoutPrincipal = new QVBoxLayout;

    // Label : demande de remplir les infos
    QLabel * labelRemplirInfos = new QLabel(tr("Veuillez remplir les informations suivantes :"));
    QFont fontTitre1("Droid Sans", 12);
    fontTitre1.setBold(true);
    labelRemplirInfos->setFont(fontTitre1);

    // Groupes de saisie
    QFont fontTitre2("Droid Sans", 10);
    fontTitre2.setBold(true);
    m_groupeSaisieBarres = new GroupeSaisie(tr("Barres avant la découpe :"), fontTitre2);
    m_groupeSaisieTron = new GroupeSaisie(tr("Tronçons désirés :"), fontTitre2);

    // Label Epaisseur de lame
    QLabel * labelEpaisseur = new QLabel(tr("Epaisseur de lame"));
    labelEpaisseur->setFont(fontTitre2);

    // Epaisseur de lame
    m_epaisseurLame = new QDoubleSpinBox;
    m_epaisseurLame->setMinimum(0);

    // Unité épaisseur de lame
    m_uniteEpaisseurLame = new QComboBox;
    m_uniteEpaisseurLame->addItem("mm");
    m_uniteEpaisseurLame->addItem("in");

    // Bouton Appliquer et Quitter et changement de mode
    m_buttonAppliquer = new QPushButton(tr("Appliquer"));
    m_buttonAppliquer->setDefault(true);
    m_buttonQuitter = new QPushButton(tr("Quitter"));

    // Layout pour Epaisseur et les boutons Appliquer/Quitter
    QHBoxLayout * layoutEpaiButt = new QHBoxLayout;
    layoutEpaiButt->addWidget(m_epaisseurLame);
    layoutEpaiButt->addWidget(m_uniteEpaisseurLame);
    layoutEpaiButt->addStretch();
    layoutEpaiButt->addWidget(m_buttonAppliquer);
    layoutEpaiButt->addWidget(m_buttonQuitter);

    // ajout des widgets au  Layout Principal
    layoutPrincipal->addWidget(labelRemplirInfos);
    layoutPrincipal->addWidget(m_groupeSaisieBarres);
    layoutPrincipal->addWidget(m_groupeSaisieTron);
    layoutPrincipal->addWidget(labelEpaisseur);
    layoutPrincipal->addLayout(layoutEpaiButt);

    // Set Layout Principal
    setLayout(layoutPrincipal);

    // Connexion signaux/slots
    QObject::connect(m_buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

QPushButton * FormulaireSaisie::buttonAppliquer() const{
    return m_buttonAppliquer;
}

GroupeSaisie * FormulaireSaisie::groupeSaisieBarres() const{
    return m_groupeSaisieBarres;
}

GroupeSaisie * FormulaireSaisie::groupeSaisieTron() const{
    return m_groupeSaisieTron;
}

double FormulaireSaisie::epaisseurLame() const{
    return ConvertUnit::toMm(m_epaisseurLame->value(), m_uniteEpaisseurLame->currentText());
}

QComboBox * FormulaireSaisie::uniteEpaisseurLame() const{
    return m_uniteEpaisseurLame;
}

FormulaireSaisie::~FormulaireSaisie()
{

}
