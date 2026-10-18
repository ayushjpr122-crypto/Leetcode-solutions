class Solution {
public:
    int dp[310][11111];
    int cc(int amount, vector<int>& coins, int i) {
        if(amount == 0)return 1;
        if(i<0)return 0;
         if(dp[i][amount]!=-1)return dp[i][amount];
    int count = 0;
       for(int j=0;j<=amount;j+=coins[i]){
         count +=  cc(amount-j,coins,i-1);
       }
       return dp[i][amount] = count;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return cc(amount, coins, n-1);
    }
};