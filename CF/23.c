/*
A. Pangram
time limit per test2 seconds
memory limit per test256 megabytes
A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once. Pangrams are often used to demonstrate fonts in printing or test the output devices.

You are given a string consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. We say that the string contains a letter of the Latin alphabet if this letter occurs in the string in uppercase or lowercase.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of characters in the string.

The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

Output
Output "YES", if the string is a pangram and "NO" otherwise.

Examples
InputCopy
12
toosmallword
OutputCopy
NO
InputCopy
35
TheQuickBrownFoxJumpsOverTheLazyDog
OutputCopy
YES
*/

#include<stdio.h>
#include<string.h>
int main(){
    int n,index;
    char str[101];
    char alp[26]={0};
    scanf("%d",&n);
    scanf("%s",str);

    for(int i=0;i<n;i++){
        if(str[i]<='Z'&&str[i]>='A'){
            index = str[i]-'A';
        }else if(str[i]<='z'&&str[i]>='a'){
            index =str[i]-'a';
        }
        alp[index]=1;
    }
int sum=0;
for(int j=0;j<26;j++){
    sum+=alp[j];
}
if(sum==26){
    printf("YES");
}else{
    printf("NO");
}
}