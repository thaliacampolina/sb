#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef _maquinavirtual_h
#define _maquinavirtual_h

typedef struct maquinavirtual{
    int RAM_[1000];
    //program counter
    int PC_;
    //acumulador
    int AC_;
    //stack pointer
    int SP_;
} MaquinaVirtual;


#endif
