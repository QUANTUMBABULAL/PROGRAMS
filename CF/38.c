/*
A. Divisibility Problem
time limit per test1 second
memory limit per test256 megabytes
You are given two positive integers a
 and b
. In one move you can increase a
 by 1
 (replace a
 with a+1
). Your task is to find the minimum number of moves you need to do in order to make a
 divisible by b
. It is possible, that you have to make 0
 moves, as a
 is already divisible by b
. You have to answer t
 independent test cases.

Input
The first line of the input contains one integer t
 (1≤t≤104
) — the number of test cases. Then t
 test cases follow.

The only line of the test case contains two integers a
 and b
 (1≤a,b≤109
).

Output
For each test case print the answer — the minimum number of moves you need to do in order to make a
 divisible by b
.

Example
InputCopy
5
10 4
13 9
100 13
123 456
92 46
OutputCopy
2
5
4
333
0
*/


#include<stdio.h>
// int main(){
//     int t,a,b,count;
//     scanf("%d",&t);
//     while(t--){
//         count=0;
//         scanf("%d %d",&a,&b);
//         while(a%b!=0){
//             a+=1;
//             count++;
//         }
//         printf("%d\n",count);
//     }
// }
// int main(){

//     int t,a,b,temp;
//     scanf("%d",&t);
//     while(t--){
//         scanf("%d %d",&a,&b);
//         int i=2;
//         temp=b;
//         while(a>b){
//             b=temp*i;
//             i++;
//         }
//         printf("%d\n",b-a);
//     }
// }


int main(){

    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",(b-a%b)%b);
        
    }
}