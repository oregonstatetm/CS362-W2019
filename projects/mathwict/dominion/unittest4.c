#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int ut4()
{
printf("Unit Test 4: compare Function\n");

// int compare();

/*
int seed=1000;
struct gameState G1;
int i, numPlayers, currentPlayer,r;
int z[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


initializeGame(numPlayers, z, seed, &G1);
*/

int compareValue1;
int compareValue2;
int returnValue;

compareValue1=1;
compareValue2=1;

//EQUAL CASE
returnValue=compare(&compareValue1,&compareValue2);

if(returnValue==0)
{printf("\nEqual Case Passed\n");}
else
{printf("\nError with Equal Case\n");}


//GREATER THAN CASE (A>B)
compareValue1=2;
compareValue2=1;

//Same value case
returnValue=compare(&compareValue1,&compareValue2);

if(returnValue==1)
{printf("\nGreater Than Case Passed\n");}
else
{printf("\nError with Greater Than Case\n");}

//LESS THAN CASE (A<B)
compareValue1=1;
compareValue2=2;

//Same value case
returnValue=compare(&compareValue1,&compareValue2);

if(returnValue==-1)
{printf("\nLess Than Case Passed\n");}
else
{printf("\nError with Less Than Case\n");}


printf("\n\n ALL TESTS PASSED \n\n\n");
return (0);
}

