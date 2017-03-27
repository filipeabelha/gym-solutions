#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define cl(x, v) memset((x), (v), sizeof(x));

typedef vector<int> vi;
typedef vector<vi> vii;

const int N = 30; // Maximum number of items
const int L = 35; // Maximum value for 'limit'

int ans, n, limit, w[N], v[N], knap[L];

int main () {
    while(1) {
        scanf("%d", &n);
        if (!n) break;
        scanf("%d", &limit);
        cl(w, 0); cl(v, 0); cl(knap, 0);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &v[i], &w[i]);
        for (int i = 0; i < n; i++) {
            for (int j = L-1; j >= w[i]; j--)
                knap[j] = max(knap[j], v[i]+knap[j-w[i]]);
        }
        ans = knap[limit];
        printf("%d min.\n", ans);
    }
}
