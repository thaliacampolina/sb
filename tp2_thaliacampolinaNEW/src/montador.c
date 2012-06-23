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
    if(strcmp(instruc,"WORD")==0)ILC=ILC+1;

    return(ILC);

}


char* Remove2P(char* str){
    return strtok(str,":");
}

void PrintTable(Table* table, int tam){
    int i;
    for(i=0; i<tam; i++ ){
       printf("Tabela [%d] = %s  value = %d \n",i,table->symbol_[i]->name_,table->symbol_[i]->value_); 
    }
}

int isCommentary(char* str) {
    int i = 0;

    while((str[i] != '\0') ){
        if(str[i] == ';'){
            str[i]='\0';
            return 1;
        }
        i++;
    }
    return 0;
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
	return -1;
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
    if(strcmp(instruc,"END")==0) return 8;
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
    return -1;
}


void CreateOutput(FILE* input,FILE* output, Table* table){
    char* instruc = (char*)calloc(100,sizeof(char));
    char* label = (char*)calloc(100,sizeof(char));
    int number;
    int numberILC;
    int labelILC;
    int PC=0;
    while((fscanf(input,"%s",instruc) >0) && (strcmp(instruc,"END")!=0)) {
        if(isCommentary(instruc)==1) {
            while(fgetc(input)!='\n') {
                //printf("apagando\n");
            }
        } 
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
            if(isCommentary(label)==1) {
                while(fgetc(input)!='\n') {
                    //printf("apagando\n");
                }
            }
            labelILC = SearchLabelValue(table,label);
            numberILC = labelILC - PC -1;
            fprintf(output,"%d \n",numberILC);
        //if is other instruction
        } if ((IsKeyword(instruc) == 1) && (IsLabel(instruc) == 0) && (strcmp(instruc,"WORD")!=0)) {
            PC++;
            number = Decode(instruc);
            fprintf(output,"%d \n",number);
        //if is an operand
        } if ((IsKeyword(instruc) == 0) && (IsLabel(instruc) == 0)) {
            number = SearchLabelValue(table, instruc);
            if (number!=-1) {
                fprintf(output,"%d \n",number);
                PC++;
            }
        }if ((IsKeyword(instruc)==8) && (strcmp(instruc,"END")==0)) {
			return;
    	}
    }
}


