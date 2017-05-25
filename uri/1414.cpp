#include <bits/stdc++.h>
using namespace std;

int t, tpts, pts, n;
char team[20], chr;

int main () {
    while (1) {
        scanf("%d%d%c", &t, &n, &chr); if (!t and !n) break;
        while (t--) scanf("%s %d%c", team, &pts, &chr), tpts += pts;
        printf("%d\n", 3*n-tpts); tpts = 0;
    }
    return 0;
}
