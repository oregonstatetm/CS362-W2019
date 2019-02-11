#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int ct2()
{
printf("Card Test 2: Adventurer\n");

// int compare();


int seed=1000;
struct gameState G1;
int i, numPlayers, currentPlayer,r;
int z[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


initializeGame(numPlayers, z, seed, &G1);






printf("\n\n No test implemented for adventurer \n\n\n");
return (0);
}

