/*
    Matrix Calculator Project
    @creator: Kevin Raj
    @date: April 26, 2021
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//#include<graphics.h>
// add graphics.h


int operation;
int row;
int col;
int row2;
int col2;

void mainMenu();
bool inputCheck(int input1, int input2);
int** populateMatrix(int matrix[row][col]);
void printMatrix(int matrix[row][col]);
void printMatrixMultiply(int matrix[row][col2]);
void printMatrixV2(int matrix[col][col2]);
int** scale(int matrix[row][col], int factor);
int** add(int matrix1[row][col], int matrix2[row][col]);
int** multiply(int matrix1[row][col], int matrix2[col][col2]);
int numberOfDigits(int num);
void cp();
void white();
void bold();
void noBold();


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

            bold();
            printf("\nThis is the Matrix you inputed\n\n");
            noBold();

            printMatrix(matrix);

            printf("\n\n");
            cp();
            printf("Please input the scale factor: ");
            white();

            int scalar;
            scanf("%d", &scalar);

            bold();
            printf("\nThis is your Scaled Matrix\n\n");
            noBold();

            scale(matrix, scalar);
            printMatrix(matrix);
            

            break;
        }    
        case 2:
        {
            // Adding method call and get second matrix

            cp();
            printf("Please input values for the first matrix\n\n");
            white();

            int matrix1[row][col];
            populateMatrix(matrix1);

            cp();
            printf("Please input values for the second matrix");
            white();

            int matrix2[row][col];
            populateMatrix(matrix2);

            printMatrix(add(matrix1, matrix2));

            break;
        }
            
        case 3:
        {
            cp();
            printf("Please input values for the first matrix\n\n");
            white();


            int matrix1[row][col];
            populateMatrix(matrix1);

            cp();
            printf("Please input values for the second matrix");
            white();


            int matrix2[row][col];
            populateMatrix(matrix2);

            printMatrix(add(matrix1, scale(matrix2,-1)));
        }
            // Subtract method call and get second matrix
            break;
        case 4:
        {
            // Multiply method call and get second matrix
            cp();
            printf("Please input values for the first matrix\n\n");
            white();

            int matrix1[row][col];
            populateMatrix(matrix1);

            cp();
            printf("Col dimension of Second Matrix: ");
            white();
            scanf("%d", &col2);
            




            int matrix2[col][col2];

            int rown = col;
            int coln = col2;


            char letter=65;

            bold();
            printf("\n\nTemplate of Matrix\n\n");
            noBold();

            printf("    ");

            for(int i = 0; i < coln; i++){
                    printf("%c     ", letter+i);
            }

            letter = 65;
            printf("\n");

            for(int j = 0; j < rown; j++){
                printf("%d ",j+1);
                printf("| "); 

                for(int k = 0; k < coln; k++){
                    printf("%c%d    ", letter+k,j+1);
                }

                printf("|\n");
                
            }

            printf("\n");

            letter = 65;
            
            for(int i = 0; i < rown; i++){
                for(int j = 0; j < coln; j++){
                    cp();
                    printf("%c%d: ",letter+j, i+1);
                    white();
                    scanf("%d", &matrix2[i][j]);
                }
            }
            



            printf("\n\n");

            bold();
            printf("\nMatrix 1\n\n");
            noBold();
            printMatrix(matrix1);

            printf("\n\n");


            bold();
            printf("\nMatrix 2\n\n");
            noBold();
            printMatrixV2(matrix2);

            printf("\n\n");


            
            bold();
            printf("\nResultant Matrix\n\n");
            noBold();
            printMatrixMultiply(multiply(matrix1,matrix2));


            break;
        }
            
    }

}



int** multiply(int matrix1[row][col], int matrix2[col][col2]){
    
    int result[row][col2];
    int sum = 0;

    for(int i = 0; i < row; i++){
        for(int k = 0; k < col2; k++){
            for(int j = 0; j < col; j++){

                sum += (matrix1[i][j] * matrix2[j][k]);
                
            }
            result[i][k] = sum;

            sum = 0;
        }
        
    }

    return result;

}


void printMatrixMultiply(int matrix[row][col2]){

    const int MAXSPACES = 7;
    int cond = 0;

    for(int i = 0; i < row; i++){
        printf("|    ");
        for(int j = 0; j < col2; j++){
            printf("%d",matrix[i][j]);

            cond = (MAXSPACES - numberOfDigits(matrix[i][j]));
            if(cond == 6){
                cond = cond - 1;
            }
            

            for(int k = 0; k < cond; k++){
                printf(" ");
            }
        }
        printf("|\n");
    }

}


void printMatrix(int matrix[row][col]){

    

    const int MAXSPACES = 6;
    int cond = 0;


    for(int i = 0; i < row; i++){
        printf("|    ");
        for(int j = 0; j < col; j++){
            printf("%d",matrix[i][j]);

            cond = (MAXSPACES - numberOfDigits(matrix[i][j]));
            if(cond == 6){
                cond = cond - 1;
            }

            for(int k = 0; k < cond; k++){
                printf(" ");
            }
        }
        printf("|\n");
    }


}

void printMatrixV2(int matrix[col][col2]){
    const int MAXSPACES = 6;
    int cond = 0;


    for(int i = 0; i < col; i++){
        printf("|    ");
        for(int j = 0; j < col2; j++){
            printf("%d",matrix[i][j]);

            cond = (MAXSPACES - numberOfDigits(matrix[i][j]));
            if(cond == 6){
                cond = cond - 1;
            }

            for(int k = 0; k < cond; k++){
                printf(" ");
            }
        }
        printf("|\n");
    }
}




int** populateMatrix(int matrix[row][col]){

    

    char letter=65;

    bold();
    printf("\nTemplate of Matrix\n\n");
    noBold();

    printf("    ");

    for(int i = 0; i < col; i++){
            printf("%c     ", letter+i);
    }

    letter = 65;
    printf("\n");

    for(int j = 0; j < row; j++){
        printf("%d ",j+1);
        printf("| "); 

        for(int k = 0; k < col; k++){
            printf("%c%d    ", letter+k,j+1);
        }

        printf("|\n");
        
    }

    printf("\n");

    letter = 65;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cp();
            printf("%c%d: ",letter+j, i+1);
            white();
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n");
    return matrix;
}




int** add(int matrix1[row][col], int matrix2[row][col]){

    int result[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j ++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    
    return result;
}



int** scale(int matrix[row][col], int factor){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] = factor*matrix[i][j];
        }
    }

    return matrix;
}




int numberOfDigits(int num){
    int count = 0;

    while(num != 0){
        num = num/10;
        count++;
    }

    return count;
}




bool inputCheck(int input1, int input2){

    if(input1 <= 0) {
        cp();
        printf("Input 1 is %d. Please input non-zero positive command line arguements.\n", input1);
        return false;
    }
    if(input2 <= 0) {
        cp();
        printf("Input 2 is %d. Please input non-zero positive command line arguements.\n", input2);
        return false;    
    }
    if(input1 >=10){
        cp();
        printf("Input 1 is greater than the max length 10. Please input a length less than 10");
        return false;
    }
    if(input2 >=10){
        cp();
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
        cp();
        printf("Input Selection(1-4): ");
        white();
        scanf("%d", &operation);
    } while(!(operation >= 1 && operation <= 4));
    
}







void cp(){
    printf("\033[0;34m");
    printf("$  ");
    printf("\033[0;32m");
}

void white(){
    printf("\033[0;37m");
}

void bold(){
    printf("\033[1m");
}

void noBold(){
    printf("\033[22m");
}