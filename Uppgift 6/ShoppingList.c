#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // For dynamic memory (lab 7)


void addItem(struct ShoppingList *list)
{
    if (list->length == 5){
        printf("\nThe limit is reached (5 Items)!");
        return;
    }
    printf("\nEnter name of the product: ");
    scanf(" %[^\n]", list->ShoppingList[list->length].productName);
    
    correctAmount(list, list->length);
        
    printf("Enter units: ");
    scanf(" %[^\n]", list->ShoppingList[list->length].unit);
    
    list->length++;
}

void printList(struct ShoppingList *list)
{
    if (list->length == 0){
        printf("\nYour list is empty.");
    }else{
    printf("Your list contains %d items:\n", list->length);
        for (int i = 0; i < list->length; i++){
            printf("%-3d-  %-25s %8.1f %s\n", i+1, list->ShoppingList[i].productName, list->ShoppingList[i].amount, list->ShoppingList[i].unit);
        }
    }
}






void editItem(struct ShoppingList *list)
{
    if (list->length == 0){
        printf("\nYour list is empty.");
    }else{
        int number;
        
        correctInterval(list, &number);
        number--;
        
        correctAmount(list, number);
        
        printf("Item %d is changed.", number);
    }
}






void removeItem(struct ShoppingList *list)
{
    if (list->length == 0){
        printf("\nYour list is empty.");
    }else{
        int length1;
        correctInterval(list, &length1);
        int originalLength = length1;
        
        int length2=length1;
        length1--;
        
        while (length1 != 4){
            for (int i=0; i<100; i++){
                list->ShoppingList[length1].productName[i] = list->ShoppingList[length2].productName[i];
            }
            list->ShoppingList[length1].amount = list->ShoppingList[length2].amount;
            for (int i=0; i<100; i++){
                list->ShoppingList[length1].unit[i] = list->ShoppingList[length2].unit[i];
            }
            length1++;
            length2++;
            if (length1 == 4){
                list->length--;
            }
        }
        printf("Item %d is removed.", originalLength);
    }
}

/*saveList och loadList implementeras i laboration 7*/
void saveList(struct ShoppingList *list)
{

}

void loadList(struct ShoppingList* list)
{
    
}

void correctInterval (struct ShoppingList *list, int *trueLength){
    int number;
    do{
        printf("Give the number of the product you want to modify: ");
        scanf("%d", &number);
        if (number < 1 || number > 5) {
            printf("Give the number in the correct interval (1 - 5).\n");
        }
        else if (number > list->length){
            printf("The slot is empty, try again.\n");
        }
    }while((number > 5 || number < 1)|| number > list->length);
    
    *trueLength = number;
}


void correctAmount (struct ShoppingList *list, int number){
    do{
        printf("Enter the amount: ");
        scanf("%f", &list->ShoppingList[number].amount);
        
        if (list->ShoppingList[number].amount <=0){
            printf("The negative numbers or zero are not allowed.\n");
        }
    }while (list->ShoppingList[number].amount <=0);
}
