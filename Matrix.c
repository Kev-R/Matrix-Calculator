/*
    Matrix Calculator Project
    @creator: Kevin Raj
    @date: April 26, 2021
*/


#include<stdio.h>
#include<stdlib.h>

void inputCheck(int input1, int input2){
    //if(input1 == \0) {printf("Input 1 is null. Please input valid command line arguements.");}
        

    //if(input1 == \0) {printf("Input 2 is null. Please input valid command line arguements.");}
        
    printf("I am here\n %d %d\n", input1, input2);

    if(input1 < 0) {printf("Input 1 is negative. Please input positive command line arguements.");}

    if(input2 < 0) {printf("Input 2 is negative. Please input positive command line arguements.");}
}

int main(int argc, char *argv[]) {
    

    if(argc != 3){
        printf("Please use this command format: ./Matrix.c <rows> <columns>\n");
    }

    inputCheck(argv[1], argv[2]);
    



}

