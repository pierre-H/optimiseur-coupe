# Résumé de la réunion du 21 Avril 2015

* ~~Xavier envoie un dessin à Pierre-Emmanuel concernant le rendu des résultats.~~ FAIT
* ~~Pierre-Emmanuel construit la maquette qui constitue une image du futur programme.~~ FAIT
* Xavier va répertorier toutes les erreurs possibles et imaginables et en transmettre la liste à Pierre-Emmanuel qui s'occupera des tests de validité des entrées de l'utilisateur.
* Xavier va également rédiger des tests de non régression dans chaque fichier source du programme. 
* ~~Rébecca se charge des tests de régression pour l'un des fichiers (rajout par rapport au chat), disons List.cpp~~ FAIT
* ~~Rébecca se charge de l'écriture d'une fonction qui prend une valeur et une unité en entrée et qui renvoie la valeur convertie en mm.~~ FAIT
* Pierre-Emmanuel s'occupe d'analyser les entrées de l'utilisateur à l'aide des regex, (rajouter la fonctionnalité de l'opérateur * pour plusieurs fois le même segment, et mm par défaut si pas d'unité spécifiée) et de passer les bons arguments à cette fonction de conversion (fonction relai entre interface et moteur).
* Rajout du paramètre de l'épaisseur de perte à la coupe : pas encore de job défini, mais donnera lieu à une discussion sur l'architecture générale du programme entre Xavier et Rébecca.
* Pierre-Emmanuel rajoute la fonctionnalité de la langue, avec la reconnaissance de la langue de l'utilisateur et de l'adaptation du programme dans sa langue.
* Récapitulation des différentes unités à proposer : mm, cm, m, inches, feet, yard.
* Documentation : nous n'avons pas vraiment tranché concernant la répartition des rôles là-dessus, mais que pensez-vous que Xavier s'occupe de la génération de documentation brute par Doxygen (ou autre outil), et que Rébecca s'occupe de la rédaction d'un autre document qui explique et soutienne le choix des structures de données ? Ou bien le tout dans un même document ?
* Discussion de la possibilité ou non de venir à Paris8 pour la soutenance de projet, nous sommes plutôt tombés d'accord sur Skype.
* Xavier se fait attaquer par un python, et la réunion se finit en catastrophe...

## Questions restées sans réponses : 

* ~~XAVIER : "Autre question : connaissez-vous la commande git pour merger ûne branche dans une autre ?"

* PIERRE-EMMANUEL : "On peut aussi faire notre propre documentation avec des captures d'écran au format pdf : c'est vrai que ce serait plus simple"
REBECCA : "de quelles captures d'écran s'agit-il ?"~~ REPONDU

## Points que nous n'avons pas abordés ou petites idées qui me sont venues après :

* Je crois qu'il faut que nos discussions apparaissent sur les forums pour que M. Bernard ait une base sur quoi noter l'organisation. Je me permets donc d'ajouter le contenu de ce document sur le forum.
* ~~Nous avions parlé d'une échéance de mi-juin sur gitHub. Cela tient-il toujours, et peut-on le publier sur l'un des forums ?~~ OK POUR ECHEANCE MI-JUIN
* Nous n'avons pas parlé de qui s'occupe de la mise à jour du cahier de charges.
* ~~Il faudrait que nous soyons capables de décrire les tâches de chacun, en une expression qui tient si possible en peu de mots.~~ OK
* J'ai encore des doutes sur le nombre de documents texte qui doivent accompagner le travail : 
  1. Un cahier de charge comprenant la maquette.
  2. Une documentation minimale.
  3. Un document expliquant les structures de données du moteur (et les différents champs de l'interface ?) ou peut-être, de manière plus générale, un grand schéma de la structure du programme (document XLM ?) avec le rôle des différentes fonctions etc.
  4. Un document readme qui indique très basiquement les fonctionnalités du programme et comment s'en servir ?
  5. Un document expliquant le rôle de chacun dans le projet, et en gros qu'il voie qu'on a tous travaillé.
C'est logique ou c'est trop ? Ou pas assez ?(d'autres idées de choses qui pourraient être nécessaires ?).

### Bonne fin de journée !
Rébecca
