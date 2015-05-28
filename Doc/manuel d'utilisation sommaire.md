# Manuel d'utilisation du Moteur de Calcul

## Lancement du moteur

Créer un objet MoteurCalculs. Son constructeur doit prendre en argument :

1. Un pointeur d'une List des barres désirées dont le dernier élément doit être 0.
2. Un pointeur d'une List des tronçons désirés dont le dernier élément doit être 0.

On peut créer ces deux List via la fonction createSortedList qui prend en argument :

1. la List finale
2. un tableau de double contenant les longueurs des barres/tronçons

Les longueurs doivent être en mm. Ne pas oublier de prendre en compte la quantité en ajoutant plusieurs fois la même valeur dans le tableau.

## Affichage des résultats :

Le moteur tourne sur un espèce de gros objet qui porte le nom de MoteurCalculs.
A la fin des calculs, cet objet contient tout ce dont on a besoin pour afficher les résultats.


Pour info, voici tous les champs de cet objet dont on a besoin pour l'affichage :

1. List * m_troncons (à accéder avec getTroncons () )
            
liste des tronçons qu'on veut. 
Pour vérifier si tous ont pu être coupés et qu'il n'y a pas de manque de matière première, tester 
**getTroncons()->empty ()**, si empty, c'est qu'ils ont tous pu être coupés
           
2. List * m_barres; (a accéder avec getBarres () )
           
liste des barres dont on dispose.
Pour vérifier si toutes les barres de départ ont été utilisées, tester **getBarres().empty ()**
si empty (), c'est qu'on a tout utilisé. Sinon, c'est qu'il en reste.

            
3. std::list<Combinaison> m_resultatFinal; (à accéder avec getResultatFinal () )
            
Contient les combinaisons retenues pour chaque barre
Utiliser la fonction Combinaison::affiche qui affiche tout ce qu'il faut sur une barre
            


Pour gérer l'affichage, il faudra donc adapter les fonctions suivantes :

1. La fonction affiche de la classe Combinaison, qui affiche toutes les informations relatives à une combinaison, à savoir les tronçons utilisés dans cette combinaison, à quelle taille de barre cette combinaison s'applique, et le rendement de coupe sur cette barre

2. La fonction affiche de la classe moteurCalcul qui est censé afficher les résutats finaux.

3. La fonction affiche de la classe List qui va servir à afficher les barres inutilisées à la fin, ou les troncons restants qu'on n'a pas réusii à couper par manque de matière première.

