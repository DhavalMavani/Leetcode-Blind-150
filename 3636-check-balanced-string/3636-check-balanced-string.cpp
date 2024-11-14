class Solution {
public:
    bool isBalanced(string num) {
        int odd=0,even=0,n=num.size();
        for(int i=0;i<n;i++){
            if(i%2) odd+=(num[i]-'0');
            else even+=(num[i]-'0');
        }
        return odd==even;
    }
};