#include <bits/stdc++.h>
using namespace std;

int c, n, c1_isltr, c2_isltr, ch1, ch2;
string c1, c2, msg;
char chr;
map <char, char> m;

int main () {
    while(~scanf("%d%d%c", &c, &n, &chr)) {
        m.clear();
        getline(cin, c1);
        getline(cin, c2);
        for (int i = 0; i < c; i++) {
            c1_isltr = c2_isltr = 0;
            if (c1[i] >= 'A' and c1[i] <= 'Z') c1_isltr = 1;
            if (c2[i] >= 'A' and c2[i] <= 'Z') c2_isltr = 1;
            ch1 = c1[i]; ch2 = c2[i];
            m[ch1] = ch2; m[ch2] = ch1;
            ch1 += c1_isltr*32; ch2 += c2_isltr*32;
            m[ch1] = ch2; m[ch2] = ch1;
        }
        while (n--) {
            getline(cin, msg);
            for (int i = 0; i < msg.size(); i++)
                printf("%c", m.count(msg[i]) ? m[msg[i]] : msg[i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
