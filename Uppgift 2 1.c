//
//  main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 5.9.2025.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int angle;
    printf("Enter a positive angle in full degrees: ");
    scanf("%d",&angle);
    if (angle>=91 && angle <180)
    {
        printf("The angle is blunt!\n");
    }
    else if (1<=angle && angle<90)
    {
        printf("The angle is sharp!\n");
    }
    else if (angle==90)
    {
        printf("The angle is right!\n");
    }
    else if (angle==180 || angle==0)
    {
        printf("The angle is straight!\n");
    }
    else if (180<angle)
    {
        printf("Incorrect input.\n");
    }
    else
    {
        printf("Incorrect input.\n");
    }
    return 0;
}

