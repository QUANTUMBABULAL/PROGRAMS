#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        long long c, k;
        scanf("%d %lld %lld", &n, &c, &k);

        long long a[105];

        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
        }

        qsort(a, n, sizeof(long long), cmp);

        for(int i = 0; i < n; i++){
            if(a[i] <= c){
                long long use = k;
                a[i] += use;
                k -= use;

                c += a[i];
            } else {
                break;
            }
        }

        printf("%lld\n", c);
    }

    return 0;
}