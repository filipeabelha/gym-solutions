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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e4+5;

int t, n, ans, v[N];

void srt () {
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[mini]) mini = j;
        if (v[mini] != v[i]) ans++, swap(v[mini], v[i]);
    }
}

int main () {
    while (~scanf("%d", &t)) while (t--) {
        scanf("%d", &n);
        ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        srt();
        printf("%d\n", ans);
    }
    return 0;
}
