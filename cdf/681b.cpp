#include <bits/stdc++.h>

int n, n0, yes;

int main () {
    scanf("%d", &n);
    n0 = n;
    n %= 1234567;
    while (!yes and n <= n0) {
        for (int c = 0; c <= n/1234; c++)
            for (int b = 0; b <= n/123456; b++)
                if (b*123456 + c*1234 == n)
                    yes = 1;
        n += 1234567;
    }
    if (yes) printf("YES\n");
    else printf("NO\n");
    return 0;
}
