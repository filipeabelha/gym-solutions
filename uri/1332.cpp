#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> word;
        while(1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            word.push_back(chr);
        }
        if (word.size() > 3) {
            printf("3\n");
            continue;
        } else {
            if ((word[0] == 111 and word[1] == 110) or
                    (word[0] == 111 and word[2] == 101) or
                    (word[1] == 110 and word[2] == 101))
                printf("1\n");
            else
                printf("2\n"); 
        }
    }
    return 0;
}
