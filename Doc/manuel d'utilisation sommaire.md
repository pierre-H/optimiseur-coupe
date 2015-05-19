# Manuel d'utilisation du Moteur de Calcul

## Lancement du moteur

Créer un objet MoteurCalculs. Son constructeur doit prendre en argument :

1. Une List des barres désirées dont le dernier élément doit être 0.
2. Une List des tronçons désirés dont le dernier élément doit être 0.

On peut créer ces deux List via la fonction createSortedList qui prend en argument :

1. la List finale
2. un tableau de double contenant les longueurs des barres/tronçons

Les longueurs doivent être en mm. Ne pas oublier de prendre en compte la quantité en ajoutant plusieurs fois la même valeur dans le tableau.

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
Pour info, voici tous les champs de cet objet dont on a besoin pour l'affichage :

1. List * m_troncons
            
liste des tronçons qu'on veut. 
Pour vérifier si tous ont pu être coupés et qu'il n'y a pas de manque de matière première, tester 
m_troncons->empty (), si empty, c'est qu'ils ont tous pu être coupés
           
2. List * m_barres;
           
liste des barres dont on dispose.
Pour vérifier si toutes les barres de départ ont été utilisées, tester m_barres.empty ()
si empty (), c'est qu'on a tout utilisé. Sinon, c'est qu'il en reste.

            
3. std::list<Combinaison> m_resultatFinal;**
            
Contient les combinaisons retenues pour chaque barre
Utiliser la fonction Combinaison::affiche qui affiche tout ce qu'il faut sur une barre
            


Pour gérer l'affichage, il faudra donc adapter les fonctions suivantes :

1. La fonction affiche de la classe Combinaison, qui affiche toutes les informations relatives à une combinaison, à savoir les tronçons utilisés dans cette combinaison, à quelle taille de barre cette combinaison s'applique, et le rendement de coupe sur cette barre

2. La fonction affiche de la classe moteurCalcul qui est censé afficher les résutats finaux.

3. La fonction affiche de la classe List qui va servir à afficher les barres inutilisées à la fin, ou les troncons restants qu'on n'a pas réusii à couper par manque de matière première.

