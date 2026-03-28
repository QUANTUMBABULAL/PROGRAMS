/*
A. Beautiful Year
time limit per test2 seconds
memory limit per test256 megabytes
It seems like the year of 2013 came only yesterday. Do you know a curious fact? The year of 2013 is the first year after the old 1987 with only distinct digits.

Now you are suggested to solve the following problem: given a year number, find the minimum year number which is strictly larger than the given one and has only distinct digits.

Input
The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

Output
Print a single integer — the minimum year number that is strictly larger than y and all it's digits are distinct. It is guaranteed that the answer exists.

Examples
InputCopy
1987
OutputCopy
2013
InputCopy
2013
OutputCopy
2014

*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if all digits of a 4-digit year are distinct
bool hasDistinctDigits(int year) {
    int a = year / 1000;          // Thousands place
    int b = (year / 100) % 10;    // Hundreds place
    int c = (year / 10) % 10;     // Tens place
    int d = year % 10;            // Units place

    // Compare every digit with every other digit
    if (a != b && a != c && a != d && 
        b != c && b != d && 
        c != d) {
        return true;
    }
    return false;
}

int main() {
    int y;
    if (scanf("%d", &y) != 1) return 0;

    // Start checking from the next year
    int nextYear = y + 1;
    
    while (true) {
        if (hasDistinctDigits(nextYear)) {
            printf("%d\n", nextYear);
            break;
        }
        nextYear++;
    }

    return 0;
}