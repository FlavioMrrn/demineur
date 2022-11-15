#include <stdio.h>
#include <stdlib.h>
#include "./demineur/demineur.h"

int main(){
    dem d = dem_create(5,5,3);
    printTable(&d);
    placeRandomBombs(&d, 5);
    printTable(&d);
}