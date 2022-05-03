/*
    Matrix Calculator Project
    @creator: Kevin Raj
    @date: April 26, 2021
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int operation;
int row;
int col;

void mainMenu();
bool inputCheck(int input1, int input2);
int** populateMatrix(int matrix[row][col]);
void printMatrix(int matrix[row][col]);



int main(int argc, char *argv[]) {

    if(argc != 3){
        printf("Please use this command format: ./Matrix.c <rows> <columns>\n");
    }

    row = atoi(argv[1]);
    col = atoi(argv[2]);

    if(!inputCheck(row, col)) { exit(1); }

    mainMenu();


    switch(operation){
        case 1:
        {   // Scaling method call
            int matrix[row][col];
            populateMatrix(matrix);
            printMatrix(matrix);
            break;
        }    
        case 2:
            // Adding method call and get second matrix
            break;
        case 3:
            // Subtract method call and get second matrix
            break;
        case 4:
            // Multiply method call and get second matrix
            break;
    }

}




int** populateMatrix(int matrix[row][col]){

    char letter=65;


    printf("\nBelow is a template of the matrix. We need to populate it.\n\n");


    printf("    ");

    for(int i = 0; i < row; i++){
            printf("%c   ", letter+i);
    }

    letter = 65;
    printf("\n");

    for(int j = 0; j < col; j++){
        printf("%d ",j+1);
        printf("| ");

        for(int k = 0; k < row; k++){
            printf("%c%d  ", letter+k,j+1);
        }

        printf("|\n");
        
    }

    printf("\n");

    letter = 65;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%c%d: ",letter+i, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}


void printMatrix(int matrix[row][col]){

    for(int i = 0; i < row; i++){
        printf("| ");
        for(int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
}



bool inputCheck(int input1, int input2){

    if(input1 <= 0) {
        printf("Input 1 is %d. Please input non-zero positive command line arguements.\n", input1);
        return false;
    }
    if(input2 <= 0) {
        printf("Input 2 is %d. Please input non-zero positive command line arguements.\n", input2);
        return false;    
    }
    if(input1 >=10){
        printf("Input 1 is greater than the max length 10. Please input a length less than 10");
        return false;
    }
    if(input2 >=10){
        printf("Input 2 is greater than the max length 10. Please input a length less than 10");
        return false;
    }

    return true;

}














void mainMenu(){

    const int width = 67;

    for(int i = 0; i < 35; i++)
         printf("- ");

    printf("\n");   

    char c1[] = "\nHey. Welcome to the Matrix calculator. This calculator will\n"
                "deal with calculations that are performed on matrices\n"
                "You may pick one of the following operations to perform.\n"
                "\n(1) Scale a Matrix\n"
                "(2) Add 2 Matrices\n"
                "(3) Subtract 2 Matrices\n"
                "(4) Multiply 2 Matrices\n\n";


    int j = 0;
    for(int i = 0; i < 10; i++){
        printf("*    ");
        int counter = 3;

        for(; j < sizeof(c1); j++){
            if(c1[j] == '\n'){
                j++;
                break;
            }
            printf("%c", c1[j]);
            counter++;
        }

        for(int k = counter; k < width-1; k++){
            printf(" ");
        }
        printf("*\n");
    }

    for(int i = 0; i < 35; i++)
            printf("- ");

    printf("\n\n");

    
    do {
        printf("$ Input Selection(1-4): ");
        scanf("%d", &operation);
    } while(!(operation >= 1 && operation <= 4));
    
}

