#ifndef expansor_h
#define expansor_h

//macro structure
typedef struct macroSymbols {
    char* name_;
    char* instruc_[100];
    char* oper_[100];
    char* parameter_;
    int last_;
    int has_parameter_;
}MacroSymbols;

//macro table structure
typedef struct macroTable {
    MacroSymbols* macros_[100];
    int last_;
}MacroTable; 
//recognizes a keyword
int IsKeyword(char* instruc);
MacroSymbols* createMacroSymbols(char* name);
//inserts instruction inside a macro structure
void insertInstrucInTable(MacroSymbols* macro, char* instruc,char* oper);
MacroTable* createMacroTable();
//insert a macro in the macro tables
void insertInMacroTable(MacroTable* macroTable, MacroSymbols* macroSymbol);
//prints the macro table on the screen
void PrintTable(MacroTable* macroTable);
//recognizes a label
int IsLabel(char* str);
//finds the name of a label
int findLabelName(MacroTable* macro, char* name);
//prints a macro table in the output file
void PrintMacroTable(MacroTable* macroTable, int i);
//prints a macro with parameter table in the output file
void PrintMacroTableInFileParameter(FILE*output,MacroTable* macroTable, int i,char* parameter);
//recognizes a macro
int isMacro(MacroTable* macroTable, char* name);
//recognizes if the macro has a parameter
int hasParameter(MacroTable* macroTable,char* name);
//removes 2P from a Label or macro
void remove2P(char *str);

#endif
