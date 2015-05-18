## Ce que le moteur attend :

Le moteur n'a besoin de la part de l'interface que de deux tableaux se terminant par 0 :
Un qui contient les barres disponibles et l'autre qui contient les tronçons demandés.
NE PAS OUBLIER LE 0 A LA FIN DE CHACUN DE CES DEUX TABLEAUX !

## Affichage des résultats :

Le moteur tourne sur un espèce de gros objet qui porte le nom de DoubleListPaires.
A la fin des calculs, cet objet contient tout ce dont on a besoin pour afficher les résultats.

Pour ce qui est de l'affichage des résultats :
Pour l'instant, j'ai délégué cette partie à une fonction affiche, membre de la classe DoubleListPaires.
Cette fonction est appelée par pilote () (qui est la fonction directrice du moteur)

Pour l'instant, les différents messages sont :
- Si on a réussi à couper tous les troncons ou s'il manquait de la matière première
- Si on a utilisé toutes les barres de départ ou s'il en reste encore
- L'explication des coupes avec le rendement associé à chaque barre.
- Le rendement moyen de toute la coupe.

En gros, après le calcul, on a ce gros objet DoubleListPaires
Pour info, voici le contenu de cet objet expliqué :

        protected:
            **List * m_troncons;**	
            
            /* liste des tronçons qu'on veut. 
            Pour vérifier si tous ont pu être coupés et qu'il n'y a pas de manque de matière première, tester 
            m_troncons->empty (), si empty, c'est qu'ils ont tous pu être coupés*/
           
           **List * m_barres;**
           
           /* liste des barres dont on dispose.
           Pour vérifier si toutes les barres de départ ont été utilisées, tester m_barres.empty ()
           si empty (), c'est qu'on a tout utilisé. Sinon, c'est qu'il en reste.
           */
            
            **std::list<Combinaison> m_possibilites;**
            
            /* pas d'utilité pour l'affichage des résultats*/
            
            **std::list<Combinaison> m_resultatFinal;**
            
            /*Contient les combinaisons retenues pour chaque barre
            Utiliser la fonction Combinaison::affiche qui affiche tout ce qu'il faut sur une barre*/
            
            **std::vector<double>  m_copieTroncons;**
            
            /* pas d'utilité pour l'affichage des résultats*/
            
            int m_exigence; 
            /* pas d'utilité pour l'affichage des résultats*/

Je ne sais pas si c'est possible de réutiliser mes fonctions affiche (), mais de manière générale, le principe est que j'ai une fonction affiche pour chaque classe. Et que chaque classe d'un niveau supérieur utilise la fonction affiche du niveau inférieur : la classe Paire a une fonction affiche qui affiche un tronçon et sa position dans la liste des tronçons. La classe Combinaison a aussi une fonction affiche qui affiche les différentes Paire (s) de la combianison et le rendement attaché à la barre. Enfin, la classe doubleListPaires a sa propre fonction affiche qui utilise celle de Combinaison.

Pour se charger de tout ce qui est affichage, il faut donc étudier vite fait le code de ces trois fonctions et le trafiquer un peu pour indiquer les mêmes éléments, mais sur un support autre que la sortie standard. Je recopie ici ces trois fonctions :

void Paire::affiche ()
{
    cout <<"(" <<m_longueur << ", " << m_position << ")";
}

void Combinaison::affiche()
{
	#if DEBUG
    cout <<"[";
    for (list<Paire>::iterator it = m_liste.begin(); it != m_liste.end(); it++)
    {
        if (it != m_liste.begin())
            cout <<", ";
        it->affiche();
    }
    cout <<"]"<<endl;
    cout << "Rendement de "<< m_rendement <<"\% sur une barre de " << m_barre << endl;
    #endif
}


void DoubleListPaires::affiche()
{
	#if DEBUG
	if (m_troncons->empty ())
		cout <<"Vous avez réussi à couper tous les tronçons que vous désiriez." << endl;
	else
	{
    	cout <<"Vous n'avez pas eu assez de matière première pour couper tous les tronçons que vous désiriez... Liste de troncons restants: ";
    	m_troncons->affiche();
    }
    if (m_barres->empty ())
		cout <<"Vous avez utilisé toutes vos barres." << endl;
	else
	{
    	cout <<"Il vous reste des barres entières que vous n'avez pas utilisées : Liste des barres restantes: ";
    	m_barres->affiche();
    }
    cout << "Voici la liste des coupes que vous devez effectuer : " << endl;
    for(list<Combinaison>::iterator it=m_resultatFinal.begin(); it!= m_resultatFinal.end(); ++it)
    {
        it->affiche();
        cout <<endl;
    }
    cout << "Exigence : "<<m_exigence<<endl;
	cout << "Vous avez un rendement moyen de " << calculeRendementFinal ()<<"%"<<endl;
	#endif
}

A part ça, il y a une dernière fonction affiche de la classe List qui permet d'afficher ce qu'il reste dans la liste des tronçons si on ne les a pas tous utilisés, et ce qu'il reste dans la liste des barres.
