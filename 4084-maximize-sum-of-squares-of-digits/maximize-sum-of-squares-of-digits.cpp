class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string s = "";
        int count = 0;
        int x=-1;
        int places = 0;
        for(int i=0;i<num;i++){
            if(count + 9<=sum){
                count += 9;
                s += '9';
                places ++;
            }
            else{
                x = i;
                break;
            }
        }
        int final = sum - count;
        if(final>9 || (final>0 && places == num))return "";
        if(places<num) {
        s += char( '0' + final);
        for(int i=x+1;i<num;i++){
            s += '0';
        }
        }

        return s;

    }
};