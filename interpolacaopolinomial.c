//e vamos de interpolação POLINOMIAL COMPLETASSO E SAI A FUNÇÃO
//av8 rc3
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "resolvesistema.h"


void interpolacaoPolinomial(double xi[], double yi[], int t){
double matriz[t][t], resposta[t];
int i, j;

for(i = 0; i<t;i++){
    for(j=0; j<t;j++){
        if(j==0)
            matriz[i][j] = 1;
        else if(j == 1)
            matriz[i][j] = xi[i];
        else
            matriz[i][j] = pow(xi[i], j);
    }
}

Cramer(t,matriz,yi,resposta);
imprimebonitin(t, resposta);

}

int contador(FILE *arquivo){
char c;
int cont=0;
    if(arquivo !=NULL){
        while(!feof(arquivo)){
            fscanf(arquivo,"%c", &c);
               if(c == '\n')
                    cont++;
        }
        cont++;
        fclose(arquivo);
        return cont;
}else{
    	printf("Arquivo não encontrado ou vazio.");
    	fclose(arquivo);
    	return 0;
	}
}

int main(){
FILE *arq;
double *x, *y;
int i, p;

arq= fopen("dados.txt", "r");

p = contador(arq);


if(p){
        arq= fopen("dados.txt", "r");

        x = (double*) malloc(p*sizeof(double));
        y = (double*) malloc(p*sizeof(double));

        for(i=0;i<p;i++)
            fscanf(arq,"%lf\t%lf", &x[i], &y[i]);

        fclose(arq);

        interpolacaoPolinomial(x,y,p);

        free(x);
        free(y);
}



return 0;
}
