#include<iostream>
#include<vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,-1);
        stack <int> st;
        for(int i=0;i<2*n;i++){
            int index =i%n;
            while(!st.empty()&&nums[index]>nums[st.top()]){
                ans[st.top()]=nums[index];
                st.pop();
            }
            st.push(index);
        }
        return ans;
    }
};