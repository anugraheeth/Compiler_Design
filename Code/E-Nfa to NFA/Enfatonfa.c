#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
int st;
struct node *link;
};
void findclosure(int, int);
void insert_trantbl(int, char, int);
int findalpha(char);
void findfinalstate(void);
void unionclosure(int);
void print_e_closure(int);
void compute_nfa_without_epsilon(void);
static int set[20], nostate, noalpha, s, notransition, nofinal, finalstate[20], r, buffer[20], start;
char alphabet[20], c;
static int e_closure[20][20] = {0};
struct node *transition[20][20] = {NULL};
int main() {
int i;
printf("\nEnter the number of alphabets: ");
scanf("%d", &noalpha);
getchar();
printf("\nEnter the alphabets: ");
for (i = 0; i < noalpha; i++) {
alphabet[i] = getchar();
getchar();
}
printf("\nEnter the number of states: ");
scanf("%d", &nostate);
printf("\nEnter the start state: ");
scanf("%d", &start);
printf("\nEnter the number of final states: ");
scanf("%d", &nofinal);
printf("\nEnter the final states: ");
for (i = 0; i < nofinal; i++) {
scanf("%d", &finalstate[i]);
}
printf("\nEnter the number of transitions: ");scanf("%d", &notransition);
printf("\nEnter the transitions: ");
for (i = 0; i < notransition; i++) {
scanf("%d %c %d", &r, &c, &s);
insert_trantbl(r, c, s);
}
for (i = 1; i <= nostate; i++) {
c = 0;
for (int j = 0; j < 20; j++) {
buffer[j] = 0;
e_closure[i][j] = 0;
}
findclosure(i, i);
}
printf("\nEquivalent NFA without epsilon");
printf("\n..............................\n");
printf("\nStart state: ");
print_e_closure(start);
printf("\nAlphabets: ");
for (i = 0; i < noalpha; i++)
printf("%c ", alphabet[i]);
  printf("\nEpsilon closure of state ");
   for(i=1;i<=nostate;i++)
   {
    printf("\nstate q%d: ",i);
    print_e_closure(i);
    printf("\n");
   }




compute_nfa_without_epsilon();
printf("\nFinal states: ");
findfinalstate();
printf("\n");
return 0;
}
void findclosure(int x, int sta) {
struct node *temp;
int i;
if (buffer[x]) return;
e_closure[sta][c++] = x;
buffer[x] = 1;
if (alphabet[noalpha - 1] == 'e' && transition[x][noalpha - 1] != NULL) {
temp = transition[x][noalpha - 1];
while (temp != NULL) {
findclosure(temp->st, sta);
temp = temp->link;
}
}
}
void insert_trantbl(int r, char c, int s) {
int j;
struct node *temp;
j = findalpha(c);
if (j == 999) {printf("\nError: Alphabet not found.");
exit(0);
}
temp = (struct node *)malloc(sizeof(struct node));
temp->st = s;
temp->link = transition[r][j];
transition[r][j] = temp;
}
int findalpha(char c) {
int i;
for (i = 0; i < noalpha; i++)
if (alphabet[i] == c)
return i;
return 999;
}
void unionclosure(int i) {
int j = 0, k;
while (e_closure[i][j] != 0) {
k = e_closure[i][j];
set[k] = 1; // Use '1' to indicate that the state is part of the closure
j++;
}
}
void findfinalstate() {
int i, j, k;
for (i = 0; i < nofinal; i++) {
for (j = 1; j <= nostate; j++) {
for (k = 0; e_closure[j][k] != 0; k++) {
if (e_closure[j][k] == finalstate[i]) {
printf("q%d ", j);
}
}
}
}
}
void print_e_closure(int i) {
int j;
for (j = 0; e_closure[i][j] != 0; j++) {
if (j > 0) printf(", ");
printf("q%d", e_closure[i][j]);
}
}
void compute_nfa_without_epsilon(void) {
int i, j, k, m, t;
printf("\nTransitions are:\n");for (i = 1; i <= nostate; i++) {
for (j = 0; j < noalpha - 1; j++) { // Exclude epsilon (last index in alphabet array)
for (k = 0; k < 20; k++) set[k] = 0;
for (m = 0; e_closure[i][m] != 0; m++) {
t = e_closure[i][m];
struct node *temp = transition[t][j];
while (temp != NULL) {
unionclosure(temp->st);
temp = temp->link;
}
}
printf("{");
print_e_closure(i);
printf("}\t%c\t{", alphabet[j]);
for (k = 1; k <= nostate; k++) {
if (set[k] != 0) {
printf("q%d", k);
if (set[k + 1] != 0) printf(",");
}
}
printf("}\n");
}
}
}
