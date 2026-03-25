#include<stdio.h>

int main(){
    char s[50];
    int t,n;

    scanf("%d",&t);

    while(t--){
        scnaf("%d",&n);
        scanf("%s",s);
        int count = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == 'R'){
                count++;
            }
            else if(s[i] == 'L'){
                count++;
                break;   
            }
        }

        printf("%d\n", count);
    }

    return 0;
}