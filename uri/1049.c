#include <stdio.h>

int main() {
    char a[100], b[100], c[100];
    scanf(" %s %s %s", &a, &b, &c);
    if (strcmp(b,"ave") == 0      && strcmp(c,"carnivoro") == 0)  printf("aguia\n");
    if (strcmp(b,"ave") == 0      && strcmp(c,"onivoro") == 0)    printf("pomba\n");
    if (strcmp(b,"mamifero") == 0 && strcmp(c,"onivoro") == 0)    printf("homem\n");
    if (strcmp(b,"mamifero") == 0 && strcmp(c,"herbivoro") == 0)  printf("vaca\n");
    if (strcmp(b,"inseto") == 0   && strcmp(c,"hematofago") == 0) printf("pulga\n");
    if (strcmp(b,"inseto") == 0   && strcmp(c,"herbivoro") == 0)  printf("lagarta\n");
    if (strcmp(b,"anelideo") == 0 && strcmp(c,"hematofago") == 0) printf("sanguessuga\n");
    if (strcmp(b,"anelideo") == 0 && strcmp(c,"onivoro") == 0)    printf("minhoca\n");
    return 0;
}
