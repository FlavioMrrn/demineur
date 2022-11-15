# Principes généraux de résolution du TP du démineur

1. Lire l'énoncé et bien comprendre ce qu'on va faire:
    * La boucle principale: comment on interagit avec l'utilisateur 
        (au début rien marche donc on va pas coder direct cette partie).
    * Qu'est-ce que le jeu?
        a. la structure de donnée (types): 
            - l'aire de jeu: 
                - contient les cases du jeu (bombes, drapeaux, etc.)
                - décompte des bombes voisines
                - état de la case (visible ou caché)
            - on peut représenter ces données de différentes façon informatiquement:
                - un tableau
                - deux tableaux
                - trois tableaux, etc.
        b. pour démarrer le jeu on a besoin de:
            - taille de l'aire de jeu
            - nombre de bombes (et leur positions).
    * Logique du jeu (phase initiale):
        a. La quelles sont les étapes pour interagir avec l'utilisateur:
            - demander la taille de l'aire de jeu
            - demander le nombre de bombes (évent. leur position)
        b. Création de l'aire de jeu:
            - Initialisation:
                - poser les bombes
                - calculer le nombre de bombes adjacentes
                - "tout est caché"
    * Logique du jeu (boucle de jeu):
        a. afficher l'aire de jeu
        b. demander à l'utilisateur sur quelle case il veut jouer. 
        c. cas à traîter:
            - case déjà ouverte (rien se passe et éventuellement on prévient qu'il a fait un truc nul)
            - case fermée:
                - poser un drapeau
                - ouvrir:
                    - bombe: perdu
                    - pas bombre: on dévoile la case:
                        - si un nombre on affiche le nombre
                        - sinon on ouvre les case adjactentes pas déjà ouvertes.
            - drapeau sur la case (enlever le drapeau ou rien faire)
            - fin du jeu s'il y a autant de cases fermées que de bombes.
        d. 2-3 goodies (mesure du temps de jeu, nombre de tours, compteur de drapeau, etc.)
    **Jusqu'ici on a encore rien programmé bon sang!!!**
2. De quelles fonctions on a besoin?
    * affiche(aire_jeu, visibilité // dépendant si vous avez 1 ou 2 ou 3 tableaux)
    * mise_à_jour(aire_de_jeu, action, case)
    * partie_est_finie(aire_de_jeu)
    * initialisation(aire_de_jeu, visibilité, etc.)
    * poser_bombes_au_hasard(...)
    * calcule_le_nombre_de_bombes_dans_voisinage(...)
    * ouvre_case(...)
    * et peut-être encore d'autres trucs! comme des fonctions utilitaires.
    * vérification_dindices(...) // vérifier si un indice est dans le tableau
3. On programme:
    * définir types: 
        - bool (visibilité), chiffre (valeur de case), état de la case (enum), ...
        - aire_de_jeu
    * affichage.
    * TESTER (COMPILER) APRÈS CHAQUE FONCTION!
    * initialisation
    * TESTER (COMPILER) APRÈS CHAQUE FONCTION!
    * calcul des voisinages
    * TESTER (COMPILER) APRÈS CHAQUE FONCTION!
    * ouverture de la case (sans récursion)
    * TESTER (COMPILER) APRÈS CHAQUE FONCTION!
    * ouverture de la case (avec récursion)
    * TESTER (COMPILER) APRÈS CHAQUE FONCTION!
    * entrées utilisateur.
    * TESTER (COMPILER) APRÈS CHAQUE FONCTION!
    * peut-être structurer en fichiers, quoi que....
            
    **Vous pouvez commencer par simplifier en ignorant les drapeaux pour le moment.**