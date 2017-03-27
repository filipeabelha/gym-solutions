#include <bits/stdc++.h>

int main () {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        long long sum = (b*(b+1) - a*(a-1))/2;
        printf("%lld\n", sum);
        return 0;
}
