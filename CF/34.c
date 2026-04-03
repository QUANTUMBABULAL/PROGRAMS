/*
A. I Wanna Be the Guy
time limit per test1 second
memory limit per test256 megabytes
There is a game called "I Wanna Be the Guy", consisting of n levels. Little X and his friend Little Y are addicted to the game. Each of them wants to pass the whole game.

Little X can pass only p levels of the game. And Little Y can pass only q levels of the game. You are given the indices of levels Little X can pass and the indices of levels Little Y can pass. Will Little X and Little Y pass the whole game, if they cooperate each other?

Input
The first line contains a single integer n (1 ≤  n ≤ 100).

The next line contains an integer p (0 ≤ p ≤ n) at first, then follows p distinct integers a1, a2, ..., ap (1 ≤ ai ≤ n). These integers denote the indices of levels Little X can pass. The next line contains the levels Little Y can pass in the same format. It's assumed that levels are numbered from 1 to n.

Output
If they can pass all the levels, print "I become the guy.". If it's impossible, print "Oh, my keyboard!" (without the quotes).

Examples
InputCopy
4
3 1 2 3
2 2 4
OutputCopy
I become the guy.
InputCopy
4
3 1 2 3
2 2 3
OutputCopy
Oh, my keyboard!
Note
In the first sample, Little X can pass levels [1 2 3], and Little Y can pass level [2 4], so they can pass all the levels both.

In the second sample, no one can pass level 4.


*/


#include <stdio.h>

int main() {
    int n, p, q, level;
    // levels array to keep track of which levels are covered
    // size 101 because levels are 1-indexed up to 100
    int levels[101] = {0};
    int count = 0;

    // Read total number of levels
    if (scanf("%d", &n) != 1) return 0;

    // Read Little X's levels
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &level);
        if (levels[level] == 0) {
            levels[level] = 1;
            count++;
        }
    }

    // Read Little Y's levels
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &level);
        if (levels[level] == 0) {
            levels[level] = 1;
            count++;
        }
    }

    // If the count of unique levels covered equals n, they pass
    if (count == n) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }

    return 0;
}