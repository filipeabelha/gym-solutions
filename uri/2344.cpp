#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; scanf("%d", &n);
    printf("%c\n", n>85?'A':n>60?'B':n>35?'C':n?'D':'E');
    return 0;
}
