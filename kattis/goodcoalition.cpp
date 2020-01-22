#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int N = 2e2+5;

ld prob[N];

int main () {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        memset(prob, 0, sizeof prob);
        prob[0] = 1;

        int n;
        scanf("%d", &n);
        while (n--) {
            int a, b;
            scanf("%d%d", &a, &b);
            for (int i = N-1; i >= a; i--) {
                if (prob[i] < prob[i-a]*b/100.) {
                    prob[i] = prob[i-a]*b/100.;
                }
            }
        }
        ld ans = 0;
        for (int i = 76; i <= 150; i++)
            ans = max(ans, prob[i]);

        printf("%.10Lf\n", ans*100);
    }
    return 0;
}
