//
//  Main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 14.9.2025.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int tal,tal2,min,max,sum,x,rounds;
    float avg;
    printf("Welcome!\nEnter a negative number to exit input and print the result.\n\n");
    tal2=-1;
    while (tal2!=0)
    {
        tal=0;
        x=0;
        min=0;
        max=0;
        sum=0;
        avg=0;
        rounds=0;
        printf("Give number: ");
        scanf("%d",&tal);
        sum=sum+tal;
        min=tal;
        max=tal;

        while (tal>-1)
        {
            printf("Give number: ");
            scanf("%d",&tal);
            sum=sum+tal;
            rounds++;
            if (tal>-1){  //Låter inte negativa variabler påverka minimum värdet
                if (min>tal){
                    min=tal;
                }
            }
            if (max<tal){
                max=tal;
            }
        }
        
        if (tal<0){
            if (min<0){
                min=0;
            }
            if (max<0){
                max=0;
            }
            sum=sum-tal;
            avg=(float)sum/rounds;
            
            if (avg != avg){ //Fixar problemet att avg=nan.
                avg=0;
            }
            printf("The smallest number is: %d\n", min);
            printf("The biggest number is: %d\n", max);
            printf("The sum of the numbers is: %d\n", sum);
            printf("The average value is: %.3f\n\n", avg);
            printf("Would you like to run the program again (1 for yes, 0 for no)? ");
            scanf("%d",&tal2);
            while(tal2!=0 && tal2!=1){
                printf("Incorrect input, try again!\n");
                printf("Would you like to run the program again (1 for yes, 0 for no)? ");
                scanf("%d", &tal2);
            }
            if (tal2==0 || tal2==1){
                switch (tal2)
                {
                    case 1:
                        printf("Enter a negative number to exit input and print the result.\n\n");
                        break;
                    case 0:
                        printf("Exiting program, bye bye!\n\n");
                        break;
                }
            }
        }
    }
    return 0;
}
