#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

int n, a, b;
vector <int> v;

int main () {
    while (~scanf("%d%d%d", &n, &a, &b)) {
        v.resize(n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = v.size()-1; i >= 0; i -= a) {
            ans += v[i];
        }

        printf("%s\n", ans <= b ? "S" : "N");


    }
}
