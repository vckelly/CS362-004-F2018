#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

    printf("\n\nCard Test: Smithy\n\n");

    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    struct gameState g1, testGame;

    initializeGame(2, cards, 256, &g1);

    memcpy(&testGame, &g1, sizeof(struct gameState));

    int turn = whoseTurn(&g);
    cardEffect(cards[9], 0, 0, 0, &g, 0, NULL);

    assert(g.handCount[turn] > testGame.handCount[turn]);
    assert(g.handCount[turn] == testGame.handCount[turn] + 3);

    assert(g.discardCount[turn] > testGame.discardCount[turn]);
    assert(g.discardCount[turn] == testGame.discardCount[turn] + 1);

    printf("\nCard test for Smithy has passed!\n");

    printf("\n\nCard Test: Smithy has completed\n\n");

}