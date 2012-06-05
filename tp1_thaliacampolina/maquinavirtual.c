#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maquinavirtual.h"

//IMPLEMENTAC_AO DAS INSTRUCOES

//01
MaquinaVirtual LOAD(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_]; 
    MV.PC_=MV.PC_+1;  
    MV.AC_=MV.RAM_[MV.PC_+M];
    return(MV);
}
//02
MaquinaVirtual STORE(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.RAM_[MV.PC_+M]=MV.AC_;
    return(MV);
}
//03
MaquinaVirtual PUSH(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.SP_=MV.SP_-1;
    MV.RAM_[MV.SP_]=MV.RAM_[MV.PC_+M];
    return(MV);
}
//04
MaquinaVirtual POP(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.RAM_[MV.PC_+M]=MV.RAM_[MV.SP_];
    MV.SP_=MV.SP_+1;
    return(MV);
}
//05
MaquinaVirtual JMP(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.PC_=MV.PC_+M;
    return(MV);
}
//06
// if AC_>0
MaquinaVirtual JPG(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    if(MV.AC_>0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//07
// if AC_>=0
MaquinaVirtual JPGE(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    if(MV.AC_>=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);

}
//08
// if AC_<0
MaquinaVirtual JPL(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    if(MV.AC_<0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//09
// if AC_<=0
MaquinaVirtual JPLE(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    if(MV.AC_<=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//10
// if AC_=0
MaquinaVirtual JPE(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    if(MV.AC_=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//11
// if AC_!=0
MaquinaVirtual JPNE(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    if(MV.AC_!=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//12
MaquinaVirtual XOR(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.AC_=MV.AC_^MV.RAM_[MV.PC_+M];
    return(MV);
}
//13
MaquinaVirtual AND(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.AC_=MV.AC_&MV.RAM_[MV.PC_+M];
    return(MV);
}
//14
MaquinaVirtual OR(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.AC_=MV.AC_|MV.RAM_[MV.PC_+M];
    return(MV);
}
//15
MaquinaVirtual NOT(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.AC_=~MV.AC_;
    return(MV);
}
//16
MaquinaVirtual ADD(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.AC_=MV.AC_+MV.RAM_[MV.PC_+M];
    return(MV);
}
//17
MaquinaVirtual SUB(MaquinaVirtual MV){
   int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.AC_=MV.AC_-MV.RAM_[MV.PC_+M];
    return(MV);
}
//18
MaquinaVirtual READ(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    printf("Insira um numero inteiro: ");
    scanf("%d",&MV.RAM_[MV.PC_+M]);
    return(MV);
}
//19
MaquinaVirtual WRITE(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    printf("Conteudo da Memoria: %d\n",MV.RAM_[MV.PC_+M]);
    return(MV);
}
//20
MaquinaVirtual CALL(MaquinaVirtual MV){
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+1;
    MV.SP_=MV.SP_-1;
    MV.RAM_[MV.SP_]=MV.PC_;
    MV.PC_=MV.PC_+M;
    return(MV);
}
//21
MaquinaVirtual RET(MaquinaVirtual MV){
    MV.PC_=MV.RAM_[MV.SP_];
    MV.SP_=MV.SP_+1;
    return(MV);
}
//22
MaquinaVirtual HALT(MaquinaVirtual MV){
    exit(0);
}

