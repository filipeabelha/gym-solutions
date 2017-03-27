#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int su, ans, cost;
vector <int> income;

int main () {
    int n;
    while(scanf("%d", &n) != EOF) {
        scanf("%d", &cost);
        income.clear();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            income.pb(x-cost);
        }
        su = 0; ans = 0;
        for (int i = 0; i < n; i++) {
            su += income[i];
            if (su < 0) su = 0;
            if (su > ans) ans = su;
        }
        printf("%d\n", ans);
    }
    return 0;
}
