#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define cl(x, v) memset((x), (v), sizeof(x))

typedef vector<int> vi;
typedef vector<vi> vii;

const int N = 55; // Maximum number of items
const int L = 105; // Maximum value for 'limit'

int tc, res, ans, n, limit, w[N], v[N], knap[L];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(w, 0); cl(v, 0); cl(knap, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &v[i], &w[i]);
        for (int i = 0; i < n; i++)
            for (int j = L-1; j >= w[i]; j--)
                knap[j] = max(knap[j], v[i]+knap[j-w[i]]);
        scanf("%d", &limit);
        scanf("%d", &res);
        ans = knap[limit];
        if (ans >= res) printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    }
}

