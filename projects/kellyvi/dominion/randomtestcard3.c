#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"

//global counters
int cardDraw = 0;
int deckCount = 0;
int otherGameState = 0;

int checkDrawCard(int player, struct gameState *G1) {
  int result;
  int errFlag = 0;

  struct gameState pre;

  memcpy(&pre, G1, sizeof(struct gameState));
    
  result = drawCard(player, G1);

  //test that hand size was incremented correctly
  if(G1->handCount[player] == pre.handCount[player] + 1){
    ;
  }
  else{
    cardDraw++;
    errFlag = 1;
  }
  
  //test that deck count was decremented correctly
  if(G1->deckCount[player] == pre.discardCount[player] - 1){
    ;
  }
  else{
    deckCount++;
    errFlag = 1;
  }

  int otherP;
  if(player == 1){
    otherP = 0;
  }
  else{
    otherP = 1;
  }
  //test other player game state was not changed
  if(G1->deckCount[otherP] == pre.deckCount[otherP] && G1->handCount[otherP] == pre.handCount[otherP]){
    ;
  }
  else{
    otherGameState++;
    errFlag = 1;
  }

  return errFlag; 
}

int main(){

  int i, n, result, player, errFlag;

  int cards[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};

  struct gameState G1;

  printf ("Testing Draw Card.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(5);

  errFlag = 0;
  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G1)[i] = floor(Random() * 256);
    }
    player = floor(Random() * 2);
    G1.deckCount[player] = floor(Random() * MAX_DECK);
    G1.discardCount[player] = floor(Random() * MAX_DECK);
    G1.handCount[player] = floor(Random() * MAX_HAND);
    result = checkDrawCard(player, &G1);
    if (!result){
        printf("Draw Card test failed!\n");
        errFlag = 1;
    }
  }
  if(errFlag){
    printf("\nDraw card tests finished with errors!\n");
    printf("\nOf 2000 random tests, draw card finished with the following: \n");
    printf("Card draw errors: %d of 2000\n", cardDraw);
    printf("Deck count errors: %d of 2000\n", deckCount);
    printf("Game state errors: %d of 2000\n", otherGameState);
  }
  else{
    printf("\nDraw card tests finished without error!\n");
  }
}