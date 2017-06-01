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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10, M = 2e2+10;

int n, m[N][M], cnt, k;
int ans, ansbuf, ansbgn, ansend;

void evl (int i, int buf, int bgn, int end) {
    int c1 = (buf > ansbuf);
    int c2 = (buf == ansbuf and end-bgn > ansend-ansbgn);
    int c3 = (buf == ansbuf and end-bgn == ansend-ansbgn and end > ansend);
    int c4 = (buf == ansbuf and end-bgn == ansend-ansbgn and end == ansend and i < ans);
    if (c1 or c2 or c3 or c4) {
        ans = i;
        ansbuf = buf;
        ansbgn = bgn;
        ansend = end;
    }
}

int main () {
    while (scanf("%d", &n) and n and ++cnt) {
        scanf("%d", &k);
        ans = INF, ansbuf = 1, ansbgn = 0, ansend = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= k; j++) scanf("%d", &m[i][j]);
        for (int i = 1; i <= n; i++) {
            int buf = 1;
            int bgn = m[i][1];
            int end = m[i][1];
            evl(i, buf, bgn, end);
            for (int j = 2; j <= k; j++) {
                if (m[i][j] > m[i][j-1]) {
                    buf++;
                    end = m[i][j];
                } else {
                    buf = 1;
                    bgn = m[i][j];
                    end = m[i][j];
                }
                evl(i, buf, bgn, end);
            }
        }
        printf("Instancia #%d\n%d\n\n", cnt, ans);
    }
    return 0;
}
