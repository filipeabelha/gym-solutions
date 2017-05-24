#include <bits/stdc++.h>
using namespace std;

int n, ans, x;

int main () {
    while (scanf("%d", &n) != EOF) {
        ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &x), ans += x;
        printf("%s\n", ans >= (double)n*2/3 ? "impeachment" : "acusacao arquivada");
    }
    return 0;
}
