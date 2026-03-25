/*
B. New York Hotel
time limit per test2 seconds
memory limit per test256 megabytes
Think of New York as a rectangular grid consisting of N vertical avenues numerated from 1 to N and M horizontal streets numerated 1 to M. C friends are staying at C hotels located at some street-avenue crossings. They are going to celebrate birthday of one of them in the one of H restaurants also located at some street-avenue crossings. They also want that the maximum distance covered by one of them while traveling to the restaurant to be minimum possible. Help friends choose optimal restaurant for a celebration.

Suppose that the distance between neighboring crossings are all the same equal to one kilometer.

Input
The first line contains two integers N и M — size of the city (1 ≤ N, M ≤ 109). In the next line there is a single integer C (1 ≤ C ≤ 105) — the number of hotels friends stayed at. Following C lines contain descriptions of hotels, each consisting of two coordinates x and y (1 ≤ x ≤ N, 1 ≤ y ≤ M). The next line contains an integer H — the number of restaurants (1 ≤ H ≤ 105). Following H lines contain descriptions of restaurants in the same format.

Several restaurants and hotels may be located near the same crossing.

Output
In the first line output the optimal distance. In the next line output index of a restaurant that produces this optimal distance. If there are several possibilities, you are allowed to output any of them.

Examples
InputCopy
10 10
2
1 1
3 3
2
1 10
4 4
OutputCopy
6
2

*/

#include<stdio.h>
#include<limits.h>

long long absl(long long x){
    return x>=0 ? x : -x;
}

int main(){

long long N,M;
scanf("%lld %lld",&N,&M);

long long C;
scanf("%lld",&C);

long long x,y;
long long maxsum = LLONG_MIN;
long long minsum = LLONG_MAX;
long long maxdiff = LLONG_MIN;
long long mindiff = LLONG_MAX;

for(int i=0;i<C;i++){

    scanf("%lld %lld",&x,&y);

    long long s = x+y;
    long long d = x-y;

    if(s>maxsum) maxsum=s;
    if(s<minsum) minsum=s;

    if(d>maxdiff) maxdiff=d;
    if(d<mindiff) mindiff=d;
}

long long R;
scanf("%lld",&R);

long long bestdist = LLONG_MAX;
int bestindex = 1;

for(int j=1;j<=R;j++){

    long long xr,yr;
    scanf("%lld %lld",&xr,&yr);

    long long sr = xr+yr;
    long long dr = xr-yr;

    long long r1 = absl(sr-maxsum);
    long long r2 = absl(sr-minsum);
    long long r3 = absl(dr-maxdiff);
    long long r4 = absl(dr-mindiff);

    long long maxdist = r1;

    if(r2>maxdist) maxdist=r2;
    if(r3>maxdist) maxdist=r3;
    if(r4>maxdist) maxdist=r4;

    if(maxdist<bestdist){
        bestdist=maxdist;
        bestindex=j;
    }
}

printf("%lld\n",bestdist);
printf("%d\n",bestindex);

}