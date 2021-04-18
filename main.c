#include <stdio.h>
#include <stdlib.h>
#include "opt.h"

int main()
{
    int op;
    main_menu();
    printf("> ");
    scanf("%d", &op);

    while(op != 3) {
        switch(op) {
            case 1:
                printf("Jogar\n");
                break;
            case 2:
                main_opt();
                break;
        }

        main_menu();
        printf("> ");
        scanf("%d", &op);
    }

    return 0;
}
