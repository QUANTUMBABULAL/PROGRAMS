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

int compare(const void * a,const void  *b ){
    int x=*(int*)a;
    int y=*(int*)b;
    if(x<y){
        return 1;
    }else{
        return -1;
    }
}
int maximumDistinctSubarraySum(int arr_count, int* arr, int k)
{
  qsort(arr,arr_count,sizeof(int),compare);
  int count=0;
  int temp[]={0};
  for(int i=0;i<arr_count;i++){
   for(int j=1;j<arr_count;j++){
    if(arr[i]!=arr[j]){
        temp[count]=arr[i];
    }
   }
  }
  int last_sum=0;
  int n_sum=0;
  int temp_n=sizeof(temp)/sizeof(int);
  for(int i=0;i<temp_n;i++){
    for(int j=1;j<temp_n;j++){
        for(int k=2;k<temp_n;k++){
            n_sum = temp[i]+temp[j]+temp[k];
        }
        if(last_sum<n_sum){
            last_sum=n_sum;
        }
    }
  }
  return last_sum;

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