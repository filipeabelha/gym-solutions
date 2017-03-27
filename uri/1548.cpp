#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        int res = 0;
        vector <int> fila;
        multiset <int> s;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            fila.push_back(x);
            s.insert(x);
        }
        vector <int> ord(s.begin(), s.end());
        reverse(fila.begin(), fila.end());
        for (int j = 0; j < ord.size(); j++)
            if (ord[j] == fila[j])
                res++;
        printf("%d\n", res);
    }
    return 0;
}
