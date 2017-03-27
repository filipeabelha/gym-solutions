#include <bits/stdc++.h>

using namespace std;

int n, num;

int main () {
    while (scanf("%d", &n) != EOF) {
        int sti[30], fini[30];
        memset(sti, 0, sizeof(sti));
        memset(fini, 0, sizeof(fini));
        vector <int> st;
        vector <int> fin;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            st.push_back(num);
            sti[num] = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            fin.push_back(num);
            fini[num] = i;
        }
        while (1) {
            int change = 0;
            for (int i = 1; i < n; i++)
                if (st[i] < st[i-1]) {
                    int aux = st[i];
                    st[i] = st[i-1];
                    st[i-1] = aux;
                    int aux2 = fin[fini[st[i]]];
                    fin[fini[st[i]]] = fin[fini[st[i-1]]];
                    fin[fini[st[i-1]]] = aux2;
                    int aux3 = fini[st[i]];
                    fini[st[i]] = fini[st[i-1]];
                    fini[st[i-1]] = aux3;
                    change = 1;
                }
            if (!change) break;
        }
        int total = 0;
        while (1) {
            int change = 0;
            for (int i = 1; i < n; i++)
                if (fin[i] < fin[i-1]) {
                    int aux = fin[i];
                    fin[i] = fin[i-1];
                    fin[i-1] = aux;
                    total++;
                    change = 1;
                }
            if (!change) break;
        }
        printf("%d\n", total);
    }
    return 0;
}
