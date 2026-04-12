#include <stdio.h>

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

void solve() {
    long long ct, ch, cu;
    scanf("%lld %lld %lld", &ct, &ch, &cu);


    long long ans = 3 * ch + 3 * cu + 2 * ct - min(ct, cu);

    if (ch == 0 && cu == 0 && ct > 1) {
        ans++;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}