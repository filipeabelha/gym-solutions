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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char chr;

int main () {
    while (1) {
        int ans = 0;
        scanf("%c", &chr);
        if (chr == '*') break;
        while (1) {
            int len = 0;
            int brk = 0;
            while (1) {
                scanf("%c", &chr);
                if (chr == '/') break;
                if (chr == '\n') {brk = 1; break;}
                if (chr == 'W') len += 64;
                if (chr == 'H') len += 32;
                if (chr == 'Q') len += 16;
                if (chr == 'E') len += 8;
                if (chr == 'S') len += 4;
                if (chr == 'T') len += 2;
                if (chr == 'X') len += 1;
            }
            if (len == 64) ans++;
            if (brk) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
