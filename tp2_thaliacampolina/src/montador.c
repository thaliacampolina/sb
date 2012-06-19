#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

TabelaSimbolos InsertInTable(char* simbolo, int ILC, int tam){
    TabelaSimbolos Tabela;
    Tabela.simbolo_=(char*)calloc(tam,sizeof(char));
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



int Codes(char* instruc,int c, int* ILC,FILE* OUT){
    int ilc;
    ilc=*ILC;
    if(strcmp(instruc,"LOAD")==0){fprintf(OUT,"01\n");ilc+1;c=1;}
    if(strcmp(instruc,"STORE")==0){fprintf(OUT,"02\n");ilc+1;c=1;}
    if(strcmp(instruc,"PUSH")==0){fprintf(OUT,"03\n");ilc+1;c=1;}
    if(strcmp(instruc,"POP")==0){fprintf(OUT,"04\n");ilc+1;c=1;}
    if(strcmp(instruc,"JMP")==0){fprintf(OUT,"05\n");ilc+1;c=1;}
    if(strcmp(instruc,"JPG")==0){fprintf(OUT,"06\n");ilc+1;c=1;}
    if(strcmp(instruc,"JPGE")==0){fprintf(OUT,"07\n");ilc+1;c=1;}
    if(strcmp(instruc,"JPL")==0){fprintf(OUT,"08\n");ilc+1;c=1;}
    if(strcmp(instruc,"JPLE")==0){fprintf(OUT,"09\n");ilc+1;c=1;}
    if(strcmp(instruc,"JPE")==0){fprintf(OUT,"10\n");ilc+1;c=1;}
    if(strcmp(instruc,"JPNE")==0){fprintf(OUT,"11\n");ilc+1;c=1;}
    if(strcmp(instruc,"XOR")==0){fprintf(OUT,"12\n");ilc+1;c=1;}
    if(strcmp(instruc,"AND")==0){fprintf(OUT,"13\n");ilc+1;c=1;}
    if(strcmp(instruc,"OR")==0){fprintf(OUT,"14\n");ilc+1;c=1;}
    if(strcmp(instruc,"NOT")==0){fprintf(OUT,"15\n");ilc+1;c=0;}
    if(strcmp(instruc,"ADD")==0){fprintf(OUT,"16\n");ilc+1;c=1;}
    if(strcmp(instruc,"SUB")==0){fprintf(OUT,"17\n");ilc+1;c=1;}
    if(strcmp(instruc,"READ")==0){fprintf(OUT,"18\n");ilc+1;c=1;}
    if(strcmp(instruc,"WRITE")==0){fprintf(OUT,"19\n");ilc+1;c=1;}
    if(strcmp(instruc,"CALL")==0){fprintf(OUT,"20\n");ilc+1;c=1;}
    if(strcmp(instruc,"RET")==0){fprintf(OUT,"21\n");ilc+1;c=0;}
    if(strcmp(instruc,"HALT")==0){fprintf(OUT,"22\n");ilc+1;c=0;}
    if(strcmp(instruc,"WORD")==0){
        ilc+1;c=2;
    }
    *ILC=ilc;
    return(c);
}

//PSEUDO-INSTRUCTIONS
