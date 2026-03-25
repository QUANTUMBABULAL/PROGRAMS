/*
Slavic is preparing a present for a friend's birthday. He has an array a
 of n
 digits and the present will be the product of all these digits. Because Slavic is a good kid who wants to make the biggest product possible, he wants to add 1
 to exactly one of his digits.

What is the maximum product Slavic can make?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤9
) — the number of digits.

The second line of each test case contains n
 space-separated integers ai
 (0≤ai≤9
) — the digits in the array.

Output
For each test case, output a single integer — the maximum product Slavic can make, by adding 1
 to exactly one of his digits.

Example
InputCopy
4
4
2 2 1 2
3
0 1 2
5
4 3 2 3 4
9
9 9 9 9 9 9 9 9 9
OutputCopy
16
2
432
430467210


*/


#include<stdio.h>
#include<limits.h>
int main(){

int t;
scanf("%d",&t);
for(int j=0;j<t;j++){
    int n,x,min;
    int prod=1;
    scanf("%d",&n);

    min=LLONG_MAX;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(i==0){min=x;}
        else if(x<min){
            prod=prod*min;
            min=x;
        }else {
            prod=prod*x;
        }
    }
    min++;
    prod=prod*min;
    printf("%d\n",prod);    
}
}
