#include <bits/stdc++.h>
using namespace std;

int n;;
long long res = 1;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) res *= 3;
    printf("%lld\n", res);
    return 0;
}
