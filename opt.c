#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opt.h"

struct user {
    char userName[10];
    char password[6];
    int bestScoreSum;
    int bestScoreSub;
    int bestScoreMul;
    int bestScoreDiv;
    int bestScoreMix;
};

struct treeNode {
    User* info;
    TreeNode* left;
    TreeNode* right;
};

struct tree {
    TreeNode* root;
};

Tree* tree_creates(void)
{
    Tree* t = (Tree*) malloc(sizeof(Tree));

    if(t == NULL) {
        printf("Não há memória disponível.\b");
        exit(1);
    }

    t->root = NULL;

    return t;
}

static User* creates_user(char *name, char* password)
{
    User* u = (User*) malloc(sizeof(User));

    if(u == NULL) {
        printf("Não há memória disponível.\b");
        exit(1);
    }

    strcpy(u->userName, name);
    strcpy(u->password, password);

    // inicializa os scores
    u->bestScoreSum = 0;
    u->bestScoreSub = 0;
    u->bestScoreMul = 0;
    u->bestScoreDiv = 0;
    u->bestScoreMix = 0;

    return u;
}

static TreeNode* insert(TreeNode* r, char* name, char* password)
{
    if(r == NULL) {
        r = (TreeNode*) malloc(sizeof(TreeNode));

        if(r == NULL) {
            printf("Não há memória disponível.\b");
            exit(1);
        }

        r->info = creates_user(name, password);
        r->left = r->right = NULL;
    }
    else if(strcmp(name, r->info->userName) < 0)
        r->left = insert(r->left, name, password);
    else
        r->right = insert(r->right, name, password);

    return r;
}

void bst_insert(Tree* t, char* name, char* password)
{
    t->root = insert(t->root, name, password);
}

void main_menu(void)
{
    printf("====== MENU ======\n"
           "1 - Jogar\n"
           "2 - Opções\n"
           "3 - Sair\n"
           "===================\n");
}

void menu_opt(void)
{
    printf("======= Opções =======\n"
           "1 - Cadastrar usuário\n"
           "2 - Mostrar usuários\n"
           "3 - Apagar usuário\n"
           "4 - Voltar\n"
           "======================\n");
}

static void print_users(User* u)
{
  printf("Nome: %s\n", u->userName);
}

static void print(TreeNode* r)
{
  if(r != NULL) {
    print(r->left);
    print_users(r->info);
    print(r->right);
  }
}

void bst_imprime(Tree* t)
{
  print(t->root);
}

void main_opt(void)
{
    Tree *t = tree_creates();
    
    int op;
    menu_opt();
    printf("> ");
    scanf("%d", &op);

    while(op != 4) {
        switch(op) {
            case 1: {                
                char name[11];
                char password[7];

                printf("Digite um nome de usuário: ");
                scanf("%s", name);
                printf("Digite uma senha: ");
                scanf("%s", password);
                
                bst_insert(t, name, password);
                bst_imprime(t);

                break;
            }
                break;
            case 2:
                // imprimir usuários
                break;
            case 3:
                // deletar usuário
                break;
        }

        menu_opt();
        printf("> ");
        scanf("%d", &op);
    }
}
