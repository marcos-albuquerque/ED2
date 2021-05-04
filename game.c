#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "opt.h"

static void game_menu()
{
    printf("======== MENU DO JOGO ========\n"
           " 1 - Adição\n"
           " 2 - Subtração\n"
           " 3 - Multiplicação\n"
           " 4 - Divisão\n"
           " 5 - Misto\n"
           " 6 - Voltar\n"
           "======================"
           "\n> ");
}

static void level_menu()
{
    printf("======== NÍVEL ========\n"
           " 1 - Fácil\n"
           " 2 - Médio\n"
           " 3 - Difícil\n"
           " 4 - Voltar\n"
           "======================="
           "\n> ");
}

/*
* mostra operações de soma, com diferentes tipos de dificultade (dependendo da escolha do usuário)
* para o usuário responder. Cada vez que o usuário acerta, é incrementado um ponto.
* caso o usuário erre uma operação o jogo é finalizado e, caso sua pontuação seja maior que seu score atual
* o score é atualizado com essa pontuação
*/
void sum(int level, char *name)
{
    int score = 0;
    int ansUser; // resposta do usuário
    int ansCorrect; // resposta correta

    int i = 1;
    while(i == 1)
    {
        int a, b;

        ansCorrect = randSum(level, &a, &b);
        printf("%d + %d = ", a, b);
        scanf("%d", &ansUser);

        if(ansUser == ansCorrect) // Se a resposta estiver correta
        {
            printf("Acertou!\n");
            score++;
        }
        else // tratamento para reposta errada
        {
            printf("Errou! A resposta correta era %d\n", ansCorrect);
            i = -1;
            update(name, SUM, score );
            printf("Sua pontuação nessa partida: %d\n", score);
        }
    }
}

/*
* Faz o mesmo que a função anterior, só que com a operação de subtração
*/
void subt(int level, char *name)
{
    int score = 0;
    int ansUser; // resposta do usuário
    int ansCorrect; // resposta correta

    int i = 1;
    while(i == 1)
    {
        int a, b;

        ansCorrect = randSubt(level, &a, &b);
        printf("%d - %d = ", a, b);
        scanf("%d", &ansUser);

        if(ansUser == ansCorrect)
        {
            printf("Acertou!\n");
            score++;
        }
        else
        {
            printf("Errou! A resposta correta era %d\n", ansCorrect);
            i = -1;
            update(name, SUB, score );
            printf("Sua pontuação nessa partida: %d\n", score);
        }
    }
}

/*
* Faz o mesmo que a função anterior, só que com a operação de multiplicação
*/
void mult(int level, char *name)
{
    int score = 0;
    int ansUser; // resposta do usuário
    int ansCorrect; // resposta correta

    int i = 1;
    while(i == 1)
    {
        int a, b;

        ansCorrect = randMult(level, &a, &b);
        printf("%d x %d = ", a, b);
        scanf("%d", &ansUser);

        if(ansUser == ansCorrect)
        {
            printf("Acertou!\n");
            score++;
        }
        else
        {
            printf("Errou! A resposta correta era %d\n", ansCorrect);
            i = -1;
            update(name, MUL, score );
            printf("Sua pontuação nessa partida: %d\n", score);
        }
    }
}

/*
* Faz o mesmo que a função anterior, só que com a operação de divisão
*/
void divi(int level, char *name)
{
    int score = 0;
    int ansUser; // resposta do usuário
    int ansCorrect; // resposta correta

    int i = 1;
    while(i == 1)
    {
        int a, b;

        ansCorrect = randDivi(level, &a, &b);
        printf("%d / %d = ", a, b);
        scanf("%d", &ansUser);

        if(ansUser == ansCorrect)
        {
            printf("Acertou!\n");
            score++;
        }
        else
        {
            printf("Errou! A resposta correta era %d\n", ansCorrect);
            i = -1;
            update(name, DIV, score );
            printf("Sua pontuação nessa partida: %d\n", score);
        }
    }
}

/*
* Faz o mesmo que a função anterior, só que com operações mistas
*/
void mix(int level, char *name)
{
    srand(time(NULL));

    int score = 0;
    int ansUser; // resposta do usuário
    int ansCorrect; // resposta correta
    int i = 1;

    while(i == 1)
    {
        int op = 1 + rand() % 4;
        int a, b;

        switch(op)
        {
            case 1: {
                ansCorrect = randSum(level, &a, &b);
                printf("%d + %d = ", a, b);
                scanf("%d", &ansUser);
                break;
            }
            case 2: {
                ansCorrect = randSubt(level, &a, &b);
                printf("%d - %d = ", a, b);
                scanf("%d", &ansUser);
                break;
            }
            case 3: {
                ansCorrect = randMult(level, &a, &b);
                printf("%d x %d = ", a, b);
                scanf("%d", &ansUser);
                break;
            }
            case 4: {
                ansCorrect = randDivi(level, &a, &b);
                printf("%d / %d = ", a, b);
                scanf("%d", &ansUser);
                break;
            }
        }

        if(ansUser == ansCorrect)
        {
            printf("Acertou!\n");
            score++;
        }
        else
        {
            printf("Errou! A resposta correta era %d\n", ansCorrect);
            i = -1;
            update(name, MIX, score );
            //update(name, 4, score);
            printf("Sua pontuação nessa partida: %d\n", score);
        }
    }
}

// gera operandos aleatórios para soma, de acordo com o nível de dificuldade
int randSum(int level, int *a, int *b)
{
    srand(time(NULL)); // semente geradora de números pseudo-aleatórios

    if( level == 1 )
    {
        *a = rand() % 11; // 0, 1, 2, ... , 10
        *b = rand() % 11;
    }
    else if( level == 2 )
    {
        *a = rand() % 50;
        *b = rand() % 50;
    }
    else if( level == 3 )
    {
        *a = rand() % 500;
        *b = rand() % 500;
    }

    return *a + *b;
}

// gera operandos aleatórios para subtração, de acordo com o nível de dificuldade
int randSubt(int level, int *a, int *b)
{
    srand(time(NULL)); // semente geradora de números pseudo-aleatórios

    if( level == 1 )
    {
        *a = rand() % 10;
        *b = rand() % 10;
    }
    else if( level == 2 )
    {
        *a = rand() % 50;
        *b = rand() % 50;
    }
    else if( level == 3 )
    {
        *a = rand() % 500;
        *b = rand() % 500;
    }

    return *a - *b;
}

// gera operandos aleatórios para multiplicação, de acordo com o nível de dificuldade
int randMult(int level, int *a, int *b)
{
    srand(time(NULL)); // semente geradora de números pseudo-aleatórios

    if( level == 1 )
    {
        *a = rand() % 10;
        *b = rand() % 10;
    }
    else if( level == 2 )
    {
        *a = rand() % 10;
        *b = rand() % 50;
    }
    else if( level == 3 )
    {
        *a = rand() % 20;
        *b = rand() % 50;
    }

    return *a * *b;
}

// gera operandos aleatórios para divisão, de acordo com o nível de dificuldade
int randDivi(int level, int *a, int *b)
{
    srand(time(NULL)); // semente geradora de números pseudo-aleatórios

    do
    {
        if( level == 1 )
        {
            *a = rand() % 50;
            *b = 1 + rand() % 10;
        }
        else if( level == 2 )
        {
            *a = rand() % 100;
            *b = 1 + rand() % 20;
        }
        else if( level == 3 )
        {
            *a = rand() % 200;
            *b = 1 + rand() % 50;
        }
    }
    while(*a % *b != 0);

    return *a / *b;
}

void auth()
{
    char name[11];
    char password[7];

    printf("Digite seu nome de usuário:\n> ");
    scanf("%s", name);
    printf("Digite sua senha:\n> ");
    scanf("%s", password);

    verify(name, password);
}

// função principal do game
void main_game(char *name)
{
    char op;
    game_menu();
    scanf(" %c", &op);

    while(op != '6')
    {
        switch(op)
        {
            case '1': {
                int level;

                level_menu();
                scanf("%d", &level);

                if(level == 4) break;

                sum(level, name);
                break;
            }
            case '2': {
                int nivel;

                level_menu();
                scanf("%d", &nivel);

                if(nivel == 4) break;

                subt(nivel, name);
                break;
            }
            case '3': {
                int nivel;

                level_menu();
                scanf("%d", &nivel);

                if(nivel == 4) break;

                mult(nivel, name);
                break;
            }
            case '4': {
                int nivel;

                level_menu();
                scanf("%d", &nivel);

                if(nivel == 4) break;

                divi(nivel, name);
                break;
            }
            case '5': {
                int nivel;

                level_menu();
                scanf("%d", &nivel);

                if(nivel == 4) break;

                mix(nivel, name);
                break;
            }
            default:
                printf("Opção inválida!\n");
        }

        game_menu();
        scanf(" %c", &op);
    }
}
