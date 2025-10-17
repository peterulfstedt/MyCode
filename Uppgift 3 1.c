//
//  Main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 14.9.2025.
//

#include <stdio.h>
float rate(int krona,float valutakursen);
int main(int argc, const char * argv[]) {
    int sek;
    printf("Enter SEK: ");
    scanf("%d", &sek);
    float valutaisek=10.94;
    float convertion = rate(sek, valutaisek);
    printf("This converts to %.2f\n\n", convertion);
    return 0;
}
float rate(int krona, float valutakursen){
    float convertion = (krona/valutakursen);
    return convertion;
}
