#include <stdio.h>
#include <stdlib.h>

/*
First approach to LinkedList- The following code was recovered from GeeksforGeeks:
Link: https://www.geeksforgeeks.org/linked-list-set-1-introduction/
*/

struct Node {
    int data;
    struct Node* next;
};

// Print Function Prototype
void printList(struct Node* n);


int main(){

    // List with three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data in first node
    head->data = 1;
    //Link first node with the second node
    head->next = second;

    // Assign data in second node
    second->data = 2;
    // Link second node with third node
    second->next = third;

    // Assign data in third node
    third->data = 3;
    // Link third node with NULL value
    third->next = NULL;


    //Print data of different nodes
    printList(head);

return 0;
}
// Function to print content of linked list starting from the given node (n=head)
void printList(struct Node* n){

    while(n != NULL){
        printf("Node: %d\n",n->data);
        //n will has the next value of linkedList
        n=n->next;
    }

    printf("Ready!!");
}
