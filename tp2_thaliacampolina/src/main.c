#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

void ReadFromFile(FILE* input){
    char* instruc = (char*)calloc(100,sizeof(char));
    int ILC=0;
    int tam=0;    
    strcpy(instruc,"koala");
    printf("\n%s",instruc);
    //calculates the number of instructions
    while(fscanf(input,"%s",instruc) >0) {
        tam++;
    }
    rewind(input);
    while(fscanf(input,"%s",instruc) >0) {
        printf("%s \n", instruc);
        //InsertInTable(instruc,ILC,tam);
        //IncreaseILC(ILC,instruc);  
    }
}



int main(int argc, char* argv[]){
    FILE* input;
    input = fopen(argv[2], "r");
    int verbose;
    if(strcmp(argv[1],"v")==0){
        verbose=1;
    }
    if(strcmp(argv[1],"s")==0){
        verbose=0;
    }
    
    ReadFromFile(input);    
puts("THATHA LINDINHA");

    fclose(input);

    FILE* output;
    output = fopen(argv[3], "w");
    fclose (output);
    return 0;
}
