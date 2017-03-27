#include <stdio.h>
#include <math.h>

float teste;
int ch[100000], i, n, mais, menos, s;

int main(){
    while (scanf("%d" , &n) != EOF) {
        s = mais = menos = 0;
        for(i = 0 ; i < n ; i++){
            scanf("%d" , &ch[i]);
            s += ch[i];
        }
        if(s%n > 0) printf("-1\n");
        else{
            teste = s/n;
            for(i = 0 ; i < n ; i++){
                if(ch[i] > teste) menos += ch[i]-teste;
            }
            printf("%d\n" , menos + 1);
        }
    }
    return 0;
}
