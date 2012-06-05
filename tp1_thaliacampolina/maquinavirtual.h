#ifndef _maquinavirtual_h
#define _maquinavirtual_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct maquinavirtual{
    int RAM_[1000];
    //program counter
    int PC_;
    //acumulador
    int AC_;
    //stack pointer
    int SP_;
} MaquinaVirtual;

//01
MaquinaVirtual LOAD(MaquinaVirtual MV);
//02
MaquinaVirtual STORE(MaquinaVirtual MV);
//03
MaquinaVirtual PUSH(MaquinaVirtual MV);
//04
MaquinaVirtual POP(MaquinaVirtual MV);
//05
MaquinaVirtual JMP(MaquinaVirtual MV);
//06
// if AC_>0
MaquinaVirtual JPG(MaquinaVirtual MV);
//07
// if AC_>=0
MaquinaVirtual JPGE(MaquinaVirtual MV);
//08
// if AC_<0
MaquinaVirtual JPL(MaquinaVirtual MV);
//09
// if AC_<=0
MaquinaVirtual JPLE(MaquinaVirtual MV);
//10
// if AC_=0
MaquinaVirtual JPE(MaquinaVirtual MV);
//11
// if AC_!=0
MaquinaVirtual JPNE(MaquinaVirtual MV);
//12
MaquinaVirtual XOR(MaquinaVirtual MV);
//13
MaquinaVirtual AND(MaquinaVirtual MV);
//14
MaquinaVirtual OR(MaquinaVirtual MV);
//15
MaquinaVirtual NOT(MaquinaVirtual MV);
//16
MaquinaVirtual ADD(MaquinaVirtual MV);
//17
MaquinaVirtual SUB(MaquinaVirtual MV);
//18
MaquinaVirtual READ(MaquinaVirtual MV);
//19
MaquinaVirtual WRITE(MaquinaVirtual MV);
//20
MaquinaVirtual CALL(MaquinaVirtual MV);
//21
MaquinaVirtual RET(MaquinaVirtual MV);
//22
MaquinaVirtual HALT(MaquinaVirtual MV);

#endif
