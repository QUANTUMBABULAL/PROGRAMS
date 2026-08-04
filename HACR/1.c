//this one has a lot of bugs

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'maximumDistinctSubarraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER k
 */


int maximumDistinctSubarraySum(int arr_count, int* arr, int k)
{
//base case:
    if(k>arr_count){
    return 0;
    }
    int duplicate=0;
    int freqarr[10001]={0};
    int sum=0;
    int maxsum=0;
    int left=0;
    int right=0;
    while(right<arr_count){
    sum+=arr[right];
    freqarr[arr[right]]++;
    if(freqarr[arr[right]]==2){
        duplicate++;
    }


    if(right-left+1==k){
        if(duplicate==0){
        if(sum>maxsum){
            maxsum=sum;
        }}
        sum-=arr[left];
        freqarr[arr[left]]--;
        if(freqarr[arr[left]]==1){
            duplicate--;
        }
        left++;

    }

 right++;
  }
  return maxsum;
}

int main()
{
    int arr_count;
    scanf("%d", &arr_count);

    int* arr = (int*)malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    int result = maximumDistinctSubarraySum(arr_count, arr, k);

    printf("%d\n", result);

    free(arr);

    return 0;
}