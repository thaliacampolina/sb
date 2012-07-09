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
	    //retirar 2 pontos do nome da macro
	    remove2P(prev);
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
    int index=-1;
    while(fscanf(input,"%s",instruc) > 0){
        printf("%s\n",instruc);
	if(IsKeyword(instruc)==2){//encontrada operacao com operando eh impresso seu mneomonico e seu operando 
		fscanf(input,"%s",oper);
		strcat(instruc," ");
		strcat(instruc,oper);
		fprintf(output,"%s\n",instruc);
	}
	if(IsKeyword(instruc)==1){//encotrada operacao sem operando eh impresso apenas seu mneomonico
		fprintf(output,"%s\n",instruc);
	}
	
	if(IsLabel(instruc)==1){
		remove2P(instruc);
		if(isMacro(table,instruc)==1){//encontrou uma definicao de macro
			while(strcmp(instruc,"ENDMACRO")!=0){
				fscanf(input,"%s",instruc);//eh descartada toda a sua definicao 
	
			}
		
		}
		else{
		    strcat(instruc,":");//eh um label de verdade 
		    fprintf(output,"%s ",instruc);	
		}
	}
	if(isMacro(table,instruc)==1){
		PrintMacroTableInFile(output,table, findLabelName(table,instruc));
	}

	

		
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
