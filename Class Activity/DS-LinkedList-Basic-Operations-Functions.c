#include <stdio.h>
#include <stdlib.h>

// LinkedList Operations Pedro A. Uicab Diaz

//Node structure which contains two members
struct Node{
    char letter; // Char variable
    struct Node *next;  // Pointer variable
};
// Global variable <<HEAD>>
struct Node *head = NULL;

// Print function Prototype
void printNodes();

// Insert at The Beginning Function Prototype
//void insert_at_beg(struct Node *n, char L); //---Second way
void  insert_at_beg(char L); // -- third way

// Insert at the end Function Prototype
void insert_at_end(char L);

// Insert at specific position Function Prototype
void insert_at_pos(struct Node *previous, char L);

// Delete The First Node Function Prototype
void delete_beg();

// Delete The Last Node Function Prototype
void delete_end();

// Delete Any Node
void delete_any_pos();

int main(void){

     // Char variable to save the letter
     char L;

    //The existing nodes
     struct Node *node00 = NULL;
     struct Node *node01 = NULL;
     struct Node *node02 = NULL;
     struct Node *node03 = NULL;

     // Allocate dynamic memory to node
     node00 = (struct Node*)malloc(sizeof(struct Node));
     node01 = (struct Node*)malloc(sizeof(struct Node));
     node02 = (struct Node*)malloc(sizeof(struct Node));
     node03 = (struct Node*)malloc(sizeof(struct Node));

     //Link Head to first node
     head = node00;

     // Assign data to first node HEAD
     node00->letter = 'A';
     // Link first node with the next
     node00->next = node01;

     // Assign data to second node NODE01
     node01->letter = 'B';
     // Link second node with the next
     node01->next = node02;

     // Assign data to third node NODE02
     node02->letter = 'C';
     // Link third node with the next
     node02->next = node03;

     // Assign data to forth node NODE03
     node03->letter = 'D';
     // Link forth node with NULL value
     node03->next = NULL;

     printf("\t//////////////////////////////\n");
     printf("\t/////// DATA STRUCTURE ///////\n");
     printf("\t//////////////////////////////\n\n");

     // Print nodes to see the whole LinkedList
     printNodes();

     // Asking for letter
     printf("\nEnter new Letter at the beginning: "); scanf("%c",&L);

     // At beginning
     insert_at_beg(L);
     printNodes();

     fflush(stdin);

     // Asking for letter
     printf("\nEnter new Letter at the end: "); scanf("%c",&L);

     // At end
     insert_at_end(L);
     printNodes();

     fflush(stdin);

     // Asking for letter
     printf("\nEnter new Letter at any position: "); scanf("%c",&L);

     //At any position
     insert_at_pos(node02,L);
     printNodes();

     //Delete first node
     printf("\n");
     system("PAUSE");
     delete_beg();
     printNodes();

     // Delete last node
     printf("\n");
     system("PAUSE");
     delete_end();
     printNodes();

     // Delete Any node
     printf("\n");
     system("PAUSE");
     delete_any_pos();
     printNodes();

return 0;
}
// Function 01
void printNodes(){

    // New temporal variable for traversing the LinkedList
    struct Node *tem;

    // Traversing nodes with while loop
    if(head == NULL){
        printf("Linked List is empty\n");
    }
    else{

        tem = head;
        while(tem != NULL){
        printf("%c->",tem->letter);
        // n will has the next value of LinkedList
        tem = tem->next;
        }
    }
}

//Function 02
void insert_at_beg(char L){

    //New node
    struct Node *new_node;

    // Allocate the dynamic memory to new node
    new_node = (struct Node*)malloc(sizeof(struct Node));

    //Insert letter to new node
    new_node->letter = L;
    new_node->next = NULL;

    //Link the new node to next node (head)
    if(head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head= new_node;

    }

}

// Function 03
void insert_at_end(char L){

    // New node
    struct Node *new_node;
    // New temporal node to do the traversing
    struct Node *temporal;

    // Allocate the dynamic memory to new node
    new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign char value to new node
    new_node->letter = L;

    temporal = head;

    // Traversing whole LinkedList
    while(temporal->next != NULL){
        temporal = temporal->next;
    }
    // Update Node
    temporal->next = new_node;
    // The last node link to NULL value
    new_node->next = NULL;

}

// Function 04
void insert_at_pos(struct Node *previous, char L){

    if (previous == NULL){

        printf("The previous node is empty.\n");
    }
    else{
        // New node
        struct Node *new_node;

        // Allocate the dynamic memory to new node
        new_node = (struct Node*)malloc(sizeof(struct Node));

        // Assign new letter
        new_node->letter = L;

        // New node will has the same address than previous node
        new_node->next = previous->next;

        //Update position
        previous->next = new_node;
    }
}

// Function 05
void delete_beg(){

    //New temporal variable
    struct Node *temporal;

    // Temporal variable will be equal to our head -- same data, same pointer address
    temporal = head;

    // Head will only had a pointer address of the next node --- previous head was deleted
    head = head->next;
    printf("\nNode deleted\n");

    // Free space memory
    free(temporal);
}

// Function 06
void delete_end(){

    // New temporal variables (it is necessary create 2)
    struct Node *temporal, *tempPtr;

    // Temporal will be equal to our head
    tempPtr = head ;

    while(tempPtr->next != NULL){

        temporal = tempPtr ;
        tempPtr = tempPtr->next;

    }
    // Update node's address
    temporal->next = NULL;
    printf("\nLast node was deleted\n");

    // Free space memory
    free(tempPtr);
}

// Function 07
void delete_any_pos(){

    int i, position;
    struct Node *temporal, *tempPtr;

    printf("\nEnter the position: "); scanf("%d",&position);

    if(position == 0){

        tempPtr = head;

        // Head will only had a pointer address of the next node --- previous head was deleted
        head = head->next;
        printf("\nNode deleted\n");

        // Free space memory
        free(tempPtr);
    }
    else{

        tempPtr =  head;

        for(i=0;i<position;i++){

            temporal = tempPtr;
            tempPtr = tempPtr->next;

            if(tempPtr == NULL){

                printf("\nPosition not found\n");
            }
        }

        temporal->next =tempPtr->next;
        printf("\nNode was deleted\n");
        free(tempPtr);
    }
}


