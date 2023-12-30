# huffman_decompression

Ce programme a été écrit par Emma ORSET à des fins pédagogiques.

## Organisation du projet

Pour ce projet, j'ai utilisé git pour gérer chaque étape de mon projet. Chaque branche correspond à une tâche.
J'avais commencé à utilisé un TRELLO mais le temps m'étant compté, je n'ai pas eu le temps de le mettre à jour pour chaque tâche. C'est pour ça que chaque commit dans git est très détaillé pour pallier l'absence de TRELLO.
J'ai utilisé le langage de programmation JAVA.

## Décomposition fonctionnelle du programme

Dans le code JAVA, il y a 5 classes, plus 2 classes Main d'execution.
Voyons l'utilisation de ces classes :

`* Dictionnary`
Cette classe a une méthode _readDict()_ qui permet la lecture d'un fichier qui contient un alphabet. 
Cette alphabet est la clé qui va permettre de décoder un fichier binaire associé.

`* Node`
Cette classe permet d'instancier des "nodes".

`* Tree`
Cette classe permet de créer l'arbre de codage grâce à une node racine qui contient toutes les autres. 

`* Encode`
Cette classe permet a une méthode _dictEncode()_ qui permet d'avoir un dictionnaire de node codé en binaire

`* BinaryFile`
Cette classe a une méthode _readBinFile()_ qui permet de lire un fichier binaire.

`* MainTest`
J'ai créé ce Main pour tester chacune de mes classes séparément.

`* Main`
C'est cette classe qu'il faut executer. Elle permet la lecture de tous les fichiers, et le décodage de tous les fichiers avec écriture dans un nouveau fichier.

## Mode d'emploi

Pour que ce code marche, il faut utiliser un de mes autres codes qui se trouve dans le repository : _huffman_compression_.
_huffman_compression_ demande un fichier _.txt_, il va ensuite l'encoder en binaire dans un fichier _\_comp.bin_ et fournir la clé pour le décoder dans un fichier _\_freq.txt_.

Il faut récupérer les fichiers _\_comp.bin_ et _\_freq.txt_ pour les fournir au code _huffman_decompression_.
Imaginons que nous voulons décoder un fichier qui s'appelle : _exemple_comp.bin_.
Alors il faut mettre dans le dossier _Resources_ un autre dossier _exemple_ puis il faut mettre les fichiers _exemple_comp.bin_ et  _exemple_freq.txt_ dans ce dossier.
Ensuite, à la ligne 7 de la classe Main, vous trouverez une liste. Il faudra ajouter la chaine de charactères "exemple" (et enlever les chaines qui ne nous intéressent pas) dans cette liste.

Et voilà ! Il suffit d'executer la classe Main pour décoder le fichier et retrouver le texte initialement écrit !

## Difficultés rencontrées

J'ai eu beaucoup de problèmes pour programmer ce code. Notamment lors de la lecture du fichier bin qui m'a demandé beaucoup de temps et j'ai finit par demander de l'aide, puis pour la gestion de \n car j'ai dû modifier mes classes pour que ça marche. 
J'ai eu aussi beaucoup de problèmes à l'initialisation de mon git car l'IDE que j'utilise (IntelliJ) est un peu difficile à apréhender surtout au niveau de sa connexion à git. Donc finalement j'ai finit par faire en lignes de commandes directement en Git Bash.

## Conclusion

Je ne suis pas forcément très à l'aise avec JAVA donc ce projet m'a demandé énormément de temps de programmation, néanmoins je suis très fière du resultat car il va même plus loin que ce qui était demandé (gestion des caractères spéciaux par exemple).


