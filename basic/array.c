#include<stdio.h>
#include<stdlib.h>


int findMax(int arr[],int n){
    int max=arr[0];
        for (int i=1;i<n;i++){
            if(max<arr[i]){
            max=arr[i];
            }
        }
    return max;
    }

int comparator(const void *a,const void *b){
    int x=*(int *)a;
    int y=*(int *)b;
    if(x<y){
        return 1;
    }else{
        return -1;
    }

}


int linearSearch(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l,int r,int target){
    int m=(l+r)/2;
    if(target==arr[m]){
        return m;
    }

    if(target<arr[m]){
        return binarySearch(arr,l,m,target);
    }else{
        return binarySearch(arr,m,r,target);
    }
}


int main(){
    int arr[]={1,2,3,4,5};
    //printf("%d", findMax(arr,5));
    qsort(arr,5,sizeof(int),comparator);
    for(int i=0;i<5;i++){
        printf("%d,",arr[i]);

    }
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    printf("\n%d",sum);


    int index= binarySearch(arr,0,4,3);
    printf("\n%d",index);

}