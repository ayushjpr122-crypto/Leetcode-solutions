class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int n = s.size();
        int reset = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(reset);
                reset = 0;
            }
            else{
                reset = st.top() + max(2*reset , 1);
                st.pop(); 

            }
        }

        return reset;
    }
};