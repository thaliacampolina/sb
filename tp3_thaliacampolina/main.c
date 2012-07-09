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
	    //remove ":" from the macro name
	    remove2P(prev);
            macro = createMacroSymbols(prev);
            while(strcmp(instruc,"ENDMACRO")!=0){
                fscanf(input,"%s",instruc);
                //macro with parameter
                if(IsKeyword(instruc)==0){
                    strcpy(macro->parameter_,instruc);
		    macro->has_parameter_=1;
                } else {
                    //check if theres an operand to insert in table
                    if(IsKeyword(instruc)==2 &&(strcmp(instruc,"ENDMACRO")!=0)){
                       fscanf(input,"%s",oper);
		       
                       insertInstrucInTable(macro,instruc,oper);
                    } else if(strcmp(instruc,"ENDMACRO")!=0) {
		       strcpy(oper,"\0");
		       macro->has_parameter_=0;	
                       insertInstrucInTable(macro,instruc,oper);
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
    char* parameter= (char*)calloc(100,sizeof(char));
    char* oper = (char*)calloc(100,sizeof(char)); 
    int index=-1;
    while(fscanf(input,"%s",instruc) > 0){
        // If the operation with its operand is found, its mnemonic and operand is printed
	if(IsKeyword(instruc)==2){
		fscanf(input,"%s",oper);
		strcat(instruc," ");
		strcat(instruc,oper);
		fprintf(output,"%s\n",instruc);
	}
        // If the operation without any operand is found, its mnemonic is printed
	if(IsKeyword(instruc)==1){
		fprintf(output,"%s\n",instruc);
	}
        // finds a macro definition, and ignores its definition	
	if(IsLabel(instruc)==1){
		remove2P(instruc);
		if(isMacro(table,instruc)==1||isMacro(table,instruc)==2){//find a macro definition
			while(strcmp(instruc,"ENDMACRO")!=0){
				fscanf(input,"%s",instruc);//ignores its definition 
			}
		
		}
		else{
                   //if is label:
		    strcat(instruc,":");
		    fprintf(output,"%s ",instruc);	
		}
	}
        // prints macro whithout parameter in the output file
	if(isMacro(table,instruc)==1){
		PrintMacroTableInFile(output,table, findLabelName(table,instruc));
	}
        // prints macro with parameter
	if(isMacro(table,instruc)==2){
		fscanf(input,"%s",parameter);
		PrintMacroTableInFileParameter(output,table, findLabelName(table,instruc),parameter);	
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
