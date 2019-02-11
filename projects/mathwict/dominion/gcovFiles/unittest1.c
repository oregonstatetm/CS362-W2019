#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"

int ut1()
{
printf("Unit Test 1: whoseTurn\n");

// int whoseTurn();

int seed=1000;
struct gameState G1;
int i, numPlayers, currentPlayer,r;
int z[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

for(numPlayers=1;numPlayers<=MAX_PLAYERS;numPlayers++) // Test each set of players, 1 player, 2 player, 3 player, 4 player
{

r = initializeGame(numPlayers, z, seed, &G1);

for(i=numPlayers;i>0;i--)
{

G1.whoseTurn=i;
currentPlayer=whoseTurn(&G1);
printf("Current Player is %d",currentPlayer);

if(currentPlayer!=i)
{
printf("Error when %d players play and it is player %d turn",numPlayers,currentPlayer);
}

}

}
return (0);
}
