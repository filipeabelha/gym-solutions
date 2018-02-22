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

int n;
string s;

bool isVowel (char c) {
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    if (c == 'y') return true;
    return false;
}


bool del () {
    for (int i = 1; i < s.size(); i++) {
        if (isVowel(s[i]) and isVowel(s[i-1])) {
            s.erase(s.begin()+i);
            return true;
        }
    }
    return false;
}

int main () {
    scanf("%d ", &n);
    cin >> s;
    while (del());
    cout << s << endl;
    return 0;
}
