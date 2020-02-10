#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int st[4*N], v[N],  memo[N];

void build(int p, int l, int r){
    if(l == r) {st[p] = v[l]; return;}
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1,r);
    st[p] = st[2*p] ^ st[2*p+1];
}

int query(int p, int l, int r, int i, int j){
    if(r < i or j < l) return 0;
    if(i<=l and r<=j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x^y;
}

void update(int p, int l, int r, int x, int v){
    if(x < l or r < x) return;
    if(l == r and l == x){ st[p] = v; return;}
    update(2*p, l, (l+r)/2,x,v);
    update(2*p+1, (l+r)/2+1,r,x,v);
    if(l!=r) st[p] = st[2*p] ^ st[2*p+1];
}

int grundy (int x){
    if (~memo[x]) return memo[x];

    int s[5][5];
    memset(s, 0, sizeof s);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (x&(1<<(4*i+j))) {
                s[i+1][j+1] = 1;
            }

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    int reachable[100];
    memset(reachable, 0, sizeof reachable);

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            for (int a = i; a <= 4; a++)
                for (int b = j; b <= 4; b++)
                    if (s[a][b] - s[i-1][b] - s[a][j-1] + s[i-1][j-1] == (a-i+1)*(b-j+1)) {
                        int y = x;
                        for (int k = i-1; k < a; k++) {  
                            y -= (1 << (4*k+b));
                            y += (1 << (4*k+j-1));
                        }
                        reachable[grundy(y)] = 1;
                    }
    
    for (int i = 0; ; i++) if (!reachable[i]) return memo[x] = i;
}

int getNum () {
    int ans = 0;
    string s;
    for(int j = 0;j < 4;j++){
        cin >> s;
        for(int k = 0; k < 4; k++){
            if(s[k]-'0'){
                ans += (1<<(4*j+k));
            }
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(memo, -1, sizeof memo);
    memo[0] = 0;

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            v[i] = grundy(getNum());
        }

        build(1, 1, n);

        while (m--) {
            int op,l,r,pos;
            cin >> op;
            if(op == 1){
                cin >> l >> r;
                int q = query(1, 1, n, l, r);
                cout << (q == 0 ? "Lotsy\n" : "Pishty\n");
            }
            if(op == 2){
                cin >> pos;
                update(1, 1, n, pos, grundy(getNum()));
            }
        }
    }

    return 0;
}
