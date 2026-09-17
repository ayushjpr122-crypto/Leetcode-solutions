class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         int n = nums.size();
        unordered_map<int,vector<int>>mp(n);

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int count = 0;

        for(auto [key,val]:mp){
            if(val.size()!=3)continue;
        
            int diff = val[1] - val[0];
            bool flag =1;
            for(int i=1;i<val.size()-1;i++){
                if(val[i+1] - val[i] != diff){
                    flag = 0;
                    break;
                }
            }

            if(flag)count++;

        }

        return count;
    }
};