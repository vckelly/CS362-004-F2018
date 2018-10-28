#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

//unit test for the whoseTurn function

    struct gameState g1;

    int turn_int = 0;
    int state_int;

    int i;
    for (i = 0; i < 10; i++){
        g1.whoseTurn = turn;
        state_int = whoseTurn(&g1);

        assert(state_int == turn);

        turn++
    }

    printf("\nFunc whoseTurn test passed\n");
    return 0;
}