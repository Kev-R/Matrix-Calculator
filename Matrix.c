/*
    Matrix Calculator Project
    @creator: Kevin Raj
    @date: April 26, 2021
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool inputCheck(int input1, int input2){

    if(input1 <= 0) {
        printf("Input 1 is %d. Please input non-zero positive command line arguements.\n", input1);
        return false;    
    }
    if(input2 <= 0) {
        printf("Input 2 is %d. Please input non-zero positive command line arguements.\n", input2);
        return false;    
    }
    return true;

}


void mainMenu(){
    const width = 62;

    char c[] = "Hey. Welcome to the Matrix calculator. This calculator will\n"
               "perform calcuations that deal with Matrix manipulation.\n"
               "This calculator is built on C and was built by Kevin Raj\n";
               
    for(int i = 0; i < width; i++)
        printf("*");
    
    for(int i = 0; i <= width; i++) {
        if(i == 0) {
            printf("*  ");
        } else if (i == width) {
            /* code */
        }
        
    }

}

int main(int argc, char *argv[]) {

    if(argc != 3){
        printf("Please use this command format: ./Matrix.c <rows> <columns>\n");
    }

    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    if(!inputCheck(row, col)) { exit(1); }
    
    int matrix[row][col];

}

