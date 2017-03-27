#include <bits/stdc++.h>
using namespace std;
int sc;
int main () {
    multiset <int> s;
    vector <int> k1, k2, k3, k4, k5;
    vector <vector <int> > v;
    int x1, x2, x3, x4, x5;
    scanf("%d", &x1);
    for (int i = 0; i < x1; i++) scanf("%d", &sc), k1.push_back(sc);
    v.push_back(k1);
    scanf("%d", &x2);
    for (int i = 0; i < x2; i++) scanf("%d", &sc), k2.push_back(sc);
    v.push_back(k2);
    scanf("%d", &x3);
    for (int i = 0; i < x3; i++) scanf("%d", &sc), k3.push_back(sc);
    v.push_back(k3);
    scanf("%d", &x4);
    for (int i = 0; i < x4; i++) scanf("%d", &sc), k4.push_back(sc);
    v.push_back(k4);
    scanf("%d", &x5);
    for (int i = 0; i < x5; i++) scanf("%d", &sc), k5.push_back(sc);
    v.push_back(k5);
    for (int a = 0; a < v[0].size(); a++)
    for (int b = 0; b < v[1].size(); b++)
    for (int c = 0; c < v[2].size(); c++)
    for (int d = 0; d < v[3].size(); d++)
    for (int e = 0; e < v[4].size(); e++)
        s.insert(v[0][a]+v[1][b]+v[2][c]+v[3][d]+v[4][e]);
    vector <int> val(s.begin(), s.end());
    reverse(val.begin(), val.end());
    int sum = 0, z;
    scanf("%d", &z);
    for (int i = 0; i < z; i++) sum += val[i];
    printf("%d\n", sum);
    return 0;
}
