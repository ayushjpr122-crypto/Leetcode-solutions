class Solution {
public:
    int sum(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>eggs;
        int n = nums.size();

        for(int i=0;i<n;i++){
            eggs.push_back({sum(nums[i]),nums[i]});        
        }

        sort(eggs.begin(),eggs.end());

       map<int,int>mp;
       for(int i=0;i<n;i++){
            mp[eggs[i].second] = i;
       }

        vector<int>visited(n,0);
        int swap = 0;
        for(int i=0;i<n;i++){

            if(visited[i] || mp[nums[i]] == i)continue;

            int j = i;
            int cycle = 0;

            while(!visited[j]){
                visited[j] = 1;
                j = mp[nums[j]];
                cycle++;
            }
            swap += cycle - 1;
        }

        return swap;
        
    }
};