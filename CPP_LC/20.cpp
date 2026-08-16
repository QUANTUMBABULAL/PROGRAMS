
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:

    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char>  mp;
        mp[')']='(';
        mp[']']='[';
        mp['}']='{';
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(st.empty()){
                    return false;
                }
                    if(st.top()==mp[s[i]]){
                        st.pop();
                    }else{
                        return false;
                    }
                
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return true;
        }
    return false;

    }
};