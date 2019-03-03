#include <stdio.h>
#include <stdlib.h>
#include "dominion.c"
#include <string.h>
#include <math.h>
#include "rngs.c"

int main()
{
printf("RandomTest 1: Smithy Function");
int errorReturned=0;

int i, n, r, p, deckCount, discardCount, handCount;
int k[10]={adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};


int errorCatch=0;

struct gameState G;

SelectStream(2);
PutSeed(3);


for(n=0;n<2000;n++){
    for(i=0;i<sizeof(struct gameState);i++)
    {
        ((char*)&G)[i]=floor(random()*256);
    }

    //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    p=floor(Random()*4);
   G.deckCount[p]=floor(Random()*MAX_DECK);
    G.discardCount[p]=floor(Random()*MAX_DECK);
    G.handCount[p]=floor(Random()*MAX_HAND);
    int handCounter=G.handCount[p];
    int handPosition=floor(Random()*G.handCount[p]);
    G.playedCardCount = 0;
    errorCatch=checkSmithy(p,handPosition,&G);
    if(errorCatch!=0)
        errorReturned++;
    }


if(errorReturned==0)
{
printf("\n\n ALL TESTS PASSED \n\n\n");
}
else
{
    printf("\n\nThere were %d errors in 2000 tests",errorReturned);
}
return (0);
}

int checkSmithy(int player, int handPosition, struct gameState *post)
{
    int memoryCompare;
    int i=0;
    int errorCount=0;
    post->whoseTurn=player;
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int r=cardEffect(smithy,1,1,1,post,handPosition,1);

    //Recreate effects of Smithy here for pre to use in comparison with post

    //+3 Cards
    for (i = 0; i < 3; i++)
	{
	  drawCard(player, &pre);
	}
    //discard card from hand
    discardCard(handPosition, player, &pre, 0);


    memoryCompare=(memcmp(&pre, post, sizeof(struct gameState)));
    if(r!=0)
    {
        printf("\nerror with cardEffect");
        errorCount++;
    }
    if(memoryCompare!=0)
    {
        printf("\nerror with comparison");
        errorCount++;
    }
return errorCount;
}

