#ifndef TP_DEMINEUR
#define TP_DEMINEUR

#include <stdbool.h>

typedef struct square_t{
    enum {EMPTY, BOMB, FLAG} states ;
}square_t;

typedef struct demineur
{ 
    bool t_activated[10][10];
    square_t t_state[10][10];
    int t_number[10][10];

    int area_colons;
    int area_lines;
    int bombs_number;
}dem;


dem dem_create(int aera_lines, int aera_colons, int bombs_number);
void showAerea();
void update();
void gameEnd();
void initialization();
void placeRandomBombs(dem *d, int bombsNumber);
void calculBombsNumberNear();
void openCase();
void verifyIndex();
void printTable(dem *d);

#endif