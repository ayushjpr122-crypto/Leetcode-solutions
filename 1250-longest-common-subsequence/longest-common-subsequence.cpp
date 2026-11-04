class Solution {
public:

    long long dp[1000][1000];

    int lcs(int i1,int i2,string &s1,string &s2){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2] != -1)return dp[i1][i2];
        int ans = lcs(i1-1,i2,s1,s2);

        ans = max(ans,lcs(i1,i2-1,s1,s2));

        ans = max(ans,lcs(i1-1,i2-1,s1,s2) + (s1[i1] == s2[i2]));

        return dp[i1][i2] = ans;
    }


    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1.size() - 1,text2.size() - 1,text1,text2);
    }
};