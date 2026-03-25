/*
A. Word Capitalization
time limit per test2 seconds
memory limit per test256 megabytes
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.

Input
A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 103.

Output
Output the given word after capitalization.

Examples
InputCopy
ApPLe
OutputCopy
ApPLe
InputCopy
konjac
OutputCopy
Konjac

*/

#include<stdio.h>
int main(){
    char str[1001];
    scanf("%s",str);
    if(str[0]<='Z'&&str[0]>='A'){
        printf("%s",str);
    }else{
        str[0]-=32;
        printf("%s",str);
    }
}