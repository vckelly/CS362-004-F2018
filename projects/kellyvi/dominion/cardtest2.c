#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

    printf("\nCard Test: Adventurer\n");

    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    int err_flag = 0;

    struct gameState g1, testGame;

    initializeGame(2, cards, 256, &g1);

    memcpy(&testGame, &g1, sizeof(struct gameState));

    int turn = whoseTurn(&g1);
    cardEffect(cards[0], 0, 0, 0, &g1, 0, NULL);

    if (g1.handCount[turn] >= testGame.handCount[turn] + 2){
        printf("Hand counts incremented succesfully\n!");
    }
    else{
        printf("Error: Hand count not incremented correctly\n");
        err_flag = 1;
    }

    if (g1.deckCount[turn] <= testGame.deckCount[turn] + 2){
        printf("Discard counts incremented succesfully\n!");
    }
    else{
        printf("Error: Discard counts not incremented correctly\n");
        err_flag = 1;
    }

    if (!(err_flag)){
        printf("Card test for Adventurer has passed!\n");
    }
    else{
        printf("***Card test for Smithy finished with errors***\n");
    }
}