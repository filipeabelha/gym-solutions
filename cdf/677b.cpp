#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, h, k, sum, tme, elem, res;
int main () {
    scanf("%I64d%I64d%I64d", &n, &h, &k);
    for (ll i = 0; i < n; i++) {
        scanf("%I64d", &elem);
        while (sum + elem > h) {
            if (sum >= k) {
                tme += sum/k;
                sum %= k;
            } else {
                tme++;
                sum = 0;
            }
        }
        sum += elem;
    }
    while (sum > 0) {
        if (sum >= k) {
            tme += sum/k;
            sum %= k;
        } else {
            tme++;
            sum = 0;
        }
    }
    printf("%I64d\n", tme);
    return 0;
}
