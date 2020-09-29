#include <stdio.h>
#include <stdlib.h>

// Pedro Alejandro Uicab Diaz H1.- LinkedList
// Structure
struct node{
    char letter; // char variable
    struct node *next; // Pointer variable
};

// Functions Prototypes
void isEmpty(struct node *head);

void insertEnd(struct node **head_ref, char L);

void insert(struct node **head_ref, char L, int pos);

void deleted(struct node **head_ref, int pos);

struct node *searching(struct node *head, char L);

void printList(struct node *head);

static void printListBackwards(struct node** head_ref);

int main(void){

    struct node *head = NULL;
    int opc, position;
    char L;

    do{
            // Menu
            printf("\nEnter your choice:\n");
        printf("\t1. To check if the list is empty.\n");
        printf("\t2. Insert a node at the end of list.\n");
        printf("\t3. Insert a node at specific location.\n");
        printf("\t4. Delete a node at specific location.\n");
        printf("\t5. Search a specific data in the list.\n");
        printf("\t6. Print the list.\n");
        printf("\t7. Print all elements of the list in reverse order.\n");
        printf("\t8. Exit\n");
        printf("##############################################################\n");

        // Save option
        scanf("%d", &opc);

        switch(opc)
        {
            case 1: printf("Your choice was verify the LinkedList.\n");
                    isEmpty(head);
                    system("Pause"); system("cls");
                    break;

            case 2: printf("Your choice was insert a node at the end.\n");
                    printf("Enter data of new node: "); scanf("\n%c", &L);
                    insertEnd(&head,L);
                    fflush(stdin); system("Pause"); system("cls");
                    break;

            case 3: printf("Your choice was insert a node at specific location\n");
                    printf("Enter data of new node: "); scanf("\n%c", &L);
                    printf("Type position: "); scanf("\n%d",&position);
                    insert(&head,L,position);
                    fflush(stdin); system("Pause"); system("cls");
                    break;

            case 4: printf("Your choice was delete a node at specific location.\n");
                    printf("Type position: "); scanf("\n%d",&position);
                    deleted(&head,position);
                    fflush(stdin); system("Pause"); system("cls");
                    break;

            case 5: printf("Your choice was search a specific data.\n");
                    printf("Enter data to search: "); scanf("\n%c",&L);
                    struct node *search_Ptr = searching(head,L);
                    printf("Pointer value returned is : %c\n",search_Ptr->letter);
                    system("Pause"); system("cls"); break;

            case 6: printf("Your choice was print the whole LinkedList.\n");
                    printList(head);
                    system("Pause"); system("cls"); break;

            case 7: printf("Your choice was print the linked list reverse.\n");
                    printListBackwards(&head);
                    system("Pause"); system("cls"); break;

            case 8: printf("Long Out.\n"); break;

            default: printf("Error: Invalid Option.\n");  system("Pause"); system("cls"); break;
        }


    }while(opc != 8);

return 0;
}

// First Function
void isEmpty(struct node *head){

    // Check if head pointer is link to NULL value
    if(head == NULL){
        printf("Your LinkedList is empty, try another option.\n");
        return;
    }
    // New local temporal value
    struct node *temp;

    //COUNTER HERE
    int cont=0;

    for(temp = head; temp != NULL; temp=temp->next){
        cont++;
    }
    printf("Your LinkedList has %d node(s).\n",cont);
}

//Second Function
void insertEnd(struct node **head_ref, char L){

    // New node and temporal variable
    struct node *new_node;
    struct node *temp = *head_ref;

    // Allocate dynamic memory to new node
    new_node =(struct node*)malloc(sizeof(struct node));

    // Assign data
    new_node->letter = L;

    //Check if LinkedList is empty
    if(*head_ref == NULL){
        printf("Your LinkedList is empty, so the end insertion will be the first node.\n");
        new_node->next = NULL;

        //Update
        *head_ref = new_node;
        return;
    }

    //Traversing LinkedList
    while(temp->next != NULL){
        temp = temp->next;
    }
    //Update head
    temp->next = new_node;

    // Assign NULL value
    new_node->next = NULL;

}

// Third Function
void insert(struct node **head_ref, char L, int pos){

    // New node, temporal and previous variables
    struct node *new_node;
    struct node *temp = *head_ref;
    int i, cont=0;

    //Allocate dynamic memory to new node
    new_node = (struct node*)malloc(sizeof(struct node));

    // Assign value
    new_node->letter = L;

    // verify the current size of linkedList
    while(temp != NULL){
        temp = temp->next;
        cont++;
    }

    // Verify if the position is inside of linkedList
    if(pos <= cont){

        // If the position is at the beginning we do the update
        if(pos == 1){
            new_node->next = *head_ref;
            *head_ref = new_node;
            return;
        }

        // Iterating to seek the position
        for(i=1; i< pos-1; i++){
            temp = temp->next;
        }

        // Assign the address value to new node
        new_node->next = temp->next;

        // Update the new node
        temp->next = new_node;
    }
    else{
        printf("\nError: You are out of LinkedList's range.\n");
    }
}

// Fourth Function
void deleted(struct node **head_ref, int pos){

    //New temporal variables
    struct node *tempPtr = *head_ref;
    struct node *temporal;

    int i;

    if(pos == 1){

        // Head will only had a pointer address of the next node --- previous head was deleted
        *head_ref = tempPtr->next;
        printf("\nNode deleted\n");

        // Free space memory
        free(tempPtr);
        return;
    }

    // Iterating to seek the position
    for(i=1; i<pos ;i++){
        temporal = tempPtr;
        tempPtr = tempPtr->next;

        if(tempPtr == NULL){
            printf("\nEror: You are trying remove a node out of the range.\n");
        }
    }

    // Assign new address memory to temporal node
    temporal->next = tempPtr->next;

    printf("Node was deleted.\n");

    //Free Memory
    free(tempPtr);
}

// Fifth Function
struct node *searching(struct node *head, char L){

    // Temporal variable
    struct node *temp = head ;
    int cont=0;

    // Traversing LinkedList to find the data and return the position
    while(temp != NULL && temp->letter != L){
        cont++;
        temp = temp->next;

        if(temp == NULL){
            printf("Error: Not found, try again.\n");
            return 0;
        }
    }

    printf("Position is: %d\n",cont+1);

return temp;
}

//Sixth Function
void printList(struct node *head){

    // New temporal variable for traversing the LinkedList
    struct node *tem = head;

    // Traversing nodes with while loop
    if(head == NULL){
        printf("Linked List is empty\n");
    }

    while(tem != NULL){
        printf("%c->",tem->letter);
        // n will has the next value of LinkedList
        tem = tem->next;
    }
}

// Seventh function
static void printListBackwards(struct node** head_ref){

    // Pointer variables to do the reverse
    struct node* prev = NULL;
    struct node* temp = *head_ref;
    struct node* next = NULL;

    while (temp != NULL) {

        // Assign the address value to next pointer
        next = temp->next;

        // Make the revers of pointer <<changing address>>
        temp->next = prev;

        // Moving address pointers one position ahead.
        prev = temp;
        temp = next;
    }

    *head_ref = prev;
}

