class Solution {
public:
    // const int N = 1e5+10;
    int dp[2515];
    int lis(int i,vector<int>&arr){
        if(dp[i] != -1)return dp[i];
        int ans = 1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
            ans = max(ans,lis(j,arr)+1);
        }
        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,lis(i,nums));
        }
        return ans;
    }
};