# include<stdio.h>
# include"calculadora.h"
int main(void){
    int v1,v2;
    printf(" digite dois valores inteiros:");
    scanf("%d %d",&v1,&v2);
    printf(" soma: %d\n",soma(v1,v2));
    return 0;
}