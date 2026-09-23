class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        int target = sum - x;

        if(target == 0)return n;
        int l = 0;
        int maxi = -1;
        int t = 0;
        for(int i=0;i<n;i++){
            t+=arr[i];
            while(l<=i && t>target){
                t-=arr[l];
                l++;
            }

            if(t == target){
                maxi = max(maxi,i-l+1);
            }
        }

        if(maxi == -1)return -1;

        return n - maxi;


    }
};