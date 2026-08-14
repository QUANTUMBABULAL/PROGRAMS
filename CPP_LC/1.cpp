    #include <iostream>
    #include <vector>
    #include <unordered_map>
    using namespace std;
    class Soulution{
    public:
        vector<int> tsum(vector<int>& arr,int target){
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            int need=target-arr[i];
            if(mp.find(need)!=mp.end()){
                return {mp[need],i};
            }
            mp[arr[i]]=i;
        } 
        return {};

        }
        
    };