#include <bits/stdc++.h>
using namespace std;

int fact[15], n, ans;

int main () {
    fact[0] = 1; for (int i = 1; i <= 10; i++) fact[i] = i*fact[i-1];
    scanf("%d", &n);
    for (int i = 10; i >= 1; i--)
        if (n >= fact[i] and n > 0) ans += n/fact[i], n %= fact[i];
    printf("%d\n", ans);
}
