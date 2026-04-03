/*
A teacher has recorded the marks of n students in a class. The marks are all whole numbers between 0 and 100. After the exam, the teacher receives q queries from the principal, each asking how many students scored between two values L and R (inclusive).

Since the teacher has a large class and receives many queries, she needs an efficient way to answer each one. Given the list of marks and the queries, help the teacher answer each query quickly.

Input Format

The first line contains two integers n and q, the number of students and the number of queries.

The second line contains n space-separated integers representing the marks of each student.

The next q lines each contain two integers L and R.

Constraints

1 ≤ n ≤ 10⁶

1 ≤ q ≤ 10⁵

0 ≤ marks[i] ≤ 100

0 ≤ L ≤ R ≤ 100

Output Format

For each query, print a single integer on a new line representing the number of students whose marks fall between L and R inclusive.

Sample Input 0

7 2
45 72 38 91 55 72 60
50 75
30 50
Sample Output 0

4
2
Explanation 0

For the query (50, 75), the marks within this range are 55, 60, 72, and 72, so the count is 4.
For the query (30, 50), the marks within this range are 38 and 45, so the count is 2.
Sample Input 1

5 3
10 20 30 40 50
10 50
20 40
60 100
Sample Output 1

5
3
0
Explanation 1

For the query (10, 50), all marks (10, 20, 30, 40, 50) fall within the range, so the count is 5.
For the query (20, 40), the marks within this range are 20, 30, and 40, so the count is 3.
For the query (60, 100), no marks fall within the range, so the count is 0.
Contest ends in 3 hours
Submissions: 47
Max Score: 20
Difficulty: Easy
Rate This Challenge:

    
More
 

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, q;
    int count;
    scanf("%d %d", &n, &q);

    int marks[1001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    for (int i = 0; i < q; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        count=0;
    for(int j=0;j<n;i++){
        if(marks[j]<=R &&marks[j]>=L){
            count++;
        }
    }
      printf("%d\n",count);
    }

    return 0;
}