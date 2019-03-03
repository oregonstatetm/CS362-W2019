#include <stdio.h>
#include <stdlib.h>
#include "dominion.c"
#include <string.h>
#include <math.h>
#include "rngs.c"

int main()
{
printf("RandomTest 3: Adventurer Function");

int i, n, r, p, deckCount, discardCount, handCount;
int k[10]={adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

struct gameState G;
printf("Testing drawCard.\n");
printf("Random Tests.\n");

SelectStream(2);
PutSeed(3);

for(n=0;n<20;n++){
    for(i=0;i<sizeof(struct gameState);i++)
    {
        ((char*)&G)[i]=floor(Random()*256);
    }

    //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    p=1;
    G.whoseTurn=1;
    G.deckCount[p]=floor(Random()*20);
    G.discardCount[p]=floor(Random()*10);
    G.handCount[p]=floor(Random()*6);
    G.supplyCount[estate]=floor(Random()*12);
    G.supplyCount[duchy]=floor(Random()*12);
    G.supplyCount[province]=floor(Random()*12);
    G.supplyCount[copper]=floor(Random()*50);
    G.supplyCount[copper]++;
    G.supplyCount[silver]=floor(Random()*40);
    G.supplyCount[silver]++; //Always 2 treasure cards.
    G.supplyCount[gold]=floor(Random()*30);
    checkAdventurer(p,&G);
    }



printf("\n\n ALL TESTS PASSED \n\n\n");
return (0);
}

int checkAdventurer(int p, struct gameState *post)
{

    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int r=cardEffect(adventurer,1,1,1,post,1,1);

int currentPlayer;
int cardDrawn;
int drawntreasure=0;
int temphand[MAX_HAND];
int z=0;

currentPlayer=whoseTurn(&pre);

while(drawntreasure<2)
{
if(pre.deckCount[currentPlayer]<1)
{
shuffle(currentPlayer,&pre);
}
drawCard(currentPlayer,&pre);
cardDrawn=pre.hand[currentPlayer][pre.handCount[currentPlayer]-1];
}
if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	drawntreasure++;
else{
	temphand[z]=cardDrawn;
	pre.handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	z++;
}

while(z-1>0){
pre.discard[currentPlayer][pre.discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }

if(r!=0)
 {  printf("There was an error.");
     return -1;
 }
if(memcmp(&pre,post,sizeof(struct gameState))!=0)
{  printf("There was an error.");
     return -1;
}

return 0;
}
