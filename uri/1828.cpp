#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char sheldon[10];
        char raj[10];
        scanf("%s %s", sheldon, raj);
        if (strcmp(sheldon, raj) == 0) {
            printf("Caso #%d: De novo!\n", i);
            continue;
        }
        if (strcmp(sheldon, "tesoura") == 0 && strcmp(raj, "papel") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "tesoura") == 0 && strcmp(sheldon, "papel") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "papel") == 0 && strcmp(raj, "pedra") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "papel") == 0 && strcmp(sheldon, "pedra") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "pedra") == 0 && strcmp(raj, "lagarto") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "pedra") == 0 && strcmp(sheldon, "lagarto") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "lagarto") == 0 && strcmp(raj, "Spock") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "lagarto") == 0 && strcmp(sheldon, "Spock") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "Spock") == 0 && strcmp(raj, "tesoura") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "Spock") == 0 && strcmp(sheldon, "tesoura") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "tesoura") == 0 && strcmp(raj, "lagarto") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "tesoura") == 0 && strcmp(sheldon, "lagarto") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "lagarto") == 0 && strcmp(raj, "papel") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "lagarto") == 0 && strcmp(sheldon, "papel") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "papel") == 0 && strcmp(raj, "Spock") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "papel") == 0 && strcmp(sheldon, "Spock") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "Spock") == 0 && strcmp(raj, "pedra") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "Spock") == 0 && strcmp(sheldon, "pedra") == 0) printf("Caso #%d: Raj trapaceou!\n", i);

        if (strcmp(sheldon, "pedra") == 0 && strcmp(raj, "tesoura") == 0) printf("Caso #%d: Bazinga!\n", i);
        if (strcmp(raj, "pedra") == 0 && strcmp(sheldon, "tesoura") == 0) printf("Caso #%d: Raj trapaceou!\n", i);
    }
    return 0;
}
