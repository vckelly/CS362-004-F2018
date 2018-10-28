#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

//unit test for the isGameOver function

    struct gameState g1;
    int province, supply; 

    int state_int;

    g1.supplyCount[province] = 3;
    state_int = isGameOver(&g1);

    assert(state_int == 0);

    g1.supplyCount[province] = 0;
    state_int = isGameOver(&g1);

    assert(state_int == 1);

    int i; 
    for (i = 0; i < 3; i++){
        g1.supplyCount[i] = 0;
    }

    state_int = isGameOver(&g1);

    assert(state_int == 1);

    g1.supplyCount[0] = 5;

    state_int = isGameOver(&g1);

    assert(state_int == 0);

    printf("\nFunc isGameOver test passed\n");
    
    return 0;
}