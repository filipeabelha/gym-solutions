#include <bits/stdc++.h>
using namespace std;

string st;

int main () {
    while(getline(cin, st)) {
        int upp = 0, low = 0, num = 0, ok = 1;
        int s = st.size();
        for (int i = 0; i < s; i++) {
            if (st[i] >= 'A' and st[i] <= 'Z') upp = 1;
            else if (st[i] >= 'a' and st[i] <= 'z') low = 1;
            else if (st[i] >= '0' and st[i] <= '9') num = 1;
            else ok = 0;
        }
        if (!upp or !low or !num) ok = 0;
        if (s < 6 or s > 32) ok = 0;
        printf("%s\n", (ok) ? "Senha valida." : "Senha invalida.");
    }
    return 0;
}
