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

Voici les résultats accessibles à partir de l'objet MoteurCalculs créé précédemment :

1. la liste des tronçons désirés via la méthode **List * getTroncons ()**. Est vide si tous ont pu être coupés et qu'il n'y a pas de manque de matière première (à vérifier avec la méthode **empty()**).

2. la liste des barres disponibles via la méthode **List * getBarres ()**. Est vide si toutes les barres de départ ont été utilisées (à vérifier avec la méthode **empty()**)

            
3. std::list<Combinaison> m_resultatFinal; (à accéder avec getResultatFinal () )
            
Contient les combinaisons retenues pour chaque barre
Utiliser la fonction Combinaison::affiche qui affiche tout ce qu'il faut sur une barre
            


Pour gérer l'affichage, il faudra donc adapter les fonctions suivantes :

1. La fonction affiche de la classe Combinaison, qui affiche toutes les informations relatives à une combinaison, à savoir les tronçons utilisés dans cette combinaison, à quelle taille de barre cette combinaison s'applique, et le rendement de coupe sur cette barre

2. La fonction affiche de la classe moteurCalcul qui est censé afficher les résutats finaux.

3. La fonction affiche de la classe List qui va servir à afficher les barres inutilisées à la fin, ou les troncons restants qu'on n'a pas réusii à couper par manque de matière première.

