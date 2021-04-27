#include <stdio.h>
#include <stdlib.h>
#include "opt.h"
#include "game.h"

int main()
{
    char op;
    main_menu();
    printf("> ");
    scanf(" %c", &op);

    while(op != '3') {
        switch(op) {
            case '1':
                auth(); // autenticação de usuário para poder jogar
                break;
            case '2':
                main_opt();
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        main_menu();
        printf("> ");
        scanf(" %c", &op);
    }

    printf("Programa finalizado.\n");
    return 0;
}
