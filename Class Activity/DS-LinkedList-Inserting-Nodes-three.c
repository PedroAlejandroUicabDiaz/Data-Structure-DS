#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Function Prototype to print data
void print_data(struct Node *head);


int main(){

    // Ptr variables to use for creating nodes
    struct Node *prev,*head,*n_node;

    //Variables to iterate the loop
    int num, i;

    // Asking for number of nodes to create
    printf("Enter the number the elements: ");
    scanf("%d",&num);

    //Initialization with NULL
    head = NULL;

    for(i=0; i<num; i++){

        // Allocate the ptr variable
        n_node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&n_node->data);

        //NULL
        n_node->next = NULL;

        // If there is not a node this will be the first
        if(head == NULL){
            head = n_node;
        }
        else{
            prev->next = n_node;
        }
        prev = n_node;

    }

    print_data(head);

return 0;
}

void print_data(struct Node *head){
    // Temporal variable
    struct Node *temp;
    // Assign the head data to temp variable
    temp=head;
    // Loop to print data
    while(temp != NULL){
        printf("%d\n",temp->data);
        // Traversing all nodes
        temp = temp->next;
    }
}
