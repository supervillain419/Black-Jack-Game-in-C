#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void rules(); // rules of the game!
void startGame(); // Starts the game!

int main(){
    int choice;
    int again = 1;
do
{
    printf("\n\n********* Welcome to BlackJack Game in C! ********");
    printf("\n\n1.Start Game \n2.Rules of the game:\n==>");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        startGame();
        break;
    case 2:
        rules();
        break;
    default:
        printf("Some error occured!\n");
        break;
    }
    printf("Want to play again?\n1.Yes\n2.No\n==>");
    scanf("%d",&again);
} while (again == 1);
    printf("\n********* Thank you for playing Blackjack in C! ********\n\n");
    return 0;
}

void rules(){
    printf("\n------------------------------ 0 ------------------------------\n");
    printf("When the dealer has served every player, the dealers face-down card is turned up.\nIf the total is 17 or more,it must stand.\nIf the total is 16 or under, they must take a card.\nThe dealer must continue to take cards until the total is 17 or more,\nat which point the dealer must stand. Face cards each count as 10, Aces count as 1 or 11,\nall others count at face value.\nAn Ace with any 10, Jack, Queen, or King is a blackjack!");
    printf("\n------------------------------ 0 ------------------------------\n");
}

void startGame(){
    int dealersum=0,playersum=0,hit=0,cho,i=0;
    int dealercards=0, playercards=0,r_num=0;
    int Deck[]={1,2,3,4,5,6,7,8,9,10,10,10,10}; //1-13 (11-J, 12-Q, 13-K) Cards!
    srand(time(NULL));

    r_num = (rand() % 13);
    dealersum += Deck[r_num];
    //printf("===> %d\n ===>%d",r_num,Deck[r_num]);
    dealercards += 1;
    printf("\nDealer Draws %d Card\n",Deck[r_num]);
    printf("Dealers sum is: %d\n",dealersum); //Prints dealers sum!

    do{
        r_num = (rand() % 13);
        printf("\nPlayer Draws %d Card\n",Deck[r_num]);
        if (Deck[r_num] == 1){
            if (playersum <= 10){
                
                playersum += 11;
            }else{
                playersum += 1;
            }
        }else{
            playersum += Deck[r_num];
        }
        
        //playercards += 1;
        printf("Players sum is: %d\n",playersum);
        if(playersum < 21){
            printf("\n==============================");
            printf("\n1.Hit\n2.Stay\n");
            printf("==============================\n==>");
            scanf("%d",&cho);
            if(cho == 1){
                hit = 0;
            }else{
                hit = 1;
            }
        }
    }while(playersum < 21 && hit == 0);
    printf("\nPlayers sum is: %d\n",playersum);
    printf("------------------------------");

    while (dealersum<17)
    {
        i++;
        r_num = (rand() % 13);
        printf("\nDealer Draws %d Card\n",Deck[r_num]);
        if (Deck[r_num] == 1){
            if (dealersum <= 10){
                dealersum += 11;
            }else{
                dealersum += 1;
            }
        }else{
            dealersum += Deck[r_num];
        }
        //dealersum +=Deck[r_num];
        dealercards += 1;
        printf("\n%d.Dealers sum is: %d\n",i,dealersum);
    }
    printf("\n==============================");

    //      CHECK WHO WINS      //

    if(playersum > 21){
        printf("\n\tYou Lose!");
    }else if(playersum == dealersum){
        printf("\n\tTie!");
    }else if(dealersum > playersum && dealersum < 22){
        printf("\n\tYou Lose!");
    }else{
        printf("\n\tYou win!");
    }
    printf("\n==============================\n\n");
}