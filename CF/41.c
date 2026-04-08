// again grid covering problem only but my style 


#include<stdio.h>

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
int t;
int n,m,a,b;
scanf("%d",&t);
while(t--){
    scanf("%d %d %d %d",&n,&m,&a,&b);
    if(gcd(n,a)==gcd(m,b)){
        printf("YES\n");

    }else{
        printf("NO\n");
    }
}

}