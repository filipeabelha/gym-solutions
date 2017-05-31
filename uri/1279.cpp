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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

char y[10000];

int div3 () {
    int ans = 0;
    for (int i = 0; i < strlen(y); i++) ans += y[i] - '0';
    return !(ans % 3) ? 1 : 0;
}
int div4 () {
    int s = strlen(y)-1;
    int ans = y[s]-'0' + (y[s-1]-'0')*10 + (y[s-2]-'0')*100;
    return !(ans % 4) ? 1 : 0;
}
int div5 () {return (y[strlen(y)-1] == '5' or y[strlen(y)-1] == '0') ? 1 : 0;}
int div11 () {
    int ans = 0;
    for (int i = 0; i < strlen(y); i += 2) ans += y[i] - '0';
    for (int i = 1; i < strlen(y); i += 2) ans -= y[i] - '0';
    return !ans ? 1 : 0;
}
int div100() {
    int s = strlen(y)-1;
    return (y[s] == '0' and y[s-1] == '0') ? 1 : 0;
}
int div400() {
    int s = strlen(y)-1;
    int ans = y[s]-'0' + (y[s-1]-'0')*10 + (y[s-2]-'0')*100 + (y[s-3]-'0')*1000;
    return !(ans % 400) ? 1 : 0;
}

int lea () {
    if (div400()) return 1;
    if (div100()) return 0;
    if (div4()) return 1;
    return 0;
}

int hul () {return (div3() and div5()) ? 1 : 0;}
int bul () {return (div5() and div11() and lea()) ? 1 : 0;}
int odn () {return (!lea() and !hul() and !bul()) ? 1 : 0;}

int main () {
    int frst = 0, t; while (~scanf("%s", y)) {
        if (frst) printf("\n"); frst = 1;
        if (lea()) printf("This is leap year.\n");
        if (hul()) printf("This is huluculu festival year.\n");
        if (bul()) printf("This is bulukulu festival year.\n");
        if (odn()) printf("This is an ordinary year.\n");
    }
    return 0;
}
