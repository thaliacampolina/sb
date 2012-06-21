#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

void CreateSymbol(Symbol* symbol,char* name, int ILC){
    symbol->name_=(char*)calloc(100,sizeof(char));
    strcpy(symbol->name_,name);
    symbol->value_=ILC;
}

void InsertSymbolInTable(Table* table, Symbol* symbol){
    table->symbol_[table->last_]=symbol;
    table->last_++; 
}



int IncreaseILC(int ILC, char* instruc){
    if(strcmp(instruc,"LOAD")==0)ILC=ILC+2;                  
    if(strcmp(instruc,"STORE")==0)ILC=ILC+2;                 
    if(strcmp(instruc,"PUSH")==0)ILC=ILC+2;                  
    if(strcmp(instruc,"POP")==0)ILC=ILC+2;
    if(strcmp(instruc,"JMP")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"JPG")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"JPGE")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"JPL")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"JPLE")==0)ILC=ILC+2;                  
    if(strcmp(instruc,"JPE")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"JPNE")==0)ILC=ILC+2;                  
    if(strcmp(instruc,"XOR")==0)ILC=ILC+2;
    if(strcmp(instruc,"AND")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"OR")==0)ILC=ILC+2;
    if(strcmp(instruc,"NOT")==0)ILC=ILC+1;
    if(strcmp(instruc,"ADD")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"SUB")==0)ILC=ILC+2;                   
    if(strcmp(instruc,"READ")==0)ILC=ILC+2;                  
    if(strcmp(instruc,"WRITE")==0)ILC=ILC+2;                 
    if(strcmp(instruc,"CALL")==0)ILC=ILC+2;
    if(strcmp(instruc,"RET")==0)ILC=ILC+1;
    if(strcmp(instruc,"HALT")==0)ILC=ILC+1;
    if(strcmp(instruc,"WORD")==0)ILC=ILC+2;
    if(strcmp(instruc,"END")==0)ILC=ILC+1;

    return(ILC);

}


//PSEUDO-INSTRUCTIONS

int WORD(int ILC,int value){
    int READ = 18;
    return READ;
}   
 
