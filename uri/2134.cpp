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
typedef pair<int, string> T;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, x, cnt;
char chr, w[50];

int main () {
    while (~scanf("%d%c", &n, &chr) and ++cnt) {
        priority_queue <T> pq;
        while (n--) scanf("%s %d%c", w, &x, &chr), pq.push(mp(-x, w));
        printf("Instancia %d\n%s\n\n", cnt, pq.top().nd.c_str());
    }
    return 0;
}