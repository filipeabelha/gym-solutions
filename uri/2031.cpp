#include <bits/stdc++.h>
using namespace std;

string a, b;
char chr;

int main () {
    int n;
    scanf("%d%c", &n, &chr);
    for (int i = 0; i < n; i++) {
        getline(cin, a);
        getline(cin, b);
        if (a[1] == 'e' and b[1] == 'e') printf("Sem ganhador\n");
        if (a[1] == 'a' and b[1] == 'a') printf("Ambos venceram\n");
        if (a[1] == 't' and b[1] == 't') printf("Aniquilacao mutua\n");

        if (a[1] == 'e' and b[1] == 'a') printf("Jogador 1 venceu\n");
        if (a[1] == 'e' and b[1] == 't') printf("Jogador 2 venceu\n");

        if (a[1] == 'a' and b[1] == 'e') printf("Jogador 2 venceu\n");
        if (a[1] == 'a' and b[1] == 't') printf("Jogador 2 venceu\n");

        if (a[1] == 't' and b[1] == 'a') printf("Jogador 1 venceu\n");
        if (a[1] == 't' and b[1] == 'e') printf("Jogador 1 venceu\n");
    }
    return 0;
}
