#include<stdio.h>
#include<stdlib.h>
int main(void){
    int numero;
    printf(" digite o tamnho do veto:r");
    scanf("%d",&nuumero);
    int*vetor= malloc(numero*sizeof(int));
    if(vetor==NULL){
        printf(" erro na alocaçao de memoria.\n");
        return 1;
    }
    for(int i=0;i<numero,i++){
        printf(" digite o elemento %d:",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("\n vetor na ordem inversa:\n");
    for(int i= numero-1;i>=0;i--){
        printf("%d",vetor[i]);

    }
    printf("\n");
    free(vetor);
    return 0;
}
