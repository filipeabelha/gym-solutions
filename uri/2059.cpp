#include <bits/stdc++.h>

int main () {
    int winner = 0;
    int p, j1, j2, r, a;
    scanf("%d%d%d%d%d", &p, &j1, &j2, &r, &a);
    if (r and a) winner = 2;
    else if (r) winner = 1;
    else if (a) winner = 1;
    else if ((j1 + j2) % 2 == 0 and p)  winner = 1;
    else if ((j1 + j2) % 2 == 0 and !p) winner = 2;
    else if ((j1 + j2) % 2 == 1 and p)  winner = 2;
    else if ((j1 + j2) % 2 == 1 and !p) winner = 1;
    if (winner == 1) printf("Jogador 1 ganha!\n");
    else printf("Jogador 2 ganha!\n");
    return 0;
}
