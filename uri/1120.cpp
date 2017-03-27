#include <bits/stdc++.h>
using namespace std;

int main () {
    while (1) {
        vector <int> num;
        int n;
        scanf("%d", &n);
        char chr;
        scanf("%c", &chr);
        int brk = 0;
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (num.size() == 0 and chrr == 48 and n == 0) {
                brk = 1;
                break;
            }
            if (chrr == 10) {
                break;
            } else {
                chr = chrr;
                if (chr != n+48)
                    num.push_back(chr);
            }
        }
        if (brk) break;
        if (num.size() == 0) {
            printf("0\n");
            continue;
        } else {
            while (num[0] == 48 and num.size() > 1)
                num.erase(num.begin());
            for (int j = 0; j < num.size(); j++)
                printf("%c", num[j]);
        }
        printf("\n");
    }
    return 0;
}
