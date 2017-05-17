#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main () {
    while (1) {
        cin >> s;
        int sz = s.size();
        ll n = 0;
        ll factor = 1;
        if (sz > 1 and s[1] == 'x'){
            s.erase(0,2);
            sz = s.size();
            for (int i = 0; i < sz; i++) {
                int x = s[sz-i-1];
                x -= 48;
                if (x > 10) x -= 7;
                if (x > 40) x -= 32;
                n += factor*x;
                factor *= 16;
            }
            printf("%lld\n", n);
        } else {
            try {
                n = stoi(s);
            } catch (...) {
                n = 2147483648;
            }
            if (n == -1) break;
            printf("0x");
            if (n == 0) printf("0");
            while (factor*16 <= n) factor *= 16;
            while (factor > 0) {
                int add = (n / factor);
                if (add == 10) printf("A");
                else if (add == 11) printf("B");
                else if (add == 12) printf("C");
                else if (add == 13) printf("D");
                else if (add == 14) printf("E");
                else if (add == 15) printf("F");
                else printf("%d", add);
                n -= add*factor;
                factor /= 16;
            }
            printf("\n");
        }
    }
}
