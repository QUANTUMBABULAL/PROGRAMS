/*
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.


Example 1

Input : nums = [1, 2, 3, 4, 5]

Output : true

Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.

Example 2

Input : nums = [1, 2, 1, 4, 5]

Output : false

Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.
*/
#include<stdbool.h>
#include<stdio.h>
int main(){
    bool flag=true;
    int n,x,prev;
    printf("enter the size of array");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(i==0||prev<=x){
            prev=x;    
        }else{
            flag=false;
        }
    }
printf("%d",flag);

}