#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H
/*Här lägger du eventuella makrodefinitioner*/
#define size 100

// Struct definitions
struct GroceryItem {
    char productName[size];
    float amount;
    char unit [size];
};
struct ShoppingList {
    struct GroceryItem ShoppingList[5];
    int length;
};


/*Deluppgift 3 - definiera dina strukter här.           *
 *Det är viktigt att du använder de namn som anges i    *
 *uppgiftsspecifikationen, har du inte gjort det kommer *
 *resten av kodskelettet inte att kompilera.            *
 *När du definierat strukternakommer eventuella         *
 *varningar att försvinna och du ska kunna kompilera    *
 *och köra programmet, ingenting kommer dock att hända  *
 *när du gör val i menyn.                               */



// Function declarations
void correctInterval (struct ShoppingList *list, int *trueLength);
void correctAmount (struct ShoppingList *list, int number);
void addItem(struct ShoppingList *list);
void printList(struct ShoppingList *list);
void editItem(struct ShoppingList *list);
void removeItem(struct ShoppingList *list);
void saveList(struct ShoppingList *list); //implementeras i laboration 7
void loadList(struct ShoppingList* list); //implementeras i laboration 7

#endif

