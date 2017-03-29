#include <bits/stdc++.h>
using namespace std;

int n;
char chr, w[30];

int main () {
    scanf("%d%c", &n, &chr);
    while (n--) {
        scanf("%s", w);
        if (strlen(w) == 3 and w[0] == 'U' and w[1] == 'R')
            printf("URI");
        else if (strlen(w) == 3 and w[0] == 'O' and w[1] == 'B')
            printf("OBI");
        else printf("%s", w);
        if (n) printf(" ");
    }
    printf("\n");
    return 0;
}
