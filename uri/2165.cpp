#include <bits/stdc++.h>

char chr;
int n;

int main () {
    while (1) {
        scanf("%c", &chr);
        if (chr == 10) break;
        n++;
    }
    (n > 140) ? printf("MUTE\n") : printf("TWEET\n");
    return 0;
}
