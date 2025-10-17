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

float squareRoot(float number, float *result){
    if (number >0){
        *result=sqrt(number);
        return 1;
    }
    else{
        //0 och negativt tolkas som negativt här (ingen rot)
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    float usernumber, sqrtofnumber;
    printf("Give a number: ");
    scanf("%f", &usernumber);
    if (squareRoot(usernumber, &sqrtofnumber)==1){
        printf("Square root of the number is: %.3f\n", sqrtofnumber);
    }
    else{
        printf("It is not possible to calculate the square root of a negative number.\n");
    }
   return 0;
}
