#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

void ReadFromFile(FILE* input, FILE* output, int verbose){
    char* instruc = (char*)calloc(100,sizeof(char));
    int ILC=0;
    int tam=0;
    Table* table = (Table*)malloc(sizeof(Table));
    table->last_=0;
    Symbol* symbol;
    int labelCounter=0;

    //calculates the number of instructions
    while(fgets(instruc,100,input) >0) {
        tam++;
    }
    rewind(input);
    while(fscanf(input,"%s",instruc) >0) {
        isCommentary(instruc);
		ILC=IncreaseILC(ILC,instruc);

        if((IsKeyword(instruc) == 0) && (IsLabel(instruc) == 1)) {
            strcpy(instruc,Remove2P(instruc));
            symbol = (Symbol*)malloc(sizeof(Symbol));
            CreateSymbol(symbol,instruc,ILC);
            InsertSymbolInTable(table,symbol);
            labelCounter++;
        }
    }

    if (verbose == 1){
        PrintTable(table,labelCounter);
    }

    rewind(input);
    CreateOutput(input,output,table);

}


int main(int argc, char* argv[]){
    FILE* input;
    FILE* output;
    input = fopen(argv[2], "r");
    output = fopen(argv[3], "w");
    int verbose;
    if(strcmp(argv[1],"v")==0){
        verbose=1;
    }
    if(strcmp(argv[1],"s")==0){
        verbose=0;
    }
    
    ReadFromFile(input, output, verbose);    

    fclose(input);

    fclose (output);
    return 0;
}
