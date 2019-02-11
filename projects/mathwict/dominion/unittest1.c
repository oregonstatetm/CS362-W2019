#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>


int ut1()
{
printf("Unit Test 1: whoseTurn Function");

// int whoseTurn();

int seed=1000;
struct gameState G1;
int i, numPlayers, currentPlayer,r;
int z[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

for(numPlayers=1;numPlayers<=MAX_PLAYERS;numPlayers++) // Test each set of players: 1,2,3,4
{
printf("\n\nTesting Game with %d Player(s)\n",numPlayers);
initializeGame(numPlayers, z, seed, &G1);

for(i=numPlayers;i>0;i--)
{

G1.whoseTurn=i;
currentPlayer=whoseTurn(&G1);
printf("\nTesting Player %d",currentPlayer);

if(currentPlayer!=i)
{
printf("\nError when %d players play and it is player %d turn\n",numPlayers,currentPlayer);
return (0); // Return with first error
}

}

}
printf("\n\n ALL TESTS PASSED \n\n\n");
return (0);
}
