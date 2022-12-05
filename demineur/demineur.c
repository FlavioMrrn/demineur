#include "demineur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/// @brief initialisie les variables du jeu
/// @param aera_lines nombre de lines
/// @param aera_colons nombre de colonnes
/// @param bombs_number nombre de bombe
/// @return notre jeu du demineur
dem dem_create(int aera_lines, int aera_colons, int bombs_number)
{
    dem d;
    d.area_lines = aera_lines;
    d.area_colons = aera_colons;
    d.t_state = malloc(aera_lines * sizeof(square_t*));
    for (int i = 0; i < aera_lines; i++) {
        d.t_state[i] = malloc(aera_colons * sizeof(square_t));
    }
    
    d.t_number = malloc(aera_lines * sizeof(int32_t*));
    for (int i = 0; i < aera_lines; i++)
    {
        d.t_number[i] = malloc(aera_colons*  sizeof(int32_t));
    }
    
    for (int i = 0; i < aera_lines; i++)
    {
        for (int j = 0; j < aera_colons; j++)
        {
            d.t_number[i][j] = 0;
        }
        
    }


    d.bombs_number = bombs_number;
    placeRandomBombs(&d, bombs_number);
    calculBombsNumberNear(&d);
    return d;
}

/// @brief affiche le tableau de jeu de la partie
/// @param d 
void showAerea(dem *d){
    for (int i = 0; i < d->area_lines; i++)
    {
        for (int j = 0; j < d->area_colons; j++)
        {
            // printf("l:%d c:%d   ", i,j);
            if (d->t_state[i][j].states == BOMB)
            {
                printf("B");
            }
            else if (d->t_state[i][j].states == OPEN)
            {
                printf("%d", d->t_number[i][j]);
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
};
void update(){};
void gameEnd(){};
void initialization(){};

/// @brief calcul le nombre de bombes autour d'une case.
/// @param d notre demineur sur lequel nous jouons
void calculBombsNumberNear(dem *d){
    for (int i = 0; i< d->area_lines; i++){ //parcours toutes les lignes de tout le jeu
        for (int j = 0; j< d->area_colons; j++){//parcours toutes les colonnes de tout le jeu
            for (int h = -1; h <= 1; h++) //vérifie les 3 lignes de cette cases
            {
                if (i == 0 && h == -1){
                    continue;
                }
                if (i == d->area_lines-1 && h==1){
                    continue;
                }
                
                for (int k = -1; k <= 1; k++)//parcours la colonne en cours de vérification
                {
                    if (j==0 && k == -1){
                        continue;
                    }
                    if (j == d->area_colons-1 && k==1){
                        continue;
                    }
                    if (d->t_state[i+h][j+k].states == BOMB)
                    {
                        d->t_number[i][j]++;
                    }
                }
                
            }
            
        }
    }
    
}
void openCase(){};
void verifyIndex(){};

/// @brief affiche le tableau de facon pratique pour le développement
/// @param d 
void printTable(dem *d)
{
    for (int i = 0; i < d->area_lines; i++)
    {
        for (int j = 0; j < d->area_colons; j++)
        {
            // printf("l:%d c:%d   ", i,j);
            if (d->t_state[i][j].states == BOMB)
            {
                printf("B");
            }
            else
            {
                printf("%d", d->t_number[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/// @brief plasse des bombes aleatoire dans notre tableau
/// @param d 
/// @param bombsNumber nombre de bombes
void placeRandomBombs(dem *d, int bombsNumber)
{
    srand(time(NULL));
    int actual = 0;
    while (actual != bombsNumber)
    {
        int rnd1 = rand() % d->area_lines;
        int rnd2 = rand() % d->area_colons;

            if (d->t_state[rnd1][rnd2].states != BOMB)
            {
                d->t_state[rnd1][rnd2].states = BOMB;
                actual++;
            }
    }
}

