#ifndef OPT_H_INCLUDED
#define OPT_H_INCLUDED

typedef struct user User;
typedef struct treeNode TreeNode;
typedef struct tree Tree;
typedef enum operation Operation;
enum operation{ SUM, SUB, MUL, DIV, MIX };

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
void update(char *name, Operation op, int score );
void verify(char* name, char* password);
void bst_release(Tree* t);

#endif // OPT_H_INCLUDED
