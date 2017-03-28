#include <bits/stdc++.h>

using namespace std;

int main () {
    vector <int> a;
    vector <int> b;

    while (1) {
        char chr;
        scanf("%c", &chr);
        if (chr == 32) break;
        a.push_back(chr);
    }
    while(1) {
        char chr;
        scanf("%c", &chr);
        if (chr == 10) break;
        b.push_back(chr);
    }
    int equal = 1;
    if (a.size() != b.size())
        equal = 0;
    else for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            equal = 0;
    }
    if (!equal) printf("1\n"); else {
        for (int i = 0; i < a.size(); i++)
            printf("%c", a[i]);
        printf("\n");
    }
    return 0;
}
