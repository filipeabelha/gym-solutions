#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector <int> vi;

int n, x, ans, hasone;
vi v;

int main () {
    while (1) {
        scanf("%d", &n); if (!n) break; v.clear(); hasone = ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &x), v.pb(x), hasone += x;
        while (hasone and v[0] == 0) v.pb(0), v.erase(v.begin());
        for (int i = 1; i < v.size(); i++)
            if (!v[i] and !v[i-1]) v[i] = 1, ans++;
        printf("%d\n", hasone or !(n%2) ? ans : ++ans);
    }
    return 0;
}
