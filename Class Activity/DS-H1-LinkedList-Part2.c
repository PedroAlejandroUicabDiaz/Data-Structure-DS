#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Pedro Alejandro Uicab Diaz H1.1- LinkedList
// Structure
struct node{
    // Members
    int data; // Integer value
    struct node *next; // Pointer value
};


// Prototypes

void printList(struct node *linkedlist);

struct node *generate(int sizeL);

struct node *merge_linkedlist(struct node *linkedlistA, struct node *linkedlistB);

int checkNumber(struct node *mergelist,int digit);


int main(void){

    int sizelist = 25;
    int d_0, d_10, d_20, d_30, d_40, d_50;

    // Seed for random numbers
    srand(time(0));

    struct node *linkedlistA = NULL;
    struct node *linkedlistB = NULL;

    linkedlistA = generate(sizelist);
    linkedlistB = generate(sizelist);

    printf("LinkedList A: ");
    printList(linkedlistA);
    printf("\n\n");
    printf("LinkedList B: ");
    printList(linkedlistB);

    struct node *linkedlistM = merge_linkedlist(linkedlistA, linkedlistB);
    printf("\n\n");
    printf("LinkedList Merged: ");
    printList(linkedlistM);

    // Check how many times appears the following numbers: 0, 10, 20, 30, 40, 50
    d_0 = checkNumber(linkedlistM, 0);
    printf("\n\n\n############################################");
    printf("\nThe data [ 0 ] is %d times in the LinkedList Merged.",d_0);
    d_10 = checkNumber(linkedlistM, 10);
    printf("\nThe data [ 10 ] is %d times in the LinkedList Merged.",d_10);
    d_20 = checkNumber(linkedlistM, 20);
    printf("\nThe data [ 20 ] is %d times in the LinkedList Merged.",d_20);
    d_30 = checkNumber(linkedlistM, 30);
    printf("\nThe data [ 30 ] is %d times in the LinkedList Merged.",d_30);
    d_40 = checkNumber(linkedlistM, 40);
    printf("\nThe data [ 40 ] is %d times in the LinkedList Merged.",d_40);
    d_50 = checkNumber(linkedlistM, 50);
    printf("\nThe data [ 50 ] is %d times in the LinkedList Merged.\n",d_50);
    printf("############################################\n\n");


return 0;
}

// First Function
void printList(struct node *linkedlist){

   // New temporal variable for traversing the LinkedList
    struct node *temp = linkedlist;

    // Traversing nodes with while loop
    if(linkedlist == NULL){
        printf("Linked List is empty, try another option.\n");
    }

    while(temp != NULL){
        printf("%d->",temp->data);
        // n will has the next value of LinkedList
        temp = temp->next;
    }
}

// Second Function
struct node *generate(int sizeL){

    int i;
    // Pointer variable (head)
    struct node *head;

    //Pointer variable (to transverse Linkedlist)
    struct node *prev;
    struct node *temp;

    // Pointer variable (new node)
    struct node *new_node;

    // Initialization of head pointer to NULL value
    head = NULL;

    // Iterate until reach the size required
    for(i=1;i<=sizeL;i++){

        // Allocate dynamic memory
        new_node = (struct node*)malloc(sizeof(struct node));

        // Check if the new node variable is different to NULL value
        if(new_node != NULL){

            // Assign random number to new node
            new_node->data = rand()%101;

            // Assign  address to NULL value
            new_node->next = NULL;

            // Initializing secondary variables
            prev = NULL;
            temp = head;

            //Traversing linkedList using temporal variables while it compares the numbers
            while(temp !=NULL && new_node->data > temp->data){
				prev = temp;
				temp = temp->next;
			}

			// Updating our variables in case prev variable will be reach the Null value
			if (prev != NULL){

                prev->next = new_node;
				new_node->next = temp;

				continue;
			}
			//Updating our new head (LinkedList A-B)
            new_node->next = head;
            head = new_node;

        }
    }
    //Return a header
    return head;
}

//Third Function
struct node *merge_linkedlist(struct node *linkedlistA, struct node *linkedlistB){

    // New linedList's head
    struct node *head_merge = NULL;

    // Temporal variable to sorting the two linkedLists
    struct node *temp_sort;

    if (linkedlistA && linkedlistB){

        // Initialization of temporal variable at the beginning of linkedList
        if(linkedlistA->data <= linkedlistB->data){
            temp_sort = linkedlistA;
            linkedlistA = temp_sort->next;
        }
        else{
            temp_sort = linkedlistB;
            linkedlistB = temp_sort->next;
        }
    }

    // Assign new header once checked what value is greater
    head_merge = temp_sort;

    // Traversing linked list to make the change of (links)
    while(linkedlistA && linkedlistB){
        // verify if data of linkedListA is less or equal than data in linkedListB
        if(linkedlistA->data <= linkedlistB->data){

            //Moving / Update
            temp_sort->next = linkedlistA;
            temp_sort = linkedlistA;
            linkedlistA = temp_sort->next;
        }
        else{
            //Moving / Update
            temp_sort->next = linkedlistB;
            temp_sort = linkedlistB;
            linkedlistB = temp_sort->next;
        }
    }

    // If one of the linkedList reach the end we pass to other linkedList to continue
    if(linkedlistA == NULL){
        temp_sort->next = linkedlistB;
    }
    // If one of the linkedList reach the end we pass to other linkedList to continue
    if(linkedlistB = NULL){
        temp_sort->next = linkedlistA;
    }

    //Return new header
    return head_merge;
}

//Fourth Function
int checkNumber(struct node *mergelist, int digit){

    // Temporal variable
    struct node *temp = mergelist;
    // Counter
    int cont =0;

    //Traversing the linkedList merged
    while(temp != NULL){

        if(temp->data == digit){
            // Counting the appearances (times)
            cont= cont + 1;
          }
        temp = temp->next;
    }

    //Return the times
    return cont;
}

