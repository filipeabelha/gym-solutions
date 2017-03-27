#include <bits/stdc++.h>

using namespace std;

int main () {
    char b[][5][5] = {
        {".*", "**", ".."},
        {"*.", "..", ".."},
        {"*.", "*.", ".."},
        {"**", "..", ".."},
        {"**", ".*", ".."},
        {"*.", ".*", ".."},
        {"**", "*.", ".."},
        {"**", "**", ".."},
        {"*.", "**", ".."},
        {".*", "*.", ".."},
    };
    while (1) {
        int d;
        scanf("%d", &d);
        if (d == 0) break;

        char chr;
        scanf("%c", &chr);
        scanf("%c", &chr);

        if (chr == 'S') {
            scanf("%c", &chr);
            vector <int> num;
            for (int i = 0; i < d; i++) {
                scanf("%c", &chr);
                num.push_back(chr-48);
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < d; j++) {
                    printf("%s", b[num[j]][i]);
                    if (j != d-1) printf(" "); else printf("\n");
                }
            }
        } else {
            char inp[105][5][5];
            for (int j = 0; j < 3; j++) for (int i = 0; i < d; i++)
                    scanf("%s", inp[i][j]);
            vector <int> prnt;
            for (int i = 0; i < d; i++) {
                int resp = -1;
                for (int j = 0; j < 10; j++) {
                    if (strcmp(b[j][0], inp[i][0]) == 0 and
                        strcmp(b[j][1], inp[i][1]) == 0 and
                        strcmp(b[j][2], inp[i][2]) == 0)
                    resp = j;
                }
                prnt.push_back(resp);
            }
            for (int i = 0; i < d; i++)
                printf("%d", prnt[i]);
            printf("\n");
        }
    }
    return 0;
}
