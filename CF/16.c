/*
E. Counting Cute Arrays
time limit per test2 seconds
memory limit per test512 megabytes
Let [A1,A2,…,An]
 be an array of n
 positive integers. Define array f(A)
 as followed:

For each integer i
 from 1
 to n
:

If there exists integer j
 such that j<i
 and Aj<Ai
, f(A)i=maxj<i,Aj<Aij
. That is, f(A)i
 is the index of the rightmost element before i
 whose value is strictly smaller than Ai
.
Otherwise f(A)i=0
.
We call the array [P1,P2,…,Pn]
 of non-negative integers a cute array if there exists an array A
 such that f(A)=P
.

Given a length n
 array X
 in which −1≤Xi≤n
 holds for all i
 from 1
 to n
. Count the numbers of cute arrays X′
 formed by replacing the −1
s in X
 with integers from 0
 to n
. As the number can be very large, print it modulo 998244353
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤103
). The description of the test cases follows.

The first line of each test cases contain an integer n
 (1≤n≤5000
) denoting the length of X
.

The second line contain n
 integers X1,X2,…,Xn
 (−1≤Xi≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test cases, output a single integer denoting the number of arrays X′
 such that X′
 is a cute array, modulo 998244353
.

Example
InputCopy
6
3
-1 0 -1
4
-1 -1 1 -1
5
-1 -1 -1 -1 -1
4
-1 0 2 3
4
1 1 2 3
4
0 0 0 1
OutputCopy
2
3
42
1
0
0
Note
For the first test case, only [0,0,0]
 and [0,0,2]
 are cute arrays among all possible X′
. [0,0,0]
 is a good cute array because f([1,1,1])=[0,0,0]
, and [0,0,2]
 is a good array because f([1,1,2])=[0,0,2]
.

For the second test case, only [0,1,1,0]
, [0,1,1,1]
 and [0,1,1,3]
 are cute arrays among all possible X′
.



*/