#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

void Remove2P(char* str){
    str=strtok(str,":");
}

void PrintTable(Table* table, int tam){
    int i;
    for(i=0; i<tam; i++ ){
       printf("Tabela [%d] = %s \n",i,table->symbol_[i]->name_); 
    }
}


int IsLabel(char* str){
    int i = 0;
    while((str[i] != '\0') || (i<100)){
        if(str[i] == ':'){
printf("string label = %s \n",str);
            return 1;
        }
        i++;
    }
    return 0;
}



void ReadFromFile(FILE* input){
    char* instruc = (char*)calloc(100,sizeof(char));
    int ILC=0;
    int tam=0;    
    char c;
    Table* table = (Table*)malloc(sizeof(Table));
    table->last_=0;
    Symbol* symbol;

    //calculates the number of instructions
    while(fgets(instruc,100,input) >0) {
        tam++;
        printf("%d \n", tam);
    }
    rewind(input);
    while(fscanf(input,"%s",instruc) >0) {
        IncreaseILC(ILC,instruc);
        if((IsKeyword(instruc) == 0) && (IsLabel(instruc) == 1)) {
            Remove2P(instruc);
            symbol = (Symbol*)malloc(sizeof(Symbol));
            CreateSymbol(symbol,instruc,ILC);
            InsertSymbolInTable(table,symbol);
        }
        printf("%s \n", instruc);
        //IncreaseILC(ILC,instruc);  
    }
  //  PrintTable(table,tam);
}


int IsKeyword(char* instruc){
    if(strcmp(instruc,"LOAD")==0) return 1;                  
    if(strcmp(instruc,"STORE")==0) return 1;                 
    if(strcmp(instruc,"PUSH")==0) return 1;                  
    if(strcmp(instruc,"POP")==0) return 1;
    if(strcmp(instruc,"JMP")==0) return 1;                   
    if(strcmp(instruc,"JPG")==0) return 1;                   
    if(strcmp(instruc,"JPGE")==0) return 1;                   
    if(strcmp(instruc,"JPL")==0) return 1;                   
    if(strcmp(instruc,"JPLE")==0) return 1;                  
    if(strcmp(instruc,"JPE")==0) return 1;                   
    if(strcmp(instruc,"JPNE")==0) return 1;                  
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

//    FILE* output;
//    output = fopen(argv[3], "w");
//    fclose (output);
    return 0;
}