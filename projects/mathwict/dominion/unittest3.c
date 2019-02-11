#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int ut3()
{
printf("Unit Test 3: kingdomCards Function\n");

// int numHandCards();

/*
int seed=1000;
struct gameState G1;
int i, numPlayers, currentPlayer,r;
int x[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};
int y[10] = {gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute};
int z[10] = {ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map}


initializeGame(numPlayers, z, seed, &G1);

*/

int* cardArray;
int i=0;
int j=0;

//Test Values 0-9
cardArray=kingdomCards(curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast);

for(j=0;j<10;j++)
{
if(cardArray[j]==i)
{
printf("\nTesting Card Enumeration %d\n",cardArray[j]);
}
else
{
printf("Error testing Card Enumeration %d",cardArray[j]);
return(0);
}
i++;
}

//Test Values 10-19
cardArray=kingdomCards(gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute);

for(j=0;j<10;j++)
{
if(cardArray[j]==i)
{
printf("\nTesting Card Enumeration %d\n",cardArray[j]);
}
else
{
printf("Error testing Card Enumeration %d",cardArray[j]);
return(0);
}
i++;
}


//Test Values 20 - 26
cardArray=kingdomCards(ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map, copper, copper, copper);

for(j=0;j<7;j++)
{
if(cardArray[j]==i)
{
printf("\nTesting Card Enumeration %d\n",cardArray[j]);
}
else
{
printf("Error testing Card Enumeration %d",cardArray[j]);
return(0);
}
i++;
}



printf("\n\n ALL TESTS PASSED \n\n\n");
return (0);
}
