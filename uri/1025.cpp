#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector <int> vi;

int a, b, k, ans;
vi v;

int main () {
    for (int t = 1; 1; t++) {
        scanf("%d%d", &a, &b);
        if (!a and !b) break;
        v.clear();
        while (a--) scanf("%d", &k), v.pb(k);
        printf("CASE# %d:\n", t);
        sort(v.begin(), v.end());
        while (b--) {
            scanf("%d", &k);
            ans = -1;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == k) ans = i+1;
                else continue;
                break;
            }
            if (ans == -1) printf("%d not found\n", k);
            else printf("%d found at %d\n", k, ans);
        }
    }
    return 0;
}
