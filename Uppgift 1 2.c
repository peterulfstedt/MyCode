//
//  main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 5.9.2025.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int num1, num2, result;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    result=num1+num2;
    printf("%d + %d = %d\n", num1, num2, result);
    return 0;
}

