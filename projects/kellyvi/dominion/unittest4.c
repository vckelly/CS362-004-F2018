#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

//unit test for the supplyCount function

    struct gameState g1;

    int rand_ints[10] = [1,5,2,5,8,19,2,9,12,2];
    int state_int = 0;
    
    int i;

    for (i = 0; i < 10; i++){
        g1.supplyCount[i] = rand_ints[i];
        state_int = g1.supplyCount(i, &g1);

        assert(state_int == rand_ints[i]);
    }

    printf("\nFunc supplyCount test passed\n");
    return 0;
}