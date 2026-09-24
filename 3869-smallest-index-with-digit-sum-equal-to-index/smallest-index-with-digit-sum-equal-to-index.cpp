class Solution {
public:
    int smallestIndex(vector<int>& arr) {
        
        int n = arr.size();
        int x = -1;
        for(int i=0;i<n;i++){
            int sum = 0;
            while(arr[i]>0){
                sum += arr[i]%10;
                arr[i] = arr[i]/10;
            }
            if(sum == i){
                x = i;
                break;
            }
        }
        return x;
    }
};