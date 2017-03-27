#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+5;

int t, m[N][N], l1, l2;

char s1[N], s2[N], chr;

int main () {
    scanf("%d%c", &t, &chr);
    for (int i = 0; i < t; i++) {
        scanf("%s%c%s%c", s1, &chr, s2, &chr);
        l1 = strlen(s1);
        l2 = strlen(s2);
        for (int p = 0; p <= l1; p++)
            for (int q = 0; q <= l2; q++)
                if (p == 0)
                    m[p][q] = q;
                else if (q == 0)
                    m[p][q] = p;
                else if (s1[p-1] == s2[q-1])
                    m[p][q] = m[p-1][q-1];
                else
                    m[p][q] = min(min(m[p-1][q], m[p][q-1]), m[p-1][q-1]) + 1;
        int ans = m[l1][l2];
        printf("%d\n", ans);
    }
    return 0;
}
