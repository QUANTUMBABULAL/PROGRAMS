/*
150. Evaluate Reverse Polish Notation
Medium
Topics
premium lock icon
Companies
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
#include<iostream>
#include<vector>
#include<stack>
class Solution {
public:
    
int ians(int a, int b,char ch){
switch(ch){
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
}
int isop(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
           return 1;     
            }else{
                return 0;
            }
}
}
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i=0;i<tokens.size();i++){
            char ch=token[i];
            if(!st.empty()&&isop(ch)){
                int second=st.pop();
                int first=st.pop();
                int answer=ans(first,second,ch);
                st.push(answer);
            }else{
                st.push(ch-'0');
            }
        }
        return st.pop();

    }
};





