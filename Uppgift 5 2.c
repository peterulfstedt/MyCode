//
//  Main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 14.9.2025.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    char input[100];
    char *thirdword=0;
    int mellanslag=0;
    
    
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    for (int i=0; input[i] != '\0'; i++){
        if (input[i] == ' '){
            mellanslag++;
            if (mellanslag==2){
                thirdword = &input[i+1];
                break;
            }
        }
    }
    
    
    if (thirdword){
        printf("%s", thirdword);
    }
    else {
        printf("The sentence is too short.\n");
    }
   return 0;
}
