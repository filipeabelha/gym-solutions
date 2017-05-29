#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int j, r, maxi, ans, v[N];

int main () {
    scanf("%d%d", &j, &r);
    for (int i = 1; i <= j*r; i++) scanf("%d", &v[i]);
    for (int jog = 1; jog <= j; jog++) {
        int p = 0;
        for (int i = jog; i <= j*r; i += j) p += v[i];
        if (p >= maxi) maxi = p, ans = jog;
    }
    printf("%d\n", ans);
    return 0;
}
