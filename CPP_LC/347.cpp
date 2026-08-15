/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]
*/
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
     static bool compare(pair<int,int> a , pair<int,int> b){
        return b.second<a.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
         sort(v.begin(),v.end(),compare);
         vector<int> ans;
         for(int j=0;j<k;j++){
             ans.push_back(v[j].first);
         }
     return ans;    
    }
};