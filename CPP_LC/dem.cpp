#include<unordered_map>
class Solution {
public:
    unordered_map<int,int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        int x=target;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
            int need=nums[i]-target;
            if(mp.count(need)){
                return {mp[need],i};
            }
        }
        return {};
    }
};