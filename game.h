#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void sum(int level, char *name);
void subt(int nivel, char *login);
void mult(int nivel, char *login);
void divi(int nivel, char *login);
void mix(int nivel, char *login);
int randSum(int nivel, int *a, int *b);
int randSubt(int nivel, int *a, int *b);
int randMult(int nivel, int *a, int *b);
int randDivi(int nivel, int *a, int *b);
void auth();
void main_game(char *name);

#endif // GAME_H_INCLUDED
