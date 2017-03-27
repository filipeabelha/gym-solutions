#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int b, s, l, r, bleft[N], bright[N];

int main () {
    while(1) {
        scanf("%d%d", &s, &b);
        if (!s and !b) break;
        memset(bleft, 0, sizeof(bleft));
        memset(bright, 0, sizeof(bright));
        for (int i = 1; i <= s+1; i++) bleft[i]  = i-1;
        for (int i = 0; i <= s; i++) bright[i] = i+1;
        for (int i = 0; i < b; i++) {
            scanf("%d%d", &l, &r);
            bright[bleft[l]] = bright[r];
            bleft[bright[r]] = bleft[l];
            if (bleft[l] > 0)   printf("%d ", bleft[l]);
            else                printf("* ");
            if (bright[r] <= s) printf("%d\n", bright[r]);
            else                printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}
