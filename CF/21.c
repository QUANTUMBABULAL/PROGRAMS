// #include<stdio.h>
// #include<limits.h>
// int main(){
//     int t,n;
//     int max=INT_MIN;
//     int count;
//     int maxindex;
//     int arr[200001];
//     scanf("%d",&t);
//     while(t--){
//         scanf("%d",&n);

        
//         for(int i=0;i<n;i++){
//             scanf("%d",&arr[i]);
//         }
//         for(int j=0;j<n;j++){
//             if(arr[j]>=max){
//                 max=arr[j];
//                 maxindex=j;
//             }

//         }
//         for(int k=j;k>=0;k--){
//             if(arr[k])
//         }
        
//         }
//     }
// }

#include <stdio.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    int current_max = 0;
    int operations = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        if (val >= current_max) {
            operations++;
            current_max = val;
        }
    }

    printf("%d\n", operations);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        solve();
    }
    
    return 0;
}