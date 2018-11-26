#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

//unit test for the drawCard function
    struct gameState g1;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    initializeGame(2, cards, 256, &g1);

    int player1 = 0;

    int hand = g1.handCount[player1];
    int deck = g1.deckCount[player1];
    drawCard(player1, &g1);

    assert(g1.handCount[player1] > hand);
    assert(g1.deckCount[player1] < deck);

    g1.deckCount[player1] = 0;
    drawCard(player1, &g1);

    assert(g1.discardCount[player1] == 0);

    printf("\nFunc drawCard test passed\n");
    return 0;
}