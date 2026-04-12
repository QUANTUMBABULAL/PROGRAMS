#include <stdio.h>

void solve() {
    unsigned long long n;
    if (scanf("%llu", &n) != 1) return;

    unsigned long long ans = 0;

    // 1. Divisor method for exact cases where k = 1 and p = 2
    // We look for divisors x such that x = b + 1.
    for (unsigned long long x = 1; x * x <= n; x++) {
        if (n % x == 0) {
            unsigned long long y = n / x;

            // Check if divisor x can act as (b + 1)
            if (x >= 3) {
                if (y <= x - 2) {
                    ans++;
                }
            }

            // Check if divisor y can act as (b + 1)
            if (y != x && y >= 3) {
                if (x <= y - 2) {
                    ans++;
                }
            }
        }
    }

    // 2. Loop for other (b, p) combinations where b <= sqrt(n)
    for (unsigned long long b = 2; b * b <= n; b++) {
        unsigned long long R = 1 + b;
        unsigned long long B = b * b;
        int p = 2;

        while (R <= n) {
            if (n % R == 0) {
                unsigned long long M = n / R;
                
                // Skip k=1, p=2 combinations as they were already counted in Step 1
                if (!(p == 2 && M < b)) {
                    unsigned long long tempM = M;
                    int ok = 1;
                    
                    // Verify that all blocks (digits of M in base B) are strictly < b
                    while (tempM > 0) {
                        if (tempM % B >= b) {
                            ok = 0;
                            break;
                        }
                        tempM /= B;
                    }
                    if (ok) {
                        ans++;
                    }
                }
            }

            // Safeguard to prevent calculation overflow in the next iteration 
            // of R = R * b + 1 and B = B * b
            if (n / b < R) {
                break;
            }
            
            R = R * b + 1;
            B = B * b;
            p++;
        }
    }

    printf("%llu\n", ans);
}

int main() {
    int t;
    // Fast I/O is not strictly necessary for 1000 items, but scanf is efficient.
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}