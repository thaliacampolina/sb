#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

TabelaSimbolos InsertInTable(char* simbolo, int ILC){
    TabelaSimbolos Tabela;
    Tabela.simbolo_=(char*)calloc(100,sizeof(char));
    strcpy(Tabela.simbolo_,simbolo);
    Tabela.valor_=ILC;
    return Tabela;
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

    return(ILC);

}


//PSEUDO-INSTRUCTIONS
