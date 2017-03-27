#include <bits/stdc++.h>
using namespace std;

int main () {
    while(1) {
        vector <int> str;
        char chr;
        int notloop = 1;
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (chrr == 10)
                break;
            chr = chrr;
            if (chr >= 65 and chr <= 77)
                chr += 13;
            else if (chr > 77 and chr <= 90)
                chr -= 13;
            else if (chr >= 97 and chr <= 109)
                chr += 13;
            else if (chr > 109 and chr <= 122)
                chr -= 13;
            str.push_back(chr);
        }
        for (int i = 0; i < str.size(); i++) {
            printf("%c", str[i]);
            notloop = 0;
        }
        if (notloop) break;
        printf("\n");
    }
    return 0;
}
