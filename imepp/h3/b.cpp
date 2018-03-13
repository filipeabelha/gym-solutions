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
const int N = 1e5+5;

struct point {
    int x, y;
};

point p[5];

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int sqdist (point a, point b) {
    return abs(a.y-b.y)*abs(a.y-b.y)+abs(a.x-b.x)*abs(a.x-b.x);
}

bool isTriangle (point a, point b, point c) {
    int A = sqdist(a, b);
    int B = sqdist(b, c);
    int C = sqdist(a, c);
    if (!A or !B or !C) return false;
    return true;
}

int r;

int main () {
    for (int i = 0; i < 3; i++) scanf("%d%d", &p[i].x, &p[i].y);
    if (sqdist(p[0], p[1]) == sqdist(p[0], p[2]) + sqdist(p[1], p[2])) r = 1;
    if (sqdist(p[0], p[2]) == sqdist(p[0], p[1]) + sqdist(p[1], p[2])) r = 1;
    if (sqdist(p[1], p[2]) == sqdist(p[0], p[1]) + sqdist(p[0], p[2])) r = 1;
    if (r) return printf("RIGHT\n"), 0;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            point q[5];
            q[k].x = p[k].x + dx[i];
            q[k].y = p[k].y + dy[i];
            for (int z = 0; z < 3; z++) if (z != k) {
                q[z].x = p[z].x;
                q[z].y = p[z].y;
            }
            if (!isTriangle(q[0], q[1], q[2])) continue;

            if (sqdist(q[0], q[1]) == sqdist(q[0], q[2]) + sqdist(q[1], q[2])) r = 1;
            if (sqdist(q[0], q[2]) == sqdist(q[0], q[1]) + sqdist(q[1], q[2])) r = 1;
            if (sqdist(q[1], q[2]) == sqdist(q[0], q[1]) + sqdist(q[0], q[2])) r = 1;
        }
    }
    if (r) return printf("ALMOST\n"), 0;
    printf("NEITHER\n");
    return 0;
}
