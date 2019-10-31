#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int v[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

int day(int d, int m, int y) {
    y -= m<3;
    return (y + y/4 - y/100 + y/400 + v[m-1] + d)%7;
}

string day2 (int d, int m, int y) {
    int ans = day(d, m, y);
    if (ans == 0) return "Sunday";
    if (ans == 1) return "Monday";
    if (ans == 2) return "Tuesday";
    if (ans == 3) return "Wednesday";
    if (ans == 4) return "Thursday";
    if (ans == 5) return "Friday";
    if (ans == 6) return "Saturday";
}

int x;

int main () {
    cin >> x;
    cout << day2(22, 9, x+1867) << endl;
    return 0;
}
