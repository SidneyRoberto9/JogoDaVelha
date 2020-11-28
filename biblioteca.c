#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void limp(int n){
    if(n == 0){
        system("cls");
        setbuf(stdin, NULL);
    } else if (n == 1){
        setbuf(stdin, NULL);
    }
}

int *criar_campo(int m){
    int *p, *q, i;

    p = (int *) malloc (m * m * sizeof(int *));

    q = p;
    for(i = 0; i < (m*m); i++, q++){
        *q = 3;
    }

    return p;
}

void tela(int *v, int m){
	int i, j;

	for(i = 0; i< m; i++){
        for(j = 0; j< m; j++){
            printf("  %d ",*(v + (i* m) + j));
        }
        printf("\n");
    }
}

void jogo(int *v, int m){
    int i,j, num;

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            num = *(v + (i * m) + j);
            if (num == 3){
                printf("  +");
            } else if (num  == 1){
                printf("  X");
            } else if (num  == 0){
                printf("  O");
            }
        }
        printf("\n");
    }
}

int mudar_X(int *v, int num, int tam){
    int i, j, k = 0, campo = 0, numb = 0;

    if(tam == 3){
        campo = 10;
        numb = 3;
        j = 2;
        if( num > 9 || num < 1){
            return 2;
        }

    } else if (tam == 5){
        campo = 26;
        numb = 5;
        j = 4;
        if( num > 25 || num < 1){
            return 2;
        }

    } else if (tam == 7){
        campo = 50;
        numb = 7;
        j = 6;
        if( num > 49 || num < 1){
            return 2;
        }
    }

    for(i = 1;i < campo; i++){
        if(i == num){
            if( *(v + (j * numb) + k) == 0){
                return 2;

            } else if(*(v + (j * numb) + k) == 1){
                return 2;

            } else{
                *(v + (j * numb) + k) = 1;
            }
        }
        k++;
        if(k == numb){
            k = 0;
            j--;
        }
    }
}

int mudar_O(int *v, int num, int tam){
    int i, j ,k = 0 , campo = 0, numb = 0;;

     if(tam == 3){
        campo = 10;
        numb = 3;
        j = 2;
        if( num > 9 || num < 1){
            return 2;
        }

    } else if (tam == 5){
        campo = 26;
        numb = 5;
        j = 4;
        if( num > 25 || num < 1){
            return 2;
        }

    } else if (tam == 7){
        campo = 50;
        numb = 7;
        j = 6;
        if( num > 49 || num < 1){
            return 2;
        }
    }

    for(i = 1;i < campo; i++){
        if(i == num){
            if( *(v + (j * numb) + k) == 1){
                return 2;

            } else if(*(v + (j * numb) + k) == 0){
                return 2;

            } else{
                *(v + (j * numb) + k) = 0;
            }
        }
        k++;
        if(k == numb){
            k = 0;
            j--;
        }
    }
}

int verif3(int *v){
    int i , tam = 3;

    for(i = 0;i < tam; i++){
        if( *(v + (i * tam) + 0) == 1 && *(v + (i * tam) + 1) == 1 && *(v + (i * tam) + 2) == 1){
            return 10;

        } else if ( *(v + (i * tam) + 0) == 0 && *(v + (i * tam) + 1) == 0 && *(v + (i * tam) + 2) == 0){
            return 20;

        } else if( *(v + (0 * tam) + i) == 1 && *(v + (1 * tam) + i) == 1 && *(v + (2 * tam) + i) == 1){
            return 10;

        } else if ( *(v + (0 * tam) + i) == 0 && *(v + (1 * tam) + i) == 0 && *(v + (2 * tam) + i) == 0){
            return 20;

        } else if( *(v + (0 * tam) + 0) == 1 && *(v + (1 * tam) + 1 ) == 1 && *(v + (2 * tam) + 2) == 1){
            return 10;

        } else if ( *(v + (0 * tam) + 0) == 0 && *(v + (1  * tam) + 1 ) == 0 && *(v + (2 * tam) + 2) == 0){
            return 20;

        }  else if( *(v + (0 * tam) + 2) == 1 && *(v + (1 * tam) + 1 ) == 1 && *(v + (2 * tam) + 0) == 1){
            return 10;

        } else if ( *(v + (0 * tam) + 2) == 0 && *(v + (1 * tam) + 0 ) == 1 && *(v + (2 * tam) + 0) == 0){
            return 20;

        }
    }
    return 0;
}

int verif5(int *v){
    int i, tam = 5;

    for(i = 0; i < tam; i++){
        if( *(v + (i * tam) + 0) == 1 && *(v + (i * tam) + 1) == 1 && *(v + (i * tam) + 2) == 1  && *(v + (i * tam) + 3) == 1){
            return 10;

        } else if (*(v + (i * tam) + 1) == 1 && *(v + (i * tam) + 2) == 1 && *(v + (i * tam) + 3) == 1  && *(v + (i * tam) + 4) == 1){
            return 10;

        } else if( *(v + (i * tam) + 0) == 0 && *(v + (i * tam) + 1) == 0 && *(v + (i * tam) + 2) == 0  && *(v + (i * tam) + 3) == 0){
            return 20;

        } else if (*(v + (i * tam) + 1) == 0 && *(v + (i * tam) + 2) == 0 && *(v + (i * tam) + 3) == 0  && *(v + (i * tam) + 4) == 0){
            return 20;

        } else if( *(v + (0 * tam) + i) == 1 && *(v + (1 * tam) + i) == 1 && *(v + (2 * tam) + i) == 1  && *(v + (3 * tam) + i) == 1){
            return 10;

        } else if (*(v + (1 * tam) + i) == 1 && *(v + (2 * tam) + i) == 1 && *(v + (3 * tam) + i) == 1  && *(v + (4 * tam) + i) == 1){
            return 10;

        } else if( *(v + (0 * tam) + i) == 0 && *(v + (1 * tam) + i) == 0 && *(v + (2 * tam) + i) == 0  && *(v + (3 * tam) + i) == 0){
            return 20;

        } else if (*(v + (1 * tam) + i) == 0 && *(v + (2 * tam) + i) == 0 && *(v + (3 * tam) + i) == 0  && *(v + (4 * tam) + i) == 0){
            return 20;

        } else if (*(v + (0 * tam) + 0) == 1 && *(v + (1 * tam) + 1) == 1 && *(v + (2 * tam) + 2) == 1  && *(v + (3 * tam) + 3) == 1){
            return 10;

        } else if (*(v + (1 * tam) + 1) == 1 && *(v + (2 * tam) + 2) == 1 && *(v + (3 * tam) + 3) == 1  && *(v + (4 * tam) + 4) == 1){
            return 10;

        } else if (*(v + (0 * tam) + 0) == 0 && *(v + (1 * tam) + 1) == 0 && *(v + (2 * tam) + 2) == 0  && *(v + (3 * tam) + 3) == 0){
            return 20;

        } else if (*(v + (1 * tam) + 1) == 0 && *(v + (2 * tam) + 2) == 0 && *(v + (3 * tam) + 3) == 0  && *(v + (4 * tam) + 4) == 0){
            return 20;

        } else if (*(v + (0 * tam) + 1) == 1 && *(v + (1 * tam) + 2) == 1 && *(v + (2 * tam) + 3) == 1  && *(v + (3 * tam) + 4) == 1){
            return 10;

        } else if (*(v + (1 * tam) + 0) == 1 && *(v + (2 * tam) + 1) == 1 && *(v + (3 * tam) + 2) == 1  && *(v + (4 * tam) + 3) == 1){
            return 10;

        } else if (*(v + (0 * tam) + 1) == 0 && *(v + (1 * tam) + 2) == 0 && *(v + (2 * tam) + 3) == 0  && *(v + (3 * tam) + 4) == 0){
            return 20;

        } else if (*(v + (1 * tam) + 0) == 0 && *(v + (2 * tam) + 1) == 0 && *(v + (3 * tam) + 2) == 0  && *(v + (4 * tam) + 3) == 0){
            return 20;

        } else if (*(v + (0 * tam) + 4) == 1 && *(v + (1 * tam) + 3) == 1 && *(v + (2 * tam) + 2) == 1  && *(v + (3 * tam) + 1) == 1){
            return 10;

        } else if (*(v + (1 * tam) + 3) == 1 && *(v + (2 * tam) + 2) == 1 && *(v + (3 * tam) + 1) == 1  && *(v + (4 * tam) + 0) == 1){
            return 10;

        } else if (*(v + (0 * tam) + 4) == 0 && *(v + (1 * tam) + 3) == 0 && *(v + (2 * tam) + 2) == 0  && *(v + (3 * tam) + 1) == 0){
            return 20;

        } else if (*(v + (1 * tam) + 3) == 0 && *(v + (2 * tam) + 2) == 0 && *(v + (3 * tam) + 1) == 0  && *(v + (4 * tam) + 0) == 0){
            return 20;

        } else if (*(v + (0 * tam) + 3) == 1 && *(v + (1 * tam) + 2) == 1 && *(v + (2 * tam) + 1) == 1  && *(v + (3 * tam) + 0) == 1){
            return 10;

        } else if (*(v + (1 * tam) + 4) == 1 && *(v + (2 * tam) + 3) == 1 && *(v + (3 * tam) + 2) == 1  && *(v + (4 * tam) + 1) == 1){
            return 10;

        }  else if (*(v + (0 * tam) + 3) == 0 && *(v + (1 * tam) + 2) == 0 && *(v + (2 * tam) + 1) == 0  && *(v + (3 * tam) + 0) == 0){
            return 20;

        } else if (*(v + (1 * tam) + 4) == 0 && *(v + (2 * tam) + 3) == 0 && *(v + (3 * tam) + 2) == 0  && *(v + (4 * tam) + 1) == 0){
            return 20;
        }
    }
}

int verif7(int *v){
    int i, tam = 7;

    for(i = 0; i < tam; i++){
        if( *(v + (i * tam) + 0) == 1 && *(v + (i * tam) + 1) == 1 && *(v + (i * tam) + 2) == 1 && *(v + (i * tam) + 3) == 1){
            return 10;

        } else if( *(v + (i * tam) + 1) == 1 && *(v + (i * tam) + 2) == 1 && *(v + (i * tam) + 3) == 1 && *(v + (i * tam) + 4) == 1){
            return 10;

        } else if( *(v + (i * tam) + 2) == 1 && *(v + (i * tam) + 3) == 1 && *(v + (i * tam) + 4) == 1 && *(v + (i * tam) + 5) == 1){
            return 10;

        } else if( *(v + (i * tam) + 3) == 1 && *(v + (i * tam) + 4) == 1 && *(v + (i * tam) + 5) == 1 && *(v + (i * tam) + 6) == 1){
            return 10;

        } else if( *(v + (i * tam) + 0) == 0 && *(v + (i * tam) + 1) == 0 && *(v + (i * tam) + 2) == 0 && *(v + (i * tam) + 3) == 0){
            return 20;

        } else if( *(v + (i * tam) + 1) == 0 && *(v + (i * tam) + 2) == 0 && *(v + (i * tam) + 3) == 0 && *(v + (i * tam) + 4) == 0){
            return 20;

        } else if( *(v + (i * tam) + 2) == 0 && *(v + (i * tam) + 3) == 0 && *(v + (i * tam) + 4) == 0 && *(v + (i * tam) + 5) == 0){
            return 20;

        } else if( *(v + (i * tam) + 3) == 0 && *(v + (i * tam) + 4) == 0 && *(v + (i * tam) + 5) == 0 && *(v + (i * tam) + 6) == 0){
            return 20;

        } else if( *(v + (0 * tam) + i) == 1 && *(v + (1 * tam) + i) == 1 && *(v + (2 * tam) + i) == 1 && *(v + (3 * tam) + i) == 1){
            return 10;

        } else if( *(v + (1 * tam) + i) == 1 && *(v + (2 * tam) + i) == 1 && *(v + (3 * tam) + i) == 1 && *(v + (4 * tam) + i) == 1){
            return 10;

        } else if( *(v + (2 * tam) + i) == 1 && *(v + (3 * tam) + i) == 1 && *(v + (4 * tam) + i) == 1 && *(v + (5 * tam) + i) == 1){
            return 10;

        } else if( *(v + (3 * tam) + i) == 1 && *(v + (4 * tam) + i) == 1 && *(v + (5 * tam) + i) == 1 && *(v + (6 * tam) + i) == 1){
            return 10;

        } else if( *(v + (0 * tam) + i) == 0 && *(v + (1 * tam) + i) == 0 && *(v + (2 * tam) + i) == 0 && *(v + (3 * tam) + i) == 0){
            return 20;

        } else if( *(v + (1 * tam) + i) == 0 && *(v + (2 * tam) + i) == 0 && *(v + (3 * tam) + i) == 0 && *(v + (4 * tam) + i) == 0){
            return 20;

        } else if( *(v + (2 * tam) + i) == 0 && *(v + (3 * tam) + i) == 0 && *(v + (4 * tam) + i) == 0 && *(v + (5 * tam) + i) == 0){
            return 20;

        } else if( *(v + (3 * tam) + i) == 0 && *(v + (4 * tam) + i) == 0 && *(v + (5 * tam) + i) == 0 && *(v + (6 * tam) + i) == 0){
            return 20;

        } else if( *(v + (0 * tam) + 0) == 1 && *(v + (1 * tam) + 1) == 1 && *(v + (2 * tam) + 2) == 1 && *(v + (3 * tam) + 3) == 1){
            return 10;

        } else if( *(v + (1 * tam) + 1) == 1 && *(v + (2 * tam) + 2) == 1 && *(v + (3 * tam) + 3) == 1 && *(v + (4 * tam) + 4) == 1){
            return 10;

        } else if( *(v + (2 * tam) + 2) == 1 && *(v + (3 * tam) + 3) == 1 && *(v + (4 * tam) + 4) == 1 && *(v + (5 * tam) + 5) == 1){
            return 10;

        } else if( *(v + (3 * tam) + 3) == 1 && *(v + (4 * tam) + i) == 1 && *(v + (5 * tam) + 5) == 1 && *(v + (6 * tam) + 6) == 1){
            return 10;

        } else if( *(v + (0 * tam) + 0) == 0 && *(v + (1 * tam) + 1) == 0 && *(v + (2 * tam) + 2) == 0 && *(v + (3 * tam) + 3) == 0){
            return 20;

        } else if( *(v + (1 * tam) + 1) == 0 && *(v + (2 * tam) + 2) == 0 && *(v + (3 * tam) + 3) == 0 && *(v + (4 * tam) + 4) == 0){
            return 20;

        } else if( *(v + (2 * tam) + 2) == 0 && *(v + (3 * tam) + 3) == 0 && *(v + (4 * tam) + 4) == 0 && *(v + (5 * tam) + 5) == 0){
            return 20;

        } else if( *(v + (3 * tam) + 3) == 0 && *(v + (4 * tam) + i) == 0 && *(v + (5 * tam) + 5) == 0 && *(v + (6 * tam) + 6) == 0){
            return 20;

        } else if( *(v + (0 * tam) + 1) == 1 && *(v + (1 * tam) + 2) == 1 && *(v + (2 * tam) + 3) == 1 && *(v + (3 * tam) + 4) == 1){
            return 10;

        } else if( *(v + (1 * tam) + 2) == 1 && *(v + (2 * tam) + 3) == 1 && *(v + (3 * tam) + 4) == 1 && *(v + (4 * tam) + 5) == 1){
            return 10;

        } else if( *(v + (2 * tam) + 3) == 1 && *(v + (3 * tam) + 4) == 1 && *(v + (4 * tam) + 5) == 1 && *(v + (5 * tam) + 6) == 1){
            return 10;

        } else if( *(v + (0 * tam) + 2) == 1 && *(v + (1 * tam) + 3) == 1 && *(v + (2 * tam) + 4) == 1 && *(v + (3 * tam) + 5) == 1){
            return 10;

        } else if( *(v + (1 * tam) + 3) == 1 && *(v + (2 * tam) + 4) == 1 && *(v + (3 * tam) + 5) == 1 && *(v + (4 * tam) + 6) == 1){
            return 10;

        } else if( *(v + (0 * tam) + 3) == 1 && *(v + (1 * tam) + 4) == 1 && *(v + (2 * tam) + 5) == 1 && *(v + (3 * tam) + 6) == 1){
            return 10;

        } else if( *(v + (0 * tam) + 1) == 0 && *(v + (1 * tam) + 2) == 0 && *(v + (2 * tam) + 3) == 0 && *(v + (3 * tam) + 4) == 0){
            return 20;

        } else if( *(v + (1 * tam) + 2) == 0 && *(v + (2 * tam) + 3) == 0 && *(v + (3 * tam) + 4) == 0 && *(v + (4 * tam) + 5) == 0){
            return 20;

        } else if( *(v + (2 * tam) + 3) == 0 && *(v + (3 * tam) + 4) == 0 && *(v + (4 * tam) + 5) == 0 && *(v + (5 * tam) + 6) == 0){
            return 20;

        } else if( *(v + (0 * tam) + 2) == 0 && *(v + (1 * tam) + 3) == 0 && *(v + (2 * tam) + 4) == 0 && *(v + (3 * tam) + 5) == 0){
            return 20;

        } else if( *(v + (1 * tam) + 3) == 0 && *(v + (2 * tam) + 4) == 0 && *(v + (3 * tam) + 5) == 0 && *(v + (4 * tam) + 6) == 0){
            return 20;

        } else if( *(v + (0 * tam) + 3) == 0 && *(v + (1 * tam) + 4) == 0 && *(v + (2 * tam) + 5) == 0 && *(v + (3 * tam) + 6) == 0){
            return 20;

        } else if( *(v + (1 * tam) + 0) == 1 && *(v + (2 * tam) + 1) == 1 && *(v + (3 * tam) + 2) == 1 && *(v + (4 * tam) + 3) == 1){
            return 10;

        } else if( *(v + (2 * tam) + 1) == 1 && *(v + (3 * tam) + 2) == 1 && *(v + (4 * tam) + 3) == 1 && *(v + (5 * tam) + 4) == 1){
            return 10;

        } else if( *(v + (3 * tam) + 2) == 1 && *(v + (4 * tam) + 3) == 1 && *(v + (5 * tam) + 4) == 1 && *(v + (6 * tam) + 5) == 1){
            return 10;

        } else if( *(v + (2 * tam) + 0) == 1 && *(v + (3 * tam) + 1) == 1 && *(v + (4 * tam) + 2) == 1 && *(v + (5 * tam) + 3) == 1){
            return 10;

        } else if( *(v + (3 * tam) + 1) == 1 && *(v + (4 * tam) + 2) == 1 && *(v + (5 * tam) + 3) == 1 && *(v + (6 * tam) + 4) == 1){
            return 10;

        } else if( *(v + (3 * tam) + 0) == 1 && *(v + (4 * tam) + 1) == 1 && *(v + (5 * tam) + 2) == 1 && *(v + (6 * tam) + 3) == 1){
            return 10;

        } else if( *(v + (1 * tam) + 0) == 0 && *(v + (2 * tam) + 1) == 0 && *(v + (3 * tam) + 2) == 0 && *(v + (4 * tam) + 3) == 0){
            return 20;

        } else if( *(v + (2 * tam) + 1) == 0 && *(v + (3 * tam) + 2) == 0 && *(v + (4 * tam) + 3) == 0 && *(v + (5 * tam) + 4) == 0){
            return 20;

        } else if( *(v + (3 * tam) + 2) == 0 && *(v + (4 * tam) + 3) == 0 && *(v + (5 * tam) + 4) == 0 && *(v + (6 * tam) + 5) == 0){
            return 20;

        } else if( *(v + (2 * tam) + 0) == 0 && *(v + (3 * tam) + 1) == 0 && *(v + (4 * tam) + 2) == 0 && *(v + (5 * tam) + 3) == 0){
            return 20;

        } else if( *(v + (3 * tam) + 1) == 0 && *(v + (4 * tam) + 2) == 0 && *(v + (5 * tam) + 3) == 0 && *(v + (6 * tam) + 4) == 0){
            return 20;

        } else if( *(v + (3 * tam) + 0) == 0 && *(v + (4 * tam) + 1) == 0 && *(v + (5 * tam) + 2) == 0 && *(v + (6 * tam) + 3) == 0){
            return 20;

        }
    }
}
