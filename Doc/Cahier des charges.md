#Cahier de charges
##Description générale :
L'utilisateur possède un certain nombre de barres/cylindres/baguettes de même dimensions et souhaite les découper en un certain nombre de tronçons de différentes longueurs qu'il définira.
Le programme doit calculer la meilleure combinaison des coupes de manière à obtenir le moins de chutes possible.

###Interface :
L’interface comportera un formulaire en 3 parties :
1. La première concerne la saisie barres avant la découpe. L'utilisateur peut ajouter ou supprimer via des boutons, des groupes de champs où chaque groupe possède :
  * un champ DoubleSpinBox pour la longueur
  * un champ de sélection pour l'unité
  * un champ SpinBox pour la quantité de ce type de barres
2. La deuxième partie est identique à la première dans la forme sauf qu'elle concerne les tronçons désirés.
3. La troisième partie est composée d'un champ DoubleSpinBox pour saisir l'épaisseur de la lame utilisée et un champ permettant de sélectionner l'unité de celle-ci.

Près du formulaire, un bouton **Appliquer** lance le moteur de calcul et un espace  d'affiche les résultats.

###Présentation des résultats :
Soit sous forme écrite : morceau1 : 12, 15,12.5,7	 morceau2 : 50 etc., soit sous forme graphique avec un schéma de découpe de chaque morceau. Il faudra aussi faire figurer le pourcentage de chutes et  le nombre de poutres non entamées.
La page des résultats devrait comporter un lien vers le formulaire de départ pour pouvoir commencer une nouvelle simulation à tout moment.
Gestion des exceptions : 
Seront détectés les problèmes suivants : 
* Tronçon demandé plus grand que la longueur des tronçons de départ.
* Trop de tronçons demandés par rapport à la quantité disponible au départ. Possibilité d’augmenter le nombre de poutres disponibles « en cours de route »…
* Mauvais format d’entrée des tailles de tronçons voulues. L’utilisateur est invité à ressaisir les données selon le bon format.
* Bien entendu, vérifier que les chiffres ne sont pas négatifs et définir un nombre maximal de poutres pour ne pas que l’utilisateur ne s’amuse à faire planter le programme en entrant un nombre aberrant.

###Moteur de calcul :

Il combine les différentes possibilités pour tomber sur la ou les solutions qui donnent le moins de chutes possibles. Doit-il proposer 2 solutions au choix si elles sont équivalentes ?


##Langages de programmation :
La programmation se fera en c++.

## Informations diverses
###Date du début de projet :
inconnue
###Objectifs et timing :
à discuter
###Partage des tâches :
Pierre-Emmanuel s’occupe de la partie interface graphique et Rébecca, du moteur de calcul. La partie gestion des erreurs de l’utilisateur : à discuter…
