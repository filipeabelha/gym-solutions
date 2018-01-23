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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e5+5;

int d, m, y, sz, ans;
string mo, ye;

int v[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
int day(int d, int m, int y) {
    y -= m<3;
    return (y + y/4 - y/100 + y/400 + v[m-1] + d)%7;
}

int main () {
    while (~scanf(" %d", &d)) {
        cin >> mo >> ye;
        sz = ye.size();
        y = 1000*(ye[sz-4]-'0')+100*(ye[sz-3]-'0')+10*(ye[sz-2]-'0')+(ye[sz-1]-'0');
        if (mo == "January")   m = 1;
        if (mo == "February")  m = 2;
        if (mo == "March")     m = 3;
        if (mo == "April")     m = 4;
        if (mo == "May")       m = 5;
        if (mo == "June")      m = 6;
        if (mo == "July")      m = 7;
        if (mo == "August")    m = 8;
        if (mo == "September") m = 9;
        if (mo == "October")   m = 10;
        if (mo == "November")  m = 11;
        if (mo == "December")  m = 12;
        ans = day(d, m, y);
        if (ans == 0) printf("Sunday\n");
        if (ans == 1) printf("Monday\n");
        if (ans == 2) printf("Tuesday\n");
        if (ans == 3) printf("Wednesday\n");
        if (ans == 4) printf("Thursday\n");
        if (ans == 5) printf("Friday\n");
        if (ans == 6) printf("Saturday\n");
    }
    return 0;
}
