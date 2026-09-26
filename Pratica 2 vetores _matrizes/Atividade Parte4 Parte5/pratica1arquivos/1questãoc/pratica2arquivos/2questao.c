#include <stdio.h>
# include <stdlib.h>
int main(void) {

    FILE *arquivo;
    char c;

      int caracteres = 0;
       int palavras = 0;
       int linhas = 0;
       int letrasA = 0;

       int dentroPalavra = 0;

     
    arquivo = fopen("texto.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    
    while (!feof(arquivo)) {

        c = fgetc(arquivo);

        if (c != EOF) {

            
            caracteres++;

               
            if (c == '\n') {
                linhas++;
            }

               
            if (c == 'a' || c == 'A') {
                letrasA++;
            }

                
            if (c != ' ' && c != '\n' && c != '\t') {

                if (dentroPalavra == 0) {
                    palavras++;
                    dentroPalavra = 1;
                }

            } else {
                dentroPalavra = 0;
            }
        }
    }

        
    
    if (caracteres > 0) {
        linhas++;
    }

    
    fclose(arquivo);

    printf("\nQuantidade de caracteres: %d\n", caracteres);
    printf("Quantidade de palavras: %d\n", palavras);
    printf("Quantidade de linhas: %d\n", linhas);
    printf("Quantidade de letras A: %d\n", letrasA);

    return 0;
}