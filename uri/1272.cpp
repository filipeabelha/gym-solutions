#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> msg;
        int lastchr = 32;
        while(1) {
            scanf("%c", &chr);
            if (chr == 10)
                break;
            else {
                if (lastchr == 32 and chr != 32) {
                    lastchr = chr;
                    msg.push_back(chr);
                } else {
                    lastchr = chr;
                    continue;
                }
            }
        }
        for (int j = 0; j < msg.size(); j++)
            printf("%c", msg[j]);
        printf("\n");
    }
    return 0;
}
