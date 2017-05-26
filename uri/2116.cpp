#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int primes[N], a, b, ans = 1;

int main () {
    for (int i = 2; i <= 1000; i++) if (!primes[i]) for (int j = i*i; j <= 1000; j+=i) primes[j] = 1;
    scanf("%d%d", &a, &b);
    for (int i = a; i >= 2; i--) if (!primes[i]) {ans *= i; break;}
    for (int i = b; i >= 2; i--) if (!primes[i]) {ans *= i; break;}
    printf("%d\n", ans);
    return 0;
}
