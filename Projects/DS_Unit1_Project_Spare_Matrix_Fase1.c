#include<stdio.h>
#include<stdlib.h>
/*
Data structures Data 3-A
- Spare matrix by Multi-linked circular list implementation
Andres Eduardo Arana Bejar
Emmanuel Alejandro Hurtado Alejandre
Pedro Alejandro Uicab Diaz
*/
struct node{ // Node structure which contains the members established in the PDF
    int info; // It stores the numeric value
    int row, column; // Theses store the position A(i,j)
    struct node *nextRow; // It stores the address of next row
    struct node *nextColumn; // It stores the address of next column
};
struct matrix{ // Matrix structure which contains the size of matrix
    int total_rows; // Rows total
    int total_columns; // Columns total
};

// Prototypes
void createMatrix(struct node **head_node,struct matrix m_size);
void insert(struct node **head_node, struct matrix m_size, int r, int c, int data);
int searchNode(struct node *head_node, struct matrix m_size, int row, int column);
int deleteNode(struct node **head_node, struct matrix m_size, int row, int column);
void printSpareMatrix(struct node *head_node);
struct node *Matrix_Mul(struct node **head_M1, struct node **head_M2, struct node **head_result, struct matrix m_sizeA, struct matrix m_sizeB, struct matrix m_sizeMr);
struct node *Matrix_Sum(struct node **head_M1, struct node **head_M2, struct node **head_result, struct matrix m_sizeA, struct matrix m_sizeB, struct matrix m_sizeMr);
int read(struct node *head_node, struct matrix m_size, int row, int column);
void assign(struct node *head_node, struct matrix m_size, int row, int column, int data);

int main(void){
    struct node *first_nodeA = NULL; // Header pointer to Matrix A
    struct node *first_nodeB = NULL; // Header pointer to Matrix B
    struct node *result_sum = NULL;  // Header pointer to Sum-result Matrix
    struct node *result_mult = NULL; // Header pointer to Mult_result Matrix
    struct matrix matxA; struct matrix matxB; struct matrix matxSr; struct matrix matxMr; // Structures to sizes of matrices
    int ro, co, data; // Row, column and data variables
    int choice, ch_matx; // Matrix choice The first one is the main menu choice and the second one is the matrix choice

    do{
        printf("\t**********************************************************\n");
        printf("\tSpare matrix by Multi-Linked-Circular-List Implementation \n");
        printf("\t**********************************************************\n\n");
        printf("Enter your choice:\n"
        "\t 1 to create the row and column header from a Matrix.\n"
        "\t 2 to insert a node at an specific position of Matrix.\n"
        "\t 3 to delete a node at an specific position of Matrix..\n"
        "\t 4 to assign a value at an specific node of Matrix.\n"
        "\t 5 to read a value of an existent node of Matrix.\n"
        "\t 6 to sum two Matrices.\n"
        "\t 7 to make Matrix Multiplication of two Matrices.\n"
        "\t 8 to print out a chosen Matrix.\n"
        "\t 9 to exit.\n\n" );
        scanf("%d", &choice);

        switch(choice){
                    // Create row and column headers of Matrix
            case 1: printf("\tWhat matrix would you like to use?\nPress [1] for Matrix A.\nPress [2] for Matrix B.\n"); scanf("\n%d", &ch_matx);
                    if(ch_matx != 1 && ch_matx != 2 ){printf("Invalid Matrix choice!\n"); system("PAUSE"); system("cls"); break;}
                    if(ch_matx != 2){
                        printf("Enter the size of your matrix A[i,j]:\n");
                        printf("I (rows): "); scanf("\n%d",&matxA.total_rows);
                        printf("J (columns): "); scanf("\n%d",&matxA.total_columns);
                        createMatrix(&first_nodeA, matxA);
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                        }
                    printf("Enter the size of your matrix B[i,j]:\n");
                    printf("I (rows): "); scanf("\n%d",&matxB.total_rows);
                    printf("J (columns): "); scanf("\n%d",&matxB.total_columns);
                    createMatrix(&first_nodeB, matxB);
                    fflush(stdin); system("PAUSE"); system("cls"); break;

                    // Insert new Node at specific position of Matrix
            case 2: printf("\tWhat matrix would you like to use?\nPress [1] for Matrix A.\nPress [2] for Matrix B.\n"); scanf("\n%d", &ch_matx);
                    printf("Warning!, make sure to give existent vertexes of chosen Matrix\n");
                    if(ch_matx != 1 && ch_matx !=2 ){ printf("Invalid Matrix choice!\n"); system("PAUSE"); system("cls"); break; }
                    if(ch_matx == 1){
                        if(first_nodeA == NULL){ printf("Matrix A had not been created!\n"); system("PAUSE"); system("cls"); break; }
                            printf("Enter the position of your value A(i,j):\n");
                            printf("Enter i: "); scanf("\n%d",&ro);
                            printf("Enter j: "); scanf("\n%d",&co);
                            printf("Enter data: "); scanf("\n%d", &data);
                            insert(&first_nodeA, matxA, ro, co, data);
                            fflush(stdin); system("PAUSE"); system("cls"); break;
                        }
                    if(ch_matx == 2){
                        if(first_nodeB == NULL){ printf("Matrix B had not been created!\n"); system("PAUSE"); system("cls"); break; }
                            printf("Enter the position of your value A(i,j):\n");
                            printf("Enter i: "); scanf("\n%d",&ro);
                            printf("Enter j: "); scanf("\n%d",&co);
                            printf("Enter data: "); scanf("\n%d", &data);
                            insert(&first_nodeB, matxB, ro, co, data);
                            fflush(stdin); system("PAUSE"); system("cls"); break;
                        }

                    // Delete a Node at specific position of Matrix
            case 3: printf("\tWhat matrix would you like to use?\nPress [1] for Matrix A.\nPress [2] for Matrix B.\n"); scanf("\n%d", &ch_matx);
                    printf("Warning!, make sure to give existent vertexes of chosen Matrix\n");
                    if(ch_matx != 1 && ch_matx !=2 ){ printf("Invalid Matrix choice!\n"); system("PAUSE"); system("cls"); break; }
                    if(ch_matx == 1){
                        if(first_nodeA == NULL){ printf("Matrix A had not been created!\n"); system("PAUSE"); system("cls"); break; }
                        printf("Enter the position of your value A(i,j):\n");
                        printf("Enter i: "); scanf("\n%d",&ro);
                        printf("Enter j: "); scanf("\n%d",&co);
                        printf("Position [%d][%d]\nValue [%d]",ro,co,deleteNode(&first_nodeA, matxA, ro, co));
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    if(ch_matx == 2){
                        if(first_nodeB == NULL){ printf("Matrix B had not been created!\n"); system("PAUSE"); system("cls"); break; }
                        printf("Enter the position of your value A(i,j):\n");
                        printf("Enter i: "); scanf("\n%d",&ro);
                        printf("Enter j: "); scanf("\n%d",&co);
                        printf("Position [%d][%d]\nValue [%d]",ro,co,deleteNode(&first_nodeA, matxA, ro, co));
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }

                    // Assign a value to an existent node of Matrix
            case 4: printf("\tWhat matrix would you like to use?\nPress [1] for Matrix A.\nPress [2] for Matrix B.\n"); scanf("\n%d", &ch_matx);
                    printf("Warning!, make sure to give existent vertexes of chosen Matrix\n");
                    if(ch_matx != 1 && ch_matx != 2){ printf("Invalid Matrix choice!\n"); system("PAUSE"); system("cls"); break;}
                    if(ch_matx != 2){
                        if(first_nodeA == NULL){ printf("Matrix A had not been created!\n"); system("PAUSE"); system("cls"); break; }
                        printf("Enter i: "); scanf("\n%d",&ro);
                        printf("Enter j: "); scanf("\n%d",&co);
                        printf("Enter data: "); scanf("\n%d", &data);
                        assign(first_nodeA, matxA, ro, co, data);
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    if(first_nodeB == NULL){ printf("Matrix A had not been created!\n"); system("PAUSE"); system("cls"); break; }
                    printf("Enter i: "); scanf("\n%d",&ro);
                    printf("Enter j: "); scanf("\n%d",&co);
                    printf("Enter data: "); scanf("\n%d", &data);
                    assign(first_nodeB, matxB, ro, co, data);
                    fflush(stdin); system("PAUSE"); system("cls");break;

                    // Read a value to an existent node of Matrix
            case 5: printf("\tWhat matrix would you like to use?\nPress [1] for Matrix A.\nPress [2] for Matrix B.\n"); scanf("\n%d", &ch_matx);
                    printf("Warning!, make sure to give existent vertexes of chosen Matrix\n");
                    if(ch_matx != 1 && ch_matx != 2){ printf("Invalid Matrix choice!\n"); system("PAUSE"); system("cls"); break; }
                    if(ch_matx != 2){
                        if(first_nodeA == NULL){ printf("Matrix A had not been created!\n"); system("PAUSE"); system("cls"); break; }
                        printf("Enter i: "); scanf("\n%d",&ro);
                        printf("Enter j: "); scanf("\n%d",&co);
                        printf("The value in [%d,%d] is: %d\n",ro,co,read(first_nodeA, matxA, ro, co));
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    if(first_nodeB == NULL){ printf("Matrix A had not been created!\n"); system("PAUSE"); system("cls"); break; }
                    printf("Enter i: "); scanf("\n%d",&ro);
                    printf("Enter j: "); scanf("\n%d",&co);
                    printf("The value in [%d,%d] is: %d\n",ro,co,read(first_nodeB, matxB, ro, co));
                    fflush(stdin); system("PAUSE"); system("cls"); break;

                    // Sum o two Matrices
            case 6: if(first_nodeA == NULL || first_nodeB == NULL){ // Whether matrices don't exist
                    printf("Matrix A or Matrix B had not been created!\nYou cannot preform Matrix Addition\n");
                    system("PAUSE"); system("cls"); break;
                    }
                    printf("\tMatrix A and Matrix B will be added.\n");
                    if(matxA.total_columns == matxB.total_columns && matxA.total_rows == matxB.total_rows){ // Verify if the multiplication can be preformed
                        matxSr.total_rows = matxA.total_rows;       // Rows size of result matrix
                        matxSr.total_columns = matxB.total_columns; // Columns size of result matrix
                        createMatrix(&result_sum, matxSr);  // Create result matrix header
                        Matrix_Sum(&first_nodeA, &first_nodeB, &result_sum, matxA, matxB, matxSr); // Adding Matrices
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    else{
                        printf("Sizes of Matrices incompatible!\nYou cannot preform Matrix Addition.\n");
                    }
                    system("PAUSE"); system("cls"); break;

                   // Matrix Multiplication of two Matrices
            case 7: if(first_nodeA == NULL || first_nodeB == NULL){ // Whether matrices don't exist
                        printf("Matrix A or Matrix B had not been created!\nYou cannot preform Matrix Multiplication\n");
                        system("PAUSE"); system("cls"); break;
                    }
                    printf("\tMatrix A and Matrix B will be multiplied.\n");
                    if(matxA.total_columns == matxB.total_rows){ // Verify if the multiplication can be preformed
                        matxMr.total_rows = matxA.total_rows;       // Rows size of result matrix
                        matxMr.total_columns = matxB.total_columns; //columns size of result matrix
                        createMatrix(&result_mult, matxMr); // Create result matrix header
                        Matrix_Mul(&first_nodeA, &first_nodeB, &result_mult, matxA, matxB, matxMr); //Multiply Matrices
                        system("PAUSE"); system("cls"); break;
                    }
                    else{
                        printf("Sizes of Matrices incompatible!\nYou cannot preform Matrix Multiplication.\n");
                    }
                    system("PAUSE"); system("cls"); break;

                   // Print out given Matrix
            case 8: printf("\tWhat matrix would you like to use?\nPress [1] for Matrix A.\nPress [2] for Matrix B.\nPress [3] for Matrix Sum_result.\nPress [4] for Matrix Mult_result.\n");
                    printf("Warning!, make sure to chose a created Matrix\n"); scanf("\n%d", &ch_matx);

                    if(ch_matx > 4){ printf("Invalid Matrix choice!\n"); system("PAUSE"); system("cls"); break; }
                    if(ch_matx == 1){
                        if(first_nodeA == NULL){system("cls"); break;}
                        printf("\n\tMatrix A\n");
                        printSpareMatrix(first_nodeA);
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    if(ch_matx == 2){
                        if(first_nodeB == NULL){system("cls"); break;}
                        printf("\n\tMatrix B\n");
                        printSpareMatrix(first_nodeB);
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    if(ch_matx == 3){
                        if(result_sum == NULL){system("cls"); break;}
                        printf("\n\tResult_Sum Matrix\n");
                        printSpareMatrix(result_sum);
                        fflush(stdin); system("PAUSE"); system("cls"); break;
                    }
                    if(ch_matx == 4){
                        if(result_mult == NULL){system("cls"); break;}
                        printf("\n\tResult_Multiplication Matrix\n");
                        printSpareMatrix(result_mult);
                    }
                    fflush(stdin); system("PAUSE"); system("cls"); break;

            case 9: printf("Log out.\n"); system("PAUSE"); system("cls"); break;

            default:
                printf("\tInvalid choice!\n\n"); system("PAUSE"); system("cls"); break;
        }
    }while(choice != 9);

    printf("\tThanks for using me, see you soon!\n");
 return 0;
}
// Create Matrix Function
void createMatrix(struct node **head_node, struct matrix m_size){

    struct node *init_node;
    struct node *new_node;
    struct node *aux, *prev;

    // Allocate dynamic memory
    init_node = (struct node*)malloc(sizeof(struct node));
    // Verify if the node has dynamic memory
    if(init_node == NULL){
        printf("Dynamic memory for init node was not allocated.\n");
        return;
    }
    // Assign values [row][column][value] --> [0][0][0]
    init_node->row = 0;
    init_node->column = 0;
    init_node->info = 0;
    // Pointers initialization, node links to itself
    init_node->nextColumn = init_node;
    init_node->nextRow = init_node;

    *head_node = init_node; // Head pointer links to init node which is the first node [0][0]

    for(int i = 1; i <= m_size.total_rows; i++){ // Loop to insert the extra row 0

        new_node =(struct node*)malloc(sizeof(struct node)); // Allocate dynamic memory to new nodes generated

        if(new_node != NULL){ // Verify the node has got dynamic memory

            new_node->info = 0; // Assign value
            new_node->column = 0; // Assign the column value [0]
            new_node->row = i; // Assigning the row value, it will change depending of size typed

            if(init_node->nextRow == init_node){ // It will be true when the first node is crated

                new_node->nextRow = init_node->nextRow; // New node will has the init node address
                new_node->nextColumn = new_node; // We ensure that the node points to itself
                init_node->nextRow = new_node; // Links init node to new node
            }
            else{
                aux = init_node; // We initialize aux pointer
                prev = init_node;  // We initialize aux pointer
                aux = aux->nextRow; // Bring a node forward

                while(aux != init_node){ // It traverses the circular linked list until reach the last node
                    prev = aux;
                    aux = aux->nextRow;
                }
                new_node->nextRow = prev->nextRow; // New node will has the prev node address
                new_node->nextColumn = new_node; // We ensure that the node points to itself
                prev->nextRow = new_node; // Links prev node to new node
            }

        }
    }

    for(int j = 1; j <= m_size.total_columns; j++){ // Loop to insert the extra column [0], The same operations is done but changing to columns

        new_node =(struct node*)malloc(sizeof(struct node));

        if(new_node != NULL){
            new_node->info = 0;
            new_node->column = j;
            new_node->row = 0;

            if(init_node->nextColumn == init_node){

                new_node->nextColumn = init_node->nextColumn;
                new_node->nextRow = new_node;
                init_node->nextColumn = new_node;
            }
            else{
                aux = init_node;
                prev = init_node;
                aux = aux->nextColumn;

                while(aux != init_node){
                    prev = aux;
                    aux = aux->nextColumn;
                }
                new_node->nextColumn = prev->nextColumn;
                new_node->nextRow = new_node;
                prev->nextColumn = new_node;
            }
        }
    }
}
// Insert Function
void insert(struct node **head_node, struct matrix m_size, int r, int c, int data){

    if(r > m_size.total_rows || c > m_size.total_columns){ // Verify whether position typed is inside of the matrix range
        printf("You are trying to insert a node out of the size entered.\n");
        return;
    }
    struct node *new_node;
    struct node *tempR;
    struct node *tempC;
    struct node *aux, *prev;;
    int cont = 0;

    new_node = (struct node*)malloc(sizeof(struct node)); // Allocate dynamic memory
    new_node->info = data; // Assign new value
    new_node->row = r; // Assign the row
    new_node->column = c; // Assign the column

    for(tempR = *head_node; tempR->row != r; tempR = tempR->nextRow){ // Loop to locate the pointers in its respective header nodes
        for(tempC = *head_node; tempC->column != c; tempC = tempC->nextColumn){
         cont = cont + 1;
        }
    }
    if(tempR->nextColumn == tempR && tempC->nextRow == tempC){ // First case: When the matrix is empty
        new_node->nextColumn = tempR->nextColumn; // Link new node column to header
        tempR->nextColumn = new_node; // Link header node to new node

        new_node->nextRow = tempC->nextRow; // Link new node row to header
        tempC->nextRow = new_node; // Link header node to new node
        return;
    }
    else if(tempR->nextColumn == tempR && tempC->nextRow != tempC){ // Second case: When the matrix has a header not linked
        new_node->nextColumn = tempR->nextColumn; // Link new node column to header
        tempR->nextColumn = new_node; // Link header node to new node

        prev = tempC; //  We initialize prev pointer
        aux = tempC; // We initialize aux pointer
        aux = aux->nextRow; // Bring a node forward

        while(aux != tempC){  // It traverses the circular linked list until reach the last node
            if(aux->row > r){ // If the traversing finish and this condition is not true, it means that the new node is not be among the nodes already created
                new_node->nextRow = aux;
                tempC->nextRow = new_node;
                return;
            }
            prev = aux; // Update prev pointer
            aux = aux->nextRow;
        }
        new_node->nextRow = prev->nextRow; // So, new node will insert at the end
        prev->nextRow = new_node; // Link prev node to new node
        return;
    }
    else if(tempR->nextColumn != tempR && tempC->nextRow == tempC){ // Third case: When the matrix has a header not linked
        new_node->nextRow = tempC->nextRow; // Link new node row to header
        tempC->nextRow = new_node; // Link header node to new node

        prev = tempR; //  We initialize prev pointer
        aux = tempR; // We initialize aux pointer
        aux = aux->nextColumn; // Bring a node forward

        while(aux != tempR){ // It traverses the circular linked list until reach the last node
            if(aux->column > c){ // If the traversing finish and this condition is not true, it means that the new node is not be among the nodes already created
                new_node->nextColumn = aux;
                tempR->nextColumn = new_node;
                return;
            }
            prev = aux; // Update prev pointer
            aux = aux->nextColumn;
        }
        new_node->nextColumn = prev->nextColumn; // So, new node will insert at the end
        prev->nextColumn = new_node; // Link prev node to new node
        return;
    }
    else if(tempR->nextColumn != tempR && tempC->nextRow != tempC){ // Forth case: When the matrix has its headers linked
        // Row
        prev = tempR; //  We initialize prev pointer
        aux = tempR; // We initialize aux pointer
        aux = aux->nextColumn; // Bring a node forward

        while(aux != tempR){ // It traverses the circular linked list until reach the last node
            if(aux->column > c){
                new_node->nextColumn = aux;
                tempR->nextColumn = new_node;

                // Column
                prev = tempC; //  We initialize prev pointer
                aux = tempC; // We initialize aux pointer
                aux = aux->nextRow; // Bring a node forward

                while(aux != tempC){ // It traverses the circular linked list until reach the last node
                    if(aux->row > r){
                        new_node->nextRow = aux;
                        tempC->nextRow = new_node;
                        return;
                    }
                    prev = aux; // Update prev pointer
                    aux = aux->nextRow;
                }

                new_node->nextRow = prev->nextRow; // Link new node to node which has prev node
                prev->nextRow = new_node; // link prev node to new node
                return;
            }
            prev = aux; // Update prev pointer
            aux = aux->nextColumn;
        }
        new_node->nextColumn = prev->nextColumn; // Link new node to node which has prev node
        prev->nextColumn = new_node; // link prev node to new node

        // Column
        prev = tempC; //  We initialize prev pointer
        aux = tempC; // We initialize aux pointer
        aux = aux->nextRow; // Bring a node forward

        while(aux != tempC){
            if(aux->row > r){
                new_node->nextRow = aux;
                tempC->nextRow = new_node;
                return;
            }
            prev = aux; // Update prev pointer
            aux = aux->nextRow;
        }
        new_node->nextRow = prev->nextRow; // Link new node to node which has prev node
        prev->nextRow = new_node; // link prev node to new node
    }
}
// Search a node
int searchNode(struct node *head_node, struct matrix m_size, int row, int column){

    struct node *tempR = head_node;
    struct node *tempC;

    if(row > m_size.total_rows || column > m_size.total_columns){ // Verify whether position typed is inside of the matrix range
        printf("You are trying to perform a operation outside of the matrix range.\n");
        return 0;
    }

    for(int i = 0; i <= row-1; i++){ // Loop to position the pointer to the correct header
        tempR = tempR->nextRow; // It will advance until it reaches the row entered
    }
    tempC = tempR; // We initialize tempC pointer
    tempC = tempC->nextColumn; // Bring one node forward

    while(tempC != tempR){ // Loop to traverse the circular linked list until it found the node
        if(tempC->column == column) return 1; // return 1 if it find it
        tempC = tempC->nextColumn;
    }
    printf("The position typed has not a node.\n"); // If the loop end and does not find anything it return 0
    return 0;
}
// Delete a node given a row and column
int deleteNode(struct node **head_node, struct matrix m_size, int row, int column){

    struct node *tempR;
    struct node *tempC;
    struct node *prev, *aux;
    int pase, data, cont = 0;

    pase = searchNode(*head_node,m_size,row,column); // Verify it the node exist
    if(pase != 1) return 0;

    for(tempR = *head_node; tempR->row != row; tempR = tempR->nextRow){ // Loop to locate the pointers in its respective header nodes
        for(tempC = *head_node; tempC->column != column; tempC = tempC->nextColumn){
         cont = cont + 1;
        }
    }

    if(tempR->nextColumn != tempR && tempC->nextRow != tempC){ // Verify that the headers has other nodes
        aux = tempR; // We initialize aux pointer
        prev = tempR; // We initialize prev pointer
        aux = aux->nextColumn; // Bring a node forward

        while(aux != tempR){ // Loop to find the node in the rows
            if(aux->row == row && aux->column == column){
                prev->nextColumn = aux->nextColumn;
                aux->nextColumn = aux;

                aux = tempC; // We initialize aux pointer
                prev = tempC; // We initialize prev pointer
                aux = aux->nextRow; // Bring a node forward

                while(aux != tempC){ // Loop to find the node in the columns
                    if(aux->row == row && aux->column == column){
                        prev->nextRow = aux->nextRow;
                        aux->nextRow = aux;
                        data = aux->info; // Save the value
                        free(aux); // Free the memory
                        return data; // Return the value
                    }
                    prev = aux; // Update prev pointer
                    aux = aux->nextRow; // Bring a node forward
                }
            }
            prev = aux; // Update prev pointer
            aux = aux->nextColumn; // Bring a node forward
        }
    }
}
// Printing Matrix Function
void printSpareMatrix(struct node *head_node){

    struct node *tempR = head_node;
    struct node *tempC;

    tempR = tempR->nextRow; // Bring a node forward
    if(head_node != NULL){ // Verify the head pointer has nodes already created

        while(tempR->nextRow != head_node){ // Loop to perform the traversing
            tempC = tempR; // We initialize tempC
            tempC = tempC->nextColumn; // Bring a node forward

            do{
                printf(" [%d] ",tempC->info); // Print the info
                tempC = tempC->nextColumn; // Bring a node forward
            }while(tempC != tempR);

            printf("\n");
            tempR = tempR->nextRow; // Bring a node forward
        }
        tempC = tempR; // We initialize tempC
        tempC = tempC->nextColumn; // Bring a node forward
        do{
            printf(" [%d] ",tempC->info); // Print the info
            tempC = tempC->nextColumn; // Bring a node forward
        }
        while(tempC != tempR);
    }
}
// ReadOp function
int read(struct node *head_node, struct matrix m_size, int row, int column){

    struct node *tempR = head_node;
    struct node *tempC;

    if(row > m_size.total_rows || column > m_size.total_columns){ // Verify whether position typed is inside of the matrix range
        printf("You are trying to perform a operation outside of the matrix range.\n");
        return 0;
    }
    tempR = tempR->nextRow; // Bring a node forward
    if(head_node != NULL){

        while(tempR->nextRow != head_node){
            tempC = tempR;
            tempC = tempC->nextColumn; // Bring a node forward
            do{
                if(row == tempC->row && column == tempC->column){
                    return tempC->info; //returning found data
                }
                tempC = tempC->nextColumn; // Bring a node forward
            }while(tempC != tempR);
            tempR = tempR->nextRow; // Bring a node forward
        }
        tempC = tempR;
        tempC = tempC->nextColumn; // Bring a node forward
        do{
            if(row == tempC->row && column == tempC->column){
                return tempC->info; //returning found data
            }
            tempC = tempC->nextColumn; // Bring a node forward
        }
        while(tempC != tempR);
        return 0; //returning zero if node does not exists
    }
}
// Assign Function*/
void assign(struct node *head_node, struct matrix m_size, int row, int column, int data){

    struct node *tempR = head_node;
    struct node *tempC;

    if(row > m_size.total_rows || column > m_size.total_columns){ // Verify whether position typed is inside of the matrix range
        printf("You are trying to perform a operation outside of the matrix range.\n");
        return;
    }
    tempR = tempR->nextRow; // Bring a node forward
    if(head_node != NULL){

        while(tempR->nextRow != head_node){
            tempC = tempR;
            tempC = tempC->nextColumn; // Bring a node forward
            do{
                if(row == tempC->row && column == tempC->column){
                    tempC->info = data; //adding given value
                    printf("Value changed!\n");
                    return;
                }
                tempC = tempC->nextColumn; // Bring a node forward
            }while(tempC != tempR);
            tempR = tempR->nextRow; // Bring a node forward
        }
        tempC = tempR;
        tempC = tempC->nextColumn; // Bring a node forward
        do{
            if(row == tempC->row && column == tempC->column){
                tempC->info = data; //adding given value
                printf("Value changed!\n");
                return;
            }
            tempC = tempC->nextColumn; // Bring a node forward
        }
        while(tempC != tempR);
        printf("Given node does not exists!\n");
        return;
    }
}
// Matrix Addition
struct node *Matrix_Sum(struct node **head_M1, struct node **head_M2, struct node **head_result, struct matrix m_sizeA, struct matrix m_sizeB, struct matrix m_sizeMr){

    int i; int j; //Rows and columns counters
    int data=0; //result of operation variable

    for(i=1; i<=m_sizeA.total_rows; i++){
        for(j=1; j<=m_sizeB.total_rows; j++){
            data = 0;
            data = data + read(*head_M1,m_sizeA, i, j) + read(*head_M2, m_sizeB,i,j); // Sum operation
            insert(head_result, m_sizeMr, i, j, data); // Insert the value to new matrix
        }
    }
    return *head_result; // Return a pointer of new matrix
}
// Matrix Multiplication (pow)
struct node *Matrix_Mul(struct node **head_M1, struct node **head_M2, struct node **head_result, struct matrix m_sizeA, struct matrix m_sizeB, struct matrix m_sizeMr){

    int i; int j; //Rows and columns variables
    int k, data=0; //result of operation variable

    for(i=1; i<=m_sizeA.total_rows; i++){
        for(j=1; j<=m_sizeB.total_columns; j++){
            data = 0;
            for(k=1; k<=m_sizeA.total_columns; k++){
                data = data + read(*head_M1,m_sizeA, j, k) * read(*head_M2, m_sizeB,k,i); // Multiplication operation
            }
            insert(head_result, m_sizeMr, j, i, data); // Insert the value in the new matrix
        }
    }
    return *head_result; // return the pointer of new matrix
}
