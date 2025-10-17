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

void comparison(int inputArr[], int inputCount, int *quantity, int *frequentnumber);

int main(int argc, const char * argv[]) {
    int arr[100];
    int number, frequency, mostFrequentNumber;
    int count=0;
    printf("Please enter numbers between 0 and 1000, both of these included, (max 100 numbers). End with a negative number.\n");
    for (int i=0; i<100; i++){
        printf("Number: ");
        scanf("%d", &number);
        if (number <=1000 && number>=0){
            arr[i]=number;
            count++;
        }
        else if (number <0){
            break;
        }
        else{
            i--;
        }
    }
    comparison(arr, count, &frequency, &mostFrequentNumber);
    if (frequency>0){
        printf("The number %d occurs the most times, a total of %d times.\n", mostFrequentNumber, frequency);
    }else{
        printf("No number has been given between the 0 and 1000.\n");
        
    }
   return 0;
}

void comparison(int inputArr[], int inputCount, int *quantity, int *frequentnumber){
    int currentQuantity=0, prevQuantity=0;
    for (int i=0; i<inputCount; i++){
        for (int j=0; j<inputCount; j++){
            if (inputArr[i]==inputArr[j]){
                currentQuantity++;
            }
        }
        if (currentQuantity<=prevQuantity){
            currentQuantity=0;
        }
        else{
            prevQuantity=currentQuantity;
            currentQuantity=0;
            *frequentnumber=inputArr[i];
        }
    }
    *quantity=prevQuantity;
}
