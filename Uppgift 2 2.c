//
//  Main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 14.9.2025.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int code;
    printf("Enter a number: ");
    scanf("%d",&code);
    switch (code)
    {
        case 0:
            printf("Morse code: -----\n");
            break;
        case 1:
            printf("Morse code: .----\n");
            break;
        case 2:
            printf("Morse code: ..---\n");
            break;
        case 3:
            printf("Morse code: ...--\n");
            break;
        case 4:
            printf("Morse code: ....-\n");
            break;
        case 5:
            printf("Morse code: .....\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }
    return 0;
}
