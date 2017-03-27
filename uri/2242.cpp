#include <bits/stdc++.h>

char palavra[100];
char chr;
int n;
int ok = 1;

int main () {
    while (1) {
        scanf("%c", &chr);
        if (chr == 10) break;
        if (chr == 'a') palavra[n] = 'a', n++;
        if (chr == 'e') palavra[n] = 'e', n++;
        if (chr == 'i') palavra[n] = 'i', n++;
        if (chr == 'o') palavra[n] = 'o', n++;
        if (chr == 'u') palavra[n] = 'u', n++;
    }
    for (int i = 0; i < n; i++)
        if (palavra[i] != palavra[n-i-1]) ok = 0;
    if (ok) printf("S\n"); else printf("N\n");
    return 0;
}
