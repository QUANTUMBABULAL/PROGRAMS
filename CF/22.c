//A. Spy Detected!
#include<stdio.h>
int main(){

    int t,x,index,compele,n;
    int arr[101];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        
        index=1;
        compele=arr[0];
        for(int j=1;j<n;j++){
            if(compele==arr[j]){
                continue;
            }else {
                index=j;
                break;
            }
        }
        printf("%d\n",index);
    }
}