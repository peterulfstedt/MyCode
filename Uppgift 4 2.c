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

int isPalindrome(char inputString[]);
void converttosmall(char inputString[]);
void removewrongchars(char inputString[]);
void clear(char inputString[]);

int main(int argc, const char * argv[]) {
    int length = 100;
    char string[length];
    int round = 1;
    
    while (round == 1) {
        printf("\nEnter a sentence: ");
        scanf(" %[^\n]", string);
        
        converttosmall(string);
        removewrongchars(string);
        
        if (isPalindrome(string) == 1) {
            printf("This sentence is a palindrome.\n");
        }
        else if (isPalindrome(string) == 0) {
            printf("This sentence is not a palindrome.\n");
        }
        
        clear(string);
        
        printf("Do you want to enter another sentence (1 for yes, 0 for no): ");
        scanf("%d", &round);
        
        while (round != 1 && round != 0) {
            printf("\nGive the correct number (1 for yes, 0 for no): ");
            scanf("%d", &round);
        }
    }
    
    return 0;
}

int isPalindrome(char inputString[]) {
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] != inputString[strlen(inputString) - i - 1]) {
            return 0;
        }
    }
    
    return 1;
}

void converttosmall(char inputString[]) {
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] >= 'A' && inputString[i] <= 'Z') {
            inputString[i] = inputString[i] + 32;
        }
    }
}

void removewrongchars(char inputString[]) {
    int j = 0;
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (isalpha(inputString[i])) {
            inputString[j] = inputString[i];
            j++;
        }
    }
    
    inputString[j] = '\0';
}

void clear(char inputString[]) {
    inputString[0] = '\0';
}
