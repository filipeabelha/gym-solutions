#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2+10;

int num[N], x, y, k, z;

int main () {
    while (1) {
        scanf("%d%d%d", &x, &y, &k);
        if (!x and !y and !k) break;
        cl(num, 0);

        for (int i = 0; i < x; i++) for (int j = 0; j < y; j++)
            scanf("%d", &z), num[z]++;

        priority_queue <pii> pq;
        for (int i = 1; i <= k; i++) pq.push(mp(-num[i], -i));

        int n = -pq.top().st, i = -pq.top().nd;
        printf("%d", i); pq.pop();
        while (!pq.empty()) {
            if (-pq.top().st != n) break;
            printf(" %d", -pq.top().nd); pq.pop();
        }
        printf("\n");
    }
    return 0;
}
