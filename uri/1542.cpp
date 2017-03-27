#include <bits/stdc++.h>

int main () {
    while (1) {
        int a, b, c;
        scanf("%d", &a);
        if (a == 0) break;
        scanf("%d%d", &b, &c);
        int result = a*b*c/(c-a);
        if (result == 1)
            printf("1 pagina\n");
        else
            printf("%d paginas\n", result);
    }
    return 0;
}
