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

int a, b, cpf[20], s, bye;
char x;

int main () {
    while (1) {
        a = b = 0;
        for (int i = 1; i <= 9; i++) {
            if (scanf("%c", &x) == EOF) return 0;
            x -= '0';
            a += i*x;
            b += (10-i)*x;
            cpf[i] = x;
        }
        scanf("%c", &x);
        a %= 11; b %= 11;
        a %= 10; b %= 10;
        for (int i = 1; i <= 11; i++) {
            if (i % 4 == 0) printf(".");
            else printf("%d", cpf[i-i/4]);
        }
        printf("-%d%d\n", a, b);
    }
}
