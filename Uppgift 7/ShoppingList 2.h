#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#define MAX_STRING_SIZE 100

// Struct definitions

struct GroceryItem {
    char productName[MAX_STRING_SIZE];
    float amount;
    char unit [MAX_STRING_SIZE];
};

struct ShoppingList {
    struct GroceryItem *itemList;
    int length;
};



// Function declarations
void addItem(struct ShoppingList *list);
void printList(struct ShoppingList *list);
void editItem(struct ShoppingList *list);
void removeItem(struct ShoppingList *list);
void saveList(struct ShoppingList *list); //implementeras i laboration 7
void loadList(struct ShoppingList* list); //implementeras i laboration 7

#endif

