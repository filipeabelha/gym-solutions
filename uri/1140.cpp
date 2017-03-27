#include <bits/stdc++.h>

int main () {
    char chr;
    while (1) {
        scanf("%c", &chr);
        char st = chr;
        if (st == '*') break;
        bool alit = true;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            if (chr == 32) {
                scanf("%c", &chr);
                if (chr != st and chr != st+32 and chr != st-32)
                    alit = false;
            }
        }
        if (alit) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

