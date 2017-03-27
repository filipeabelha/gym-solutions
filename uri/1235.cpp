#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> word;
        vector <int> result;
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (chrr == 10)
                break;
            else {
                chr = chrr;
                word.push_back(chr);
            }
        }
        for (int j = 0; j < word.size()/2; j++)
            result.push_back(word[word.size()/2-1-j]);
        for (int j = 0; j < word.size()/2; j++)
            result.push_back(word[word.size()-1-j]);
        for (int j = 0; j < result.size(); j++)
            printf("%c", result[j]);
        printf("\n");
    }
    return 0;
}
