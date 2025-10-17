//
//  Main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 14.9.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game(int usernumber, int randomnumber);
void attempt(int round, int usernumber, int randomnumber);

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(0));
    int guess=0;
    int number=rand()%100+1;
    int userattempt=0;
    printf("I’m ”thinking” of a number between 1 and 100, guess which!\n");
    do{
        printf("Guess: ");
        scanf("%d",&guess);
        game(guess, number);
        userattempt++;
        attempt(userattempt,guess,number);
    }while(guess!=number);
    return 0;
}


void game(int usernumber, int randomnumber){
    if (usernumber!=randomnumber){
        if (usernumber>randomnumber){
            printf("Your guess is too high, try again!\n");
        }
        else if (usernumber<randomnumber){
            printf("Your guess is too low, try again!\n");
        }
    }
    else {
        printf("Congratulations, that is correct!\n");
    }
    return;
}


void attempt(int round, int usernumber, int randomnumber){
   if (usernumber==randomnumber){
        printf("You made %d attempts.\n",round);
    }
    return;
}

