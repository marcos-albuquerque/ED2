#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opt.h"

struct user {
    char userName[11];
    char password[7];
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

static TreeNode* insert(TreeNode* r, User* u)
{
    if(r == NULL) {
        r = (TreeNode*) malloc(sizeof(TreeNode));

        if(r == NULL) {
            printf("Não há memória disponível.\b");
            exit(1);
        }

        r->info = creates_user(u->userName, u->password);
        r->left = r->right = NULL;
    }
    else if(strcmp(u->userName, r->info->userName) < 0)
        r->left = insert(r->left, u);
    else if(strcmp(u->userName, r->info->userName) > 0)
        r->right = insert(r->right, u);
    else
        printf("Esse nome de usuário já existe!\n");

    return r;
}

void bst_insert(Tree* t, User* u)
{
    t->root = insert(t->root, u);
}

static void Save(TreeNode* r, FILE* file)
{
  if(r != NULL) {
    Save(r->left, file);
    fwrite(r->info, sizeof(User), 1, file);
    Save(r->right, file);
  }
}

void SaveInFile(Tree* t) {
  FILE* file = fopen("./user.b", "wb");

  if(file == NULL) {
    printf("O arquivo não pode ser aberto.\n");
    exit(1);
  }

  Save(t->root, file);
  fclose(file);
}

static void readFromFile(Tree *t)
{
  FILE* file = fopen("./user.b", "rb");
  User u;

  if(file == NULL) {
    printf("O arquivo não pode ser aberto.\n");
    exit(1);
  }

  if(t->root == NULL) {
    while( fread(&u, sizeof(User), 1, file) ) {
        bst_insert(t, &u);
    }
  }
  fclose(file);
}

static void print_users(User* u)
{
  printf("Nome: %s\t", u->userName);
  printf("Senha: %s\t", u->password);
  printf("ScoreMix: %d\n\n", u->bestScoreMix);
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

void main_menu(void)
{
    printf("====== MENU ======\n"
           "1 - Jogar\n"
           "2 - Opções\n"
           "3 - Sair\n"
           "===================\n");
}

static void menu_opt(void)
{
    printf("======= Opções =======\n"
           "1 - Cadastrar usuário\n"
           "2 - Mostrar usuários\n"
           "3 - Apagar usuário\n"
           "4 - Voltar\n"
           "======================\n");
}

static int readUser(User* u)
{
    char s1[11];
    char s2[7];
    printf("Degite um nome de no máximo 10 caracteres: ");
    scanf("%s", s1);

    if(strlen(s1) > 10) {
      printf("\nO nome deve ter no máximo 10 caracteres.\n");
      printf("Tente novamente.\n\n");
      return -1;
    }

    strcpy(u->userName, s1);

    printf("Digite uma senha de no máximo 6 caracteres: ");
    scanf("%s", s2);

    if(strlen(s2) > 6) {
      printf("\nA senha deve ter no máximo 6 caracteres.\n");
      printf("Tente novamente.\n\n");
      return -1;
    }
    strcpy(u->password, s2);

    return 1;
}

static TreeNode* Remove(TreeNode* r, User* u)
{
    if(r == NULL)
        return NULL;
    else if( strcmp(r->info->userName, u->userName) > 0 )
        r->left = Remove(r->left, u);
    else if( strcmp(r->info->userName, u->userName) < 0 )
        r->right = Remove(r->right, u);
    else { // achou o elemento
        printf("Passou aqui\n");
        // elemento sem filho
        if( r->left == NULL && r->right == NULL ) {
            free(r);
            r = NULL;
        }

        // só tem filho à direita
        else if(r->left == NULL) {
            TreeNode* t = r;
            r = r->right;
            free(t);
        }
        // só tem filho à esquerda
        else if(r->right == NULL) {
            TreeNode* t = r;
            r = r->left;
            free(t);
        }
        // tem os dois filhos
        else {
            TreeNode* t = r->left;
            while(t->right != NULL) {
                t = t->right;
            }

            r->info = t->info; // troca as informações
            t->info = u;
            r->left = Remove(r->left, u);
        }
    }

    return r;
}

void bst_remove(Tree* t, User* u)
{
    t->root = Remove(t->root, u);
}

void main_opt(void)
{
    Tree *t = tree_creates();
    readFromFile(t);

    char op;
    menu_opt();
    printf("> ");
    scanf(" %c", &op);

    while(op != '4') {
        switch(op) {
            case '1': {
                User u;
                int r = readUser(&u);
                while(r == -1) {
                  r = readUser(&u);
                }

                bst_insert(t, &u);

                SaveInFile(t);
                break;
            }
            case '2':
                bst_imprime(t);
                break;
            case '3': {
                User u;
                char name[11];
                printf("Digite o nome do usuário: ");
                scanf(" %s", name);
                strcpy(u.userName, name);

                bst_remove(t, &u);
                SaveInFile(t);
                break;
            }
            default:
                printf("Opção inválida!\n");
                break;
        }

        menu_opt();
        printf("> ");
        scanf(" %c", &op);
    }
}
