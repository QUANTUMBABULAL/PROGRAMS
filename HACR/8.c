#include <stdbool.h>
bool checkInclusion(char* s1, char* s2){
int right=0;
int left =0;
int n=strlen(s1);
int m=strlen(s2);
int freqofs1[26]={0};
int freqofs2[26]={0};

if(n>m){
    return false;
}

for(int i=0;i<n;i++){
    freqofs1[s1[i]-'a']++;
}

while(right<m){
    int same=true;
    freqofs2[s2[right]-'a']++;
    if(right-left+1==n){
        for(int i=0;i<26;i++){
            if(freqofs1[i]!=freqofs2[i]){
                same=false;
            }
          
        }
        if(same==true){
                return true;
            }
            freqofs2[s2[left]-'a']--;
            left++;
         
    }
    right++;

}
return false;
}
