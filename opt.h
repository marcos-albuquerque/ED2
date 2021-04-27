#ifndef OPT_H_INCLUDED
#define OPT_H_INCLUDED

typedef struct user User;
typedef struct treeNode TreeNode;
typedef struct tree Tree;

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

Tree* tree_creates(void);
void bst_insert(Tree* t, User* u);
void SaveInFile(Tree* t);
void readFromFile(Tree *t);
void bst_imprime(Tree* t);
void bst_remove(Tree* t, User* u);
void main_menu(void);
void main_opt(void);
TreeNode* bst_search(Tree *t, char* name);
TreeNode* bst_searchByValue(Tree* t, int v);
int bst_bestMix(Tree* t);
void bst_release(Tree* t);

#endif // OPT_H_INCLUDED
