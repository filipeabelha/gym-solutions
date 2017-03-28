#include <bits/stdc++.h>

int n, s50, s25, err;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 25) s25++;
        if (x == 50)
            if (s25 > 0) s50++, s25--;
            else err = 1;
        if (x == 100)
            if (s50 > 0 and s25 > 0) s50--, s25--;
            else if (s50 == 0 and s25 >= 3) s25 -= 3;
            else err = 1;
    }
    if (err) printf("NO\n"); else printf("YES\n");
    return 0;
}
