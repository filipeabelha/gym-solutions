#include <bits/stdc++.h>

using namespace std;

int n;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        vector <int> discarded;
        queue <int> cards;
        for (int i = 1; i <= n; i++) cards.push(i);
        while (cards.size() > 1) {
           discarded.push_back(cards.front());
           cards.pop();
           cards.push(cards.front());
           cards.pop();
        }
        printf("Discarded cards: ");
        for (int i = 0; i < discarded.size(); i++) {
            printf("%d", discarded[i]);
            if (i != discarded.size()-1) printf(", ");
            else printf("\n");
        }
        printf("Remaining card: %d\n", cards.front());
    }   
    return 0;
}
