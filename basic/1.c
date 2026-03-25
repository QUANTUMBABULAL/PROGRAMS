/*
Given an array of integers nums, return the value of the largest element in the array


Example 1

Input: nums = [3, 3, 6, 1]

Output: 6

Explanation: The largest element in array is 6

Example 2

Input: nums = [3, 3, 0, 99, -40]

Output: 99

Explanation: The largest element in array is 99
*/

#include<stdio.h>
// void main(){
//     int n;
//     int array[100];
//     printf("enter the number of arrays");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&array[i]);
//     }
//     int max=array[0];
//     for(int j=1;j<n;j++){
//         if(array[j]>max){
//             max=array[j];
//         }
//     }
//     printf("%d",max);
// }

//more optimal one!

int main(){
    int n,x,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(i==0||x>max){
            max=x;
        }
    }
    printf("%d",max);
}