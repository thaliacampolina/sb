#include <stdlib.h>
#include <stdio.h>
#include "maquinavirtual.h"


void executaOperacoes(MaquinaVirtual MV, int verbose){
    
    MV.PC_--;
    int instrucao;
	
    while(1) {
        MV.PC_++;
	instrucao=MV.RAM_[MV.PC_];

    //INTRUCTION LOAD
    if(instrucao==1){
        MV=LOAD(MV);
        if(verbose==1){
            printf("Executando o LOAD \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION STORE
    if(instrucao==2){
        MV=STORE(MV);
        if(verbose==1){
            printf("Executando o STORE \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION PUSH
    if(instrucao==3){
        MV=PUSH(MV);
        if(verbose==1){
            printf("Executando o PUSH \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION POP
    if(instrucao==4){
        MV=POP(MV);
        if(verbose==1){
            printf("Executando o POP \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JMP
    if(instrucao==5){
        MV=JMP(MV);
        if(verbose==1){
            printf("Executando o JMP \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JPG
    if(instrucao==6){
        MV=JPG(MV);
        if(verbose==1){
            printf("Executando o JPG \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JPGE
    if(instrucao==7){
        MV=JPGE(MV);
        if(verbose==1){
            printf("Executando o JPGE \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JPL
    if(instrucao==8){
        MV=JPL(MV);
        if(verbose==1){
            printf("Executando o JPL \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JPLE
    if(instrucao==9){
        MV=JPLE(MV);
        if(verbose==1){
            printf("Executando o JPLE \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JPE
    if(instrucao==10){
        MV=JPE(MV);
        if(verbose==1){
            printf("Executando o JPE \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION JPNE
    if(instrucao==11){
        MV=JPNE(MV);
        if(verbose==1){
            printf("Executando o JPNE \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }



    //INTRUCTION XOR
    if(instrucao==12){
        MV=XOR(MV);
        if(verbose==1){
            printf("Executando o XOR \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION AND
    if(instrucao==13){
        MV=AND(MV);
        if(verbose==1){
            printf("Executando o AND \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }



    //INTRUCTION OR
    if(instrucao==14){
        MV=OR(MV);
        if(verbose==1){
            printf("Executando o OR \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION NOT
    if(instrucao==15){
        MV=NOT(MV);
        if(verbose==1){
            printf("Executando o NOT \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION ADD
    if(instrucao==16){
        MV=ADD(MV);
        if(verbose==1){
            printf("Executando o ADD \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }



    //INTRUCTION SUB
    if(instrucao==17){
        MV=SUB(MV);
        if(verbose==1){
            printf("Executando o SUB \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION READ
    if(instrucao==18){
        MV=READ(MV);
        if(verbose==1){
            printf("Executando o READ \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }


    //INTRUCTION WRITE
    if(instrucao==19){
        MV=WRITE(MV);
        if(verbose==1){
            printf("Executando o WRITE \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION CALL
    if(instrucao==20){
        MV=CALL(MV);
        if(verbose==1){
            printf("Executando o CALL \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION RET
    if(instrucao==21){
        MV=RET(MV);
        if(verbose==1){
            printf("Executando o RET \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    //INTRUCTION HALT
    if(instrucao==22){
        MV=HALT(MV);
        if(verbose==1){
            printf("Executando o HALT \n ");
            printf("PC_=%d, SP_=%d, AC_=%d\n",MV.PC_,MV.SP_,MV.AC_);
            printf("\n ");
        }
    }

    }
}

int main (int argc, char* argv[]) {
    FILE* input;
    input = fopen(argv[5], "r");
    int verbose;
    MaquinaVirtual MV;
    if(strcmp(argv[4],"v")==0){
        verbose=1;
    }
    if(strcmp(argv[4],"s")==0){
        verbose=0;
    }
    if (input == NULL){
        puts("O ARQUIVO NAO FOI ABERTO");
        return 0;
    } else {

//inicializa maquina virtual, memoria default=0, AC=0.
        MV.PC_=atoi(argv[1]);
        MV.SP_=atoi(argv[2]);
        MV.AC_=0;
        int i;
        for(i=0;i<1000;i++){
            MV.RAM_[i]=0;
        }

//salvar a instrucao na memoria
        int instruc;
        i=atoi(argv[3]);
        while(fscanf(input,"%d",&instruc) >0) {
            MV.RAM_[i]=instruc;
            i++;
        }

    
	executaOperacoes(MV,verbose);
	
    }

    return 0;
}

