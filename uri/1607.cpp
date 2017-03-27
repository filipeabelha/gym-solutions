#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> word1;
        vector <int> word2;
        int sum = 0;
        while (1) {
            scanf("%c", &chr);
            if (chr == 32) break;
            word1.push_back(chr);
        }
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            word2.push_back(chr);
        }
        for (int j = 0; j < word1.size(); j++) {
            int diff = word2[j] - word1[j];
            if (diff < 0) diff += 26;
            sum += diff;
        }
        printf("%d\n", sum);
    }
    return 0;
}
