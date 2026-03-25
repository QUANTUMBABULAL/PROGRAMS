#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    while(k--) {
    int n;
    scanf("%d", &n);

    int freq[10001] = {0}; 
    int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);

                freq[x]++;

                if (freq[x] > maxi) {
                    maxi = freq[x];
                }
            }
        }

        if (maxi > n)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}