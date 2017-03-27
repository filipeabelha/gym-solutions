#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+10;

int n, k = 1, atk, e[N];
ll sum;
set <int> s;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &e[i]);
        sum += e[i];
    }
    while (1) {
        if (k < 1 or k > n) break;
        if (e[k] % 2 == 0) {
            if (e[k] > 0) e[k]--, sum--;
            s.insert(k);
            k--;
        } else {
            if (e[k] > 0) e[k]--, sum--;
            s.insert(k);
            k++;
        }
    }
    atk = s.size();
    printf("%d %lld\n", atk, sum);
    return 0;
}
