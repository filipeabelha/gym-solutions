#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2*n; i++) {
        vector <int> word;
        char chr;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            word.push_back(chr);
        }
        int desl;
        scanf("%d", &desl);
        for (int j = 0; j < word.size(); j++) {
            word[j] -= desl;
            if (word[j] < 65) word[j] += 26;
            if (word[j] > 90) word[j] -= 26;
            printf("%c", word[j]);
            if (j == word.size() - 1) printf("\n");
        }
    }
    return 0;
}
