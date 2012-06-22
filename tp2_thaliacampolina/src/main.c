#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

char* Remove2P(char* str){
    return strtok(str,":");
}

void PrintTable(Table* table, int tam){
    int i;
    for(i=0; i<tam; i++ ){
       printf("Tabela [%d] = %s  value = %d \n",i,table->symbol_[i]->name_,table->symbol_[i]->value_); 
    }
}


int IsLabel(char* str){
    int i = 0;
    while((str[i] != '\0') || (i<100)){
        if(str[i] == ':'){
            return 1;
        }
        i++;
    }
    return 0;
}


int SearchLabelValue(Table* table, char* label){
    int i=0;
    for(i=0;i<table->last_;i++){
        if(strcmp(table->symbol_[i]->name_,label) == 0) 
            return table->symbol_[i]->value_;
    }
}



void CreateOutput(FILE* input,FILE* output, Table* table){
    char* instruc = (char*)calloc(100,sizeof(char));
    char* label = (char*)calloc(100,sizeof(char));
    int number;
    int numberILC;
    int labelILC;
    int PC=0;
    while((fscanf(input,"%s",instruc) >0) && (strcmp(instruc,"END")!=0)) {
        //if is WORD
        if ((IsKeyword(instruc)==1) && (strcmp(instruc,"WORD")==0)) {
            PC++;
            fscanf(input,"%d",&number);
            fprintf(output,"%d \n",number);
        //if is any Jump instruction 
        } if ((IsKeyword(instruc) == 2)) {
            PC++;
            number = Decode(instruc);
            fprintf(output,"%d \n",number);
            fscanf(input,"%s",label);
            labelILC = SearchLabelValue(table,label);
            numberILC = labelILC - PC -1;
printf("labelILC=%d PC=%d \n", labelILC, PC );
            fprintf(output,"%d \n",numberILC);
        //if is other instruction
        } if ((IsKeyword(instruc) == 1) && (IsLabel(instruc) == 0) && (strcmp(instruc,"WORD")!=0)) {
            PC++;
            number = Decode(instruc);
            fprintf(output,"%d \n",number);
        //if is an operand
        } if ((IsKeyword(instruc) == 0) && (IsLabel(instruc) == 0)) {
            PC++;
            number = SearchLabelValue(table, instruc);
            fprintf(output,"%d \n",number);
        }
    }
}


void ReadFromFile(FILE* input, FILE* output, int verbose){
    char* instruc = (char*)calloc(100,sizeof(char));
    int ILC=0;
    int tam=0;
    char c;
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
        ILC=IncreaseILC(ILC,instruc);


//    if(strcmp(instruc,"END")==0){
//        END(ILC);
//    }

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


int IsKeyword(char* instruc){
    if(strcmp(instruc,"LOAD")==0) return 1;
    if(strcmp(instruc,"STORE")==0) return 1;
    if(strcmp(instruc,"PUSH")==0) return 1;
    if(strcmp(instruc,"POP")==0) return 1;
    if(strcmp(instruc,"JMP")==0) return 2;
    if(strcmp(instruc,"JPG")==0) return 2;
    if(strcmp(instruc,"JPGE")==0) return 2;
    if(strcmp(instruc,"JPL")==0) return 2;
    if(strcmp(instruc,"JPLE")==0) return 2;
    if(strcmp(instruc,"JPE")==0) return 2;
    if(strcmp(instruc,"JPNE")==0) return 2;
    if(strcmp(instruc,"XOR")==0) return 1;
    if(strcmp(instruc,"AND")==0) return 1;
    if(strcmp(instruc,"OR")==0) return 1;
    if(strcmp(instruc,"NOT")==0) return 1;
    if(strcmp(instruc,"ADD")==0) return 1;
    if(strcmp(instruc,"SUB")==0) return 1;
    if(strcmp(instruc,"READ")==0) return 1;
    if(strcmp(instruc,"WRITE")==0) return 1;
    if(strcmp(instruc,"CALL")==0) return 1;
    if(strcmp(instruc,"RET")==0) return 1;
    if(strcmp(instruc,"HALT")==0) return 1;
    if(strcmp(instruc,"WORD")==0) return 1;
    if(strcmp(instruc,"END")==0) return 1;
    return 0;
}

int Decode(char* instruc){
    if(strcmp(instruc,"LOAD")==0) return 1;
    if(strcmp(instruc,"STORE")==0) return 2;
    if(strcmp(instruc,"PUSH")==0) return 3;
    if(strcmp(instruc,"POP")==0) return 4;
    if(strcmp(instruc,"JMP")==0) return 5;
    if(strcmp(instruc,"JPG")==0) return 6;
    if(strcmp(instruc,"JPGE")==0) return 7;
    if(strcmp(instruc,"JPL")==0) return 8;
    if(strcmp(instruc,"JPLE")==0) return 9;
    if(strcmp(instruc,"JPE")==0) return 10;
    if(strcmp(instruc,"JPNE")==0) return 11;                  
    if(strcmp(instruc,"XOR")==0) return 12;
    if(strcmp(instruc,"AND")==0) return 13;                   
    if(strcmp(instruc,"OR")==0) return 14;
    if(strcmp(instruc,"NOT")==0) return 15;
    if(strcmp(instruc,"ADD")==0) return 16;
    if(strcmp(instruc,"SUB")==0) return 17;
    if(strcmp(instruc,"READ")==0) return 18;
    if(strcmp(instruc,"WRITE")==0) return 19;
    if(strcmp(instruc,"CALL")==0) return 20;
    if(strcmp(instruc,"RET")==0) return 21;
    if(strcmp(instruc,"HALT")==0) return 22;
   // if(strcmp(instruc,"WORD")==0) return value;
   // if(strcmp(instruc,"END")==0) return 1;
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
puts("THATHA LINDINHA");

    fclose(input);

    fclose (output);
    return 0;
}
