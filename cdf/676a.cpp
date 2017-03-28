#include <bits/stdc++.h>

using namespace std;

int num[150];

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    int maxi = 0, mini = 150, imaxi, imini;
    for (int i = 0; i < n; i++) {
        if (num[i] > maxi) maxi = num[i], imaxi = i;
        if (num[i] < mini) mini = num[i], imini = i;
    }
    printf("%d\n", max(n-min(imaxi, imini)-1, max(imaxi, imini)));
    return 0;
}
