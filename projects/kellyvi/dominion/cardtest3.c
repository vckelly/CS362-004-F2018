#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

    printf("\n\nCard Test: Village\n\n");

    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    struct gameState g1, testGame;

    initializeGame(2, cards, 256, &g1);

    memcpy(&testGame, &g1, sizeof(struct gameState));

    int turn = whoseTurn(&g);
    cardEffect(cards[3], 0, 0, 0, &g, 0, NULL);

    assert(g.handCount[turn] > testGame.handCount[turn]);
    assert(g.handCount[turn] == testGame.handCount[turn] + 1);

    assert(g.numActions > testGame.numActions);
    assert(g.numActions == testGame.numActions + 2);

    printf("\nCard test for Village has passed!\n");

    printf("\n\nCard Test: Village has completed\n\n");

}