#include<unorderd_map>
#include<iosteam>
#include<vector>
using namespacestd;
class Solution{
    public:
        unordered_map<int,int> mp;
        vector<int> twoSum(vector<int>& nums, int target) {
            for(int i=0;i<nums.size();i++){
                int need=target-nums[i];
                if(mp.count(need)){
                    return {mp[need],i};
                }
                mp[nums[i]]=i;
            }
            return {};
        }

};