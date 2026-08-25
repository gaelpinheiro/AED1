# include<stdio.h>
# include<stdlib.h>
int i, main(void){
    int tamanho =10;
    int* vetor =(int*)malloc(tamaho*sizeof(int));
    if(vetor==NULL){
        printf(" erro na alocaçao");
        exit(1)
    }
else{
    printf(" vetor alocado!\n")
}
for(1=0;i<tamaho;i++){
    vertor[i]=i;
    printf("%d\t",vetor[i]);
}
return 0;
