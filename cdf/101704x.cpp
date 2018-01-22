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

set<int> s,t;

int main () {

    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        s.insert(x);
        t.insert(-x);
    }
    if(n%2==0) 
    {
        for(set<int>::iterator it=t.begin();it!=t.end();++it)
            cout << *it*(-1) << "\n";
    }
    else
    {
        for(set<int>::iterator it=s.begin();it!=s.end();++it)
            cout << *it << "\n";
    }
    return 0;
}
