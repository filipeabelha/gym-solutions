#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char par[100], choice1[100], impar[100], choice2[100];
        long long a, b;
        scanf("%s %s %s %s %lld %lld", par, choice1, impar, choice2, &a, &b);
        long long sum = a+b;
        char ans1[100], ans2[100];
        if (choice1[0] == 'P') strcpy(ans1, par), strcpy(ans2, impar);
        else                   strcpy(ans2, par), strcpy(ans1, impar);
        if (sum % 2 == 0) printf("%s\n", ans1); else printf("%s\n", ans2);
    }
    return 0;
}
