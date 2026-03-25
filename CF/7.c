/*
D. Monster Game
time limit per test2 seconds
memory limit per test256 megabytes
You have been gifted a new game called "Elatyh". In the game, you are given n
 swords, each with its own strength. In particular, the sword numbered i
 has a strength of ai
. The game consists of n
 levels, each of which features a monster.

You start at level 1
 and progress further. To pass level i
 and move on to level i+1
, you need to defeat the monster at level i
. To defeat the monster at level i
, you need to deal it bi
 sword strikes. The swords in the game are very fragile, so they can only deal one strike before breaking. If you complete level n
 or run out of swords, you can finish the game and proceed to score calculation.

Before the game, you are allowed to choose the difficulty level. If you choose difficulty x
, swords with a strength less than x
 will not affect the monsters. The game score in this case is equal to x
 multiplied by the number of levels completed. Your task is to choose the game difficulty in such a way as to maximize the game score.

Input
Each test consists of several test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The following describes the test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
).

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109)
.

The third line of each test case contains n
 integers b1,b2,…,bn
 (1≤bi≤n)
.

It is guaranteed that the sum of the values of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the maximum game score.
*/