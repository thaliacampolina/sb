
//macro structure
typedef struct macroSymbols {
    char* name_;
    char* instruc_[100];
    char* parameter_;
    int last_;
}MacroSymbols;

//macro table structure
typedef struct macroTable {
    MacroSymbols* macros_[100];
    int last_;
}MacroTable; 

int IsKeyword(char* instruc);
MacroSymbols* createMacroSymbols(char* name);
void insertInstrucInTable(MacroSymbols* macro, char* instruc);
MacroTable* createMacroTable();
void insertInMacroTable(MacroTable* macroTable, MacroSymbols* macroSymbol);
void PrintTable(MacroTable* macroTable);
int IsLabel(char* str);
int findLabelName(MacroTable* macro, char* name);
void PrintMacroTable(MacroTable* macroTable, int i);
int isMacro(MacroTable* macroTable, char* name);
