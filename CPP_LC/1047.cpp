/*
1047. Remove All Adjacent Duplicates In String
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

#include<iostream>
#include<stack>
class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        for(int i=0;i<s.size();i++){
            bool flag=false;
            while(!st.empty()&&s[i]==st.top()){
                flag=true;
                st.pop();
            }
            if(!flag){
                st.push(s[i]);
            }
        } 
        string ans="";
        int n=st.size();
        for(int j=0;j<n;j++){
            char last=st.top();
            st.pop();
            ans=last+ans;
        }
        return ans;
    }
};