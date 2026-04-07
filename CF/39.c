/*
E. Definitely Larger
time limit per test2 seconds
memory limit per test256 megabytes
You are given a permutation p

∗
 of integers from 1
 to n
.
For an arbitrary permutation q
 of length n
, we say that index j
 dominates index i
 if and only if all of the following conditions hold:
j>i
,
p
j
>p
i
, and
q
j
>q
i
.
You are also given an array d
 of length n
, where d
i
 denotes the number of indices that dominate index i
.
Your task is to construct a permutation q
 of integers from 1
 to n
 such that for every index i
 (1≤i≤n
), the number of indices j
 that dominate i
 is exactly d
i
.
If such q
 exists, output any valid one. Otherwise, report that it does not exist.

∗
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).
Input

Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.
The first line of each test case contains an integer n
 (1≤n≤5000
).
The second line of each test case contains n
 integers p
1
,p
2
,…,p
n
. It is guaranteed that p
 forms a permutation of integers from 1
 to n
.
The third line of each test case contains n
 integers d
1
,d
2
,…,d
n
 (0≤d
i
≤n
).
It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.
Output

For each test case:
If it is possible to construct q
, output a line containing n
 integers q
1
,q
2
,…,q
n
 — a valid permutation. If multiple valid answers exist, you may output any of them.
Otherwise, output −1
.
Example
InputCopy
7
3
2 3 1
1 0 0
4
3 4 1 2
2 1 1 0
5
2 3 1 4 5
2 2 1 1 0
1
1
0
5
3 1 4 2 5
1 1 1 1 0
4
3 4 2 1
1 1 1 0
8
7 6 3 1 2 5 4 8
1 1 2 2 2 1 1 0
OutputCopy
1 2 3
-1
2 1 4 3 5
1
2 4 1 3 5
-1
1 2 4 6 5 3 7 8
Note

In the first test case, a valid output is q=[1,2,3]
:
For i=1
, we have p
1
=2
 and q
1
=1
. The index j=2
 dominates i=1
 because 2>1
, p
2
=3>p
1
, and q
2
=2>q
1
. Index j=3
 does not dominate i=1
 because p
3
=1<p
1
. Thus, exactly 1
 index dominates i=1
, which matches d
1
=1
.
For i=2
, we have p
2
=3
 and q
2
=2
. The only larger index is j=3
, but p
3
=1<p
2
, so it does not dominate. Thus, 0
 indices dominate i=2
, matching d
2
=0
.
For i=3
, there are no larger indices j>3
, so 0
 indices dominate, matching d
3
=0
.
In the second test case, p=[3,4,1,2]
 and d=[2,1,1,0]
. Let's look at i=2
, where p
2
=4
. Since there is no index j>2
 with p
j
>p
2
, no index can dominate i=2
. However, the array d
 requires d
2
=1
, which makes it impossible to construct a valid permutation q
. Hence, the answer is -1.
*/


#include <stdio.h>
#include <stdbool.h>

#define MAXN 5005

int p[MAXN];
int d[MAXN];
int cur[MAXN];
int q[MAXN];
bool active[MAXN];

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);

    // Initial calculation of potential dominators (j > i and pj > pi)
    for (int i = 1; i <= n; i++) {
        cur[i] = 0;
        active[i] = true;
        for (int j = i + 1; j <= n; j++) {
            if (p[j] > p[i]) {
                cur[i]++;
            }
        }
    }

    // Assign values 1 to n greedily
    for (int v = 1; v <= n; v++) {
        int best_i = -1;

        for (int i = 1; i <= n; i++) {
            if (active[i] && cur[i] == d[i]) {
                // If multiple candidates, pick the one with the smallest p[i]
                if (best_i == -1 || p[i] < p[best_i]) {
                    best_i = i;
                }
            }
        }

        // If no index can satisfy its di requirement with remaining elements
        if (best_i == -1) {
            printf("-1\n");
            return;
        }

        q[best_i] = v;
        active[best_i] = false;

        // Since best_i is now "taken" by a smaller q value (v),
        // it can no longer dominate any index k to its left.
        for (int k = 1; k < best_i; k++) {
            if (active[k] && p[k] < p[best_i]) {
                cur[k]--;
            }
        }
    }

    // Output the constructed permutation q
    for (int i = 1; i <= n; i++) {
        printf("%d%c", q[i], (i == n ? '\n' : ' '));
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}