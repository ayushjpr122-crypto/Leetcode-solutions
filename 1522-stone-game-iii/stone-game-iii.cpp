class Solution {
public:

    pair<int,int> dp[50001];
    bool vis[50001] = {};

    pair<int,int> func(int i,vector<int>& a){
        
        int n = a.size();

        if(i>=n)return {0,0};

        if(vis[i])return dp[i];

      auto p1 = func(i+1,a);

      int x = a[i] + p1.second;
      int y = p1.first;

      pair<int,int> ans = {x,y};

      if(i<n-1){
        auto p2 = func(i+2,a);

        int x = a[i] + a[i+1] + p2.second;
        int y = p2.first;

        if(ans.first < x){
            ans = {x,y};
        }

      }

      if(i<n-2){
        auto p3 = func(i+3,a);

        int x = a[i] + a[i+1] + a[i+2] + p3.second;
        int y = p3.first;

        if(ans.first < x){
            ans = {x,y};
        }
      }

        vis[i] = true;
        return dp[i] = ans;

    }


    string stoneGameIII(vector<int>& stoneValue) {
        
        auto ans = func(0, stoneValue);

        if (ans.first > ans.second) return "Alice";
        if (ans.first < ans.second) return "Bob";

        return "Tie";
    }
};