#ifndef TP_DEMINEUR
#define TP_DEMINEUR

#include <stdbool.h>

typedef struct square_t{
    enum {CLOSED, BOMB, FLAG, OPEN} states ;
}square_t;

typedef struct demineur
{ 
    int area_colons;
    int area_lines;
    square_t **t_state;
    int **t_number;
    int bombs_number;
}dem;


dem dem_create(int aera_lines, int aera_colons, int bombs_number);
void showAerea();
void update();
void gameEnd();
void initialization();
void placeRandomBombs(dem *d, int bombsNumber);
void calculBombsNumberNear(dem *d);
void openCase();
void verifyIndex();
void printTable(dem *d);

#endif