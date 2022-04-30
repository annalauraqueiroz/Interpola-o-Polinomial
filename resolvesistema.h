#include <stdio.h>
#include <math.h>
//linhas
//#define x 3
//colunas
//#define y 3

void recebematrizvetor(int x, int y, float a[x][y],float b[x]){
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("digite o coef %d equacao n° %d\n",j+1, i+1);
            scanf("%f", &a[i][j]);
            if(j==(x-1)){
                printf("digite o valor de b%d",i+1);
                scanf("%f", &b[i]);
            }
        }
    }

}

void imprime(int n, float a[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%.0f ", a[i][j]);
        printf("\n");
    }
}

void imprimevetor(int n,double b[]){
    int i;
    printf("\n");
    for(i=0; i<n; i++){
       printf("\na%d: %.3lf\n", i,b[i]);

    }
}

void imprimebonitin(int n, double b[]){
	int i;
	double x=3, y;


    for(i=0; i<n; i++){
       printf("\na%d: %.1lf\n", i,b[i]);

    }
    while(x!=0){
    printf("\nDigite o x que vc quer aproximar: ");
    scanf("%lf", &x);

	y = b[0] + b[1]*x + b[2]*x*x + b[3]*x*x*x + b[4]*x*x*x*x;

	printf("\ny(%.3lf) = %.3lf", x, y);
	}

}

void removelc(int l, int c, int n, double math_in[n][n], double math_out[n-1][n-1]){
    int i,j,p=0,k=0;
   //quando j aumentar e for permitido entao p aumenta
   //k vai mudar quando i mudar e for permitido

   for(i=0;i<n;i++){
        if(i==l)
            continue;
        for(j=0;j<n;j++){
            if(j==c)
                continue;
            math_out[k][p] = math_in[i][j];
            p++;
        }
    p=0;
    k++;
   }
}

double determinante(int n, double a[n][n]){
    double det, s[n-1][n-1];
    det=0.0;
    int i=1,j;

    if(n==1){
        det= a[0][0];
    }else{
        for(j=0;j<n;j++){
            removelc(i,j,n,a,s);
            det+= pow(-1,(i+j))*a[i][j]*determinante(n-1,s);
        }
    }
return det;
}

void Dn(int c, int n2, double m2[n2][n2], double v2[n2] ){
    int i;

    for(i=0;i<n2;i++){
        m2[i][c] = v2[i];
    }

}
//passa elementos de uma matriz pra outra
void troca(int n, double moriginal[n][n], double m2[n][n]){

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            m2[i][j] = moriginal[i][j];
    }

}
void Cramer(int n, double mcoef[n][n], double vetorb[n], double vetorx[n]){
    double z[n], mtroca[n][n],dete;
    int i;

    if(determinante(n,mcoef)==0){
        printf("SISTEMA SEM SOLUCAO");
    }else{


        for(i=0;i<n;i++){
            troca(n,mcoef,mtroca);
            Dn(i,n,mtroca,vetorb);
            vetorx[i]= determinante(n,mtroca)/determinante(n,mcoef);
        }

}}


/*int main(){
    float a[x][x], b[y], d[y];

    recebematrizvetor(a,b);

    Cramer(x,a,b,d);
    imprimevetor(y,d);

    return 0;
}*/
