#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expansor.h"

void ReadFromFile(FILE* input,MacroTable* table){
    char* instruc = (char*)calloc(100,sizeof(char));
    char* prev= (char*)calloc(100,sizeof(char)); 
    char* oper = (char*)calloc(100,sizeof(char)); 
    MacroSymbols* macro;

//READING MACROS AND CREATING TABLES
    while(fscanf(input,"%s",instruc) > 0){
        if(strcmp(instruc,"BEGINMACRO")!=0){
            strcpy(prev,instruc);
        } else {
            //creates macro with its name (prev)
            macro = createMacroSymbols(prev);
            while(strcmp(instruc,"ENDMACRO")!=0){
                //TODO:check parameters
                fscanf(input,"%s",instruc);
                //macro with parameter
                if(IsKeyword(instruc)==0){
                    strcpy(macro->parameter_,instruc);
                } else {
                    //check if theres an operand to insert in table
                    if(IsKeyword(instruc)==2 &&(strcmp(instruc,"ENDMACRO")!=0)){
                       fscanf(input,"%s",oper);
                       strcat(instruc," ");
                       strcat(instruc, oper);
                      insertInstrucInTable(macro,instruc);
                    } else if(strcmp(instruc,"ENDMACRO")!=0) {
                       insertInstrucInTable(macro,instruc);
                    }
                }
            }
            insertInMacroTable(table,macro);
        }
    }
    PrintTable(table);
}

void createOutputFile(FILE* input, FILE* output, MacroTable* table ){
    char* instruc = (char*)calloc(100,sizeof(char));
    char* prev= (char*)calloc(100,sizeof(char)); 
    char* oper = (char*)calloc(100,sizeof(char)); 
    while(fscanf(input,"%s",instruc) > 0){
        strcpy(prev,instruc);

        //threat macro instructions
        if(strcmp(instruc,"BEGINMACRO")==0){
            int index = findLabelName(table,prev);
            //throw away macro def
            while(strcmp(instruc,"ENDMACRO")!=0){
                fscanf(input,"%s",instruc);
            }
            //ignore instruction ENDMACRO
            fscanf(input,"%s",instruc);
            //print macro table in output file 
        } else {
            if(IsKeyword(instruc)==2){
                fscanf(input,"%s",oper);
                strcat(instruc," ");
                strcat(instruc, oper);
                fprintf(output,"%s \n",instruc);
            } else if (IsKeyword(instruc)==1){
                fprintf(output,"%s\n",instruc);
            }
            if(IsLabel(instruc)==1){
                fscanf(input,"%s",oper); 
                //treat macro instructions
                if(strcmp(oper,"BEGINMACRO")==0){
                //treat labels
                }
                if(isMacro(table,oper)==1){
                    PrintMacroTableInFile(output, table, index);
                }
            } else {
                    strcat(instruc, " ");
                    strcat(instruc, oper);
                    fgets(oper,100,input); 
                    strcat(instruc, oper);
                    fprintf(output,"%s",instruc);
            }
        }
           // fprintf(output,"%s",instruc);
    }
    
}



int main(int argc, char* argv[]){
    FILE* input;
    FILE* output;
    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");
    MacroTable* table;
    table = createMacroTable();
    
    ReadFromFile(input, table);    
    rewind(input);
    createOutputFile(input, output, table);
    fclose(input);

    fclose (output);
    return 0;
}
