#include <bits/stdc++.h>

int n, a, b, sum, bigsum, bug;

int main () {
    scanf("%d%d", &n, &b);
    for (int i = 2; i <= n; i++) {
        a = b;
        scanf("%d", &b);
        if (a > b) sum++;
        if (a < b) sum--;
        if (a == b) bug = 1;
        if (sum > 1) bug = 1;
        if (sum < -1) bug = 1;
        bigsum += sum;
    }
    if (!bug and (bigsum == n/2 or bigsum == -n/2)) printf("1\n");
    else printf("0\n");
    return 0;
}
