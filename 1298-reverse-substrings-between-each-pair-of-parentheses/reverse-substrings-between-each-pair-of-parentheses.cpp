class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char>st;
        vector<char>result;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                //st.pop();
                string fake = "";
                while(st.top()!='('){
                    fake += st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<fake.size();i++){
                    st.push(fake[i]);
                }
            }
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return string(result.begin(), result.end());

    }
};