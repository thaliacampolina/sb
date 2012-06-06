#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maquinavirtual.h"

//IMPLEMENTAC_AO DAS INSTRUCOES

//01
MaquinaVirtual LOAD(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;  
    int M=MV.RAM_[MV.PC_]; 
    MV.AC_=MV.RAM_[MV.PC_+M];
    return(MV);
}
//02
MaquinaVirtual STORE(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.RAM_[MV.PC_+M]=MV.AC_;
    return(MV);
}
//03
MaquinaVirtual PUSH(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.SP_=MV.SP_-1;
    MV.RAM_[MV.SP_]=MV.RAM_[MV.PC_+M];
    return(MV);
}
//04
MaquinaVirtual POP(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.RAM_[MV.PC_+M]=MV.RAM_[MV.SP_];
    MV.SP_=MV.SP_+1;
    return(MV);
}
//05
MaquinaVirtual JMP(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.PC_=MV.PC_+M;
    return(MV);
}
//06
// if AC_>0
MaquinaVirtual JPG(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    if(MV.AC_>0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//07
// if AC_>=0
MaquinaVirtual JPGE(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    if(MV.AC_>=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);

}
//08
// if AC_<0
MaquinaVirtual JPL(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    if(MV.AC_<0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//09
// if AC_<=0
MaquinaVirtual JPLE(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    if(MV.AC_<=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//10
// if AC_=0
MaquinaVirtual JPE(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    if(MV.AC_=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//11
// if AC_!=0
MaquinaVirtual JPNE(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    if(MV.AC_!=0){
        MV.PC_=MV.PC_+M;
    }
    return(MV);
}
//12
MaquinaVirtual XOR(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.AC_=MV.AC_^MV.RAM_[MV.PC_+M];
    return(MV);
}
//13
MaquinaVirtual AND(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.AC_=MV.AC_&MV.RAM_[MV.PC_+M];
    return(MV);
}
//14
MaquinaVirtual OR(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.AC_=MV.AC_|MV.RAM_[MV.PC_+M];
    return(MV);
}
//15
MaquinaVirtual NOT(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.AC_=~MV.AC_;
    return(MV);
}
//16
MaquinaVirtual ADD(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.AC_=MV.AC_+MV.RAM_[MV.PC_+M];
    return(MV);
}
//17
MaquinaVirtual SUB(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    MV.AC_=MV.AC_-MV.RAM_[MV.PC_+M];
    return(MV);
}
//18
MaquinaVirtual READ(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    printf("Insira um numero inteiro: ");
    scanf("%d",&MV.RAM_[MV.PC_+M]);
    return(MV);
}
//19
MaquinaVirtual WRITE(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
    printf("Conteudo da Memoria: %d\n",MV.RAM_[MV.PC_+M]);
    return(MV);
}
//20
MaquinaVirtual CALL(MaquinaVirtual MV){
    MV.PC_=MV.PC_+1;
    int M=MV.RAM_[MV.PC_];
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

