//
//  Main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 14.9.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countElement(int inputArray[], int arraySize, int elementToCount);
void randomfill(int inputArray[], int arraySize);

int main(int argc, const char *argv[]) {
    srand((unsigned int)time(0));
    
    int search;
    int size = 10;
    int list[size];
    
    randomfill(list, size);
    
    for (int i = 0; i < size; i++) {
        printf("Number: %d\n", list[i]);
    }
    
    printf("What to search for: ");
    scanf("%d", &search);
    
    int found = countElement(list, size, search);
    printf("The number %d occurs %d times.\n", search, found);
    
    return 0;
}

void randomfill(int inputArray[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        int randomNumber = rand() % 10 + 1;
        inputArray[i] = randomNumber;
    }
}

int countElement(int inputArray[], int arraySize, int elementToCount) {
    int numberofelements = 0;
    for (int i = 0; i < arraySize; i++) {
        if (elementToCount == inputArray[i]){
            numberofelements++;
        }
    }
    
    return numberofelements;
}
