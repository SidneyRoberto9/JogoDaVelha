#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "jogos.c"
#include "biblioteca.c"

int main(){
    int esc;
    setlocale(LC_ALL, "");

    while(1){
        limp(0);
        printf("\n\tMENU\n\n");
        printf("1 - JOGAR \n2 - RANKINGS \n3 - TUTORIAL \n4 - CREDITOS \n5 - SAIR\n");
        printf("\n->Escolha: ");
        scanf("%d", &esc);
        limp(0);

        if (esc == 1){
            jogar();

        } else if (esc == 2){
            print_arquivo();

        } else if (esc == 3){
            tuto();

        } else if (esc == 4){
            Creditos();

        } else if (esc == 5){
            printf("Obrigado por jogar!!");
            break;

        } else {
            printf("\nOpção invalida...\nCLique enter para tentar novamente...");
            getchar();
        }

    }
    return 0;
}
