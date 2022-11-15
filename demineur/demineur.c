#include "demineur.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

dem dem_create(int aera_lines, int aera_colons, int bombs_number){
    dem d;
    d.area_colons = aera_colons;
    d.area_lines = aera_lines;
    d.bombs_number = bombs_number;
    return d;
}


void showAerea(){};
void update(){};
void gameEnd(){};
void initialization(){};

void calculBombsNumberNear(){};
void openCase(){};
void verifyIndex(){};

void printTable(dem *d){
    for (int i = 0; i < d->area_lines; i++)
    {
        for (int j = 0; j < d->area_colons; j++)
        {
            //printf("l:%d c:%d   ", i,j);
            if (d->t_state[i][j].states == BOMB)
            {
                printf("B");
            }else{
                printf("-");
            }
            
        }
        printf("\n");
    }
    printf("\n");
}

void placeRandomBombs(dem *d, int bombsNumber){
    srand(time(NULL));
    int actual = 0;
    int save_rnd[bombsNumber][bombsNumber];
    bool doublon = false;
    while (actual < bombsNumber)
    {
        doublon = false;
        int rnd1 = rand() % d->area_lines;
        int rnd2 = rand() % d->area_colons;
        for (int j = 0; j < actual; j++)
        {
            if (save_rnd[rnd1][rnd2] == 1)
            {
                doublon = true;
            }
            
        }
        if (doublon == true){ continue; }
        save_rnd[rnd1][rnd2];
        d->t_state[rnd1][rnd2].states = BOMB;
        actual++;
    }
}

