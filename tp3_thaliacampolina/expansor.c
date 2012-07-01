#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expansor.h"

MacroSymbols* createMacroSymbols(char* name){
    MacroSymbols* macro = (MacroSymbols*) malloc(sizeof(MacroSymbols));
    macro->name_ = (char*) calloc(100,sizeof(char));
    macro->parameter_ = (char*) calloc(100,sizeof(char));
    macro->last_=0;
    strcpy(macro->name_,name);
    return macro;
}

void insertInstrucInTable(MacroSymbols* macro, char* instruc){
    macro->instruc_[macro->last_]=(char*) calloc(100,sizeof(char));
    strcpy(macro->instruc_[macro->last_],instruc);
    macro->last_++;
}

MacroTable* createMacroTable(){
    MacroTable* macroTable = (MacroTable*) malloc(sizeof(MacroTable));
    macroTable->last_=0; 
    return macroTable;
}

void insertInMacroTable(MacroTable* macroTable, MacroSymbols* macroSymbol){
    macroTable->macros_[macroTable->last_] = macroSymbol; 
    macroTable->last_ ++;
}

void PrintTable(MacroTable* macroTable){
    int i = 0;
    int j = 0;
    for(i=0;i<macroTable->last_; i++){
        for(j=0;j<macroTable->macros_[i]->last_; j++){
            printf("name: %s parameter: %s info: %s \n", macroTable->macros_[i]->name_ , macroTable->macros_[i]->parameter_ ,macroTable->macros_[i]->instruc_[j]);
        }
    }
}

//char* FindMacroByName(){
//}

//Recognizes a Label
int IsLabel(char* str){
    int i = 0;
    while(str[i]){
        if(str[i] == ':'){
            return 1;
        }
        i++;
    }
    return 0;
}

int findLabelName(MacroTable* macro, char* name){
    int i = 0;
    for(i=0;i<macro->last_;i++){
       if(strcmp(macro->macros_[i]->name_, name)==0){
           return i;
       }
    }
    return -1;
}

void PrintMacroTableInFile(FILE*output,MacroTable* macroTable, int i){
    int j;
    for(j=0;j<macroTable->macros_[i]->last_; j++){
    printf("name: %s parameter: %s info: %s \n", macroTable->macros_[i]->name_ , macroTable->macros_[i]->parameter_ ,macroTable->macros_[i]->instruc_[j]);
    fprintf(output,"%s\n",macroTable->macros_[i]->instruc_[j]);
    }
}

int isMacro(MacroTable* macroTable, char* name){
    int i;
    for(i=0;i<macroTable->last_; i++){
        if(findLabelName(macroTable,name) != -1){
            return 1;
        }
    }
    return 0;
}



//Recognizes a keyword
int IsKeyword(char* instruc){
    if(strcmp(instruc,"LOAD")==0) return 2;
    if(strcmp(instruc,"STORE")==0) return 2;
    if(strcmp(instruc,"PUSH")==0) return 2;
    if(strcmp(instruc,"POP")==0) return 2;
    if(strcmp(instruc,"JMP")==0) return 2;
    if(strcmp(instruc,"JPG")==0) return 2;
    if(strcmp(instruc,"JPGE")==0) return 2;
    if(strcmp(instruc,"JPL")==0) return 2;
    if(strcmp(instruc,"JPLE")==0) return 2;
    if(strcmp(instruc,"JPE")==0) return 2;
    if(strcmp(instruc,"JPNE")==0) return 2;
    if(strcmp(instruc,"XOR")==0) return 2;
    if(strcmp(instruc,"AND")==0) return 2;
    if(strcmp(instruc,"OR")==0) return 2;
    if(strcmp(instruc,"NOT")==0) return 1;
    if(strcmp(instruc,"ADD")==0) return 2;
    if(strcmp(instruc,"SUB")==0) return 2;
    if(strcmp(instruc,"READ")==0) return 2;
    if(strcmp(instruc,"WRITE")==0) return 2;
    if(strcmp(instruc,"CALL")==0) return 2;
    if(strcmp(instruc,"RET")==0) return 1;
    if(strcmp(instruc,"HALT")==0) return 1;
    if(strcmp(instruc,"WORD")==0) return 2;
    if(strcmp(instruc,"END")==0) return 1;
    if(strcmp(instruc,"ENDMACRO")==0) return 1;
    if(strcmp(instruc,"BEGINMACRO")==0) return 1;
    return 0;
}

