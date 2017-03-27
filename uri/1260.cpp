#include <bits/stdc++.h>

using namespace std;

int n, total;
char chr;

int main () {
    scanf("%d", &n);
    scanf("%c", &chr);
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        map <string, int> pct;
        total = 0;
        while(1) {
            char name[30];
            if (gets(name) == NULL) break;
            if (strlen(name) == 0) break;
            pct[name]++;
            total++;
        }
        for (map <string, int>::iterator it = pct.begin(); it != pct.end(); ++it) {
            printf("%s %.4f\n", it->first.c_str(), (float)100*it->second/total);
        }
        if (i != n-1) printf("\n");
    }
    return 0;
}
