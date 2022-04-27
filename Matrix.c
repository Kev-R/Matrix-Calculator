/*
    Matrix Calculator Project
    @creator: Kevin Raj
    @date: April 26, 2021
*/


#include<stdio.h>
#include<stdlib.h>

void inputCheck(int input1, int input2){

    if(input1 <= 0) {printf("Input 1 is %d. Please input non-zero positive command line arguements.\n", input1);}
    if(input2 <= 0) {printf("Input 2 is %d. Please input non-zero positive command line arguements.\n", input2);}

}

int main(int argc, char *argv[]) {

    if(argc != 3){
        printf("Please use this command format: ./Matrix.c <rows> <columns>\n");
    }

    inputCheck(atoi(argv[1]), atoi(argv[2]));

}

