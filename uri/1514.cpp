#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    while (1) {
        scanf("%d%d", &n, &m);
        if (n == 0 and m == 0) break;
        vector <vector <int> > mat;
        for (int i = 0; i < n; i++) {
            vector <int> line;
            for (int j = 0; j < m; j++) {
                int num;
                scanf("%d", &num);
                line.push_back(num);
            }
            mat.push_back(line);
        }
        int car = 0;
        int bonus = 0;
        // Ninguem fez todas
        bonus = 1;
        for (int i = 0; i < n; i++) {
            int feztodas = 1;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) feztodas = 0;
            }
            if (feztodas) bonus = 0;
        }
        if (bonus) car++;
        // Todos fizeram alguma
        bonus = 1;
        for (int i = 0; i < n; i++) {
            int feznada = 1;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) feznada = 0;
            }
            if (feznada) bonus = 0;
        }
        if (bonus) car++;
        // Todas foram resolvidas
        bonus = 1;
        for (int j = 0; j < m; j++) {
            int ninguemfez = 1;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 1) ninguemfez = 0;
            }
            if (ninguemfez) bonus = 0;
        }
        if (bonus) car++;
        // Nenhuma foi completamente acertada
        bonus = 1;
        for (int j = 0; j < m; j++) {
            int geralacertou = 1;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 0) geralacertou = 0;
            }
            if (geralacertou) bonus = 0;
        }
        if (bonus) car++;
        printf("%d\n", car);
    }
    return 0;
}
