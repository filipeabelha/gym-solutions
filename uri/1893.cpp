#include <bits/stdc++.h>

int main () {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y <= 2) printf("nova\n");
    else if (y >= 97) printf("cheia\n");
    else if (x > y) printf("minguante\n");
    else printf("crescente\n");
    return 0;
}
