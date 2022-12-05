#include <stdio.h>
#include <stdlib.h>
#include "./demineur/demineur.h"

int main(){
    dem d = dem_create(5,5,5);
    printTable(&d);
    showAerea(&d);
    
    for (int i = 0; i < d.area_lines; i++)
    {
        free(d.t_state[i]);
        free(d.t_number[i]);
    }
    
    
    free(d.t_number);
    free(d.t_state);
}