#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int ut2()
{
printf("Unit Test 2: getCost Function\n");

// int functionName();

int seed=1000;
struct gameState G1;
int testCost,i;
int numPlayers=2;
int z[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

initializeGame(numPlayers, z, seed, &G1);

for(i=0;i<27;i++)
{
testCost=getCost(i);
printf("\nCard #%d .",(i));

//Cost 0 - Copper / Curse
if(i==curse||i==copper)
{
printf("\nTesting Cost 0 Cards\n");
if(testCost!=0)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}
}

//Cost 2 - Estate / Embargo
if(i==estate||i==embargo)
{
printf("\nTesting Cost 2 Cards\n");
if(testCost!=2)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}
}

//Cost 3 - Ambassador / Steward / Great_Hall / Village / Silver
if(i==ambassador||i==steward||i==great_hall||i==village||i==silver)
{
printf("\nTesting Cost 3 Cards\n");
if(testCost!=3)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}
}

//Cost 4 - Feast / Gardens / Remodel / Smithy / Baron / Cutpurse / Salvager / Sea_Hag / Treasure_Map
if(i==feast||i==gardens||i==remodel||i==smithy||i==baron||i==cutpurse||i==salvager||i==sea_hag||i==treasure_map)
{
printf("\nTesting Cost 4 Cards\n");
if(testCost!=4)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}
}

//Cost 5 - Duchy / Council_Room / Mine / Minion / Tribute / Outpost
if(i==duchy||i==council_room||i==mine||i==minion||i==tribute||i==outpost)
{
printf("\nTesting Cost 5 Cards\n");
if(testCost!=5)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}
}


//Cost 6 - Gold / Adventurer
if(i==gold||i==adventurer)
{
printf("\nTesting Cost 6 Cards\n");
if(testCost!=6)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}
}

//Cost 8 - Province
if(i==province)
{
printf("\nTesting Cost 8 Cards\n");
if(testCost!=8)
{
printf("Error when testing card enumeration %d",testCost);
return (0);
}

}

}

printf("\n\n ALL TESTS PASSED \n\n\n");
return (0);
}
