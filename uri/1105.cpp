#include <bits/stdc++.h>
using namespace std;

int main () {
        while (1) {
                vector<int> s;
                s.push_back(0);

                int b, n;
                scanf("%d%d", &b, &n);
                if (b == 0 and n == 0) break;

                for (int i = 1; i <= b; i++) {
                        int ss; // saldo
                        scanf("%d", &ss);
                        s.push_back(ss);
                }

                for (int i = 1; i <= n; i++) {
                        int dev, cre, deb; // devedor, credor, debenture
                        scanf("%d%d%d", &dev, &cre, &deb);
                        s[dev] -= deb;
                        s[cre] += deb;
                }

                int ok = 1;
                for (int i = 1; i < s.size(); i++) if (s[i] < 0) ok = 0;
                if (ok) printf("S\n"); else printf("N\n");
        }
        return 0;
}
