#include <stdio.h>

long long A[100005];
long long B[100005];
long long M[100005];
long long a[100005];

void solve() {
    int n, k;
    long long p, q;
    if (scanf("%d %d %lld %lld", &n, &k, &p, &q) != 4) return;
    
    long long sumM = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        
        A[i] = a[i] % p;
        
        B[i] = (a[i] % q) % p;
        
        M[i] = A[i] < B[i] ? A[i] : B[i];
        sumM += M[i];
    }
    
   
    
    long long min_penalty = -1;
    
    long long current_PA = 0;
    for (int i = 0; i < k; i++) {
        current_PA += (A[i] - M[i]);
    }
    min_penalty = current_PA;
    
    for (int i = k; i < n; i++) {
        current_PA += (A[i] - M[i]);
        current_PA -= (A[i - k] - M[i - k]);
        if (current_PA < min_penalty) {
            min_penalty = current_PA;
        }
    }
    
    long long current_PB = 0;
    for (int i = 0; i < k; i++) {
        current_PB += (B[i] - M[i]);
    }
    if (current_PB < min_penalty) {
        min_penalty = current_PB;
    }
    
    for (int i = k; i < n; i++) {
        current_PB += (B[i] - M[i]);
        current_PB -= (B[i - k] - M[i - k]);
        if (current_PB < min_penalty) {
            min_penalty = current_PB;
        }
    }
    
    printf("%lld\n", sumM + min_penalty);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}