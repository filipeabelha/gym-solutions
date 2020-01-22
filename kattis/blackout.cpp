#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

char s[50];
int a, b, c, d;

int x (int k) { 
    int ans = 7-k;
    if (ans < 1) ans = 1;
    if (ans > 6) ans = 6;
    return ans;
}

int y (int k) {
    int ans = 5-k;
    if (ans < 1) ans = 1;
    if (ans > 5) ans = 5;
    return ans;
}

int main () {
    setlinebuf(stdout);

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        printf("5 1 5 6\n");
        fflush(stdout);
        while (1) {
            scanf("%s", s);
            if (s[0] == 'M') {
                scanf("%d%d%d%d", &a, &b, &c, &d);
                pair <int, int> p = {y(a), x(b)};
                pair <int, int> q = {y(c), x(d)};
                if (p.st > q.st) swap(p, q);
                if (p.st == q.st or p.nd > q.nd) swap(p, q);
                printf("%d %d %d %d\n", p.st, p.nd, q.st, q.nd);
                fflush(stdout);
            } else break;
        }
    }

    return 0;
}
