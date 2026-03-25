/*
Second Largest Element
Subscribe to TUF+

Hints
Company
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.


Example 1

Input: nums = [8, 8, 7, 6, 5]

Output: 7

Explanation:

The largest value in nums is 8, the second largest is 7

Example 2

Input: nums = [10, 10, 10, 10, 10]

Output: -1

Explanation:

The only value in nums is 10, so there is no second largest value, thus -1 is returned

*/

#include<stdio.h>
#include<limits.h>


int secondlargest(int arr[],int n){
    int secondlargest = LLONG_MIN;
    int largest =LLONG_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }else if(arr[i]>secondlargest&&arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    if(secondlargest==LLONG_MIN){
        return -1;
    }

    return secondlargest;
}

int main(){
    int arr[]={5,5,5,5,5};
    printf("%d",secondlargest(arr,5));
}