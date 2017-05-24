#include <bits/stdc++.h>
using namespace std;

int n, d, dayi, moi, yri, day, mo, yr, ans, x;

int main () {
    while(~scanf("%d%d", &n, &d)) {
        day = mo = yr = 0;
        while (d--) {
            ans = 0;
            scanf("%d/%d/%d", &dayi, &moi, &yri);
            for (int i = 0; i < n; i++) scanf("%d", &x), ans += x;
            if (ans == n and !day) day = dayi, mo = moi, yr = yri;
        }
        if (day) printf("%d/%d/%d\n", day, mo, yr);
        else printf("Pizza antes de FdI\n");
    }
    return 0;
}
