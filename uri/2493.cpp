#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int t, x, ok, m[55][5];
char player[60], chr;
vector <string> v;

int main () {
    while (~scanf("%d", &t)) {
        for (int i = 1; i <= t; i++)
            scanf("%d %d=%d", &m[i][1], &m[i][2], &m[i][3]);
        for (int i = 1; i <= t; i++) {
            ok = 0;
            scanf("%s %d %c", player, &x, &chr);
            if (chr == '*' and m[x][1]*m[x][2]==m[x][3]) ok = 1;
            if (chr == '+' and m[x][1]+m[x][2]==m[x][3]) ok = 1;
            if (chr == '-' and m[x][1]-m[x][2]==m[x][3]) ok = 1;
            if (chr == 'I') {
                if (m[x][1]*m[x][2]!=m[x][3] and
                    m[x][1]+m[x][2]!=m[x][3] and
                    m[x][1]-m[x][2]!=m[x][3]) ok = 1;
            }
            if (!ok) v.pb(player);
        }
        if (!v.size()) printf("You Shall All Pass!\n");
        else if (v.size() == t) printf("None Shall Pass!\n");
        else {
            sort(v.begin(), v.begin()+v.size());
            for (int i = 0; i < v.size(); i++)
                printf("%s%s", v[i].c_str(), i < v.size()-1 ? " " : "\n");
        }
        v.clear();
    }
    return 0;
}
