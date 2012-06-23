#ifndef _montador_h
#define _montador_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct symbol {
    char* name_;
    int value_;
}Symbol;

typedef struct table {
    Symbol* symbol_[100];
    int last_;
}Table;


void CreateSymbol(Symbol* symbol,char* name, int ILC);
void InsertSymbolInTable(Table* table, Symbol* symbol);
int IncreaseILC(int ILC, char* instruc);
char* Remove2P(char* str);
void PrintTable(Table* table, int tam);
int isCommentary(char* str);
int IsLabel(char* str);
int SearchLabelValue(Table* table, char* label);
int IsKeyword(char* instruc);
int Decode(char* instruc);
void CreateOutput(FILE* input,FILE* output, Table* table);


#endif
