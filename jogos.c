#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "jogos.h"


//  ---------------------------------------------------------- so o ranking
void entry(int score){
    char l[3];

    printf("\nAgora informe Seu NickName(ate 3 letras): ");
    scanf("%s", l);
    intro(l, score);
}

void intro(char* nome, int score){
    int i, j, k, num;
    char linha[100];
    char *space_nome, *space_pontos;
    N *lista;
    N aux;
    FILE* arquivo = NULL;

    lista = (N*)malloc(100*sizeof(N));

    arquivo = fopen("rank.txt", "r");

    if (arquivo == NULL){
        arquivo = fopen("rank.txt", "w");
        fclose(arquivo);
        intro(nome, score);
        return;
    }

    i = 0;
    while(fgets(linha, 100, arquivo)!= 0){
        space_pontos = strtok(linha,",");
        space_nome = strtok(NULL,",");
        for(k = 0; k < strlen(space_nome); k++){
            if(space_nome[k] == '\n'){
                 space_nome[k] = '\0';
                 break;
            }
        }
        lista[i].pontos = atoi(space_pontos);
        strcpy(lista[i].nome,space_nome);
        i++;
    }
    fclose(arquivo);

    for(k = 0; k < i; k++){
        if(strcmp(nome,lista[k].nome) == 0){
            lista[k].pontos = lista[k].pontos + score;
            break;
        }
        if(k == i - 1){
            lista[i].pontos = score;
            strcpy(lista[i].nome,nome);
            i++;
            break;
        }
    }

    // organiza vetor
    for(k = 0; k < i; k++){
        for(j = k; j < i; j++){
            if(lista[k].pontos < lista[j].pontos){
                aux.pontos = lista[k].pontos;
                strcpy(aux.nome, lista[k].nome);

                lista[k].pontos = lista[j].pontos;
                strcpy(lista[k].nome, lista[j].nome);

                lista[j].pontos = aux.pontos;
                strcpy(lista[j].nome,aux.nome);
            }
        }
    }

    arquivo = fopen("rank.txt", "w");

    if (arquivo == NULL){
        printf("lul");
        return;
    }
    fprintf(arquivo, "%d,%s\n", lista[0].pontos, lista[0].nome);
    for(j = 1; j < i; j++){
        fprintf(arquivo, "%d,%s\n", lista[j].pontos, lista[j].nome);

    }
    fclose(arquivo);
    printf("\n->Confirmação que ocorreu todo certo\n");
    free(lista);
}

void print_arquivo(){
    char linha[100], *token, *token2;
    int i, j;
    FILE *arquivo;
    limp(0);

    printf("\n");

    arquivo = fopen("rank.txt", "r");

    if (!(arquivo == NULL)){
        for(i = 1;fgets(linha, sizeof(linha), arquivo); i++){
            token = strtok(linha, ",");
            token2 = strtok(NULL, ",");

            for(j = 0; j < strlen(token2); j++){
                if(token2[j] == '\n'){
                    token2[j] = '\0';
                }
            }

            printf("%3dº | %s = %s\n", i, token2, token);

             if(i == 10){
                break;
            }
        }
        fclose(arquivo);
    }
    limp(1);
    printf("\nClique em Enter para Retornar ao menu!!");
    getchar();
    printf("Retornando...");
    sleep(1);
}

void Creditos(){
    printf("\n\tCreditos\n\n");
    printf("Projeto de Técnicas de Desenvolvimento de Algoritmos\n");
    printf("Do Curso de Ciencias da Computação - UNIPE\n");
    printf("Feito Por Sidney Roberto");
    printf("\nClique em Enter para Retornar ao menu!!");
    getchar();
    printf("Retornando...");
    sleep(1);
}

void jogar(){
    int esc;

    limp(0);
    printf("\nQual Modo de Jogo?\n1 - Singleplayer\n2 - Multplayer\n\n->Escolha: ");
    scanf("%d", &esc);

    if(esc == 1){
        tipo_jogo(1);

    } else if (esc == 2){
        tipo_jogo(2);

    }
}

void tipo_jogo(int tipo){
    int esc;

    limp(0);

    printf("Deseja jogar:\n1 - velha 3x3\n2 - velha 5x5\n3 - velha 7x7\n\n->Escolha: ");
    scanf("%d", &esc);

    if(tipo == 1){
        if(esc == 1){
            velha_c(3);

        } else if (esc == 2){
            velha_c(5);

        } else if(esc == 3){
            velha_c(7);

        }
    } else if (tipo == 2){
        if(esc == 1){
            velha_p(3);

        } else if (esc == 2){
            velha_p(5);

        } else if(esc == 3){
            velha_p(7);

        }
    }
}

void saida(){
    int esc;

    limp(1);
    printf("\n\nOque deseja?\n1 - sair\n2 - retornar ao menu!\n\n->Escolha: ");
    scanf("%d", &esc);
    if(esc == 1){
        exit(1);
    }else if (esc == 2){
        printf("\n");
    } else {
        printf("Opção invalida, tente novamente...");
        sleep(1);
        saida();
    }
}

void tuto(){
    int esc, i, j, k;

    limp(0);
    printf("\nQual modo de jogo?\n1 - 3x3\n2 - 5x5\n3 - 7x7\n4 - Rank\n\n->Escolha: ");
    scanf("%d", &esc);
    limp(0);

    if(esc == 1){
        k = 10 - 3;
        printf("\n");
        for(i = 0; i < 3; i++){
            printf("\n");
            for(j = 0; j < 3; j++){
                printf("%3d ", k + j);
            }
            k = k - 3;
        }
        printf("\n\nDentro do jogo sera nescessario informar um numero\nutilize um dos numeros mostrados para definir a posição de cada jogada...");
        printf("\nClique em Enter para Retornar ao menu!!");
        getchar();
        printf("Retornando...");
        sleep(1);

    }else if (esc == 2){
        k = 26 - 5;
        printf("\n");
        for(i = 0; i < 5; i++){
            printf("\n");
            for(j = 0; j < 5; j++){
                printf("%3d ", k + j);
            }
            k = k - 5;
        }
        printf("\n\nDentro do jogo sera nescessario informar um numero\nutilize um dos numeros mostrados para definir a posição de cada jogada...");
        printf("\nClique em Enter para Retornar ao menu!!");
        getchar();
        printf("Retornando...");
        sleep(1);

    }else if (esc == 3){
        k = 50 - 7;
        printf("\n");
        for(i = 0; i < 7; i++){
            printf("\n");
            for(j = 0; j < 7; j++){
                printf("%3d ", k + j);
            }
            k = k - 7;
        }
        printf("\n\nDentro do jogo sera nescessario informar um numero\nutilize um dos numeros mostrados para definir a posição de cada jogada...");
        printf("\nClique em Enter para Retornar ao menu!!");
        getchar();
        printf("Retornando...");
        sleep(1);
    } else if (esc == 4) {
        printf("\nAs Posições irão aparecer apos a primeira jogada\nAntes disso não havera nada, A pontuação é dada\nPor cada vitoria de cada usuario...\nRecebendo pontos em qualquer modo de jogo\nRelacionando seu nome a uma pontuação.\n");
        printf("\nClique em Enter para Retornar ao menu!!");
        getchar();
        printf("Retornando...");
        sleep(1);
    }
}

void velha_p(int tam){
    int i, j, k, l;
    int player = 1, esc = 0, timer = 0, vitoria = 0;
    int *campo;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    if(tam == 3 || tam == 5 || tam == 7){
        campo = criar_campo(tam);

        tela(campo, tam);
        limp(0);

        while(1){
            printf("\n");
            jogo(campo, tam);
            k = 0;
            l = 0;
            esc = 0;

            if(player == 1){
                limp(1);
                printf("\nJogador X escolha onde vai jogar: ");
                scanf("%d", &esc);
                k = mudar_X(campo, esc, tam);
                if(k == 2){
                    limp(1);
                    printf("\nLugar preenchido!! ou Posição invalida!!\nTente Novamente...");
                    getchar();

                } else{
                    timer++;
                    player = 0;
                }
            } else if (player == 0){
                limp(1);
                printf("\nJogador O escolha onde vai jogar: ");
                scanf("%d", &esc);
                l = mudar_O(campo, esc , tam);
                if(l == 2){
                    limp(1);
                    printf("\nLugar preenchido!! ou Posição invalida!!\nTente Novamente...");
                    getchar();

                }else{
                    timer++;
                    player = 1;
                }
            }
            limp(0);
            if (tam == 3){
                vitoria = verif3(campo);

            } else if (tam == 5){
                vitoria = verif5(campo);

            } else if (tam == 7){
                vitoria = verif7(campo);

            }
            if(vitoria == 10){
                printf("\nPARABENS , O GANHADOR É O JOGADOR NUMERO 1, X!!");

            } else if(vitoria == 20){
                printf("\nPARABENS , O GANHADOR É O JOGADOR NUMERO 2, O!!");

            } else if(timer > 0){
                if(tam == 3 && timer == 9){
                    printf("\nDEU VELHA, EMPATE , NÃO HOUVE GANHADORES!!");
                    saida();
                    break;

                } else if (tam == 5 && timer == 25){
                    printf("\nDEU VELHA, EMPATE , NÃO HOUVE GANHADORES!!");
                    saida();
                    break;

                } else if (tam == 7 && timer == 49){
                    printf("\nDEU VELHA, EMPATE , NÃO HOUVE GANHADORES!!");
                    saida();
                    break;

                }
            }
            if( vitoria > 0){
                if (tam == 3){
                    entry(1);
                    saida();
                    break;

                } else if (tam == 5){
                    entry(2);
                    saida();
                    break;

                } else if (tam == 7){
                    entry(3);
                    saida();
                    break;

                }
            }
        }
    } else {
        printf("Tamanho informado Invalido");
    }
}

void velha_c(int tam){
    int i, j, k, l;
    int player = 1, esc = 0, timer = 0, vitoria = 0;
    int *campo;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    if(tam == 3 || tam == 5 || tam == 7){
        campo = criar_campo(tam);

        tela(campo, tam);
        limp(0);

        while(1){
            printf("\n");
            jogo(campo, tam);
            k = 0;
            l = 0;
            esc = 0;

            if(player == 1){
                limp(1);
                printf("\nJogador X escolha onde vai jogar: ");
                scanf("%d", &esc);
                k = mudar_X(campo, esc, tam);
                if(k == 2){
                    limp(1);
                    printf("\nLugar preenchido!! ou Posição invalida!!\nTente Novamente...");
                    getchar();

                } else{
                    timer++;
                    player = 0;
                }
            } else if (player == 0){
                limp(1);
                if(tam == 3){
                    esc = 1 + (rand() % 9);

                } else if ( tam == 5){
                    esc = 1 + (rand() % 25);

                } else if (tam == 7){
                    esc = 1 + (rand() % 49);;

                }
                l = mudar_O(campo, esc, tam);
                if(l == 2){
                    limp(1);

                }else{
                    sleep(1);
                    timer++;
                    player = 1;
                }
            }
            limp(0);
            if (tam == 3){
                vitoria = verif3(campo);

            } else if (tam == 5){
                vitoria = verif5(campo);

            } else if (tam == 7){
                vitoria = verif7(campo);

            }

            if(vitoria == 10){
                printf("\nPARABENS , O GANHADOR É O JOGADOR NUMERO 1, X!!");

             } else if(vitoria == 20){
                printf("\nQUE PENA O COMPUTADOR GANHOU!!");
                saida();
                break;

             } else if(timer > 0){
                if(tam == 3 && timer == 9){
                    printf("\nDEU VELHA, EMPATE , NÃO HOUVE GANHADORES!!");
                    saida();
                    break;

                } else if (tam == 5 && timer == 25){
                    printf("\nDEU VELHA, EMPATE , NÃO HOUVE GANHADORES!!");
                    saida();
                    break;

                } else if (tam == 7 && timer == 49){
                    printf("\nDEU VELHA, EMPATE , NÃO HOUVE GANHADORES!!");
                    saida();
                    break;

                }
            }
            if( vitoria == 10){
                if (tam == 3){
                    entry(1);
                    saida();
                    break;

                } else if (tam == 5){
                    entry(2);
                    saida();
                    break;

                } else if (tam == 7){
                    entry(3);
                    saida();
                    break;

                }
            }
        }
    } else {
        printf("Tamanho informado Invalido");
    }
}
