#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, a, b;
char s[N];

int main () {
    scanf("%d", &n);
    while (n--) {
        strcpy(s, "");
        scanf("%d%d", &a, &b);
        for (int i = a; i <= b; i++)
            sprintf(s, "%s%d", s, i);
        printf("%s", s);
        for (int i = (int) strlen(s)-1; i >= 0; i--)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
