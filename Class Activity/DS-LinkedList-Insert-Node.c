#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char *name;
    struct Node* next;
}Book;

// Function Prototype to create a new node list
Book *ListBook(Book *List);
// Function Prototype to insert new node / book
Book *AddBook(Book *List, char *nombre);

int main(){
    // Passing variable into ListBook Function
    Book *List = ListBook(List);
    // Inserting new node / book
    List = AddBook(List, "The Angels");
    // Print data and address of next node
    printf("Title: %s\n",List->name);
    printf("Next pointer: [%p]\n",List->next);

return 0;
}

// Function to create a new node list
Book *ListBook(Book *List){

    List = NULL;

return List;
}
// Function to insert new node / book
Book *AddBook(Book *List, char *name){

    //New node
    Book *newBook;
    // Allocate the variable
    newBook = (Book*)malloc(sizeof(Book));
    //Insert the name into new node
    newBook->name = name;
    // Link the first node with NULL value
    newBook->next = NULL;

    if(List == NULL){
        List=newBook;
    }

return List;
}
