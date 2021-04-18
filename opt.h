#ifndef OPT_H_INCLUDED
#define OPT_H_INCLUDED

typedef struct user User;
typedef struct treeNode TreeNode;
typedef struct tree Tree;

Tree* tree_creates(void);
void main_opt(void);
void main_menu(void);
void bst_insert(Tree* t, char* name, char* password);

#endif // OPT_H_INCLUDED
