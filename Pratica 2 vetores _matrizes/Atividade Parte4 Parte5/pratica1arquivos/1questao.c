# include<stdio.h>
# include<stdlib.h>
int main(void){
    int id;
   char nome[50];
   float salario;
   printf(" digite o nome:");
   sacnf("%[^\n]s",nome);
   printf(" digite o id:");
   printf(" digite o id:");
   scanf("%d",&id);
   printf(" digite o salario:");
   scanf("%f",&salario);
   FILE *arq=fopen(" entrada.txt","w");
   if(arq==NULL) (exit(1));
   fprintf(arq ," %d %s %f,",id,nome,salario);
   fclose(arq);
   return 0;
   }
