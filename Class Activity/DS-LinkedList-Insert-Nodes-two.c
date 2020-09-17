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
    List = AddBook(List, "The Devils");

    while(List != NULL){
        printf("Title: %s\n",List->name);
        List = List->next;
    }


return 0;
}

// Function to create a new node list
Book *ListBook(Book *List){

    List = NULL;

return List;
}
// Function to insert new node / book
Book *AddBook(Book *List, char *name){

    // New node
    Book *newBook;
    // Temporal Variable to save the previous node (first node)
    Book *temp;

    // Allocate the variable
    newBook = (Book*)malloc(sizeof(Book));
    //Insert the name into new node
    newBook->name = name;
    // Link the first node with NULL value
    newBook->next = NULL;

    if(List == NULL){
        List=newBook;
    }
    else{
        temp = List;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newBook;

    }

return List;
}
