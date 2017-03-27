#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > m;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        m.clear();
        printf("Instancia %d\n", i+1);
        for (int j = 0; j < 9; j++) {
            vector <int> l;
            for (int k = 0; k < 9; k++) {
                int x;
                scanf("%d", &x);
                l.push_back(x);
            }
            m.push_back(l);
        }
        bool valid = true;
        for (int j = 0; j < 9; j++) {
            int freq[15];
            memset(freq, 0, sizeof(freq));
            for (int k = 0; k < 9; k++) {
                freq[m[j][k]]++;
                if(freq[m[j][k]] > 1) valid = false;
            }
        }
        for (int k = 0; k < 9; k++) {
            int freq[15];
            memset(freq, 0, sizeof(freq));
            for (int j = 0; j < 9; j++) {
                freq[m[j][k]]++;
                if(freq[m[j][k]] > 1) valid = false;
            }
        }
        for (int x = 0; x < 9; x += 3) for (int y = 0; y < 9; y += 3) {
            int freq[15];
            memset(freq, 0, sizeof(freq));
            for (int j = x; j < x+3; j++) for (int k = y; k < y+3; k++) {
                freq[m[j][k]]++;
                if(freq[m[j][k]] > 1) valid = false;
            }
        }
        if (valid) printf("SIM\n");
        else printf("NAO\n");
        printf("\n");
    }
    return 0;
}
