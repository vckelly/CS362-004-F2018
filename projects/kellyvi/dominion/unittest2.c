#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

//unit test for the handCard function

    struct gameState g1;
    int player1 = 0;

    int rand_ints[10] = [1,5,2,-4,8,10,2,9,12,2];
    int state_int = 0;
    
    g1.handCount[player1] = 0;

    assert(g1.handCount[player1] == 0);

    int i;
    for (i = 0; i < 10; i++){
        g1.handCount[player1] = rand_ints[i];
        state_int = g1.handCard(player1, &g1);

        assert(state_int == rand_ints[i]);

    }

    printf("\nFunc handCard test passed\n");
    return 0;
}