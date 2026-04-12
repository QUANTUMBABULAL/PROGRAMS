#include <stdio.h>

void solve() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return;

    int a[25]; 
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
    }

    int b[55];      
    int cnt[25] = {0}; 
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (b[i] <= k) {
            cnt[b[i]]++;
        }
    }

    int ops[1005];
    int op_count = 0;

    while (1) {
        int moved = 0;

        for (int lv = k; lv >= 1; lv--) {
            for (int i = 1; i <= n; i++) {
                if (b[i] == lv) {

                    if (lv == k || cnt[lv + 1] < a[lv + 1]) {
                        // Perform the move
                        cnt[lv]--;
                        b[i]++;
                        if (b[i] <= k) {
                            cnt[b[i]]++;
                        }
                        
                        ops[op_count++] = i;
                        moved = 1;
                        break; 
                    }
                }
            }
            if (moved) break; 
        }

        if (!moved) break;
    }

    // Output the results
    printf("%d\n", op_count);
    for (int i = 0; i < op_count; i++) {
        printf("%d%c", ops[i], (i == op_count - 1 ? '\n' : ' '));
    }
    if (op_count == 0) printf("\n");
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}