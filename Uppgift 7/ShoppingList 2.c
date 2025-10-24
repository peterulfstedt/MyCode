#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // For dynamic memory (lab 7)

//Help-function declarations
void correctInterval (struct ShoppingList *list, int *trueLength);
void correctAmount (struct ShoppingList *list, int number);
int checkEmptiness (struct ShoppingList *list);
void memoryAllocation (struct ShoppingList *list, int capacity);

//Main-function definitions
void addItem(struct ShoppingList *list)
{
    memoryAllocation (list, 1);
    printf("\nEnter name of the product: ");
    scanf(" %[^\n]", list->itemList[list->length].productName);
    
    correctAmount(list, list->length);
        
    printf("Enter units: ");
    scanf(" %[^\n]", list->itemList[list->length].unit);
    
    list->length++;
}

void printList(struct ShoppingList *list)
{
    if (checkEmptiness(list)) return;
    printf("Your list contains %d items:\n", list->length);
    for (int i = 0; i < list->length; i++){
        printf("%-3d-  %-25s %8.1f %s\n", i+1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
        
    }
}



void editItem(struct ShoppingList *list)
{
    if (checkEmptiness(list)) return;
    
    int number;
        
    correctInterval(list, &number);
        
    correctAmount(list, number);
        
    printf("Item %d is changed.", number + 1);
    
}






void removeItem(struct ShoppingList *list)
{
    if (checkEmptiness(list)) return;
    int length1;
    correctInterval(list, &length1);
        
    for (int i = length1; i < list->length - 1; i++){
        strcpy(list->itemList[i].productName,  list->itemList[i + 1].productName);
        
        list->itemList[i].amount = list->itemList[i + 1].amount;
        
        strcpy(list->itemList[i].unit,  list->itemList[i + 1].unit);
    }
        
    list->length--;
    printf("Item %d is removed.", length1 + 1);
}

/*saveList och loadList implementeras i laboration 7*/
void saveList(struct ShoppingList *list)
{
    if (checkEmptiness(list)) return; //Man får inte lämna in en tom fil.
    FILE *fpText;
    char string[MAX_STRING_SIZE];
    
    printf("Choose the name of your file: ");
    scanf(" %[^\n]", string);
    
    fpText = fopen(string, "w");
    if (fpText == NULL) {
        printf("Error: Could not create or open file '%s'\n", string);
        return;
    }else{
        fprintf(fpText, "Your list contains %d items:\n", list->length);
        for (int i=0; i < list->length; i++){
            fprintf(fpText, "%-3d-  %-25s %8.1f %s\n", i+1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
        }
        printf("File is saved!\n");
        fclose(fpText);
    }
}

void loadList(struct ShoppingList* list)
{
    FILE *fpText;
    char string[MAX_STRING_SIZE];
    printf("Enter the filename: ");
    scanf(" %[^\n]", string);
    
    fpText = fopen(string, "r");
    if (fpText == NULL){
        printf("There is no such file.\n");
        fclose(fpText);
    }else{
        printf("1");
        fclose(fpText);
    }
}

//Help-function definitions
void correctInterval (struct ShoppingList *list, int *trueLength){
    int number;
    do{
        printf("Give the number of the product you want to modify: ");
        scanf("%d", &number);
        if (number < 1) {
            printf("Give the number in the correct interval.\n");
        }
        else if (number > list->length){
            printf("The slot is empty, try again.\n");
        }
    }while(number > list->length || number < 1);
    
    number--;
    
    *trueLength = number;
}


void correctAmount (struct ShoppingList *list, int number){
    do{
        printf("Enter the amount: ");
        scanf("%f", &list->itemList[number].amount);
        
        if (list->itemList[number].amount <=0){
            printf("The negative numbers or zero are not allowed.\n");
        }
    }while (list->itemList[number].amount <=0);
}


int checkEmptiness (struct ShoppingList *list){
    if (list->length == 0){
        printf("\nYour list is empty.");
        return 1;
    }
    return 0;
}

void memoryAllocation (struct ShoppingList *list, int capacity){
    if (list->itemList == NULL){
        list->itemList = (struct GroceryItem*)calloc(capacity, sizeof(struct GroceryItem));
        
    }else{
        capacity++;
        struct GroceryItem *temp = realloc(list->itemList, capacity * sizeof(struct GroceryItem));
        if (!temp){
            printf("Could not expand memory!\n");
            return;
        }
        list->itemList = temp;
    }
}
